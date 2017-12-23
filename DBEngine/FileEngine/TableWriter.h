#ifndef __TABLE_WRITER_H
#define __TABLE_WRITER_H

#include <fstream>
#include <string>

#include "../Table.h"

namespace DBEngine
{
   namespace FileEngine
   {
       class TableWriter
       {
       private:
            std::string dblocation = "";
            std::string database = "";
            DBEngine::Table* table = NULL;

            std::ofstream catalogFile;
            std::ofstream dataFile;

       public:

            TableWriter(std::string dblocation, std::string database, DBEngine::Table* table);
            ~TableWriter();

            void write();
       };
   }
}

#endif // __TABLE_WRITER_H
