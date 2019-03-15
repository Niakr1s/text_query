#if !defined(ORQUERY_H)
#define ORQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
    std::string op;

   public:
    OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r), op("|"){};
    OrQuery(const std::string &l, const std::string &r)
        : BinaryQuery(l, r), op("|"){};

    ~OrQuery(){};

    friend Query &Query::operator|(const Query &rhs) const &;

    QueryResult eval(TextQuery &tq) const override;
    std::string rep() const override;
};

#endif  // ORQUERY_H
