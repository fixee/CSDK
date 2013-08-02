#ifndef _HTTP_CLIENT_H_
#define _HTTP_CLIENT_H_

#include <Windows.h>
#include <string>

interface HTTPVersion
{
	virtual std::string GetVersionName() = 0;
};

class HTTPVersion_1_1 : public HTTPVersion
{
public:
	virtual std::string GetVersionName()
	{
		std::string name("HTTP/1.1");
		return name;
	}
};

typedef enum
{
	HTTP_METHOD_GET = 0,
	HTTP_METHOD_HEAD = 1,
	HTTP_METHOD_PUT = 2,
	HTTP_METHOD_POST = 3
}HTTP_METHOD;









#endif