#pragma once

/************************************************************************/
/*
����һ�������顱�洢ָ��©������©�����תΪ������Ϊ������������ or ���� or map��
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
