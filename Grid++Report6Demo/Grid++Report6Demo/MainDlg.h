// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include "GridppReport/GridppReportEventImpl.h"

using namespace SOUI;
class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

	void OnPreView();
	void InitGridppCtrl(void);
	void FillReport();
	void FillNodeitems(void);
	void OnTreeSelChanged(EventArgs* pEvt);
	void OnRadioClick(EventArgs* pEvt);
	void OnChangeSkin(EventArgs* pEvt);
	void OnQuery();
	void OnDesign();
protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"preview", OnPreView)
		EVENT_NAME_HANDLER(R.name.template_tree, EVT_TC_SELCHANGED, OnTreeSelChanged)
		EVENT_NAME_HANDLER(R.name.radio_preview, EVT_CMD, OnRadioClick)
		EVENT_NAME_HANDLER(R.name.radio_query, EVT_CMD, OnRadioClick)
		EVENT_ID_RANGE_HANDLER(R.id.radio_def, R.id.radio_blue, EVT_CMD, OnChangeSkin)
		EVENT_NAME_COMMAND(R.name.btn_query, OnQuery)
		EVENT_NAME_COMMAND(R.name.btn_design, OnDesign)
	EVENT_MAP_END()
		
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;	
	IGridppReportPtr m_pGridppReport;
	IGRDisplayViewerPtr m_pDisplayViewer;
	IGRPrintViewerPtr	m_pPrintViewer;
	CGridppReportEventImpl* m_pReportEvents;
	SStringT m_TemplateFile;
};
