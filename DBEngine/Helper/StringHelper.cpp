#include "StringHelper.h"

#include <sstream>
#include <string>

#include <cstdlib>

using namespace std;
using namespace DBEngine::Helper;

vector<string> StringHelper::split(string str, char separator)
{
    vector<string> vect;
    stringstream stream;
    char tmp[256];

    stream << str;

    while(stream.good()) {
        stream.getline(tmp, 256, separator);
        vect.push_back(string(tmp));
    }

    return vect;
}

int StringHelper::strToInt(string str)
{
    char* cStr = (char*) str.c_str();

    return atoi(cStr);
}

float StringHelper::strToFloat(string str)
{
    char* cStr = (char*) str.c_str();

    return atof(cStr);
}
