#ifndef __ENTITY_H
#define __ENTITY_H

#include <map>
#include <string>

namespace DBEngine
{
    namespace Entity
    {
        class Entity
        {
        public:
            virtual void setValues(std::map<std::string, std::string> values) = 0;
            virtual std::map<std::string, std::string> getValues() = 0;
        };
    }
}

#endif // __ENTITY_H
