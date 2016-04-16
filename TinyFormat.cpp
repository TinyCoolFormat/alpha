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
    cout<<"Create by  DennisMi"<<endl;
    cout<<"E-mail  2475027682@qq.com "<<endl<<endl;
    cout<<"I want to make this program a tiny tool to format your code."<<endl;
    cout<<"The current Code Type is C and C++,and I will add other type "<<endl;
    cout<<"such as Java,XML and so on.The base Code is from a format Tool"<<endl;
    cout<<"called CoolFormat.Thanks to the author .				 "<<endl;
}


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
        }
        break;
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
    CCFCppTidy util;
    std::string strSrc="";
    if(ReadStringFromFile(srcFile,strSrc))
    {
        std::string strOut="";
        std::string strOpt=" --mode=c ";
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
