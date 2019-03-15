#include "Query.h"

#include <algorithm>
#include <cctype>
#include "AndQuery.h"
#include "NoQuery.h"
#include "OrQuery.h"

Query::Query(const std::string &s)
    : query(nullptr){

      };

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

void remove_spaces(std::string &s) {
    s.erase(std::remove_if(s.begin(), s.end(),
                           [](char x) { return std::isspace(x); }),
            s.end());
}

bool remove_outer_braces(std::string &s) {
    if (!(*s.begin() == '(' && *(s.end() - 1) == ')')) return false;
    int depth = 0;
    for (auto it = s.begin(); it != s.end() - 1; ++it) {
        switch (*it) {
            case ('('):
                ++depth;
                break;
            case (')'):
                --depth;
                break;
        }
        if (depth == 0) return false;
    }
    s.erase(s.end() - 1);
    s.erase(s.begin());
    return true;
}