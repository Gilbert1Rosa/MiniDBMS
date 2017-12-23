#include "Persona.h"

using namespace std;
using namespace DBEngine::Entity;

Persona::Persona()
{
    record = map<string, string>();
    record["id"]  = "4";
    record["nombre"] = "Bleh";
    record["sueldo"] = "25900.35";
    record["fechaNac"] = "19-01-1988";
}

Persona::~Persona()
{

}

void Persona::setValues(map<string, string> values)
{

}

map<string, string> Persona::getValues()
{
    return record;
}
