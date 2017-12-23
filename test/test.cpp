#include "test.h"


using namespace std;
using namespace DBEngine;
using namespace DBEngine::Constraint;
using namespace DBEngine::Entity;
using namespace DBEngine::FileEngine;
using namespace DBEngine::Helper;


Table getTestTable()
{
    Table testTable;
    Field f1, f2, f3, f4;
    vector<string> r1, r2, r3;

    testTable.setName("Persona");

    f1.setOrdinal(0);
    f1.setName("id");
    f1.setType(FieldType::INTEGER);
    f1.setPK(true);

    f2.setOrdinal(1);
    f2.setName("nombre");
    f2.setType(FieldType::STRING);

    f3.setOrdinal(2);
    f3.setName("sueldo");
    f3.setType(FieldType::FLOAT);

    f4.setOrdinal(3);
    f4.setName("fechaNac");
    f4.setType(FieldType::DATE);

    testTable.addField(f1);
    testTable.addField(f2);
    testTable.addField(f3);
    testTable.addField(f4);

    r1.push_back("0");
    r1.push_back("Juan");
    r1.push_back("140.5");
    r1.push_back("14-11-1995");

    r2.push_back("1");
    r2.push_back("Jose");
    r2.push_back("153.5");
    r2.push_back("17-10-1998");

    r3.push_back("2");
    r3.push_back("Alberto");
    r3.push_back("133.5");
    r3.push_back("17-10-1992");

    testTable.addRecord(r1);
    testTable.addRecord(r2);
    testTable.addRecord(r3);

    return testTable;
}

Table getTestTable1()
{
    Table testTable;
    Field f1, f2, f3, f4;
    vector<string> r1, r2, r3;

    testTable.setName("Factura");

    f1.setOrdinal(0);
    f1.setName("id");
    f1.setType(FieldType::INTEGER);
    f1.setPK(true);

    f2.setOrdinal(1);
    f2.setName("id_persona");
    f2.setType(FieldType::INTEGER);
    f2.setFK(true);
    f2.setFKField("id");
    f2.setFKTable("Persona");

    f3.setOrdinal(2);
    f3.setName("importe");
    f3.setType(FieldType::FLOAT);

    f4.setOrdinal(3);
    f4.setName("fecha");
    f4.setType(FieldType::DATE);

    testTable.addField(f1);
    testTable.addField(f2);
    testTable.addField(f3);
    testTable.addField(f4);

    r1.push_back("0");
    r1.push_back("0");
    r1.push_back("1440.5");
    r1.push_back("14-09-2005");

    r2.push_back("1");
    r2.push_back("1");
    r2.push_back("1533.5");
    r2.push_back("17-08-2008");

    r3.push_back("2");
    r3.push_back("2");
    r3.push_back("1333.5");
    r3.push_back("17-07-2002");

    testTable.addRecord(r1);
    testTable.addRecord(r2);
    testTable.addRecord(r3);

    return testTable;
}


void testTableWriter()
{
    string loc = "C:\\Users\\Gilbert\\Documents\\Codigos\\filesx\\MiniDBMS";
    string db = "testdb";

    Table tabla = getTestTable();
    TableWriter writer(loc, db, &tabla);
    writer.write();
}


void testTableReader()
{
    string loc = "C:\\Users\\grosa\\Documents\\projects\\filesx\\MiniDBMS";
    string db = "testdb";

    Table* tablaleida;
    vector<string> recordNuevo;
    TableReader reader(loc, db, "Persona");

    tablaleida = reader.read();

    if(tablaleida != nullptr) {
        cout << "Table readed: OK" << endl;
    }
}

void testAddNewRecord()
{
    string loc = "C:\\Users\\grosa\\Documents\\projects\\filesx\\MiniDBMS";
    string db = "testdb";

    Table* tablaleida;
    vector< vector<string> > data;
    vector<string> recordNuevo;
    TableReader reader(loc, db, "Persona");

    tablaleida = reader.read();

    recordNuevo.push_back("3");
    recordNuevo.push_back("asdf");
    recordNuevo.push_back("17-12-1993");

    tablaleida->addRecord(recordNuevo);

    data = tablaleida->getData();

    for(vector<string> reg : data) {
        string regStr = "";
        for(string value : reg) {
             regStr += value + "|";
        }

        regStr = regStr.substr(0, regStr.size() - 1);
        cout << regStr << endl;
    }

    TableWriter writer(loc, db, tablaleida);
    writer.write();
}

