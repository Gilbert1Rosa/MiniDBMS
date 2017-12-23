#ifndef __STRING_HELPER_H
#define __STRING_HELPER_H

#include <string>
#include <vector>

namespace DBEngine
{
    namespace Helper
	{
       class StringHelper
       {
        public:
           static std::vector<std::string> split(std::string str, char separator);

           static int strToInt(std::string str);
           static float strToFloat(std::string str);
       };
    }
}

#endif // __STRING_HELPER_H
