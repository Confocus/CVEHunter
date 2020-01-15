#pragma once

/************************************************************************/
/*
构建一个“数组”存储指定漏洞，以漏洞编号转为数字作为索引。用数组 or 链表 or map？
*/
/************************************************************************/

class CVulList
{
public:
	CVulList(void);
	~CVulList(void);

	CVulNode* GetVulNode(int);

public:
	VOID Insert();
	VOID Remove();
	VOID Clear();
	VOID Search();
};
