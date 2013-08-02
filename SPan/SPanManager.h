#ifndef _S_PAN_MANAGER_H_
#define _S_PAN_MANAGER_H_

#include "SPanInfo.h"

class SPanManager
{
public:
	SPanManager( VOID );
	~SPanManager( VOID );

	BOOL Init( VOID );

private:
	SPanInfo m_pSPanInfo;
};

#endif