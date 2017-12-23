#ifndef __TABLE_READER_H
#define __TABLE_READER_H

#include <fstream>
#include <string>
#include <vector>

#include "../Table.h"

namespace DBEngine
{
   namespace FileEngine
   {
       class TableReader
       {
       private:
            std::string tableName;
            std::string dblocation;
            std::string database;

            std::ifstream catalogFile;
            std::ifstream dataFile;
       public:

            TableReader(std::string dblocation, std::string database, std::string tableName);
            ~TableReader();

            Table* read();
       };
   }
}
#endif // __TABLE_READER_H
