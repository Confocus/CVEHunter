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
	//��Щ���ݿ��Ƿ�ȫ���б�Ҫ��ÿ�����ݿ��Ƿ���Ҫȫ�����ؽ��ڴ棬Ҫ�ڿ��������п��ǡ�
	LoadCveDatabase();
	LoadCpeDatabase();
	LoadCLDatabase();
	LoadSysPatchDatabase();
	LoadPocDatabase();
	
	if(/*ָ����Ҫɨ���©��*/)
	{
		//����m_pVulList����
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
	if(m_pVulList)/*���ָ����Ҫɨ���©��*/
	{
		for(;;)//����VulList���õ�ÿ��VulNode
		{
			for(;;)//����enum CheckerType
			{
				CheckerType eChecker;//����ѭ��CheckerType��Ϊ�˱���ͨ����ʱ��ôд
				IChecker* pChecker = NULL;
				pChecker = pVulNode->GetChecker(eChecker);
				if(!pChecker)
				{
					if(pChecker->DoCheck())
					{
						//�����澯��Ϣ���Ͳ���Ҫ����Check��
						break;
					}
				}
			}
		}

		return TRUE;
	}

	GetInstalledPackages();
	for(;;)//���������Ѱ�װ�����
	{
		CVulList *pVulList = NULL;
		//���� software-cpe �� cpe-cve ��ϵ
		pVulList = GetVulInfo(NULL);//�����п���һ�������Ӧ���CVE�����Ի�Ҫ��һ��forѭ��
		
		for(;;)//����pVulList����
		{
			CVulNode *pVulNode = NULL;//��ʱ�����
			for(;;)//����enum CheckerType
			{
				CheckerType eChecker;//����ѭ��CheckerType��Ϊ�˱���ͨ����ʱ��ôд
				IChecker* pChecker = NULL;
				pChecker = pVulNode->GetChecker(eChecker);
				if(!pChecker)
				{
					if(pChecker->DoCheck())
					{
						//�����澯��Ϣ���Ͳ���Ҫ����Check��
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
* ��ɨ��ϵͳ�Ͽ������İ���������changelogƥ�����CVE��
* ����ά��һ��db������ÿ�ζ�ȥ����apt-get�����ѯ��
*
* ��ȥ��ȡ�Ѱ�װ��ģ�飨���ܻ����ظ�����ȥƥ��
* @return 
*/

BOOL CCveHunter::ScanInstalledPackages()
{
	return TRUE;
}

/**
* ��صĹٷ���վ����CVE���ݺ�CPE���ݣ�������CPE��CVE�Ĺ�ϵ��
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
