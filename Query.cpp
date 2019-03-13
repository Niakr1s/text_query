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

// Query &Query::operator|(const Query &rhs) const &
// {
//     auto ret = new Query(*this);
//     ret->query = std::make_shared<OrQuery>(ret->query->word, rhs.query->word);
//     return *ret;
// };

// Query &Query::operator|(Query &rhs) &&
// {
//     query = std::make_shared<OrQuery>(query->word, rhs.query->word);
//     return *this;
// };
