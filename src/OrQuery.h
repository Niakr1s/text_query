#if !defined(ORQUERY_H)
#define ORQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery
{

  public:
    OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r){};

    ~OrQuery(){};

    QueryResult eval(TextQuery &tq) const override;
    std::string rep() const override;
};

#endif // ORQUERY_H
