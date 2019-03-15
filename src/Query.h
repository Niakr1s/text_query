#if !defined(QUERY_H)
#define QUERY_H

#include <string>
#include <utility>
#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "WordQuery.h"

class Query {
   private:
    std::shared_ptr<QueryBase> query;

   public:
    Query(std::string &&s);
    Query() : query(nullptr){};
    ~Query(){};

    Query(const Query &q) : query(q.query){};
    Query &operator=(const Query &rhs);

    // members
    QueryResult eval(TextQuery &tq) const;
    std::string rep() const;

    // ops
    Query &operator~() const &;
    Query &operator|(const Query &rhs) const &;
    Query &operator&(const Query &rhs) const &;
};

void remove_spaces(std::string &s);
bool remove_outer_braces(std::string &s);
std::pair<std::string, std::string> split_string(
    const std::string &s, std::string::const_iterator it);

#endif  // QUERY_H
