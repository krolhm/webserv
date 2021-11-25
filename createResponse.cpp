#include "HTTPResponse.hpp"

std::vector<unsigned char>	createResponse(HTTPRequest request, struct server s)
{
	HTTPResponse response(request, s);
	response.defineResponseHeader();
	response.defineResponseBody();
	response.aggregateResponse();
	std::cout << "NEW RESPONSE\n" << response.resp << std::endl;
	std::vector<unsigned char> resp(response.resp.begin(), response.resp.end());
	return (resp);
}
