#include "Framework.h"

string Utility::ToString(wstring value)
{
    string temp;
    temp.assign(value.begin(), value.end());
    return temp;
}

wstring Utility::ToWString(string value)
{
    wstring temp;
    temp.assign(value.begin(), value.end());
    return temp;
}
