#include "test_smalpha.hpp"

int main(int argc, char **argv)
{
    int result = -1;
    if (argc == 3)
    {
        std::string code_seq(argv[1]);
        std::string example_sol(argv[2]);
        result = test_smalpha::test_extra_smalpha(code_seq, example_sol);
    }
    return result;
}
