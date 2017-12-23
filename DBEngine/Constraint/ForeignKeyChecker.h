#ifndef __FOREIGN_KEY_CHECKER_H
#define __FOREIGN_KEY_CHECKER_H

#include <string>
#include <vector>

#include "../Table.h"

namespace DBEngine
{
    namespace Constraint
    {
        class ForeignKeyChecker
        {
        private:
            Table* table;

        public:

            ForeignKeyChecker(Table* table);
            ~ForeignKeyChecker();

            bool check(std::vector<std::string> record, Table* parent, int childField);
        };
    }
}

#endif // __FOREIGN_KEY_CHECKER_H
