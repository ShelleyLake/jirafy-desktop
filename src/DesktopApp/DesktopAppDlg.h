#pragma once

#include <afxdialogex.h>

#include "Browser\BrowserScreen.h"
#include "DesktopAppFrame.h"

class DesktopAppDlg : public CDialogEx
{
public:
//Constructors / Destructors
  DesktopAppDlg(_In_opt_ CWnd* pParent = nullptr);

//Member variables
  enum { IDD = IDD_TOASTPP_DIALOG };

//Methods
  void ReportToastNotification(_In_z_ LPCTSTR pszDetails, _In_ BOOL bAppend);

protected:
//Member variables
  HICON m_hIcon;
  CComboBox m_wndPayloads;
  CEdit m_wndPayload;
  CString m_sPayload;
  CEdit m_wndStatusMessages;

  std::unique_ptr<desktop::ui::BrowserScreen> m_browser_dlg;
  std::unique_ptr<DesktopAppFrame> m_frame;

//Methods
  static CStringW FixUpImagesInXML(_In_ const CStringW& sXML);
  void DoDataExchange(CDataExchange* pDX) override;
  BOOL OnInitDialog() override;
  
  HRESULT VerifyXML(_Inout_ CString& sError);

//Message handlers
  afx_msg void OnPaint();
  afx_msg HCURSOR OnQueryDragIcon();
  afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
  afx_msg BOOL OnNcActivate(BOOL bActive);
  afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
  afx_msg LRESULT OnNcHitTest(CPoint point);
  afx_msg void OnChangePayload();
  afx_msg void OnClickedClear();
  afx_msg void OnSize(UINT, int, int);

  DECLARE_MESSAGE_MAP()
};
