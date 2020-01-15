#pragma once
#include "ichecker.h"

/************************************************************************/
/* Check with poc.                                                      */
/************************************************************************/

class CPocChecker :
	public IChecker
{
public:
	CPocChecker(void);
	~CPocChecker(void);

public:
	BOOL DoCheck();
};
