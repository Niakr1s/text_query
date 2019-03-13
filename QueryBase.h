#if !defined(QUERYBASE_H)
#define QUERYBASE_H

#include <string>
#include <memory>
#include "QueryResult.h"
#include "TextQuery.h"

class QueryBase
{
  public:
    friend class Query;
    virtual ~QueryBase() = default;

    virtual QueryResult eval(TextQuery &tq) const = 0;
    virtual std::string rep() const = 0;
};

#endif // QUERYBASE_H
