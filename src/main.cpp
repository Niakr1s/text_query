#include "Query.h"
#include "TextQuery.h"

int main(int argc, char *argv[]) {
    TextQuery tq("text.txt");

    auto m = Query("(|)|\nmotor | swam");
    auto no_m = ~m;
    m.eval(tq).print();
    no_m.eval(tq).print();
    auto new_q = m | Query("which");
    new_q.eval(tq).print();

    return 0;
}
