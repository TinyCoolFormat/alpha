#include "tinyxml.h"
#include "Option.h"
#include <iostream>
#include <time.h>
using namespace std;

string GetCurTime()
{
	char chTime[128]={0};
	struct tm * tm_ptr;
	time_t curTime;
	time(&curTime);
	tm_ptr = localtime(&curTime);
	sprintf(chTime,"%d-%d-%d %d:%d:%d",1900+tm_ptr->tm_year,
									   tm_ptr->tm_mon+1,
									   tm_ptr->tm_mday,
									   tm_ptr->tm_hour,
									   tm_ptr->tm_min,
									   tm_ptr->tm_sec);
	string strResult(chTime);
	return strResult;
}

CBaseOption * optionArray[]=
{
	new CBracketModifyOption(),
	new CPadOption(),
	new CFormatOption(),
	new CModeOption(),
	new CFormatOption(),
	new CStyleOption(),
};


bool SaveOption(char * pConfig)
{
	TiXmlDocument doc;
	TiXmlElement * pRoot = new TiXmlElement("Config");
	pRoot->SetAttribute("Date",GetCurTime().c_str());

	int nCount = sizeof(optionArray)/sizeof(optionArray[0]);
	for(int i = 0 ; i < nCount ; i++)
	{
		TiXmlElement * pNewElem = new TiXmlElement(optionArray[i]->GetOptionName().c_str());
		TiXmlText * pText = new TiXmlText(optionArray[i]->GetCurOption().c_str());
		pNewElem->InsertEndChild(*pText);
		pRoot->InsertEndChild(*pNewElem);
	}

	doc.InsertEndChild(*pRoot);
	doc.SaveFile(pConfig);
	return true;
}

string ParseOption(char * pConfigFile)
{
	TiXmlDocument doc;
	if(doc.LoadFile(pConfigFile))
	{
		TiXmlElement * pRoot = doc.RootElement();
		if(pRoot)
		{
			TiXmlElement * pChild = pRoot->FirstChildElement();
			while(NULL != pChild)
			{
				
				int nCount = sizeof(optionArray)/sizeof(optionArray[0]);
				for(int i = 0 ; i < nCount ; i++)
				{
					if(optionArray[i]->GetOptionName().compare(pChild->Value())==0)
					{
						optionArray[i]->SetCurOption(pChild->GetText());
						break;
					}
				}
				pChild=pChild->NextSiblingElement();
			}
		}
		string strResult="";
		int nCount = sizeof(optionArray)/sizeof(optionArray[0]);
		for(int i = 0 ; i < nCount ; i++)
		{
			strResult = strResult +" " + optionArray[i]->GetCurOption();
		}
		return strResult;
	}
	else
	{
		return "";
	}
}


bool SaveUserChoice(char * pConfig)
{
	TiXmlDocument doc;
	TiXmlElement * pRoot = new TiXmlElement("Config");

	int nCount = sizeof(optionArray)/sizeof(optionArray[0]);
	for(int i = 0 ; i < nCount ; i++)
	{
		optionArray[i]->ChooseOption();
		TiXmlElement * pNewElem = new TiXmlElement(optionArray[i]->GetOptionName().c_str());
		TiXmlText * pText = new TiXmlText(optionArray[i]->GetCurOption().c_str());
		pNewElem->InsertEndChild(*pText);
		pRoot->InsertEndChild(*pNewElem);
	}

	doc.InsertEndChild(*pRoot);
	doc.SaveFile(pConfig);
	return true;
}

void TinyXmlTest()
{

	TiXmlDocument doc;
	doc.LoadFile("config.xml");
	doc.Print();


	TiXmlElement * pRoot = doc.RootElement();
	TiXmlElement * pTabElem = new TiXmlElement("TabChoice");
	pTabElem->SetValue("MyTab");
	pTabElem->LinkEndChild(new TiXmlText("MyTabValue"));
	pRoot->LinkEndChild(pTabElem);
	doc.SaveFile("NewConfig.xml");
}
int main(int argc,char * argv[])
{

	char * pConfig="NewConfig.xml";
	SaveOption("Save.xml");
	ParseOption("Save.xml");
	SaveUserChoice("UserChoice");
	return 0;
}
