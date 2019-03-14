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
  std::string word;
  std::shared_ptr<QueryBase> query;

public:
  Query() : word(""), query(nullptr){};
  Query(const std::string &s) : word(s), query(std::make_shared<WordQuery>(s)){};
  ~Query(){};

  // members
  QueryResult eval(TextQuery &tq) const;
  std::string rep() const;

  // ops
  Query &operator~() const &;
  // Query &operator|(const Query &rhs) const &;
};

#endif // QUERY_H
