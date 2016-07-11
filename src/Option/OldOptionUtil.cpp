#include "tinyxml.h"
#include "Option.h"
#include <iostream>
using namespace std;



CBaseOption * optionArray[]=
{
	new CBracketModifyOption(),
	new CPadOption(),
	new CFormatOption(),
	new CModeOption(),
	new CFormatOption(),
	new CStyleOption(),
};

bool ParseOption(char * pConfigFile)
{
	cout<<"------------ParseOption-------------------"<<endl;
	TiXmlDocument doc;
	if(doc.LoadFile(pConfigFile))
	{
		TiXmlElement * pRoot = doc.RootElement();
		if(pRoot)
		{
			TiXmlElement * pChild = pRoot->FirstChildElement();
			while(NULL != pChild)
			{
				cout<<pChild->Value()<<":"<<pChild->GetText()<<endl;
				pChild=pChild->NextSiblingElement();
			}
		}
		cout<<"------------ParseOption-------------------"<<endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool SaveOption(char * pConfig)
{
	TiXmlElement * pRoot = new TiXmlElement("Config");

	int nCount = sizeof(optionArray)/sizeof(optionArray[0]);
	for(int i = 0 ; i < nCount ; i++)
	{
		TiXmlElement * pNewElem = new TiXmlElement(optionArray[i]->GetOptionName().c_str());
		TiXmlText * pText = new TiXmlText(optionArray[i]->GetCurOption().c_str());
		pNewElem->InsertEndChild(pText);
		pRoot->InsertEndChild(pNewElem);
	}

	TiXmlDocument doc;
	doc.InsertEndChild(pRoot);
	doc.SaveFile(pConfig);
	return true;
}
int main(int argc,char * argv[])
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
    
	char * pConfig="NewConfig.xml";
	ParseOption(pConfig);

	SaveOption("Save.xml");
	return 0;
}
