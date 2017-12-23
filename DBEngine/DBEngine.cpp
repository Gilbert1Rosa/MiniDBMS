#include "DBEngine.h"

#include "FileEngine/TableReader.h"
#include "FileEngine/TableWriter.h"

#include "Constraint/PrimaryKeyChecker.h"
#include "Constraint/ForeignKeyChecker.h"


using namespace std;
using namespace DBEngine;
using namespace DBEngine::Constraint;
using namespace DBEngine::Entity;
using namespace DBEngine::FileEngine;

EngineBD::EngineBD(string dblocation,
                   string dbname,
                   vector<string> tables) : dblocation(dblocation), dbname(dbname)
{
    for(string table : tables) {
        TableReader reader(this->dblocation, this->dbname, table);
        Table* tbl = reader.read();
        if(tbl != NULL) {
            tablecatalog.push_back(tbl);
        }
    }
}

EngineBD::~EngineBD()
{
    for(Table* table : tablecatalog) {
         if(table != NULL)
             delete table;
    }
}

void EngineBD::createTable(string tablename, vector<Field> fields)
{
    Table* newtable = new Table();
    newtable->setName(tablename);

    TableWriter writer(dblocation, dbname, newtable);

    for(Field field : fields) {
        newtable->addField(field);
    }

    tablecatalog.push_back(newtable);

    writer.write();
}

vector< map<string, string> > EngineBD::selectAll(string table)
{
    Table* tbl = findTable(table);
    vector< map<string, string> > result;

    if(tbl != NULL)
    {
    vector< vector<string> > data = tbl->getData();
    vector<Field> fields = tbl->getFields();

    for(vector<string> record : data) {
         map<string, string> recordMap;
         int i = 0;

         for(string value : record) {
             Field field = EngineBD::findFieldByOrdinal(fields, i);
             recordMap[field.getName()] = value;
             i++;
         }

         result.push_back(recordMap);
    }
    }

    return result;
}

map<string, string> EngineBD::selectByPK(string table, string PK)
{
    Table* tbl = findTable(table);
    map<string, string> result;

    if(tbl != NULL)
    {
    vector< map<string, string> > records = selectAll(table);
    Field PKField = tbl->getPKField();


    for(map<string, string> record : records) {
        if(record[PKField.getName()] == PK) {
            result = record;
            break;
        }
    }
    }

    return result;
}

void EngineBD::insert(string table, Entity::Entity* entity)
{
    Table* tbl = findTable(table);
    PrimaryKeyChecker PKChecker(tbl);
    ForeignKeyChecker FKChecker(tbl);
    vector<Field> FKFields = tbl->getFKFields();
    bool constraintViolation = false;
    string messageConstraint = "";

    TableWriter writer(dblocation, dbname, tbl);
    vector<Field> fields = tbl->getFields();
    map<string, string> record = entity->getValues();
    vector<string> recordVect;

    recordVect.resize(tbl->getFields().size());

    for(map<string, string>::iterator it=record.begin(); it!=record.end(); ++it) {
         Field field = EngineBD::findFieldByName(fields, it->first);
         recordVect[field.getOrdinal()] = it->second;
    }

    if(!PKChecker.check(recordVect)) {
        constraintViolation = true;
        messageConstraint = "PK Constraint violation";
    }

    for(Field FKField : FKFields) {
        Table* parent = findTable(FKField.getFKTable());
        if(!FKChecker.check(recordVect, parent, FKField.getOrdinal())) {
            constraintViolation = true;
            messageConstraint = "FK Constraint violation";
            break;
        }
    }

    if(!constraintViolation) {
       tbl->addRecord(recordVect);
       writer.write();
    } else {
       writer.write();
       throw runtime_error(messageConstraint.c_str());
    }
}


Table* EngineBD::findTable(string name)
{
    Table* table = NULL;

    for(Table* current : tablecatalog) {
        if(current->getName() == name) {
            table = current;
        }
    }

    return table;
}

Field EngineBD::findFieldByOrdinal(vector<Field> fields, int ordinal)
{
    Field result;

    for(Field current : fields) {
        if(current.getOrdinal() == ordinal) {
            result = current;
            break;
        }
    }

    return result;
}

Field EngineBD::findFieldByName(vector<Field> fields, string name)
{
    Field result;

    for(Field current : fields) {
        if(current.getName() == name) {
            result = current;
            break;
        }
    }

    return result;
}
