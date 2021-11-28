#include "test_smalpha.hpp"
#include "smalpha.hpp"
#include "smorse.hpp"

int test_smalpha::test_smalpha(std::string code_sequence, std::size_t max_permutations)
{
    int result = 0;
    std::vector<std::string> letter_sequences = smalpha::smalpha(code_sequence, max_permutations);
    for (std::vector<std::string>::iterator lsi = letter_sequences.begin(); lsi != letter_sequences.end(); lsi++)
    {
        if (code_sequence != smorse::smorse(*lsi.base()))
        {
            result = -1;
            break;
        }
    }
    return result;
}

int test_smalpha::test_extra_smalpha(std::string code_sequence, std::string example_permutation)
{
    int result = -1;
    std::vector<std::string> letter_sequences = smalpha::smalpha(code_sequence, __LONG_MAX__);
    if (code_sequence == smorse::smorse(example_permutation))
    {
        for (std::vector<std::string>::iterator lsi = letter_sequences.begin(); lsi != letter_sequences.end(); lsi++)
        {
            if (*lsi.base() == example_permutation)
            {
                result = 0;
                break;
            }
        }
    }
    return result;
}
