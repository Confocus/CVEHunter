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
	* 加载漏洞数据库。该库中应该至少包含这个漏洞可用的检测方法等信息。
	*
	* @return 
	*/
	BOOL LoadVulsDatabase();

	/**
	* 如果没有拉取cve数据，则到一些官方网站下载cve数据，并建立数据库
	* 否则直接加载cve数据库
	*
	* @return 
	*/
	BOOL LoadCveDatabase();

	/**
	* 如果没有拉取cpe数据，则到一些官方网站下载cpe数据，并建立数据库
	* 否则直接接在cpe数据库
	*
	* @return 
	*/
	BOOL LoadCpeDatabase();

	/**
	* 如果没有事先预存的changelog信息，则通过Linux命令，拉取changelog信息，并构建数据库
	* 否则，直接接在即可
	*
	* @return 
	*/
	BOOL LoadCLDatabase();

	/**
	* 加载系统补丁或安全配置数据库，这个数据库需要另外维护，本程序不负责维护
	*
	* @return 
	*/
	BOOL LoadSysPatchDatabase();

	/**
	* 加载CVE对应的poc数据库，这个数据库需要另外维护，本程序不负责维护
	*
	* @return 
	*/
	BOOL LoadPocDatabase();

	/**
	* 加载指定的要扫描的漏洞（本程序主要是针对文档中存在的53个漏洞）
	*
	* @param pVulList:保存漏洞链表
	* @return 
	*/
	BOOL LoadTargetVuls(CVulList** pVulList);

	/**
	* 根据软件信息获取漏洞信息。可借助Levenshtein距离进行匹配。
	*
	* @param : Software info
	* @return : 得到一个Vul的链表
	*/
	CVulList* GetVulInfo(VOID*/*Software info*/);

public:

	/**
	* 做一些扫描前的前置工作
	*
	* @return 
	*/
	BOOL PreScan();

	/**
	* 扫描
	*
	* @return 
	*/
	BOOL Scan();

	/**
	* 做一些扫描后的清理工作，如关闭数据库之类
	*
	* @return 
	*/
	BOOL PostScan();

private:
	CConfigManager m_ConfigManager;//LoadTargetVuls中用来加载配置文件的
	CSqliteManager m_SqlManager;//LoadXXX函数中用来加载数据库的。也可以考虑使用XML或json。
	CVulList* m_pVulList;
};
