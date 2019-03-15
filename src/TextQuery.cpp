#include "TextQuery.h"

#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

std::set<size_t> TextQuery::all_lines() {
    std::set<size_t> ret;
    for (size_t i = 0; i < text->size(); ++i) ret.insert(i);
    return ret;
};

TextQuery::TextQuery(const std::string &filename)
    : text(std::make_shared<std::vector<std::string>>()) {
    std::ifstream f(filename);
    if (!f.is_open()) throw std::runtime_error("Bad file");
    std::string line;
    size_t line_no = 0;
    while (std::getline(f, line)) {
        text->push_back(line);
        std::istringstream ss(line);
        std::string word;
        while (ss >> word) {
            lines[word].insert(line_no);
        }
        ++line_no;
    }
}

void TextQuery::print_text() {
    std::copy(text->begin(), text->end(),
              std::ostream_iterator<std::string>(std::cout, "\n"));
};

void TextQuery::print_words() {
    for (auto &i : lines) {
        std::cout << i.first << ": {";
        std::copy(i.second.cbegin(), i.second.cend(),
                  std::ostream_iterator<size_t>(std::cout, ", "));
        std::cout << " }\n";
    }
};