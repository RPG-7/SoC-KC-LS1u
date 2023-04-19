
// GlowCompilerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "GlowCompiler.h"
#include "GlowCompilerDlg.h"
#include "afxdialogex.h"

#include "cpp.h"
#include "c.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGlowCompilerDlg 对话框



CGlowCompilerDlg::CGlowCompilerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GLOWCOMPILER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGlowCompilerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGlowCompilerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CGlowCompilerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CGlowCompilerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CGlowCompilerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CGlowCompilerDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CGlowCompilerDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CGlowCompilerDlg 消息处理程序

BOOL CGlowCompilerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	FindComm();
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("115200"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("230400"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("460800"));
	GetDlgItem(IDC_COMBO3)->SetWindowTextW(_T("8"));
	GetDlgItem(IDC_COMBO4)->SetWindowTextW(_T("NO"));
	GetDlgItem(IDC_COMBO6)->SetWindowTextW(_T("1"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGlowCompilerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGlowCompilerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGlowCompilerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGlowCompilerDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}

/*文本文件转CString*/
void File_To_CString(char* file, CString* str) {
	FILE* fp;
	char fp_buf[1024];
	int fp_size;
	int rd_size;

	if ((fp = fopen(file, "rb")) != NULL) {
		fseek(fp, 0, SEEK_END);
		fp_size = ftell(fp);
		rewind(fp);
		while (fp_size != 0) {
			if (fp_size < 1024) {
				fread(fp_buf, 1, fp_size, fp);
				rd_size = fp_size;
				fp_size = 0;
			}
			else {
				fread(fp_buf, 1, 1024, fp);
				rd_size = 1024;
				fp_size -= 1024;
			}
			for (int i = 0; i < rd_size; ++i) {
				if (fp_buf[i] == '\n' && fp_buf[i > 0 ? i - 1 : 0] != '\r')
					*str += "\r\n";
				else if (fp_buf[i] < 0) {
					char buf[3];
					buf[0] = fp_buf[i++];
					buf[1] = fp_buf[i];
					buf[2] = 0;
					*str += buf;
				}
				else
					*str += fp_buf[i];
			}
		}
		fclose(fp);
	}
}

char* alu_str[25] = {
	"ADD",
	"SUB",
	"ADD_C",
	"SUB_C",
	"EQUAL_C",
	"AND",
	"OR",
	"A_NOT",
	"XOR",
	"A_BH_LSH",
	"B_AL_RSH",
	"A_AH_RSH",
	"A_0_RSH",
	"A_0_LSH",
	"B_0_LSH",
	"MUL_L",
	"MUL_H",
	"DIV",
	"MOD",
	"A_ADD_1",
	"A_SUB_1",
	"A_ADD_1_C",
	"A_SUB_1_C",
	"OUTA",
	"OUTB"
};

extern void glow_global_init(void); //glow全局初始化
extern void one_c_file_redirect_addr(CString* redirect_addr_err); //单个C文件内局部重定向地址
extern void all_c_file_redirect_addr(CString* redirect_addr_err); //所有C文件全局重定向地址
extern ADDRDATA newaddrdata(char*); //查询或新建addrdata,并返回该指针
extern void insertaddr(ADDRDATA, unsigned long, unsigned long, unsigned long, long); //addrdata插入等待重定向内存地址
extern unsigned long sp0_init_romaddr; //栈页低8位初始化值所在ROM地址
extern unsigned long sp1_init_romaddr; //栈页高8位初始化值所在ROM地址
extern unsigned long romentry; //ROM入口跳转指令地址
extern unsigned long ramallocaddr; //RAM内存分配地址(全局初始化)
extern unsigned char romdata[]; //ROM为1MB
extern unsigned long rom_cp; //ROM使用计数(全局初始化)
extern unsigned long rom_cp_max; //ROM使用最大值
extern short maxlocreg; //最大寄存器使用数量
extern void MODIFY_A2A1A0(unsigned long, unsigned long); //修改A2A1A0
extern unsigned long cpu_alu_sp_init_size; //生成的初始化指令序列大小
extern void sp_redirect_addr(); //栈页指针重定向地址
extern void entry_redirect_to_main(CString*); //程序入口重定向至main函数

/*反汇编*/
void RomData_To_CString(unsigned char* romdata, CString* str, unsigned long skip) {
	for (unsigned long i = skip; i < rom_cp; i += 2) {
		CString buf;

		switch (romdata[i]) {
			/*立即数为源传送指令*/
		case 0x00: buf.Format(_T("%XH: 0x%02x%02x  RF = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
		case 0x01: buf.Format(_T("%XH: 0x%02x%02x  A = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
		case 0x02: buf.Format(_T("%XH: 0x%02x%02x  A0 = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
		case 0x03: buf.Format(_T("%XH: 0x%02x%02x  A1 = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
		case 0x04: buf.Format(_T("%XH: 0x%02x%02x  A2 = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
		case 0x05: buf.Format(_T("%XH: 0x%02x%02x  RA = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
		case 0x06: buf.Format(_T("%XH: 0x%02x%02x  B = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
		case 0x08: buf.Format(_T("%XH: 0x%02x%02x  RAM = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
		case 0x0a: buf.Format(_T("%XH: 0x%02x%02x  IO0 = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
		case 0x0b: buf.Format(_T("%XH: 0x%02x%02x  IO1 = 0x%02x;\r\n"), i >> 1, romdata[i], romdata[i + 1], romdata[i + 1]); break;
			/*ALU为源传送指令*/
		case 0x10: buf.Format(_T("%XH: 0x%02x%02x  RF = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x11: buf.Format(_T("%XH: 0x%02x%02x  A = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x12: buf.Format(_T("%XH: 0x%02x%02x  A0 = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x13: buf.Format(_T("%XH: 0x%02x%02x  A1 = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x14: buf.Format(_T("%XH: 0x%02x%02x  A2 = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x15: buf.Format(_T("%XH: 0x%02x%02x  RA = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x16: buf.Format(_T("%XH: 0x%02x%02x  B = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x18: buf.Format(_T("%XH: 0x%02x%02x  RAM = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x1a: buf.Format(_T("%XH: 0x%02x%02x  IO0 = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x1b: buf.Format(_T("%XH: 0x%02x%02x  IO1 = ALU[%s];\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
			/*RF为源传送指令*/
		case 0x21: buf.Format(_T("%XH: 0x%02x%02x  A = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x22: buf.Format(_T("%XH: 0x%02x%02x  A0 = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x23: buf.Format(_T("%XH: 0x%02x%02x  A1 = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x24: buf.Format(_T("%XH: 0x%02x%02x  A2 = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x25: buf.Format(_T("%XH: 0x%02x%02x  RA = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x26: buf.Format(_T("%XH: 0x%02x%02x  B = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x28: buf.Format(_T("%XH: 0x%02x%02x  RAM = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x29: buf.Format(_T("%XH: 0x%02x%02x  ALU[%s] = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x2a: buf.Format(_T("%XH: 0x%02x%02x  IO0 = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x2b: buf.Format(_T("%XH: 0x%02x%02x  IO1 = RF;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
			/*RAM为源传送指令*/
		case 0x30: buf.Format(_T("%XH: 0x%02x%02x  RF = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x31: buf.Format(_T("%XH: 0x%02x%02x  A = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x32: buf.Format(_T("%XH: 0x%02x%02x  A0 = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x33: buf.Format(_T("%XH: 0x%02x%02x  A1 = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x34: buf.Format(_T("%XH: 0x%02x%02x  A2 = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x35: buf.Format(_T("%XH: 0x%02x%02x  RA = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x36: buf.Format(_T("%XH: 0x%02x%02x  B = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x39: buf.Format(_T("%XH: 0x%02x%02x  ALU[%s] = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x3a: buf.Format(_T("%XH: 0x%02x%02x  IO0 = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x3b: buf.Format(_T("%XH: 0x%02x%02x  IO1 = RAM;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
			/*IO0为源传送指令*/
		case 0x40: buf.Format(_T("%XH: 0x%02x%02x  RF = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x41: buf.Format(_T("%XH: 0x%02x%02x  A = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x42: buf.Format(_T("%XH: 0x%02x%02x  A0 = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x43: buf.Format(_T("%XH: 0x%02x%02x  A1 = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x44: buf.Format(_T("%XH: 0x%02x%02x  A2 = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x45: buf.Format(_T("%XH: 0x%02x%02x  RA = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x46: buf.Format(_T("%XH: 0x%02x%02x  B = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x48: buf.Format(_T("%XH: 0x%02x%02x  RAM = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x49: buf.Format(_T("%XH: 0x%02x%02x  ALU[%s] = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x4a: buf.Format(_T("%XH: 0x%02x%02x  IO0 = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x4b: buf.Format(_T("%XH: 0x%02x%02x  IO1 = IO0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
			/*IO1为源传送指令*/
		case 0x50: buf.Format(_T("%XH: 0x%02x%02x  RF = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x51: buf.Format(_T("%XH: 0x%02x%02x  A = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x52: buf.Format(_T("%XH: 0x%02x%02x  A0 = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x53: buf.Format(_T("%XH: 0x%02x%02x  A1 = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x54: buf.Format(_T("%XH: 0x%02x%02x  A2 = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x55: buf.Format(_T("%XH: 0x%02x%02x  RA = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x56: buf.Format(_T("%XH: 0x%02x%02x  B = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x58: buf.Format(_T("%XH: 0x%02x%02x  RAM = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x59: buf.Format(_T("%XH: 0x%02x%02x  ALU[%s] = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
		case 0x5a: buf.Format(_T("%XH: 0x%02x%02x  IO0 = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
		case 0x5b: buf.Format(_T("%XH: 0x%02x%02x  IO1 = IO1;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
			/*无条件跳转*/
		case 0x07: buf.Format(_T("%XH: 0x%02x%02x  PC = A2A1A0;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
			/*判断ALU输出条件跳转*/
		case 0x17: buf.Format(_T("%XH: 0x%02x%02x  if(!(ALU[%s] & 0x01)) PC = A2A1A0;\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
			/*判断RF输出条件跳转*/
		case 0x27: buf.Format(_T("%XH: 0x%02x%02x  if(!(RF & 0x01)) PC = A2A1A0;\r\n"), i >> 1, romdata[i], romdata[i + 1], (CString)alu_str[romdata[i + 1]]); break;
			/*空操作*/
		case 0xff: buf.Format(_T("%XH: 0x%02x%02x  NOP;\r\n"), i >> 1, romdata[i], romdata[i + 1]); break;
			/*没有指令*/
		default: buf.Format(_T("%XH: 0x%02x%02x  NULL;\r\n"), i >> 1, romdata[i], romdata[i + 1]);
		}
		*str += buf;
	}
}

/*编译按钮*/
void CGlowCompilerDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	TCHAR* FilePathBuff = L"*.c";

	hFind = FindFirstFile(FilePathBuff, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		CString ErrorOut;
		CString RccOut;
		FILE* fp;
		unsigned long main_base;

		char* cpp_arg[] = {
			"",
			"",
			"CppOut"
		};
		char* rcc_arg[] = {
			"",
			"-target=glow",
			"CppOut",
			"RccOut",
			"-errout=RccError"
		};
		ErrorOut = "";
		RccOut = "";
		glow_global_init();
		do {
			USES_CONVERSION;
			cpp_arg[1] = T2A(FindFileData.cFileName);
			cpp_main(3, cpp_arg);
			rcc_main(5, rcc_arg);
			one_c_file_redirect_addr(&ErrorOut);
			File_To_CString("CppError", &ErrorOut);
			File_To_CString("RccError", &ErrorOut);
			GetDlgItem(IDC_EDIT3)->SetWindowTextW(ErrorOut);
			((CEdit*)GetDlgItem(IDC_EDIT3))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT3))->GetLineCount());
		} while (FindNextFile(hFind, &FindFileData) != 0);
		FindClose(hFind);
		GetDlgItem(IDC_EDIT3)->SetWindowTextW(ErrorOut);
		((CEdit*)GetDlgItem(IDC_EDIT3))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT3))->GetLineCount());
		all_c_file_redirect_addr(&ErrorOut);
		entry_redirect_to_main(&ErrorOut);
		sp_redirect_addr();
		ErrorOut.Format(ErrorOut + _T("寄存器堆占用: %d字节;\r\n"), maxlocreg);
		if (maxlocreg > 256)
			ErrorOut += _T("寄存器堆溢出错误,大于设定值256字节\r\n");
		ErrorOut.Format(ErrorOut + _T("RAM占用: %d字节;\r\n"), ramallocaddr);
		ErrorOut.Format(ErrorOut + _T("ROM占用: %d字节;\r\n"), rom_cp_max);
		if (rom_cp_max > rom_cp)
			ErrorOut.Format(ErrorOut + _T("ROM溢出错误,大于设定值%d字节\r\n"), rom_cp);
		GetDlgItem(IDC_EDIT3)->SetWindowTextW(ErrorOut);
		RomData_To_CString(romdata, &RccOut, 0);
		fp = fopen("rom.bin", "wb");
		fwrite(romdata, 1, rom_cp, fp);
		fclose(fp);
		fp = fopen("error.txt", "wb");
		fwrite(CT2CA(ErrorOut), 1, strlen(CT2CA(ErrorOut)), fp);
		fclose(fp);
		fp = fopen("asm.txt", "wb");
		fwrite(CT2CA(RccOut), 1, strlen(CT2CA(RccOut)), fp);
		fclose(fp);
	}
	else
		GetDlgItem(IDC_EDIT3)->SetWindowTextW(_T("没有找到C文件."));
	((CEdit*)GetDlgItem(IDC_EDIT3))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT3))->GetLineCount());
}

/*搜索串口*/
void CGlowCompilerDlg::FindComm() {
	LONG result = 0;
	HKEY key = NULL;
	TCHAR portname[250];
	TCHAR data[250];
	DWORD portnamelen = 0;
	DWORD datalen = 0;
	int index = 0;

	result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("HARDWARE\\DEVICEMAP\\SERIALCOMM"), 0, KEY_READ, &key);
	if (result) {
		AfxMessageBox(_T("无法获取串口，请确认是否安装并连接串口!"));
		return;
	}
	while (1) {
		portnamelen = 255;
		datalen = 255;
		result = RegEnumValue(key, index++, portname, &portnamelen, NULL, NULL, (LPBYTE)data, &datalen);
		if (result)
			break;
		((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(data);
	}
	RegCloseKey(key);
}

/*打开串口*/
int CGlowCompilerDlg::OpenComm(CString nCom, int nBaud, int nData, int nStop, int nCal) {
	COMMTIMEOUTS TimeOuts;
	DCB dcb;

	hCom = CreateFile(nCom, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH, NULL);
	if (hCom == INVALID_HANDLE_VALUE) {
		AfxMessageBox(_T("打开COM失败，串口不存在或已被占用!"));
		return 0;
	}
	SetCommMask(hCom, EV_TXEMPTY | EV_RXCHAR);
	SetupComm(hCom, 16, 16);
	TimeOuts.ReadIntervalTimeout = MAXDWORD;
	TimeOuts.ReadTotalTimeoutConstant = MAXDWORD;
	TimeOuts.ReadTotalTimeoutMultiplier = MAXDWORD;
	TimeOuts.WriteTotalTimeoutConstant = MAXDWORD;
	TimeOuts.WriteTotalTimeoutMultiplier = MAXDWORD;
	if (SetCommTimeouts(hCom, &TimeOuts) == false) {
		CloseHandle(hCom);
		return 0;
	}
	GetCommState(hCom, &dcb);
	dcb.BaudRate = nBaud; //波特率
	dcb.ByteSize = nData; //字节数
	dcb.StopBits = nStop; //停止位
	dcb.Parity = nCal; //校验位
	if (SetCommState(hCom, &dcb) == false) {
		CloseHandle(hCom);
		return 0;
	}
	return 1;
}

/*关闭串口*/
void CGlowCompilerDlg::CloseComm() {
	CloseHandle(hCom);
	hCom = NULL;
}

/*打开串口按钮*/
void CGlowCompilerDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CString cmp;

	GetDlgItem(IDC_BUTTON2)->GetWindowTextW(cmp);
	if (cmp == _T("打开串口")) {
		CString Baud_str;
		CString Comx = NULL;
		int Index;

		if ((Index = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel()) < 0) {
			AfxMessageBox(_T("请选择串口!"));
			return;
		}
		((CComboBox*)GetDlgItem(IDC_COMBO1))->GetLBText(Index, Comx);
		GetDlgItem(IDC_COMBO2)->GetWindowTextW(Baud_str);
		long Baud_v = _ttol(Baud_str);
		if (Baud_v == 0)
			AfxMessageBox(_T("串口波特率不能为0!"));
		if (OpenComm(Comx, Baud_v, 8, ONESTOPBIT, NOPARITY) == 0)
			return;
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("关闭串口"));
		GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	}
	else {
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("打开串口"));
		GetDlgItem(IDC_COMBO1)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
		CloseComm();
	}
}

/*发送按钮*/
void CGlowCompilerDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	CProgressCtrl* myProCtrl2 = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);

	myProCtrl2->SetRange(0, 1024);
	for (unsigned long i = 0; i < rom_cp; i += 16) {
		if ((PurgeComm(hCom, PURGE_TXCLEAR | PURGE_RXCLEAR) == false) | (WriteFile(hCom, &romdata[i], 16, NULL, NULL) == false)) {
			GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("打开串口"));
			CloseComm();
			return;
		}
		myProCtrl2->SetPos(i * 1024 / (rom_cp - 16));
	}
}

/*编译发送按钮*/
void CGlowCompilerDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	OnBnClickedButton1();
	OnBnClickedButton3();
}
