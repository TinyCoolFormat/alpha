#ifndef _OPTION_H_
#define _OPTION_H_
#include <vector>
#include <string>
using namespace std;

class CStyleChoice
{
	private:
		vector<string> m_styleVec;
	public:
		CStyleChoice()
		{
			InitStyle();
		}
		void InitStyle()
		{
			m_styleVec.push_back("--style=allman");
			m_styleVec.push_back("--style=java");
			m_styleVec.push_back("--style=kr");
			m_styleVec.push_back("--style=whitesmith");
			m_styleVec.push_back("--style=stroustrup");
			m_styleVec.push_back("--style=vtk");
			m_styleVec.push_back("--style=banner");
			m_styleVec.push_back("--style=gun");
			m_styleVec.push_back("--style=linux");
			m_styleVec.push_back("--style=1tbs");
			m_styleVec.push_back("--style=horstmann");
			m_styleVec.push_back("--style=google");
			m_styleVec.push_back("--style=pico");
			m_styleVec.push_back("--style=lisp");	
		}
		string GetCurOption()
		{
			return m_styleVec[0];
		}
};


class CTabChoice
{
	private:
		vector<string> m_tabVec;
	public:
		CTabChoice()
		{
			Init();
		}
		void Init()
		{
			m_tabVec.push_back("--indent=spaces=#");
			m_tabVec.push_back("--indent=tab");
			m_tabVec.push_back("--indent=force-tab=#");
			m_tabVec.push_back("--indent=force-tab-x=#");
		}


		string GetCurOption()
		{
			return m_tabVec[0];
		}
};


class CBracketModifyChoice
{
	private:
		vector<string> m_BracketVec;


public:
		CBracketModifyChoice()
		{
			Init();
		}
		void Init()
		{
			m_BracketVec.push_back("--attach-namespaces");
			m_BracketVec.push_back("--attach-classes");
			m_BracketVec.push_back("--attach-inlines");
			m_BracketVec.push_back("--attach-extern-c");
		}

		string GetCurOption()
		{
			return m_BracketVec[0];
		}
};


class CIndentChoice
{
	private:
		vector<string> m_IndentVec;
	public:
		CIndentChoice()
		{
			Init();
		}
		void Init()
		{
			m_IndentVec.push_back("--indent-classes");
			m_IndentVec.push_back("--indent-modifiers");
			m_IndentVec.push_back("--indent-switches");
			m_IndentVec.push_back("--indent-cases");

			m_IndentVec.push_back("--indent-namespaces");
			m_IndentVec.push_back("--indent-labels");
			m_IndentVec.push_back("--indent-preproc-block");
			m_IndentVec.push_back("--indent-preproc-cond");
			m_IndentVec.push_back("--indent-preproc-define");
			m_IndentVec.push_back("--indent-col1-comments");
			m_IndentVec.push_back("--min-conditional-indent=#");
			m_IndentVec.push_back("--max-instatement-indent=#");
		}

		string GetCurOption()
		{
			return m_IndentVec[0];
		}
};


class CPadChoice
{
	private:
		vector<string> m_PadVec;
	public:
		CPadChoice()
		{
			Init();
		}
		void Init()
		{
			m_PadVec.push_back("--break-blocks");
			m_PadVec.push_back("--break-blocks=all");
			m_PadVec.push_back("--pad-oper");
			m_PadVec.push_back("--pad-paren");
			m_PadVec.push_back("--pad-paren-out");
			m_PadVec.push_back("--pad-first-paren-out");
			m_PadVec.push_back("--pad-paren-in");
			m_PadVec.push_back("--pad-header");
			m_PadVec.push_back("--unpad-paren");
			m_PadVec.push_back("--delete-emtpy-lines");
			m_PadVec.push_back("--file-empty-lines");
			m_PadVec.push_back("--align-pointer=type");
			m_PadVec.push_back("--align-pointer=middle");
			m_PadVec.push_back("--align-pointer=name");

			m_PadVec.push_back("--align-reference=none");
			m_PadVec.push_back("--align-reference=type");
			m_PadVec.push_back("--align-reference=middle");
			m_PadVec.push_back("--align-reference=name");

		}

		string GetCurOption()
		{
			return m_PadVec[0];
		}
};


class CFormatChoice
{
	private:
		vector<string> m_FormatVec;
	public:

		CFormatChoice()
		{
			Init();
		}
		void Init()
		{
			m_FormatVec.push_back("--break-closing-brackets");
			m_FormatVec.push_back("--break-elseifs");
			m_FormatVec.push_back("--add-brackets");
			m_FormatVec.push_back("--add-one-line-brackets");

			m_FormatVec.push_back("--remove-brackets");
			m_FormatVec.push_back("--keep-one-line-blocks");
			m_FormatVec.push_back("--keep-one-line-statements");

			m_FormatVec.push_back("--convert-tabs");
			m_FormatVec.push_back("--close-templates");
			m_FormatVec.push_back("--remove-comment-prefix");

			m_FormatVec.push_back("--max-code-length=#");
			m_FormatVec.push_back("--break-after-logical");
		}

		string GetCurOption()
		{
			return m_FormatVec[0];
		}
};


class CModeChoice
{
	private:
		vector<string> m_modeVec;
	public:

		CModeChoice()
		{
			Init();
		}
		void Init()
		{

			m_modeVec.push_back("--mode=c");
			m_modeVec.push_back("--mode=java");
			m_modeVec.push_back("--mode=cs");

		}

		string GetCurOption()
		{
			return m_modeVec[0];
		}
};
#endif
