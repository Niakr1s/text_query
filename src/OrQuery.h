#if !defined(ORQUERY_H)
#define ORQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery
{
    std::string op;

  public:
    OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r), op("|"){};

    ~OrQuery(){};

    QueryResult eval(TextQuery &tq) const override;
    std::string rep() const override;
};

#endif // ORQUERY_H
