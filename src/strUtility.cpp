#include "strUtility.h"

#include <algorithm>
#include <cctype>
#include <exception>
#include "AndQuery.h"
#include "NoQuery.h"
#include "OrQuery.h"
#include "WordQuery.h"

std::shared_ptr<QueryBase> parse(std::string &s) {
    remove_spaces(s);
    while (remove_outer_braces(s))
        ;
    // std::cout << "\nGot string : \"" << s << "\"\n";  // for debug
    int depth = 0;

    for (auto it = s.begin(); it != s.end(); ++it) {
        switch (*it) {
            case '(':
                ++depth;
                break;
            case ')':
                --depth;
                break;
            case '&':
                if (depth == 0) {
                    auto p = split_string(s, it);
                    return std::make_shared<AndQuery>(p.first, p.second);
                }
                break;
            case '|': {
                if (depth == 0) {
                    auto p = split_string(s, it);
                    return std::make_shared<OrQuery>(p.first, p.second);
                }
                break;
            }
        }
        if (depth < 0) throw std::runtime_error("Wrong braces in input");
    }
    if (s[0] == '~') {
        s.erase(s.begin());
        return std::make_shared<NoQuery>(s);
    }
    return std::make_shared<WordQuery>(s);
};

void remove_spaces(std::string &s) {
    s.erase(std::remove_if(s.begin(), s.end(),
                           [](char x) { return std::isspace(x); }),
            s.end());
}

bool remove_outer_braces(std::string &s) {
    if (!(*s.begin() == '(' && *(s.end() - 1) == ')')) return false;
    int depth = 0;
    for (auto it = s.begin(); it != s.end() - 1; ++it) {
        switch (*it) {
            case ('('):
                ++depth;
                break;
            case (')'):
                --depth;
                break;
        }
        if (depth == 0) return false;
    }
    s.erase(s.end() - 1);
    s.erase(s.begin());
    return true;
}

std::pair<std::string, std::string> split_string(
    const std::string &s, std::string::const_iterator it) {
    return {std::string(s.begin(), it), std::string(it + 1, s.end())};
};
