#include "CveChecker.h"
#include "CLChecker.h"
#include "CpeCveChecker.h"
#include "PocChecker.h"
#include "SysPatchChecker.h"

CCveHunter::CCveHunter(void)
{
}

CCveHunter::~CCveHunter(void)
{
}

BOOL CCveHunter::PreScan()
{
	//这些数据库是否全部有必要，每个数据库是否需要全部加载进内存，要在开发过程中考虑。
	LoadCveDatabase();
	LoadCpeDatabase();
	LoadCLDatabase();
	LoadSysPatchDatabase();
	LoadPocDatabase();
	
	if(/*指定了要扫描的漏洞*/)
	{
		//构建m_pVulList链表
		LoadTargetVuls(&m_pVulList);
	}
	else
	{
		LoadVulsDatabase();
	}

	return TRUE;
}

BOOL CCveHunter::Scan()
{
	CVulNode *pVulNode = NULL;
	if(m_pVulList)/*如果指定了要扫描的漏洞*/
	{
		for(;;)//遍历VulList，拿到每个VulNode
		{
			for(;;)//遍历enum CheckerType
			{
				CheckerType eChecker;//这里循环CheckerType，为了编译通过暂时这么写
				IChecker* pChecker = NULL;
				pChecker = pVulNode->GetChecker(eChecker);
				if(!pChecker)
				{
					if(pChecker->DoCheck())
					{
						//发出告警信息，就不需要继续Check了
						break;
					}
				}
			}
		}

		return TRUE;
	}

	GetInstalledPackages();
	for(;;)//遍历所有已安装的软件
	{
		CVulList *pVulList = NULL;
		//利用 software-cpe 和 cpe-cve 关系
		pVulList = GetVulInfo(NULL);//这里有可能一个软件对应多个CVE，所以还要有一层for循环
		
		for(;;)//遍历pVulList链表
		{
			CVulNode *pVulNode = NULL;//临时定义的
			for(;;)//遍历enum CheckerType
			{
				CheckerType eChecker;//这里循环CheckerType，为了编译通过暂时这么写
				IChecker* pChecker = NULL;
				pChecker = pVulNode->GetChecker(eChecker);
				if(!pChecker)
				{
					if(pChecker->DoCheck())
					{
						//发出告警信息，就不需要继续Check了
						break;
					}
				}
			}
		}
	}
	
	return TRUE;
}

BOOL CCveHunter::PostScan()
{
	return TRUE;
}

/**
* 先扫描系统上可升级的包，并利用changelog匹配相关CVE。
* 本地维护一个db，避免每次都去调用apt-get命令查询。
*
* 再去获取已安装的模块（可能会有重复），去匹配
* @return 
*/

BOOL CCveHunter::ScanInstalledPackages()
{
	return TRUE;
}

/**
* 相关的官方网站下载CVE数据和CPE数据，并构建CPE和CVE的关系库
*
* @return 
*/
BOOL CCveHunter::BuildCpeCveDatabase()
{
	return TRUE;
}

BOOL CCveHunter::CreateCpeCveDatabase()
{
	return TRUE;
}

BOOL CCveHunter::LoadTargetVuls(CVulList* pVulList)
{
	return TRUE;
}

BOOL CCveHunter::LoadCLDatabase()
{
	return TRUE;
}

BOOL CCveHunter::GetInstalledPackages()
{
	return TRUE;
}

CVulNode* CCveHunter::GetVulInfo(VOID*/*Software info*/)
{
	return NULL;
}
