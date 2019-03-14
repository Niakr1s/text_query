#if !defined(BINARYQUERY_H)
#define BINARYQUERY_H

#include <string>
#include "QueryBase.h"
#include "Query.h"

class BinaryQuery : public QueryBase
{
protected:
  Query left;
  Query right;

public:
  BinaryQuery(const Query &l,
              const Query &r) : QueryBase(),
                                left(l), right(r){};
  ~BinaryQuery(){};
};

#endif // BINARYQUERY_H
