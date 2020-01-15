#pragma once
#include "ichecker.h"

/************************************************************************/
/* Check system patch or configuration                                  */
/************************************************************************/

class CSysPatchChecker :
	public IChecker
{
public:
	CSysPatchChecker(void);
	~CSysPatchChecker(void);

public:
	BOOL DoCheck();
};