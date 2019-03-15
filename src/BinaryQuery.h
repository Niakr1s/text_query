#if !defined(BINARYQUERY_H)
#define BINARYQUERY_H

#include <string>
#include "Query.h"
#include "QueryBase.h"

class BinaryQuery : public QueryBase {
   protected:
    Query left;
    Query right;

   public:
    BinaryQuery(const Query &l, const Query &r)
        : QueryBase(), left(l), right(r){};
    BinaryQuery(const std::string &l, const std::string &r);
    ~BinaryQuery(){};
};

#endif  // BINARYQUERY_H
