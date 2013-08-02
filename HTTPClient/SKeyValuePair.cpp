#include "SKeyValuePair.h"

using namespace std;

SKeyValuePair::SKeyValuePair( VOID )
{
}
SKeyValuePair::~SKeyValuePair( VOID )
{
}

BOOL SKeyValuePair::InsertHeader( std::string &strKey, std::string &strValue )
{
	return FALSE;
}

BOOL SKeyValuePair::Haskey( std::string &strKey )
{
	return FALSE;
}

string SKeyValuePair::ToString( VOID )
{
	string val("{ ");
	BOOL bFirst = TRUE;
	
	map<string,string>::iterator iter = m_header.begin();
	while(iter != m_header.end())
	{
		if( bFirst )
			bFirst = FALSE;
		else
			val.append(" , ");

		val.append( iter->first );
		val.append(" : ");
		val.append( iter->second );

		iter++;
	}

	val.append(" }");
	return val;
}
