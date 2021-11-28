#include "smalpha.hpp"
#include "coding.hpp"

bool possible_next(std::string code_sequence, std::size_t pos, std::string letter_code)
{
    return (code_sequence.find(letter_code, pos) == pos);
}

void run(std::string code_sequence, std::size_t pos, std::map<char, std::string> remaining, std::string current_permutation, std::size_t alphabet_size, std::vector<std::string> *results, std::size_t stop_at)
{
    if (pos < code_sequence.size())
    {
        for (std::map<char, std::string>::iterator ri = remaining.begin(); ri != remaining.end(); ri++)
        {
            if (results->size() < stop_at)
            {
                if (possible_next(code_sequence, pos, ri->second))
                {
                    std::map<char, std::string> new_remaining = remaining;
                    new_remaining.erase(ri->first);
                    run(code_sequence, pos + ri->second.size(), new_remaining, current_permutation + ri->first, alphabet_size, results, stop_at);
                }
            }
            else
            {
                return;
            }
        }
        return;
    }
    else
    {
        if (remaining.empty() && pos == code_sequence.size())
        {
            results->push_back(current_permutation);
            return;
        }
    }
    return;
}

std::vector<std::string> smalpha::smalpha(std::string code, std::size_t stop_at)
{
    std::vector<std::string> permutations;
    run(code, 0UL, smorse::coding, "", smorse::coding.size(), &permutations, stop_at);
    return permutations;
}
