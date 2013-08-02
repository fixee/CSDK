#ifndef _S_PARAM_H_
#define _S_PARAM_H_

#include "SKeyValuePair.h"

class SParam : public SKeyValuePair
{
public:
	SParam( VOID );
	~SParam( VOID );

	virtual std::string ToString( VOID );
};
#endif

