#if !defined(QUERY_H)
#define QUERY_H

#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
#include "QueryBase.h"
#include "WordQuery.h"

class Query
{
private:
  std::shared_ptr<QueryBase> query;

public:
  Query(const std::string &s) : query(std::make_shared<WordQuery>(s)){};
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
};

#endif // QUERY_H
