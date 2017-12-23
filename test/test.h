#ifndef __TEST_H
#define __TEST_H

#include <iostream>

#include <sstream>
#include <vector>

#include "../DBEngine/DBEngine.h"
#include "../DBEngine/Table.h"
#include "../DBEngine/FileEngine/TableWriter.h"
#include "../DBEngine/FileEngine/TableReader.h"

#include "../DBEngine/Constraint/PrimaryKeyChecker.h"
#include "../DBEngine/Constraint/ForeignKeyChecker.h"
#include "../DBEngine/Helper/DateHelper.h"

#include "../DBEngine/Entity/Entity.h"

#include "Persona.h"
#include "Factura.h"

#include <ctime>

DBEngine::Table getTestTable();
DBEngine::Table getTestTable1();
void testTableWriter();
void testTableReader();
void testAddNewRecord();
void testValidateTableMetadata();
void testCheckPrimaryKey();
void testDeleteRecord();
void testCheckFK();
void testCheckEngineBDPK();
void testCheckEngineBDFK();

void testCreateTable();


#endif // __TEST_H
