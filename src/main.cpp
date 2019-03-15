#include <algorithm>
#include <cctype>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "Query.h"
#include "TextQuery.h"

void parse(std::string &s) {
    remove_spaces(s);
    while (remove_outer_braces(s))
        ;
    std::cout << "\nGot string : \"" << s << "\"\n";
    int depth = 0;

    for (auto it = s.begin(); it != s.end(); ++it) {
        switch (*it) {
            case '(':
                ++depth;
                std::cout << "got '(', depth now is " << depth << "\n";
                break;
            case ')':
                --depth;
                std::cout << "got ')', depth now is " << depth << "\n";
                break;
            case '&':
            case '|': {
                std::cout << "got binary op '" << *it << "' with depth "
                          << depth << "\n";
                std::string l(s.begin(), it);
                std::string r(it + 1, s.end());
                if (depth == 0) {
                    std::cout << "gonna return l: " << l << ", and r: " << r
                              << "; op: " << *it << "\n";
                    return;
                }
                break;
            }
            default:
                break;
        }
        if (depth < 0) throw "Wrong input";
    }

    return;
};

int main(int argc, char *argv[]) {
    TextQuery tq("text.txt");
    // Query("motor").eval(tq).print();
    // (~Query("motor")).eval(tq).print();
    // Query("desert").eval(tq).print();
    // (Query("motor") | Query("desert")).eval(tq).print();
    // (Query("motor") & Query("desert")).eval(tq).print();

    // ((~Query("motor") | (Query("desert") & Query("desert"))) |
    // Query("tank")).eval(tq).print();

    return 0;
}
