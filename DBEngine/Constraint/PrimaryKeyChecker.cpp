#include "PrimaryKeyChecker.h"

#include <iostream>

using namespace std;
using namespace DBEngine;
using namespace DBEngine::Constraint;

PrimaryKeyChecker::PrimaryKeyChecker(Table* table) : table(table)
{

}

PrimaryKeyChecker::~PrimaryKeyChecker()
{

}

bool PrimaryKeyChecker::check(vector<string> record)
{
    bool success = false;

    if(table != NULL) {
        int ordinal = table->getPKField().getOrdinal();
        success = !PKExists(record[ordinal], ordinal);
    }

    return success;
}


bool PrimaryKeyChecker::PKExists(string PK, int ordinalPK)
{
    vector< vector<string> > data;
    bool exists = false;

    if(table != NULL) {
        data = table->getData();
        for(vector<string> record : data) {
            exists = record[ordinalPK] == PK;

            if(exists)
                break;
        }
    }

    return exists;
}
