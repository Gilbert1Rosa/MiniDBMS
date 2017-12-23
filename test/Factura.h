#ifndef __FACTURA_H
#define __FACTURA_H

#include "../DBEngine/Entity/Entity.h"


class Factura : public DBEngine::Entity::Entity
{
private:
    std::map<std::string, std::string> record;

public:

    Factura();

    ~Factura();

    void setValues(std::map<std::string, std::string> values);
    std::map<std::string, std::string> getValues();
};


#endif // __FACTURA_H
