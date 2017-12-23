#include "Factura.h"

using namespace std;
using namespace DBEngine::Entity;

Factura::Factura()
{
    record = map<string, string>();
    record["id"]  = "6";
    record["id_persona"] = "7";
    record["importe"] = "25900.35";
    record["fecha"] = "19-01-1988";
}

Factura::~Factura()
{

}

void Factura::setValues(map<string, string> values)
{

}

map<string, string> Factura::getValues()
{
    return record;
}
