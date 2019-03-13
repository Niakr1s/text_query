#include "Query.h"

// members
QueryResult Query::eval(TextQuery &tq) const
{
    return query->eval(tq);
};

std::string Query::rep() const
{
    return query->rep();
};

// ops
Query &Query::operator~() const &
{
    auto ret = new Query(*this);
    ret->query = std::make_shared<NoQuery>(ret->word);
    return *ret;
};