#include "ForeignKeyChecker.h"

using namespace std;
using namespace DBEngine;
using namespace DBEngine::Constraint;


ForeignKeyChecker::ForeignKeyChecker(Table* table) : table(table)
{

}

ForeignKeyChecker::~ForeignKeyChecker()
{

}

bool ForeignKeyChecker::check(vector<string> record, Table* parent, int childField)
{
    vector< vector<string> > records = parent->getData();
    int ordinal = parent->getPKField().getOrdinal();
    bool success = false;

    for(vector<string> currentRecord : records) {
        success = currentRecord[ordinal] == record[childField];

        if(success) break;
    }

    return success;
}
