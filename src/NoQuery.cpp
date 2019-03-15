#include "NoQuery.h"

#include <algorithm>
#include <iterator>

NoQuery::NoQuery(const std::string &s) : op("~") {
    std::string ss(s);
    query = Query(std::move(ss));
};

QueryResult NoQuery::eval(TextQuery &tq) const {
    auto all_lines = tq.all_lines();
    auto ls = query.eval(tq).lines;
    decltype(ls) res;
    std::set_difference(all_lines.begin(), all_lines.end(), ls.begin(),
                        ls.end(),
                        std::insert_iterator<decltype(ls)>(res, res.begin()));
    QueryResult ret(tq.text, rep(), res);
    return ret;
};

std::string NoQuery::rep() const { return op + query.rep(); };