#pragma once
#include "Macro.h"
#include "VulNode.h"
#include "IChecker.h"

/************************************************************************/
/*
存储某项漏洞的内容，包括漏洞编号、漏洞名称、漏洞相关信息、可以从哪个角度去检测（四种角度之一）
*/
/************************************************************************/

class CVulNode
{
public:
	CVulNode(void);
	~CVulNode(void);

public:
	IChecker* GetChecker(CheckerType eType);
	TCHAR* GetVulNumber();
	TCHAR* GetVulInfo();
	TCHAR* GetVulName();

private:
	TCHAR m_szVulNumber[VULNUMBER_SIZE];//CVE-XXXX-XXXX
	TCHAR m_szVulInfo[VULINFO_SIZE];
	TCHAR m_szVulName[VULNAME_SIZE];//Dirty Cow
};
