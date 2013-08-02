#ifndef _S_HEADER_H_
#define _S_HEADER_H_

#include "HTTPClient.h"
#include "SKeyValuePair.h"
#include <map>

class SHeader : public SKeyValuePair
{
public:
	SHeader( VOID );
	~SHeader( VOID );

	virtual std::string ToString( VOID );
};

#endif//_S_HEADER_H_