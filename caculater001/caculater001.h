
// caculater001.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ccaculater001App:
// �йش����ʵ�֣������ caculater001.cpp
//

class Ccaculater001App : public CWinApp
{
public:
	Ccaculater001App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ccaculater001App theApp;