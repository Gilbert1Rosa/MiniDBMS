#ifndef __PERSONA_H
#define __PERSONA_H

#include "../DBEngine/Entity/Entity.h"

class Persona : public DBEngine::Entity::Entity
{
private:
    std::map<std::string, std::string> record;

public:

    Persona();
    ~Persona();

    void setValues(std::map<std::string, std::string> values);
    std::map<std::string, std::string> getValues();
};


#endif // __PERSONA_H
