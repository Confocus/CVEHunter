#pragma once
#include "Macro.h"
#include "VulNode.h"
#include "IChecker.h"

/************************************************************************/
/*
�洢ĳ��©�������ݣ�����©����š�©�����ơ�©�������Ϣ�����Դ��ĸ��Ƕ�ȥ��⣨���ֽǶ�֮һ��
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
