#ifndef __DATE_HELPER_H
#define __DATE_HELPER_H

#include <ctime>
#include <string>

namespace DBEngine
{
    namespace Helper
    {
        class DateHelper
        {
         public:

            static time_t getDateFromString(std::string str);
            static std::string getStringFromDate(time_t date);
        };
    }
}



#endif // __DATE_HELPER_H
