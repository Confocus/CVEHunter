#pragma once

/************************************************************************/
/*
Initialize necessary db
Scan vuluerabilities                                                 
*/
/************************************************************************/

#include "SqliteManager.h"
#include "VulNode.h"

class CCveHunter
{
public:
	CCveHunter(void);
	~CCveHunter(void);

private:
	
	BOOL GetInstalledPackages();

	/**
	* ����©�����ݿ⡣�ÿ���Ӧ�����ٰ������©�����õļ�ⷽ������Ϣ��
	*
	* @return 
	*/
	BOOL LoadVulsDatabase();

	/**
	* ���û����ȡcve���ݣ���һЩ�ٷ���վ����cve���ݣ����������ݿ�
	* ����ֱ�Ӽ���cve���ݿ�
	*
	* @return 
	*/
	BOOL LoadCveDatabase();

	/**
	* ���û����ȡcpe���ݣ���һЩ�ٷ���վ����cpe���ݣ����������ݿ�
	* ����ֱ�ӽ���cpe���ݿ�
	*
	* @return 
	*/
	BOOL LoadCpeDatabase();

	/**
	* ���û������Ԥ���changelog��Ϣ����ͨ��Linux�����ȡchangelog��Ϣ�����������ݿ�
	* ����ֱ�ӽ��ڼ���
	*
	* @return 
	*/
	BOOL LoadCLDatabase();

	/**
	* ����ϵͳ������ȫ�������ݿ⣬������ݿ���Ҫ����ά���������򲻸���ά��
	*
	* @return 
	*/
	BOOL LoadSysPatchDatabase();

	/**
	* ����CVE��Ӧ��poc���ݿ⣬������ݿ���Ҫ����ά���������򲻸���ά��
	*
	* @return 
	*/
	BOOL LoadPocDatabase();

	/**
	* ����ָ����Ҫɨ���©������������Ҫ������ĵ��д��ڵ�53��©����
	*
	* @param pVulList:����©������
	* @return 
	*/
	BOOL LoadTargetVuls(CVulList** pVulList);

	/**
	* ���������Ϣ��ȡ©����Ϣ���ɽ���Levenshtein�������ƥ�䡣
	*
	* @param : Software info
	* @return : �õ�һ��Vul������
	*/
	CVulList* GetVulInfo(VOID*/*Software info*/);

public:

	/**
	* ��һЩɨ��ǰ��ǰ�ù���
	*
	* @return 
	*/
	BOOL PreScan();

	/**
	* ɨ��
	*
	* @return 
	*/
	BOOL Scan();

	/**
	* ��һЩɨ��������������ر����ݿ�֮��
	*
	* @return 
	*/
	BOOL PostScan();

private:
	CConfigManager m_ConfigManager;//LoadTargetVuls���������������ļ���
	CSqliteManager m_SqlManager;//LoadXXX�����������������ݿ�ġ�Ҳ���Կ���ʹ��XML��json��
	CVulList* m_pVulList;
};
