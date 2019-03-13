#include "NoQuery.h"

QueryResult NoQuery::eval(TextQuery &tq) const
{
    QueryResult ret(tq.text, rep(), tq.not_lines(word));
    return ret;
};

std::string NoQuery::rep() const
{
    return "~" + word;
};