#ifndef __PRIMARY_KEY_CHECKER_H
#define __PRIMARY_KEY_CHECKER_H

#include <string>
#include <vector>

#include "../Table.h"

namespace DBEngine
{
    namespace Constraint
    {
        class PrimaryKeyChecker
        {
         private:
             Table* table;

         public:

             PrimaryKeyChecker(Table* table);
             ~PrimaryKeyChecker();

             bool check(std::vector<std::string> record);

         private:

             bool PKExists(std::string PK, int ordinalPK);
        };
    }
}

#endif // __PRIMARY_KEY_CHECKER_H
