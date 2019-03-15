#include "AndQuery.h"

#include <algorithm>
#include <iterator>

QueryResult AndQuery::eval(TextQuery &tq) const {
    auto ls = left.eval(tq).lines;
    auto rs = right.eval(tq).lines;
    decltype(ls) diff;
    std::set_intersection(
        ls.begin(), ls.end(), rs.begin(), rs.end(),
        std::insert_iterator<decltype(ls)>(diff, diff.begin()));

    QueryResult ret(tq.text, rep(), diff);
    return ret;
};

std::string AndQuery::rep() const {
    return "( " + left.rep() + " " + op + " " + right.rep() + " )";
};