#include "BinaryQuery.h"

BinaryQuery::BinaryQuery(const std::string &l, const std::string &r)
    : QueryBase() {
    std::string ll(l), rr(r);
    left = Query(std::move(ll));
    right = Query(std::move(ll));
};