#ifndef _S_KEY_VALUE_PAIR_H_
#define _S_KEY_VALUE_PAIR_H_

#include "HTTPClient.h"
#include <map>

class SKeyValuePair
{
public:
	SKeyValuePair( VOID );
	~SKeyValuePair( VOID );

	BOOL InsertHeader( std::string &strKey, std::string &strValue );
	BOOL Haskey( std::string &strKey );

	virtual std::string ToString( VOID );
private:
	std::map<std::string,std::string> m_header;

};


#endif

