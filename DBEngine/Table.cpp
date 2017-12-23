#include "Table.h"

using namespace std;
using namespace DBEngine;

Table::Table()
{

}

Table::~Table()
{

}

string Table::getName()
{
    return name;
}

void Table::setName(string name)
{
    this->name = name;
}

vector<Field> Table::getFields()
{
    return fields;
}

void Table::addField(Field field)
{
    bool ordinalExists = false;

    for(Field currentField : fields) {
        ordinalExists = field.getOrdinal() == currentField.getOrdinal();
        if(ordinalExists) break;
    }

    if(!ordinalExists) {
        fields.push_back(field);
    }
}

void Table::deleteField(Field field)
{
    bool ordinalExists = false;
    int i = 0;

    for(Field currentField : fields) {
        ordinalExists = field.getOrdinal() == currentField.getOrdinal();
        if(ordinalExists) break;

        i++;
    }

    if(ordinalExists) {
        fields.erase(fields.begin()+i);
    }
}


void Table::addRecord(std::vector<std::string> entry)
{
    data.push_back(entry);
}


void Table::deleteRecord(string PK)
{
    int ordinalPK = getPKField().getOrdinal();
    bool found = false;
    int i = 0;

    for(vector<string> record : data) {
        found = record[ordinalPK] == PK;

        if(found) break;

        i++;
    }

    if(found) {
       data.erase(data.begin()+i);
    }

}

vector< vector<string> > Table::getData()
{
    return data;
}

Field Table::getPKField()
{
    vector<Field> fields = getFields();
    Field PKField;

    for(Field field : fields) {
       if(field.isPK()) {
           PKField = field;
       }
    }

    return PKField;
}

vector<Field> Table::getFKFields()
{
    vector<Field> FKs;

    for(Field field : getFields()) {
        if(field.isFK()) {
            FKs.push_back(field);
        }
    }

    return FKs;
}

void Table::sortEntries()
{

}
