#if !defined(NOQUERY_H)
#define NOQUERY_H

#include <string>
#include "Query.h"
#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"

class NoQuery : public QueryBase {
   private:
    Query query;
    std::string op;

   public:
    NoQuery(const std::string &s);
    NoQuery(const Query &q) : query(q), op("~"){};

    ~NoQuery(){};

    QueryResult eval(TextQuery &tq) const override;
    std::string rep() const override;
};

#endif  // NOQUERY_H
