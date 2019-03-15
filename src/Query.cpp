#include "Query.h"

#include "AndQuery.h"
#include "NoQuery.h"
#include "OrQuery.h"
#include "WordQuery.h"

Query &Query::operator=(const Query &rhs) {
    query = rhs.query;
    return *this;
};

// members
QueryResult Query::eval(TextQuery &tq) const { return query->eval(tq); };

std::string Query::rep() const { return query->rep(); };

// ops
Query &Query::operator~() const & {
    auto ret = new Query();
    auto no_query = std::make_shared<NoQuery>(*this);
    ret->query = no_query;
    return *ret;
};

Query &Query::operator|(const Query &rhs) const & {
    auto ret = new Query();
    auto q = std::make_shared<OrQuery>(*this, rhs);
    ret->query = q;
    return *ret;
};

Query &Query::operator&(const Query &rhs) const & {
    auto ret = new Query();
    auto q = std::make_shared<AndQuery>(*this, rhs);
    ret->query = q;
    return *ret;
};