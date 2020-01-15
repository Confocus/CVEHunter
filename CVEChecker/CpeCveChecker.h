#pragma once
#include "ichecker.h"

/************************************************************************/
/* Cpe-Cve relation check                                               */
/************************************************************************/

class CCpeCveChecker :
	public IChecker
{
public:
	CCpeCveChecker(void);
	~CCpeCveChecker(void);

public:
	BOOL DoCheck();
};
