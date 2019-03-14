#if !defined(NOQUERY_H)
#define NOQUERY_H

#include <string>
#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "Query.h"

class NoQuery : public QueryBase
{
private:
  Query query;
  // std::string word;

public:
  // NoQuery(const std::string &s) : word(s){};
  NoQuery(const Query &q) : query(q){};

  ~NoQuery(){};

  QueryResult eval(TextQuery &tq) const override;
  std::string rep() const override;
};

#endif // NOQUERY_H
