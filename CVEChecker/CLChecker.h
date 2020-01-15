#pragma once
#include "ichecker.h"

/************************************************************************/
/* ChangeLog check.                                                     */
/************************************************************************/

class CCLChecker :
	public IChecker
{
public:
	CCLChecker(void);
	~CCLChecker(void);
public:
	BOOL DoCheck();
};
