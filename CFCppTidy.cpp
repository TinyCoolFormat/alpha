#include "CFCppTidy.h"
#include "astyle.h"
#include "astyle_main.h"

CCFCppTidy::CCFCppTidy(void)
{

}

CCFCppTidy::~CCFCppTidy(void)
{

}

static std::string s_strErr;

void ASErrorHandler(int /*errorNumber*/, const char* errorMessage)
{
    s_strErr.append(errorMessage);
}

char* ASMemoryAlloc(unsigned long memoryNeeded)
{
    char* buffer = new(std::nothrow) char[memoryNeeded];
    return buffer;
}

bool CCFCppTidy::TidyMain(const char* pSourceIn, const char *pOptions, std::string &strOut, std::string &strErr)
{
    s_strErr.clear();

    char* textOut = AStyleMain(pSourceIn, pOptions,
                               ASErrorHandler,
                               ASMemoryAlloc);

    strErr = s_strErr;
    if (textOut == NULL)
    {
        return false;
    }

    strOut = textOut;
    delete[] textOut;
    return true;
}

void CCFCppTidy::InitTidyDefault()
{
}

void CCFCppTidy::SetTidyProp(const std::string& /*strParam*/, int /*nNumValue*/, const std::string& /*strNumValue*/, const std::string& /*strTextValue*/)
{
}