void testValidateTableMetadata()
{
    string loc = "C:\\Users\\grosa\\Documents\\projects\\filesx\\MiniDBMS";
    string db = "testdb";

    Table* tablaleida;
    vector<string> recordNuevo;
    TableReader reader(loc, db, "Persona");

    tablaleida = reader.read();

    vector<Field> fields;
    string value;
    string metadata = "0|id|0|1|0||\n1|nombre|2|0|0||\n2|sueldo|1|0|0||\n3|fechaNac|3|0|0||\n";

    fields = tablaleida->getFields();

    for(Field field : fields) {
        stringstream line;

        line << field.getOrdinal()
             << "|" << field.getName()
             << "|" << FieldTypeHelper::fieldTypeToString(field.getType())
             << "|" << (field.isPK()? "1":"0")
             << "|" << (field.isFK()? "1":"0")
             << "|" << field.getFKField()
             << "|" << field.getFKTable();

        value += line.str() + "\n";
    }

    if(value == metadata) {
        cout << "Metadata: OK" << endl;
    } else {
        cout << "Metadata: Failed" << endl;
    }
}

void testCheckPrimaryKey()
{
    string loc = "C:\\Users\\grosa\\Documents\\projects\\filesx\\MiniDBMS";
    string db = "testdb";

    Table* tablaleida;
    vector<string> recordNuevo;
    TableReader reader(loc, db, "Persona");

    tablaleida = reader.read();

    PrimaryKeyChecker PKChecker(tablaleida);

    recordNuevo.push_back("2");
    recordNuevo.push_back("asdf");
    recordNuevo.push_back("17-12-1993");

    cout << (PKChecker.check(recordNuevo)? "Cumple con el PK" : "No cumple con el PK") << endl;
}


void testDeleteRecord()
{
    Table tbl = getTestTable();
    vector< vector<string> > data;

    data = tbl.getData();

    for(vector<string> reg : data) {
        string regStr = "";
        for(string value : reg) {
             regStr += value + "|";
        }

        regStr = regStr.substr(0, regStr.size() - 1);
        cout << regStr << endl;
    }

    cout << endl;
    tbl.deleteRecord("2");
    data = tbl.getData();


    for(vector<string> reg2 : data) {
        string regStr2 = "";
        for(string value2 : reg2) {
             regStr2 += value2 + "|";
        }

        regStr2 = regStr2.substr(0, regStr2.size() - 1);
        cout << regStr2 << endl;
    }
}


void testCheckFK()
{
    string loc = "C:\\Users\\Gilbert\\Documents\\Codigos\\filesx\\MiniDBMS";
    string db = "testdb";
    Table Persona = getTestTable();
    Table Factura = getTestTable1();
    ForeignKeyChecker checker(&Factura);
    vector<string> record;

    TableWriter writer(loc, db, &Factura);
    writer.write();

    record.push_back("3");
    record.push_back("3");
    record.push_back("1440.5");
    record.push_back("14-09-2005");

    cout << (checker.check(record, &Persona, 1)? "Cumple el FK" : "No cumple el FK") << endl;
}

void testCheckEngineBDPK() {
    vector<string> tables;
    vector< map<string, string> > records;
    map<string, string> record;

    tables.push_back("Persona");

    EngineBD engine("C:\\Users\\Gilbert\\Documents\\Codigos\\filesx\\MiniDBMS", "testdb", tables);
    records = engine.selectAll("Persona");

    for(map<string, string> record : records) {
        for(std::map<string, string>::iterator it=record.begin(); it!=record.end(); ++it) {
            cout << it->first << " = " << it->second << endl;
        }
        cout << endl;
    }

   try {
        Persona p;

        engine.insert("Persona", &p);
    } catch(runtime_error re) {
        cout << re.what() << endl;
    }
}

void testCheckEngineBDFK()
{
    vector<string> tables;
    vector< map<string, string> > records;
    map<string, string> record;

    tables.push_back("Persona");
    tables.push_back("Factura");

    EngineBD engine("C:\\Users\\Gilbert\\Documents\\Codigos\\filesx\\MiniDBMS", "testdb", tables);

    try {
        Factura f;

        engine.insert("Factura", &f);
    } catch(runtime_error re) {
        cout << re.what() << endl;
    }
}


void testCreateTable()
{
    vector<string> tables;

    tables.push_back("Persona");
    tables.push_back("Factura");

    EngineBD engine("C:\\Users\\Gilbert\\Documents\\Codigos\\filesx\\MiniDBMS", "testdb", tables);
    vector<Field> fields;
    Field f1, f2, f3;

    f1.setOrdinal(0);
    f1.setName("id");
    f1.setType(INTEGER);
    f1.setPK(true);

    f2.setOrdinal(1);
    f2.setName("name");
    f2.setType(STRING);

    f3.setOrdinal(2);
    f3.setName("something");
    f3.setType(STRING);

    fields.push_back(f1);
    fields.push_back(f2);
    fields.push_back(f3);

    engine.createTable("Someone", fields);

    if(engine.findTable("Someone") != NULL) {
        cout << "OK" << endl;
    }
}
