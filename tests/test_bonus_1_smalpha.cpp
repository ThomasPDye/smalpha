#include "test_bonus_1_smalpha.hpp"
#include "smalpha.hpp"
#include "smorse.hpp"
#include <fstream>
#include <map>
#include <boost/chrono.hpp>

test_bonus_smalpha::result_t test_bonus_smalpha::test_bonus_1_smalpha(std::string infilename, std::size_t max_solutions_per_entry)
{
    int ret_value = 0;
    std::ifstream infile(infilename);
    std::map<std::string, std::vector<std::string>> in_out_map;
    boost::chrono::process_cpu_clock::time_point start_test = boost::chrono::process_cpu_clock::now();
    while (!infile.eof())
    {
        std::string code_seq = "";
        infile >> code_seq;
        if (!code_seq.empty())
        {
            if (in_out_map.count(code_seq) == 0)
            {
                in_out_map[code_seq] = smalpha::smalpha(code_seq, max_solutions_per_entry);
            }
        }
    }
    boost::chrono::process_cpu_clock::time_point end_test = boost::chrono::process_cpu_clock::now();
    boost::chrono::duration<double> test_time = end_test - start_test;
    infile.close();
    boost::chrono::process_cpu_clock::time_point start_check = boost::chrono::process_cpu_clock::now();
    for (std::map<std::string, std::vector<std::string>>::iterator iom = in_out_map.begin(); iom != in_out_map.end(); iom++)
    {
        for (std::vector<std::string>::iterator soli = iom->second.begin(); soli != iom->second.end(); soli++)
        {
            if (smorse::smorse(*soli.base()) != iom->first)
                ret_value--;
        }
    }
    boost::chrono::process_cpu_clock::time_point end_check = boost::chrono::process_cpu_clock::now();
    boost::chrono::duration<double> check_time = end_check - start_check;
    return {ret_value, test_time.count(), check_time.count()};
}
