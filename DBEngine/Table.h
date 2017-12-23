#ifndef __TABLE_H
#define __TABLE_H

#include <vector>

#include "Field.h"

namespace DBEngine
{
   class Table
   {
   private:
       std::string name;
       std::vector<Field> fields;
       std::vector< std::vector<std::string> > data;

   public:

       Table();
       ~Table();

       std::string getName();
       void setName(std::string name);

       std::vector<Field> getFields();
       void addField(Field field);
       void deleteField(Field field);

       void addRecord(std::vector<std::string> entry);
       void deleteRecord(std::string PK);

       std::vector< std::vector<std::string> > getData();

       Field getPKField();
       std::vector<Field> getFKFields();

       void sortEntries();
   };
}

#endif // __TABLE_H
