#include "TextQuery.h"

#include <sstream>
#include <fstream>
#include <iterator>
#include <iostream>

std::set<size_t> TextQuery::negate_lines(std::set<size_t> &to_negate)
{
    auto ret = all_lines();
    for (auto &i : to_negate)
    {
        auto it = ret.find(i);
        if (it != ret.end())
            ret.erase(it);
    }
    return ret;
};

std::set<size_t> TextQuery::all_lines()
{
    std::set<size_t> ret;
    for (size_t i = 0; i < text->size(); ++i)
        ret.insert(i);
    return ret;
};

TextQuery::TextQuery(const std::string &filename) : text(std::make_shared<std::vector<std::string>>())
{
    std::ifstream f(filename);
    std::string line;
    size_t line_no = 0;
    while (std::getline(f, line))
    {
        text->push_back(line);
        std::istringstream ss(line);
        std::string word;
        while (ss >> word)
        {
            lines[word].insert(line_no);
        }
        ++line_no;
    }
}

void TextQuery::print_text()
{
    std::copy(text->begin(),
              text->end(),
              std::ostream_iterator<std::string>(std::cout, "\n"));
};

void TextQuery::print_words()
{
    for (auto &i : lines)
    {
        std::cout << i.first << ": {";
        std::copy(i.second.cbegin(),
                  i.second.cend(),
                  std::ostream_iterator<size_t>(std::cout, ", "));
        std::cout << " }\n";
    }
};