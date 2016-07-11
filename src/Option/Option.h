#ifndef _OPTION_H_
#define _OPTION_H_
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class CBaseOption
{
	protected:
		vector<string> m_OptionVec;
		string m_strCurOption;
	public:
		virtual void InitOption() = 0;
		void PrintAllOption()
		{
			int nCount = m_OptionVec.size();
			for(int i = 0 ; i < nCount; ++i)
			{
				cout<<i<<" --- "<<m_OptionVec[i]<<endl;
			}
		}
		bool SetCurOption(string strOption)
		{
			vector<string>::iterator it = std::find(m_OptionVec.begin(),m_OptionVec.end(),strOption);
			if( it != m_OptionVec.end())
			{
				m_strCurOption = strOption;
				return true;
			}
			else
			{
				return false;
			}
		}
		virtual string GetOptionName()=0;
		string GetCurOption()
		{
			return m_strCurOption;
		}

		void ChooseOption()
		{
			PrintAllOption();

			int nCount = m_OptionVec.size();
			int nUserChoice = 0;
			do
			{
				cout<<"Please Choice your Option : ";
				cin>>nUserChoice;
			}while( (nUserChoice< 0) || (nUserChoice > (nCount-1)));
			SetCurOption(m_OptionVec[nUserChoice]);

		}
};



class CStyleOption:public CBaseOption
{
	public:
		CStyleOption()
		{
			InitOption();
		}
		void InitOption()
		{
			m_OptionVec.push_back("--style=allman");
			m_OptionVec.push_back("--style=java");
			m_OptionVec.push_back("--style=kr");
			m_OptionVec.push_back("--style=whitesmith");
			m_OptionVec.push_back("--style=stroustrup");
			m_OptionVec.push_back("--style=vtk");
			m_OptionVec.push_back("--style=banner");
			m_OptionVec.push_back("--style=gun");
			m_OptionVec.push_back("--style=linux");
			m_OptionVec.push_back("--style=1tbs");
			m_OptionVec.push_back("--style=horstmann");
			m_OptionVec.push_back("--style=google");
			m_OptionVec.push_back("--style=pico");
			m_OptionVec.push_back("--style=lisp");	

			m_strCurOption = m_OptionVec[0];
		}

		string GetOptionName()
		{
			return "CStyleOption";
		}

};


class CTabOption:public CBaseOption
{
	public:
		CTabOption()
		{
			InitOption();
		}
		void InitOption()
		{
			m_OptionVec.push_back("--indent=spaces=#");
			m_OptionVec.push_back("--indent=tab");
			m_OptionVec.push_back("--indent=force-tab=#");
			m_OptionVec.push_back("--indent=force-tab-x=#");

			m_strCurOption = m_OptionVec[1];
		}

		string GetOptionName()
		{
			return "CTabOption";
		}

};


class CBracketModifyOption:public CBaseOption
{

public:
		CBracketModifyOption()
		{
			InitOption();
		}
		void InitOption()
		{
			m_OptionVec.push_back("--attach-namespaces");
			m_OptionVec.push_back("--attach-classes");
			m_OptionVec.push_back("--attach-inlines");
			m_OptionVec.push_back("--attach-extern-c");

			m_strCurOption = m_OptionVec[0];
		}


		string GetOptionName()
		{
			return "CBracketModifyOption";
		}

};


class CIndentOption:public CBaseOption
{
	public:
		CIndentOption()
		{
			InitOption();
		}
		void InitOption()
		{
			m_OptionVec.push_back("--indent-classes");
			m_OptionVec.push_back("--indent-modifiers");
			m_OptionVec.push_back("--indent-switches");
			m_OptionVec.push_back("--indent-cases");

			m_OptionVec.push_back("--indent-namespaces");
			m_OptionVec.push_back("--indent-labels");
			m_OptionVec.push_back("--indent-preproc-block");
			m_OptionVec.push_back("--indent-preproc-cond");
			m_OptionVec.push_back("--indent-preproc-define");
			m_OptionVec.push_back("--indent-col1-comments");
			m_OptionVec.push_back("--min-conditional-indent=#");
			m_OptionVec.push_back("--max-instatement-indent=#");
		}


		string GetOptionName()
		{
			return "CIndentOption";
		}

};


class CPadOption:public CBaseOption
{
	public:
		CPadOption()
		{
			InitOption();
		}
		void InitOption()
		{
			m_OptionVec.push_back("--break-blocks");
			m_OptionVec.push_back("--break-blocks=all");
			m_OptionVec.push_back("--pad-oper");
			m_OptionVec.push_back("--pad-paren");
			m_OptionVec.push_back("--pad-paren-out");
			m_OptionVec.push_back("--pad-first-paren-out");
			m_OptionVec.push_back("--pad-paren-in");
			m_OptionVec.push_back("--pad-header");
			m_OptionVec.push_back("--unpad-paren");
			m_OptionVec.push_back("--delete-emtpy-lines");
			m_OptionVec.push_back("--file-empty-lines");
			m_OptionVec.push_back("--align-pointer=type");
			m_OptionVec.push_back("--align-pointer=middle");
			m_OptionVec.push_back("--align-pointer=name");

			m_OptionVec.push_back("--align-reference=none");
			m_OptionVec.push_back("--align-reference=type");
			m_OptionVec.push_back("--align-reference=middle");
			m_OptionVec.push_back("--align-reference=name");

			m_strCurOption = m_OptionVec[0];
		}


		string GetOptionName()
		{
			return "CPadOption";
		}


};


class CFormatOption:public CBaseOption
{
	public:

		CFormatOption()
		{
			InitOption();
		}
		void InitOption()
		{
			m_OptionVec.push_back("--break-closing-brackets");
			m_OptionVec.push_back("--break-elseifs");
			m_OptionVec.push_back("--add-brackets");
			m_OptionVec.push_back("--add-one-line-brackets");

			m_OptionVec.push_back("--remove-brackets");
			m_OptionVec.push_back("--keep-one-line-blocks");
			m_OptionVec.push_back("--keep-one-line-statements");

			m_OptionVec.push_back("--convert-tabs");
			m_OptionVec.push_back("--close-templates");
			m_OptionVec.push_back("--remove-comment-prefix");

			m_OptionVec.push_back("--max-code-length=#");
			m_OptionVec.push_back("--break-after-logical");
			m_strCurOption = m_OptionVec[0];
		}

		string GetOptionName()
		{
			return "CFormatOption";
		}

};


class CModeOption:public CBaseOption
{
	public:
		CModeOption()
		{
			InitOption();
		}
		void InitOption()
		{

			m_OptionVec.push_back("--mode=c");
			m_OptionVec.push_back("--mode=java");
			m_OptionVec.push_back("--mode=cs");
			
			m_strCurOption = m_OptionVec[0];

		}

		string GetOptionName()
		{
			return "CModeOption";
		}

};
#endif
