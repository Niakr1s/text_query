#if !defined(BINARYQUERY_H)
#define BINARYQUERY_H

#include <string>
#include "QueryBase.h"

class BinaryQuery : public QueryBase
{
    friend class Query;

  protected:
    std::string left;
    std::string right;

  public:
    BinaryQuery(const std::string &l,
                const std::string &r) : QueryBase(),
                                        left(l), right(r){};
    ~BinaryQuery(){};
};

#endif // BINARYQUERY_H
