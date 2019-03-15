#include "QueryResult.h"

#include <iostream>

std::ostream &operator<<(std::ostream &out, const QueryResult &qr) {
    out << "\nResult for " << qr.name << ":\n";
    for (auto &i : qr.lines)
        out << "Line no " << i << ": " << (*qr.text)[i] << "\n";
    return out;
};