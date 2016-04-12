#include <iostream>
#include <string>
#include <stdio.h>
#include "astyle.h"
#include "astyle_main.h"
#include "CFBaseTidy.h"
#include "CFCppTidy.h"
using namespace std;


bool  ReadStringFromFile(const char * chFileName,std::string & strFileText)
{
	FILE * pFile = fopen(chFileName,"r");
	if(NULL != pFile)
	{
		char chBuf[1024]={0};
		while(fread(chBuf,sizeof(char),1024,pFile) > 0)
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


int main(int argc,char* argv[])
{
	if(argc < 2)
	{
		cout<<"Please input the file you want to format after the command "<<endl;
		cout<<"Eg: TinyFormat Main.cpp"<<endl;
		return 0;
	}
	else
	{
		std::string srcFile(argv[1]);
		std::string dstFile;
		if(argc == 3)
		{
			dstFile = std::string(argv[2]);
		}
		CCFCppTidy util;	
		std::string strSrc="";
		if(ReadStringFromFile(srcFile.c_str(),strSrc))
		{
	
			std::string strOut="";
			std::string strOpt=" --mode=c ";
			std::string strError="";
			util.TidyMain(strSrc.c_str(),strOpt.c_str(),strOut,strError);
			cout<<"TinyCoolFormatter  "<<endl;
			cout<<"Before "<<endl;
//			cout<<strSrc.c_str()<<endl;
			cout<<endl<<"After"<<endl;
//	cout<<strOut.c_str()<<endl;
			cout<<endl;
			WriteStringToFile(strOut,dstFile.c_str());
		}
	}
	return 0;
}
