#pragma once

#include <string>
#include <vector>

namespace test_bonus_smalpha
{
    typedef struct result
    {
        int value;
        double test_time, check_time;
    } result_t;
    result_t test_bonus_1_smalpha(std::string infilename, std::size_t max_solutions_per_entry = 1UL);
} // namespace test_smalpha
