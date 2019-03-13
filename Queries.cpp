#include "Queries.h"

QueryResult NoQuery::eval(TextQuery &tq) const
{
    QueryResult ret(tq.text, rep(), tq.not_lines(word));
    return ret;
};

std::string NoQuery::rep() const
{
    return "~" + word;
};

// std::string OrQuery::rep() const
// {
//     return left + " | " + right;
// };

// std::string AndQuery::rep() const
// {
//     return left + " & " + right;
// };