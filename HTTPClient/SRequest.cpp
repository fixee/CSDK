#include "SRequest.h"
#include <tchar.h>


SRequest::SRequest( VOID ) : m_pVersion( NULL ), m_hInst(NULL), m_hConn(NULL), m_hReq(NULL),
	m_Method(HTTP_METHOD_GET), m_nPort(INTERNET_DEFAULT_HTTP_PORT)
{
}


SRequest::~SRequest( VOID )
{
	DeleteVersion();
}

inline VOID SRequest::DeleteVersion( VOID )
{
	if(NULL != m_pVersion)
	{
		delete m_pVersion;
		m_pVersion = NULL;
	}
}

BOOL SRequest::SetHTTPVersion( HTTPVersion *pVersion )
{
	if(NULL == pVersion)
		return FALSE;
	DeleteVersion();
	m_pVersion = pVersion;

	return TRUE;
}

BOOL SRequest::Init( VOID )
{
	m_pVersion = new HTTPVersion_1_1;
	if(NULL == m_pVersion)
		return FALSE;

	m_strHostName = _T("api.pan.sohu.net");

	//����Э��
	m_hInst = InternetOpen(_T("Microsoft Internet Explorer"),INTERNET_OPEN_TYPE_DIRECT,NULL,NULL,0);
	if(NULL == m_hInst)
		return FALSE;

	//�鿴�Ƿ��п��õ���������
	DWORD dwConnectable = InternetAttemptConnect(0);
	if(dwConnectable != ERROR_SUCCESS)  //�޿����������˳�
	{
		MyCloseHandle(m_hInst);
		return FALSE;        
	}

	//��������
	m_hConn = InternetConnect(m_hInst,m_strHostName.c_str(),m_nPort,NULL,NULL,INTERNET_SERVICE_HTTP,0,0);
	if(NULL == m_hConn)   //���ʧ�����˳�
	{
		MyCloseHandle(m_hInst);
		return FALSE;
	}

	return TRUE;
}

BOOL SRequest::OpenRequest( VOID )
{
	//����������
	return FALSE;
}

DWORD SRequest::ReadRecvData( BYTE *pBuff, DWORD dwSize )
{
	//��ȡ����
	//���pBuffΪ��, dwSize = -1 �򷵻�Ӧ�������ݴ�С
	//����������ȡ

	if(NULL == pBuff)
		return 0;
	return 0;
}