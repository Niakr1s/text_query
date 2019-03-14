#include "Query.h"
#include "NoQuery.h"
#include "OrQuery.h"

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

    auto ret = new Query();
    auto no_query = std::make_shared<NoQuery>(*this);
    ret->query = no_query;
    return *ret;
};

Query &Query::operator|(const Query &rhs) const &
{
    auto ret = new Query();
    auto or_query = std::make_shared<OrQuery>(*this, rhs);
    ret->query = or_query;
    return *ret;
};