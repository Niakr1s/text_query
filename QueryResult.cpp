#include "QueryResult.h"

std::ostream &QueryResult::print(std::ostream &out)
{
    out << "Result for " << name << ":\n";
    for (auto &i : lines)
        out << "Line no " << i << ": " << (*text)[i] << "\n";
    return out;
};