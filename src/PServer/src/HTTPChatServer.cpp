//
// Created by cenicol on 7/21/19.
//

#include "include/PServer/HTTPChatServer.hpp"
#include <PServer/ChatRequestHandlerFactory.hpp>

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"

#include <iostream>

using Poco::Net::HTTPServerParams;
using Poco::Net::HTTPServer;
using Poco::Net::ServerSocket;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;using Poco::ThreadPool;

void HTTPChatServer::initialize(Application& self)
{
    loadConfiguration(); // load default configuration files, if present
    ServerApplication::initialize(self);
}

void HTTPChatServer::uninitialize()
{
    ServerApplication::uninitialize();
}

void HTTPChatServer::defineOptions(OptionSet& options)
{
    ServerApplication::defineOptions(options);

    options.addOption(
            Option("help", "h", "display help information on command line arguments")
                    .required(false)
                    .repeatable(false));
}

void HTTPChatServer::handleOption(const std::string& name, const std::string& value)
{
    ServerApplication::handleOption(name, value);

    if (name == "help")
        _helpRequested = true;
}

void HTTPChatServer::displayHelp()
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("A web server that serves the current date and time.");
    helpFormatter.format(std::cout);
}

int HTTPChatServer::main(const std::vector<std::string>& args)
{
    if (_helpRequested)
    {
        displayHelp();
    }
    else
    {
        //Application& app = Application::instance();
        //app.logger().information("Starting Server");

        // get parameters from configuration file
        unsigned short port = (unsigned short) config().getInt("HTTPChatServer.port", 9980);
        //std::string format(config().getString("HTTPChatServer.format", DateTimeFormat::SORTABLE_FORMAT));
        int maxQueued  = config().getInt("HTTPChatServer.maxQueued", 100);
        int maxThreads = config().getInt("HTTPChatServer.maxThreads", 16);
        ThreadPool::defaultPool().addCapacity(maxThreads);

        HTTPServerParams* pParams = new HTTPServerParams;
        pParams->setMaxQueued(maxQueued);
        pParams->setMaxThreads(maxThreads);

        // set-up a server socket
        ServerSocket svs(port);
        // set-up a HTTPServer instance
        //HTTPServer srv(new ChatRequestHandlerFactory(format), svs, pParams);
        HTTPServer srv(new ChatRequestHandlerFactory(), svs, pParams);
        // start the HTTPServer
        srv.start();
        // wait for CTRL-C or kill
        waitForTerminationRequest();
        // Stop the HTTPServer
        srv.stop();
    }
    return Application::EXIT_OK;
}
