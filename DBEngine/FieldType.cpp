#include "FieldType.h"

using namespace std;
using namespace DBEngine;

string FieldTypeHelper::fieldTypeToString(FieldType type)
{
    string str = "";

    switch(type) {
        case INTEGER:
            str = "0";
            break;
        case FLOAT:
            str = "1";
            break;
        case STRING:
            str = "2";
            break;
        case DATE:
            str = "3";
            break;
    }

    return str;
}

FieldType FieldTypeHelper::stringToFieldType(string str)
{
    FieldType type = STRING;

    if(str == "0") {
        type = INTEGER;
    } else if(str == "1") {
        type = FLOAT;
    } else if(str == "2") {
        type = STRING;
    } else if(str == "3") {
        type = DATE;
    }

    return type;
}
