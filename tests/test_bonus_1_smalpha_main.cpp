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
        std::cout << "test time  (s): " << result.test_time << std::endl;
        std::cout << "check time (s): " << result.check_time << std::endl;
        retval = result.value;
    }
    return retval;
}
