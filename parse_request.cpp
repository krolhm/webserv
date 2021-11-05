#include "HTTPRequest.hpp"

void	printRequestHeader(HTTPRequest &request)
{
	std::map<std::string, std::string>::iterator it(request.headerFields.begin());
  std::cout << CYN << "PARSE REQUEST" << std::endl;
  for (size_t i(0); i < request.rL.method.size(); i++)
    std::cout << request.rL.method[i];
  std::cout << " ";
  for (size_t i(0); i < request.rL.requestTarget.size(); i++)
        std::cout << request.rL.requestTarget[i];
  std::cout << " ";
  for (size_t i(0); i < request.rL.httpVersion.size(); i++)
        std::cout << request.rL.httpVersion[i];
  std::cout << std::endl;
  while (it != request.headerFields.end())
  {
        std::cout << it->first << ": " << it->second << "\n";
        it++;
  }
}

void	printRequestBody(HTTPRequest &request)
{
	for (size_t i(0); i < request.body.size(); i++)
		std::cout << request.body[i];
	std::cout << std::endl;
}

void	parseRequest(std::vector<unsigned char> message, HTTPRequest &request)
{
	size_t i(0);

	if (request.isHeaderComplete == false)
	{
		std::cout << "ici???\n";
		while (i < message.size() && request.isHeaderComplete == false)
		{
			if (message[i] == '\r' && message[i + 1] == '\n')
			{
				i+= 2;
				if (message[i] == '\r' && message[i + 1] == '\n')
				{
					i+= 2;
					request.insertHeaderLine();
					request.isHeaderComplete = true;
					printRequestHeader(request);
					request.determineIfBody();
					if (request.isBody == false)
						request.isComplete = true;
				}
				else
					request.insertHeaderLine();
			}
			else
			{
				request.tmp.push_back(message[i]);
				i++;
			}
		}
	}
	if (request.isBody == true && request.isHeaderComplete == true && request.isComplete == false)
	{
		if (request.isChunked == false)
		{
			while (i < message.size() && request.currentBodySize < request.bodySize)
			{
				request.body.push_back(message[i]);
				i++;
				request.currentBodySize++;
			}
			if (request.body.size() == request.bodySize)
			{
				request.isComplete = true;
				printRequestBody(request);
			}
		}
	}
}
