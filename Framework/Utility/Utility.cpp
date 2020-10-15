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

wstring Utility::GetExtension(wstring path)
{
    size_t index = path.find_last_of('.');

    return path.substr(index + 1, path.length());
}
