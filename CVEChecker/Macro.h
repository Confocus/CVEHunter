#define VULNUMBER_SIZE	0x50
#define VULINFO_SIZE	0x500
#define VULNAME_SIZE	0x50

enum CheckerType
{
	CLChecker = 1,
	CpeCveChecker,
	SysPatchChecker,
	PocChecker
};