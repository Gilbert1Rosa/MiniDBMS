#include "TableWriter.h"

#include "../FieldType.h"

#include <vector>
#include <sstream>

using namespace std;
using namespace DBEngine;
using namespace DBEngine::FileEngine;

TableWriter::TableWriter(string dblocation,
                         string database,
                         Table* table) : database(database),
                                         dblocation(dblocation),
                                         table(table)
{
    string tableName = this->table->getName();
    string route = dblocation + "\\" + database + "\\" + tableName;
    catalogFile.open((route + "_catalog.txt").c_str(), ofstream::trunc);
    dataFile.open((route + "_data.txt").c_str(), ofstream::trunc);
}

TableWriter::~TableWriter()
{
    if(catalogFile.is_open()) {
        catalogFile.close();
    }

    if(dataFile.is_open()) {
        dataFile.close();
    }
}

void TableWriter::write()
{
    vector<Field> fields = table->getFields();
    vector< vector<string> > data = table->getData();

    for(Field field : fields) {
        stringstream line;

        line << field.getOrdinal()
             << "|" << field.getName()
             << "|" << FieldTypeHelper::fieldTypeToString(field.getType())
             << "|" << (field.isPK()? "1":"0")
             << "|" << (field.isFK()? "1":"0")
             << "|" << field.getFKField()
             << "|" << field.getFKTable();

        catalogFile << line.str() << endl;
    }

    for(vector<string> reg : data) {
        string regStr = "";
        for(string value : reg) {
             regStr += value + "|";
        }

        regStr = regStr.substr(0, regStr.size() - 1);
        dataFile << regStr << endl;
    }
}
