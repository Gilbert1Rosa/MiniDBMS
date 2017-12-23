#ifndef __FIELD_TYPE_H
#define __FIELD_TYPE_H

#include <string>

namespace DBEngine
{
    enum FieldType
    {
        INTEGER = 1,
        FLOAT = 2,
        STRING = 3,
        DATE  = 4
    };

    class FieldTypeHelper
    {
    public:
        static std::string fieldTypeToString(FieldType type);
        static FieldType stringToFieldType(std::string str);

    };
}


#endif // __FIELD_TYPE_H
