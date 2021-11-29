#include "test_bonus_1_smalpha.hpp"
#include <iostream>

int main(int argc, char ** argv)
{
    int retval = -1;
    if (argc == 3)
    {
        std::string ifn(argv[1]);
        std::string maxn_string(argv[2]);
        std::size_t maxn = std::stoul(maxn_string);
        test_bonus_smalpha::result_t result = test_bonus_smalpha::test_bonus_1_smalpha(ifn, maxn);
        for (std::map<std::string, std::vector<std::string>>::iterator soli = result.solutions.begin(); soli != result.solutions.end(); soli++)
        {
            std::cout << soli->first << std::endl;
            for (std::vector<std::string>::iterator ai = soli->second.begin(); ai != soli->second.end(); ai++)
            {
                std::cout << "\t" << *ai.base() << std::endl;
            }
        }
        std::cout << "input time (s): " << result.in_time << std::endl;
        std::cout << "test time  (s): " << result.test_time << std::endl;
        std::cout << "check time (s): " << result.check_time << std::endl;
        retval = result.value;
    }
    return retval;
}
