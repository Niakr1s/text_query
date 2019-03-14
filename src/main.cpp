#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>
#include <memory>

#include "TextQuery.h"
#include "Query.h"

int main(int argc, char *argv[])
{
    TextQuery tq("text.txt");
    // Query q("desert");
    // Query notq = ~q;
    // auto res = q.eval(tq);
    // res.print();
    // auto notres = notq.eval(tq);
    // notres.print();
    // auto movedq = ~Query("motor");
    // auto asdf = movedq.eval(tq);
    Query("motor").eval(tq).print();
    Query("desert").eval(tq).print();
    auto or_q = Query("motor") | Query("desert");
    or_q.eval(tq).print();

    return 0;
}
