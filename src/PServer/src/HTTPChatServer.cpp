//
// Created by cenicol on 7/21/19.
//
#include <PServer/HTTPChatServer.hpp>

#include <PServer/ChatRequestHandlerFactory.hpp>

#include <Poco/Debugger.h>
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"

#include <Poco/Data/Session.h>
#include <Poco/Data/SessionPool.h>
#include <Poco/Data/SQLite/Connector.h>

#include <iostream>

#include <include/PServer/Users.hpp>

using Poco::Net::HTTPServerParams;
using Poco::Net::HTTPServer;
using Poco::Net::ServerSocket;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;using Poco::ThreadPool;

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

using namespace std;

std::unique_ptr<Poco::Data::SessionPool> HTTPChatServer::pPool_ = nullptr;

HTTPChatServer & HTTPChatServer::instance()
{
    return dynamic_cast<HTTPChatServer&>( Poco::Util::Application::instance() );
}

Poco::Data::Session HTTPChatServer::getPool()
{
    return HTTPChatServer::pPool_->get();
}

bool HTTPChatServer::hasPool()
{
    return HTTPChatServer::pPool_ ? true : false;
}

HTTPChatServer::HTTPChatServer()
        : _helpRequested(false)
        , _port(9980)
{

}

HTTPChatServer::~HTTPChatServer() {

}

void HTTPChatServer::initialize(Application &self) {
    try {
        loadConfiguration(); // load default configuration files, if present
        HTTPChatServer::pPool_.reset( new Poco::Data::SessionPool("SQLite", "chat.db") );
        ServerApplication::initialize(self);
    } catch (...) {
        logger().error("exception");
    }
}

void HTTPChatServer::uninitialize() {
    pPool_->shutdown();
    ServerApplication::uninitialize();
}

void HTTPChatServer::defineOptions(OptionSet &options) {
    ServerApplication::defineOptions(options);

    options.addOption(
            Option("help", "h", "display help information on command line arguments")
                    .required(false)
                    .repeatable(false)
                    .callback(OptionCallback<HTTPChatServer>(this, &HTTPChatServer::handleHelp))
    );

    cout << "Add option --port,p" << endl;
    options.addOption(
            Option("port", "p", "port to listen")
                    .required(false)
                    .repeatable(false)
                    .argument("port", true)
                    .callback(OptionCallback<HTTPChatServer>(this, &HTTPChatServer::handlePort))
    );
}


void HTTPChatServer::handleOption(const std::string &name, const std::string &value) {
    ServerApplication::handleOption(name, value);
}

void HTTPChatServer::displayHelp() {
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("A web server that serves the current date and time.");
    helpFormatter.format(std::cout);
}

void HTTPChatServer::handleHelp(const std::string &name, const std::string &value) {
    _helpRequested = true;
    displayHelp();
    stopOptionsProcessing();
}

void HTTPChatServer::handlePort(const std::string &name, const std::string &value) {
    logger().trace(__PRETTY_FUNCTION__);
}

void HTTPChatServer::showKeys(const string& key) {
    Poco::Util::AbstractConfiguration::Keys keys;
    config().keys(key, keys);
    if(keys.empty()) {
        try {
            cout << " = " << config().getRawString(key) << endl;
        } catch(...) {
            cout << key << " not found" << endl;
        }
    } else {
        cout << endl;
    }
    for(auto i : keys) {
        cout << key << "." << i;
        string subKey {key};
        if(! key.empty()) {
            subKey.append(".");
        }
        subKey.append(i);
        showKeys(subKey);
    }
}

int HTTPChatServer::main(const std::vector<std::string> &args) {
    if (Poco::Debugger::isAvailable()) {
        cout << "Poco in debug mode" << endl;
    } else {
        cout << "Poco in release mode" << endl;
    }

    if (_helpRequested) {
        return Application::EXIT_USAGE;
    }

    Application &app = Application::instance();
    app.logger().information("Starting Server");

    showKeys("");

    // register SQLite connector
    Poco::Data::SQLite::Connector::registerConnector();

    // create a session
    //Session session = HTTPChatServer::getPool();

    Users::createUsers();

    // get parameters from configuration file
    unsigned short port = (unsigned short) config().getInt("HTTPChatServer.port", 9980);

    //std::string format(config().getString("HTTPChatServer.format", DateTimeFormat::SORTABLE_FORMAT));
    int maxQueued = config().getInt("HTTPChatServer.maxQueued", 100);
    int maxThreads = config().getInt("HTTPChatServer.maxThreads", 16);
    ThreadPool::defaultPool().addCapacity(maxThreads);

    HTTPServerParams *pParams = new HTTPServerParams;
    pParams->setMaxQueued(maxQueued);
    pParams->setMaxThreads(maxThreads);

    // set-up a server socket
    ServerSocket svs(port);

    // set-up a HTTPServer instance
    HTTPServer srv(new ChatRequestHandlerFactory(), svs, pParams);

    // start the HTTPServer
    srv.start();

    // wait for CTRL-C or kill
    waitForTerminationRequest();

    // Stop the HTTPServer
    srv.stop();

    return Application::EXIT_OK;
}
