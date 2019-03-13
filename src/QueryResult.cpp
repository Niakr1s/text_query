#include "QueryResult.h"

#include <iostream>

void QueryResult::print()
{
    std::cout << "Result for " << name << ":\n";
    for (auto &i : lines)
        std::cout << "Line no " << i << ": " << (*text)[i] << "\n";
};