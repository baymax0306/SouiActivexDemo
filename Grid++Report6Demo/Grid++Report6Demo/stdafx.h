// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

//ATL支持
#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>

#define  _CRT_SECURE_NO_WARNINGS
#define	 DLL_SOUI
#include <souistd.h>
#include <core/SHostDialog.h>
#include <control/SMessageBox.h>
#include <control/souictrls.h>
#include <res.mgr/sobjdefattr.h>
#include <com-cfg.h>
#include "resource.h"
#define R_IN_CPP	//定义这个开关来
#include "res\resource.h"
//using namespace SOUI;

//报表的IFont接口和soui冲突了
//using namespace SOUI;


//NOTE
//activex属于真窗口，还需要把主窗口的translucent属性设为0
