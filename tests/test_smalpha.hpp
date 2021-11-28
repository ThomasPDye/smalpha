#pragma once

#include <string>
#include <vector>

namespace test_smalpha
{
    int test_smalpha(std::string code_sequence, std::size_t max_permutations = 1UL);
    int test_extra_smalpha(std::string code_sequence, std::string example_permutation);
} // namespace test_smalpha
