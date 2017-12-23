#ifndef __FIELD_H
#define __FIELD_H

#include "FieldType.h"

#include <string>
#include <vector>

namespace DBEngine
{
   class Field
   {
   private:
       int ordinal;
       std::string name;
       FieldType type;

       bool PK;
       bool FK;
       std::string FKTable;
       std::string FKField;
   public:

       Field();
       ~Field();

       static Field vectorToField(std::vector<std::string> vect);

       int getOrdinal();
       void setOrdinal(int ordinal);

       std::string getName();
       void setName(std::string name);

       FieldType getType();
       void setType(FieldType type);

       void setPK(bool PK);
       bool isPK();

       void setFK(bool FK);
       bool isFK();

       std::string getFKTable();
       void setFKTable(std::string FKTable);

       std::string getFKField();
       void setFKField(std::string FKField);
   };
}

#endif // __FIELD_H
