#include "test_smalpha.hpp"

int main(int argc, char **argv)
{
    int result = -1;
    if (argc == 3)
    {
        std::string code_seq(argv[1]);
        std::string max_perm_string(argv[2]);
        std::size_t max_perm = std::stoul(max_perm_string);
        result = test_smalpha::test_smalpha(code_seq, max_perm);
    }
    return result;
}
