#include "DateHelper.h"

#include "StringHelper.h"

#include <iostream>

using namespace std;
using namespace DBEngine::Helper;

time_t DateHelper::getDateFromString(string str)
{
    vector<string> vect = StringHelper::split(str, '-');
    tm date = {0};

    date.tm_year = StringHelper::strToInt(vect[2]) - 1900;
    date.tm_mon = StringHelper::strToInt(vect[1]) - 1;
    date.tm_mday = StringHelper::strToInt(vect[0]);

    return mktime(&date);
}

string DateHelper::getStringFromDate(time_t date)
{
    char ptr[50];
    time_t local;
    tm finalDate;

    strftime(ptr, 50, "%d-%m-%Y", gmtime(&date));

    return string(ptr);
}
