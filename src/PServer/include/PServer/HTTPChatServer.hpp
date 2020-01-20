//
// Created by cenicol on 7/21/19.
//

#ifndef POCO_CHAT_HTTPCHATSERVER_HPP
#define POCO_CHAT_HTTPCHATSERVER_HPP

#include <Poco/Util/ServerApplication.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/SessionPool.h>

#if 0
namespace Poco {
    namespace Util {
        class OptionSet;
    }
}
#endif

/// The main application class.
///
/// This class handles command-line arguments and
/// configuration files.
/// Start the HTTPChatServer executable with the help
/// option (/help on Windows, --help on Unix) for
/// the available command line options.
///
/// To use the sample configuration file (HTTPChatServer.properties),
/// copy the file to the directory where the HTTPChatServer executable
/// resides. If you start the debug version of the HTTPChatServer
/// (HTTPChatServerd[.exe]), you must also create a copy of the configuration
/// file named HTTPChatServerd.properties. In the configuration file, you
/// can specify the port on which the server is listening (default
/// 9980) and the format of the date/time string sent back to the client.
///
/// To test the TimeServer you can use any web browser (http://localhost:9980/).
class HTTPChatServer : public Poco::Util::ServerApplication {
public:
    HTTPChatServer();

    ~HTTPChatServer();

    static HTTPChatServer& instance();

    static Poco::Data::Session getPool();

    static bool hasPool();

protected:
    void initialize(Application& self);

    void uninitialize();

    void defineOptions(Poco::Util::OptionSet& options);

    void handleOption(const std::string& name, const std::string& value);

    void displayHelp();

    void handleHelp(const std::string& name, const std::string& value);

    void handlePort(const std::string& name, const std::string& value);

    int main(const std::vector<std::string>& args);

private:
    void showKeys(const std::string& key);

    bool _helpRequested;
    unsigned short _port;

    static std::unique_ptr<Poco::Data::SessionPool> pPool_;
};


#endif //POCO_CHAT_HTTPCHATSERVER_HPP
