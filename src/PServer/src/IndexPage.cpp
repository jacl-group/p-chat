//
// Created by cenicol on 7/23/19.
//
//
//    This file is part of poco-chat.
//
//    tf is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    tf is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with tf.  If not, see <https://www.gnu.org/licenses/>.
//
#include "IndexPage.hpp"

#include "Poco/Util/ServerApplication.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Net/HTTPServerRequest.h"
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

using Poco::Util::Application;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;

using namespace Poco::Net;
using namespace std;

IndexPage::IndexPage(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
: HTMLPage(request, response)
{
#if 0
    Application &app = Application::instance();
    app.logger().trace(__PRETTY_FUNCTION__);
#endif
}

string IndexPage::style_ = R"END(
<style>
td.button {
  text-align: center;
  column-span: 2;
}
td.error {
  text-align: center;
  column-span: 2;
  color: red;
}
p.time {
  text-align: center;
  font-size: 48px;
}
</style>
)END";

void IndexPage::write(HTMLForm* pForm) {
    string function { __PRETTY_FUNCTION__ };
    Application &app = Application::instance();
    app.logger().information(function);

    Timestamp now;
    std::string format = DateTimeFormat::SORTABLE_FORMAT;
    std::string dt(DateTimeFormatter::format(now, format));

    std::string title{"IndexPage"};

    response_.setChunkedTransferEncoding(true);
    response_.setContentType("text/html");

    std::ostream &ostr = response_.send();
    ostr << "<html><head>";
    ostr << "\n<!-- " << function << " -->\n";
    ostr << "<title>" << title << "</title>";
    ostr << IndexPage::style_;
    ostr << "</head>\n<body>";
    ostr << R"(<p class="time">)" << dt << "</p>";

    ostr << R"END(
<p>The welcome page which is basically index.html</p>
<p>Other things can be placed on this page, but the minimum is a way to login to the site.</p>
)END";

    auto commentIt = pForm->find("comment");
    if( commentIt != pForm->end() ) {
        ostr << endl << "<!-- " << commentIt->second << " -->" << endl;
    }

    ostr << R"END(
<form action="signin" method="post">
<table>)END";

    auto errorIt = pForm->find("error");
    if( errorIt != pForm->end() ) {
        ostr << R"(<tr><td class="error" colspan="2">)";
        ostr << errorIt->second;
        ostr << "</td></tr>";
    }
      ostr << R"END(
<tr><td>Username:</td><td><input type="text" name="username"></input></td></tr>
<tr><td>Password:</td><td><input type="password" name="password"></input></td></tr>
<tr><td class="button" colspan="2"><input type="submit" name="action" value="Login"></td></tr>
<tr><td class="button" colspan="2">or <input type="submit" name="action" value="Register"></td></tr>
</table>
</form>
)END";

    ostr << "</body>";
    ostr << "</html>";
}
