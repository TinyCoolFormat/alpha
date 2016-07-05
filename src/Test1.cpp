#include <iostream>

using namespace std;

char * g_version="0.1";

class CStyleChoice
{
private:
    vector<string> m_styleVec;
public:
    void InitStyle()
    {
        m_styleVec.push_back("--style=allman");
        m_styleVec.push_back("--style=lisp");
    }
    string GetCurOption()
    {
        return m_styleVec[0];
    }
};

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

namespace Test
{
class MyTest
{
public:
private:
protected:
};

}
