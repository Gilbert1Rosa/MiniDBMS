#include "TableReader.h"

#include "../Helper/StringHelper.h"

using namespace std;
using namespace DBEngine;
using namespace DBEngine::FileEngine;
using namespace DBEngine::Helper;

TableReader::TableReader(string dblocation,
                         string database,
                         string tableName) : dblocation(dblocation),
                                             database(database),
                                             tableName(tableName)
{
    string route = dblocation + "\\" + database + "\\" + tableName;
    catalogFile.open((route + "_catalog.txt").c_str());
    dataFile.open((route + "_data.txt").c_str());
}

TableReader::~TableReader()
{
    if(catalogFile.is_open()) {
        catalogFile.close();
    }

    if(dataFile.is_open()) {
        dataFile.close();
    }
}

DBEngine::Table* TableReader::read()
{
    Table* tabla = nullptr;

    if(catalogFile.is_open() && dataFile.is_open()) {
        char tmp[1024];
        tabla = new Table();

        tabla->setName(tableName);

        while(catalogFile.good()) {
            Field field;

            catalogFile.getline(tmp, 1024, '\n');
            if(tmp[0] != '\0') {
                field = Field::vectorToField(StringHelper::split(string(tmp), '|'));
                tabla->addField(field);
            }
        }

        while(dataFile.good()) {
            vector<string> record;

            dataFile.getline(tmp, 1024, '\n');
            if(tmp[0] != '\0') {
                record = StringHelper::split(string(tmp), '|');
                tabla->addRecord(record);
            }
        }
    }

    return tabla;
}
