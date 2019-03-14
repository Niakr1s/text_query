#if !defined(ANDQUERY_H)
#define ANDQUERY_H

#include "BinaryQuery.h"

class AndQuery : public BinaryQuery
{
  std::string op;

public:
  AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r), op("&"){};

  ~AndQuery(){};

  QueryResult eval(TextQuery &tq) const override;
  std::string rep() const override;
};

#endif // ANDQUERY_H
