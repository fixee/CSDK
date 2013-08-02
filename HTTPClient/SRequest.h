#ifndef _S_REQUEST_H_
#define _S_REQUEST_H_

#include "HTTPClient.h"
#include "SHeader.h"
#include "SParam.h"
#include <WinInet.h>

class SRequest
{
public:
	SRequest( VOID );
	~SRequest( VOID );

	BOOL Init( VOID );
	BOOL OpenRequest( VOID );
	DWORD ReadRecvData( BYTE *pBuff, DWORD dwSize );


	BOOL SetHTTPVersion( HTTPVersion *pVersion );
	BOOL SetRequestURL( std::string &url );

	SHeader &GetHeader( VOID ){ return m_Header; }
	SParam &GetParam( VOID ){ return m_Param; }
	std::string &GetUrl( VOID ){ return m_strUrl; }


private:
	VOID DeleteVersion( VOID );
	BOOL MyCloseHandle(HINTERNET handl){ BOOL bOK = CloseHandle(handl); if(bOK) handl = NULL; return bOK; }

private:
	SHeader m_Header;
	SParam m_Param;
	HTTP_METHOD m_Method;
	HTTPVersion *m_pVersion;
	std::string m_strUrl;

private:
	HINTERNET m_hInst,m_hConn,m_hReq;
	INTERNET_PORT m_nPort;
	std::wstring m_strHostName;
};

#endif


