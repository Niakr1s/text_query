#include "WordQuery.h"

QueryResult WordQuery::eval(TextQuery &tq) const {
    QueryResult ret(tq.text, rep(), tq.lines[word]);
    return ret;
};

std::string WordQuery::rep() const { return word; };
