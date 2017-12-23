#include "Field.h"

#include "Helper/StringHelper.h"

using namespace std;
using namespace DBEngine;
using namespace DBEngine::Helper;

Field::Field() : PK(false),
                 FK(false)
{

}

Field::~Field()
{

}

Field Field::vectorToField(std::vector<std::string> vect)
{
    Field field;

    field.setOrdinal(StringHelper::strToInt(vect[0]));
    field.setName(vect[1]);
    field.setType(FieldTypeHelper::stringToFieldType(vect[2]));
    field.setPK(vect[3] == "1");
    field.setFK(vect[4] == "1");
    field.setFKField(vect[5]);
    field.setFKTable(vect[6]);

    return field;
}

int Field::getOrdinal()
{
    return ordinal;
}

void Field::setOrdinal(int ordinal)
{
    this->ordinal = ordinal;
}

string Field::getName()
{
    return name;
}

void Field::setName(string name)
{
    this->name = name;
}

FieldType Field::getType()
{
    return type;
}

void Field::setType(FieldType type)
{
    this->type = type;
}

void Field::setPK(bool PK)
{
    this->PK = PK;
}

bool Field::isPK()
{
    return PK;
}

void Field::setFK(bool FK)
{
    this->FK = FK;
}

bool Field::isFK()
{
    return FK;
}

std::string Field::getFKTable()
{
    return FKTable;
}

void Field::setFKTable(std::string FKTable)
{
    this->FKTable = FKTable;
}

std::string Field::getFKField()
{
    return FKField;
}

void Field::setFKField(std::string FKField)
{
    this->FKField = FKField;
}
