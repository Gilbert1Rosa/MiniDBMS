#ifndef __DB_ENGINE_H
#define __DB_ENGINE_H

#include <map>
#include <string>
#include <vector>

#include "Table.h"
#include "Entity/Entity.h"


namespace DBEngine
{
    class EngineBD
    {
    private:
        std::string dblocation;
        std::string dbname;
        std::vector<Table*> tablecatalog;

    public:

        EngineBD(std::string dblocation, std::string dbname, std::vector<std::string> tables);
        ~EngineBD();

        void createTable(std::string tablename, std::vector<Field> fields);

        std::vector< std::map<std::string, std::string> > selectAll(std::string table);
        std::map<std::string, std::string> selectByPK(std::string table, std::string PK);

        void insert(std::string table, Entity::Entity* entity);

        Table* findTable(std::string name);

    private:



        static Field findFieldByOrdinal(std::vector<Field> fields, int ordinal);
        static Field findFieldByName(std::vector<Field> fields, std::string name);
    };
}


#endif // __DB_ENGINE_H
