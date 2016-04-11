#include <iostream>
#include <string>
#include "astyle.h"
#include "astyle_main.h"
#include "CFBaseTidy.h"
#include "CFCppTidy.h"
using namespace std;

int main(int argc,char* argv[])
{
	CCFCppTidy util;
	std::string strSrc="int x=10;\n\
						int y=11;\n\
						if(x==y)\n\
							{\n\
						int k= x;\n\
							}";
	std::string strOut="";
	std::string strOpt="--mode=c";
	std::string strError="";
	util.TidyMain(strSrc.c_str(),strOpt.c_str(),strOut,strError);
	cout<<"TinyCoolFormatter  "<<endl;
	cout<<"Before "<<endl;
	cout<<strSrc.c_str()<<endl;
	cout<<endl<<"After"<<endl;
	cout<<strOut.c_str()<<endl;
	cout<<endl;
	return 0;
}
