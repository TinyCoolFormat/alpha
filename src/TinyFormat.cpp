#include <iostream>
#include <string>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <vector>
#include <stdlib.h>
#include "astyle.h"
#include "astyle_main.h"
#include "CFBaseTidy.h"
#include "CFCppTidy.h"

using namespace std;

char * g_version="0.1";

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

std::string GetFileExtern(const char * pFileName)
{
    std::string strFileName(pFileName);
    size_t index = strFileName.rfind(".");
    std::string strResult = strFileName.substr(index+1,strFileName.length()-index);
    return strResult;
}

bool WalkDir(const char * dir,std::vector<std::string> & fileVec)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return false;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode))
        {

            if(strcmp(".",entry->d_name) == 0 ||
                    strcmp("..",entry->d_name) == 0)
            {
                continue;
            }
            std::string strFile = std::string(dir)+"/"+std::string(entry->d_name);
            WalkDir(strFile.c_str(),fileVec);
        }
        else
        {

            std::string strFile = std::string(dir)+"/"+std::string(entry->d_name);
            fileVec.push_back(strFile);
        }
    }
    chdir("..");
    closedir(dp);
    return true;
}


void PrintVersionInfo()
{
    cout<<"TinyFormat  0.01 (2016 04 13 21:00:00)"<<endl;
}
/*{
	cout<<"Create by  DennisMi"<<endl;
    cout<<"E-mail  2475027682@qq.com "<<endl<<endl;
    cout<<"I want to make this program a tiny tool to format your code."<<endl;
    cout<<"The current Code Type is C and C++,and I will add other type "<<endl;
    cout<<"such as Java,XML and so on.The base Code is from a format Tool"<<endl;
    cout<<"called CoolFormat.Thanks to the author .				 "<<endl;
}*/


bool  ReadStringFromFile(const char * chFileName,std::string & strFileText)
{
    FILE * pFile = fopen(chFileName,"r");
    if(NULL != pFile)
    {
        char chBuf[1024]= {0};
        while(fread(chBuf,sizeof(char),1023,pFile) > 0)
        {
            strFileText += std::string(chBuf);
            memset(chBuf,0,1024);
        }
        fclose(pFile);
        pFile=NULL;
        return true;
    }
    else
    {
        return false;
    }
}

bool WriteStringToFile(const std::string strFileText,const char * chFileName)
{
    FILE * pFile = fopen(chFileName,"w");
    if(NULL != pFile)
    {
        fwrite(strFileText.c_str(),sizeof(char),strFileText.length(),pFile);
        fclose(pFile);
        return true;
    }
    return false;
}

void PrintHelpInfo()
{
    cout<<"\t	-i	Input File or Input Folder 	"<<endl;
    cout<<"\t	-o 	Output File or Output Folder "<<endl;
    cout<<"\t	-h	show this Info	"<<endl;
    cout<<"\t	-v	show version info	"<<endl;
}

typedef enum code_type
{
    UNKNOWN_TYPE,
    CPP_TYPE,
} CODE_TYPE;

CODE_TYPE GetFileCodeType(const char * pChFileName)
{
    std::string strExtern = GetFileExtern(pChFileName);
    if(strExtern.compare("cpp") == 0 ||
            strExtern.compare("c")	== 0 ||
            strExtern.compare("cxx") == 0
      )
    {
        return CPP_TYPE;
    }
    else
    {
        return UNKNOWN_TYPE;
    }
}
class CInputOutputConfig
{
public:
    std::string m_strInput;
    std::string m_strOutput;
};

bool ParseInput(int argc,char * argv[],CInputOutputConfig & config)
{
    int opt = 0;
    while((opt = getopt(argc,argv,"i:o:h:v")) != -1)
    {
        switch(opt)
        {
		case 'i':
			{
            config.m_strInput = std::string(optarg);
            cout<<"Input File Or Folder "<<optarg<<endl;
			}break;
        case 'o':
        {
            config.m_strOutput = std::string(optarg);
            cout<<"Output File "<<optarg<<endl;
        }
        break;
        case 'h':
        {
            PrintHelpInfo();
        }
        break;
        case 'v':
        {
            PrintVersionInfo();
        }
        break;
        case '?':
        {
            return false;
        }
        break;
        }
    }
    return true;
}

bool IsPathAFolder(const char * pChPath)
{

    struct stat fileStatus;
    int nResult = stat(pChPath,&fileStatus);
    if(nResult == 0 && S_ISDIR(fileStatus.st_mode))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool FormatCode(const char * srcFile,const char * dstFile,int codeType = 0)
{
	
	CStyleChoice styleChoice;
	CTabChoice tabChoice;
	CBracketModifyChoice bracketChoice;
	CIndentChoice indentChoice;
	CPadChoice padChoice;
	CFormatChoice formatChoice;


    CCFCppTidy util;
    std::string strSrc="";
    if(ReadStringFromFile(srcFile,strSrc))
    {
        std::string strOut="";
        std::string strOpt=" --mode=c ";

		strOpt = strOpt + styleChoice.GetCurOption()+" ";
		strOpt = strOpt + tabChoice.GetCurOption()+" ";
		strOpt = strOpt +  bracketChoice.GetCurOption()+" ";
		strOpt = strOpt + indentChoice.GetCurOption()+" ";
		strOpt = strOpt + padChoice.GetCurOption()+" ";

        std::string strError="";
        util.TidyMain(strSrc.c_str(),strOpt.c_str(),strOut,strError);
        WriteStringToFile(strOut,dstFile);
    }
    return true;
}

int main(int argc,char* argv[])
{
    CInputOutputConfig config;
    if(ParseInput(argc,argv,config))
    {
        cout<<"Input " <<config.m_strInput<<endl;
        cout<<"Output "<<config.m_strOutput<<endl;
        bool bInputFolder = IsPathAFolder(config.m_strInput.c_str()) ;
        bool bOutputFolder =  IsPathAFolder(config.m_strOutput.c_str());
        if(bInputFolder && bOutputFolder)
        {
            std::vector<std::string> srcFileVec;
            WalkDir(config.m_strInput.c_str(),srcFileVec);
            for(int i = 0 ; i < srcFileVec.size() ; i++)
            {
                std::string srcFile=srcFileVec[i];
                std::string dstFile = srcFile+"Result.cpp";
                if(CPP_TYPE == GetFileCodeType(srcFile.c_str()) )
                {
                    FormatCode(srcFile.c_str(),dstFile.c_str());
                    cout<<"Format File "<<srcFile.c_str()<<endl;
                    rename(dstFile.c_str(),srcFile.c_str());
                }
            }
        }
        else if( !bInputFolder && !bOutputFolder)
        {
            FormatCode(config.m_strInput.c_str(),config.m_strOutput.c_str());
        }
        return 0;
    }
    else
    {
        cout<<"Param error "<<endl;
        return 0;
    }
}
