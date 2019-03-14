#include "NoQuery.h"

QueryResult NoQuery::eval(TextQuery &tq) const
{
    auto ls = query.eval(tq);
    QueryResult ret(tq.text, rep(), tq.negate_lines(ls.lines));
    return ret;
};

std::string NoQuery::rep() const
{
    return "~" + query.rep();
};