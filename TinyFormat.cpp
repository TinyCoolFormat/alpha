#include <iostream>
#include <string>
#include <stdio.h>
#include "astyle.h"
#include "astyle_main.h"
#include "CFBaseTidy.h"
#include "CFCppTidy.h"
using namespace std;

void PrintVersionInfo()
{
	//cout<<"\t-------------------------------------------------------------"<<endl;
	cout<<"TinyFormat  0.01 (2016 04 13 21:00:00)"<<endl;
	cout<<"Create by  DennisMi"<<endl;
	cout<<"E-mail  2475027682@qq.com "<<endl<<endl;
	cout<<"I want to make this program a tiny tool to format your code."<<endl;
	cout<<"The current Code Type is C and C++,and I will add other type "<<endl;
	cout<<"such as Java,XML and so on.The base Code is from a format Tool"<<endl;
	cout<<"called CoolFormat.Thanks to the author .				 "<<endl;
	//cout<<"\t-------------------------------------------------------------"<<endl;
}


bool  ReadStringFromFile(const char * chFileName,std::string & strFileText)
{
	FILE * pFile = fopen(chFileName,"r");
	if(NULL != pFile)
	{
		char chBuf[1024]={0};
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


int main(int argc,char* argv[])
{
	PrintVersionInfo();
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
			WriteStringToFile(strOut,dstFile.c_str());
		}
	}
	return 0;
}
