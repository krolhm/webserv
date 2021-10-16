/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:30:12 by rbourgea          #+#    #+#             */
/*   Updated: 2021/10/14 15:29:37 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "webserv.hpp"
# include "CGI.hpp"

std::string findTypeofFile(std::string path)
{
	std::string str = path.substr(path.find_last_of(".") + 1);

	if (str == "html")
		return ("text/html");
	else if (str == "htm")
		return ("text/html");
	else if (str == "shtml")
		return ("text/html");
	else if (str == "css")
		return ("text/css");
	else if (str == "xml")
		return ("text/xml");
	else if (str == "gif")
		return ("image/gif");
	else if (str == "jpeg")
		return ("image/jpeg");
	else if (str == "jpg")
		return ("image/jpeg");
	else if (str == "js")
		return ("application/javascript");
	else if (str == "atom")
		return ("application/atom+xml");
	else if (str == "rss")
		return ("application/rss+xml");
	else if (str == "mml")
		return ("text/mathml");
	else if (str == "txt")
		return ("text/plain");
	else if (str == "jad")
		return ("text/vnd.sun.j2me.app-descriptor");
	else if (str == "wml")
		return ("text/vnd.wap.wml");
	else if (str == "htc")
		return ("text/text/x-component");
	else if (str == "png")
		return ("image/png");
	else if (str == "svg" || str == "svgz")
		return ("image/svg+xml");
	else if (str == "tif" || str == "tiff")
		return ("image/tiff");
	else if (str == "wbmp")
		return ("image/vnd.wap.wbmp");
	else if (str == "webp")
		return ("image/webp");
	else if (str == "ico")
		return ("image/x-icon");
	else if (str == "jng")
		return ("image/x-jng");
	else if (str == "bmp")
		return ("image/x-ms-bmp");
	else if (str == "woff")
		return ("font/woff");
	else if (str == "woff2")
		return ("font/woff2");
	else if (str == "jar" || str == "war" || str == "ear")
		return ("application/java-archive");
	else if (str == "json")
		return ("application/json");
	else if (str == "hqx")
		return ("application/mac-binhex40");
	else if (str == "doc")
		return ("application/msword");
	else if (str == "pdf")
		return ("application/pdf");
	else if (str == "ps" || str == "eps" || str == "ai")
		return ("application/postscript");
	else if (str == "rtf")
		return ("application/rtf");
	else if (str == "m3u8")
		return ("application/vnd.apple.mpegurl");
	else if (str == "kml")
		return ("application/vnd.google-earth.kml+xml");
	else if (str == "kmz")
		return ("application/vnd.google-earth.kmz");
	else if (str == "xls")
		return ("application/vnd.ms-excel");
	else if (str == "eot")
		return ("application/vnd.ms-fontobject");
	else if (str == "ppt")
		return ("application/vnd.ms-powerpoint");
	else if (str == "odg")
		return ("application/vnd.oasis.opendocument.graphics");
	else if (str == "odp")
		return ("application/vnd.oasis.opendocument.presentation");
	else if (str == "ods")
		return ("application/vnd.oasis.opendocument.spreadsheet");
	else if (str == "odt")
		return ("application/vnd.oasis.opendocument.text");
	else if (str == "pptx")
		return ("application/vnd.openxmlformats-officedocument.presentationml.presentation");
	else if (str == "xlsx")
		return ("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
	else if (str == "docx")
		return ("application/vnd.openxmlformats-officedocument.wordprocessingml.document");
	else if (str == "bin" || str == "exe" || str == "ddl" || str == "deb" || str == "dmg" 
				|| str == "iso" || str == "img" || str == "msi" || str == "msp" || str == "msm")
		return ("application/octet-stream");
	else if (str == "wmlc")
		return ("application/vnd.wap.wmlc");
	else if (str == "7z")
		return ("application/x-7z-compressed");
	else if (str == "cco")
		return ("application/x-cocoa");
	else if (str == "jardiff")
		return ("application/x-java-archive-diff");
	else if (str == "jnlp")
		return ("application/x-java-jnlp-file");
	else if (str == "run")
		return ("application/x-makeself");
	else if (str == "pl" || str == "pm")
		return ("application/x-perl");
	else if (str == "prc" || str == "pdb")
		return ("application/x-pilot");
	else if (str == "rar")
		return ("application/x-rar-compressed");
	else if (str == "rpm")
		return ("application/x-redhat-package-manager");
	else if (str == "sea")
		return ("application/x-sea");
	else if (str == "swf")
		return ("application/x-shockwave-flash");
	else if (str == "sit")
		return ("application/x-stuffit");
	else if (str == "tcl" || str == "tk")
		return ("application/x-tcl");
	else if (str == "der" || str == "pem" || str == "crt")
		return ("application/x-x509-ca-cert");
	else if (str == "xpi")
		return ("application/x-xpinstall");
	else if (str == "xhtml")
		return ("application/xhtml+xml");
	else if (str == "xspf")
		return ("application/xspf+xml");
	else if (str == "zip")
		return ("application/zip");
	else if (str == "mid" || str == "midi" || str == "kar")
		return ("audio/midi");
	else if (str == "mp3")
		return ("audio/mpeg");
	else if (str == "ogg")
		return ("audio/ogg");
	else if (str == "m4a")
		return ("audio/x-m4a");
	else if (str == "ra")
		return ("audio/x-realaudio");
	else if (str == "3gpp" || str == "3gp")
		return ("video/3gpp");
	else if (str == "ts")
		return ("video/mp2t");
	else if (str == "mp4")
		return ("video/mp4");
	else if (str == "mpeg" || str == "mpg")
		return ("video/mpeg");
	else if (str == "mov")
		return ("video/quicktime");
	else if (str == "webm")
		return ("video/webm");
	else if (str == "flv")
		return ("video/x-flv");
	else if (str == "m4v")
		return ("video/x-m4v");
	else if (str == "mng")
		return ("video/x-mng");
	else if (str == "asx" || str == "asf")
		return ("video/x-ms-asf");
	else if (str == "wmv")
		return ("video/x-ms-wmv");
	else if (str == "avi")
		return ("video/x-msvideo");
	return ("text/plain");
}

std::string getFileContent(const std::string& path)
{
	std::basic_ifstream<char> fin(path, std::ios::binary);
	std::ostringstream oss;
	oss << fin.rdbuf();
	std::string data(oss.str());
	return (data);
}

bool IsPathExist(const std::string &s)
{
  struct stat buffer;
  return (stat (s.c_str(), &buffer) == 0);
}

bool CheckFilePerm(std::string& path)
{
	if (access (path.c_str(), F_OK) != 0)
	{
		if (errno == ENOENT)
			return (1);
		else if (errno == EACCES)
			return (0);
	}
	return (1);
}

std::string countFileChar(std::string string)
{
	std::ifstream in_file(string, std::ios::binary);
	in_file.seekg(0, std::ios::end);
	int file_size = in_file.tellg();
	std::stringstream ss;
	ss << file_size;
	ss >> string;
    return (string);
};

void print_CGIenv()
{
	std::cout << "\n---------------------------" << std::endl;
	std::cout << "| CGI Environment Variables:" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "| SERVER_SOFTWARE = " << getenv("SERVER_SOFTWARE") << std::endl;
	std::cout << "| SERVER_NAME = " << "???" << std::endl;
	std::cout << "| GATEWAY_INTERFACE = " << getenv("GATEWAY_INTERFACE") << std::endl;
	std::cout << "|" << std::endl;
	std::cout << "| SERVER_PROTOCOL = " << getenv("SERVER_PROTOCOL") << std::endl;
	std::cout << "| SERVER_PORT = " << "???" << std::endl;
	std::cout << "| REQUEST_METHOD = " << getenv("REQUEST_METHOD") << std::endl;
	std::cout << "| PATH_INFO = " << getenv("PATH_INFO") << std::endl;
	std::cout << "| PATH_TRANSLATED = " << "???" << std::endl;
	std::cout << "| SCRIPT_NAME = " << getenv("SCRIPT_NAME") << std::endl;
	std::cout << "| QUERY_STRING = " << getenv("QUERY_STRING") << std::endl;
	std::cout << "| REMOTE_HOST = " << "???" << std::endl;
	std::cout << "| REMOTE_ADDR = " << "???" << std::endl;
	std::cout << "| AUTH_TYPE = " << getenv("AUTH_TYPE") << std::endl;
	std::cout << "| REMOTE_USER = " << "???" << std::endl;
	std::cout << "| REMOTE_IDENT = " << "???" << std::endl;
	std::cout << "| CONTENT_TYPE = " << "???" << std::endl;
	std::cout << "| CONTENT_LENGTH = " << getenv("CONTENT_LENGTH") << std::endl;
	std::cout << "|" << std::endl;
	std::cout << "| HTTP_ACCEPT = " << getenv("HTTP_ACCEPT") << std::endl;
	std::cout << "| HTTP_ACCEPT_LANGUAGE = " << getenv("HTTP_ACCEPT_LANGUAGE") << std::endl;
	std::cout << "| HTTP_USER_AGENT = " << getenv("HTTP_USER_AGENT") << std::endl;
	std::cout << "| HTTP_COOKIE = " << "???" << std::endl;
	std::cout << "| HTTP_REFERER = " << getenv("HTTP_REFERER") << std::endl;
	std::cout << "---------------------------" << std::endl;
}

void CGIparsing(std::vector<unsigned char> buffer)
{
	std::vector<char> tmp;
	int i = 0;

	while ((size_t)i < buffer.size())
	{
		tmp.push_back(buffer[i]);
		i++;
	}
	std::string s_tmp(tmp.begin(), tmp.end());
	// std::cout << "[" << s_tmp << "] ";

	setenv("SERVER_SOFTWARE", "webserv/1.0", 0);
	setenv("GATEWAY_INTERFACE", "CGI/1.1", 0);
	setenv("SERVER_PROTOCOL", "HTTP/1.1", 0);
	setenv("AUTH_TYPE", "Basic", 0);

	std::istringstream buffer2(s_tmp);
	std::string line;
	size_t first;

	while (getline(buffer2, line, '\n'))
	{
		if (line.empty() || line == "\r")
			break;
		if (line.back() == '\r')
			line.resize(line.size() - 1);
		std::cout << "> " << line << "\n";

		first = line.find("GET /cgi-bin/");
		if (first != std::string::npos)
		{
			line.erase(first, 13);
			first = line.find(" HTTP/");
			line.erase(first, 9);
			first = line.find("/");
			setenv("QUERY_STRING", line.substr(first + 2).c_str(), 0);
			setenv("PATH_INFO", line.substr(first + 1).c_str(), 0);
			first = line.find("/");
			line.erase(first, line.length());
			setenv("SCRIPT_NAME", line.c_str(), 0);
		}

		first = line.find("User-Agent: ");
		if (first != std::string::npos)
			setenv("HTTP_USER_AGENT", line.substr(first + 12).c_str(), 0);

		first = line.find("Referer: ");
		if (first != std::string::npos)
			setenv("HTTP_REFERER", line.substr(first + 9).c_str(), 0);

		first = line.find("Accept: ");
		if (first != std::string::npos)
			setenv("HTTP_ACCEPT", line.substr(first + 8).c_str(), 0);

		first = line.find("Accept-Language: ");
		if (first != std::string::npos)
			setenv("HTTP_ACCEPT_LANGUAGE", line.substr(first + 17).c_str(), 0);

	}

	if (!getenv("REQUEST_METHOD"))
		setenv("REQUEST_METHOD", "NAN", 0);
	if (!getenv("PATH_INFO"))
		setenv("PATH_INFO", "NAN", 0);
	if (!getenv("SCRIPT_NAME"))
		setenv("SCRIPT_NAME", "NAN", 0);
	if (!getenv("QUERY_STRING"))
		setenv("QUERY_STRING", "NAN", 0);
	if (!getenv("HTTP_USER_AGENT"))
		setenv("HTTP_USER_AGENT", "NAN", 0);
	if (!getenv("HTTP_REFERER"))
		setenv("HTTP_REFERER", "NAN", 0);
	if (!getenv("HTTP_ACCEPT"))
		setenv("HTTP_ACCEPT", "NAN", 0);
	if (!getenv("HTTP_ACCEPT_LANGUAGE"))
		setenv("HTTP_ACCEPT_LANGUAGE", "NAN", 0);
}

std::vector<unsigned char> parsing(std::vector<unsigned char> buffer)
{
	std::string location = "directory", METHOD = "NAN", PATH = "NAN", HTTP, s_tmp_previous;
	std::vector<char> tmp;
	int i = 0;
	
	while ((size_t)i < buffer.size())
	{
		while ((size_t)i < buffer.size() && buffer[i] != ' ')
		{
			tmp.push_back(buffer[i]);
			i++;
		}
		
		std::string s_tmp(tmp.begin(), tmp.end());
		// GET METHODS
		if (s_tmp == "GET" || s_tmp == "POST" || s_tmp == "DELETE")
			METHOD = s_tmp;
		// GET PATH
		if (s_tmp.rfind("/", 0) == 0)
			PATH = s_tmp;
		// GET HTTP
		if (s_tmp.find("HTTP/") != std::string::npos)
			HTTP.assign(tmp.begin() + 5, tmp.begin() + 8);
		
		tmp.clear();
		i++;
	}
	
	std::string rep;
	location += PATH;

	setenv("REQUEST_METHOD", METHOD.c_str(), 0);

	if (METHOD != "GET" && METHOD != "POST" && METHOD != "DELETE")
	{
		rep = "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/html";
		location = "directory/405.html";
	}
	else if ((METHOD == "GET" || METHOD == "POST" || METHOD == "DELETE")
				&& location == "directory")
	{
		rep = "HTTP/1.1 400 Method Not Allowed\r\nContent-Type: text/html";
		location = "directory/400.html";
	}
	else if (!IsPathExist(location))
	{
		rep = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html";
		location = "directory/404.html";
	}
	// else if (s.find("Content-Length") == std::string::npos)
	// {
	// 	message += "HTTP/1.1 411 Length Required";
	// }
	else if (location == "directory/")
	{
		rep = "HTTP/1.1 200 OK\r\nContent-Type: text/html";
		location = "directory/index.html";
	}
	else if (HTTP != "1.1")
	{
		rep = "HTTP/1.1 505 HTTP Version not supported\r\nContent-Type: text/html";
		location = "directory/505.html";
	}
	else if (!CheckFilePerm(location))
	{
		rep = "HTTP/1.1 403 Forbidden\r\nContent-Type: text/html";
		location = "directory/505.html";
	}
	else
	{
		rep = "HTTP/1.1 200 OK\r\nContent-Type: ";
		rep += findTypeofFile(location);
	}
	
	rep += "\r\nContent-Length: ";
	rep += countFileChar(location);
	setenv("CONTENT_LENGTH", countFileChar(location).c_str(), 0);
	rep += "\r\n\r\n" + getFileContent(location);

	//  OLD CGI SYSTEM
	// CGIparsing(buffer);
	// print_CGIenv();
	
	// NEW CGI SYSTEM
	CGI *cgi = new CGI();

	std::vector<unsigned char> response(rep.begin(), rep.end());
	return (response);
}
