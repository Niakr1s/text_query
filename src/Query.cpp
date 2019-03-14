#include "Query.h"
#include "NoQuery.h"

Query &Query::operator=(const Query &rhs)
{
    query = rhs.query;
    return *this;
};

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
    ret->query = std::make_shared<NoQuery>(*this);
    return *ret;
};