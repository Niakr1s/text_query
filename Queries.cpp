#include "Queries.h"

QueryResult WordQuery::eval(TextQuery &tq) const
{
    QueryResult ret(tq.text, rep(), tq.lines[word]);
    return ret;
};

QueryResult NoQuery::eval(TextQuery &tq) const
{
    QueryResult ret(tq.text, rep(), tq.not_lines(word));
    return ret;
};

std::string WordQuery::rep() const
{
    return word;
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