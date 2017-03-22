#include "types.h"
#include "func.h"
#include <iostream>
using namespace std;

int main() {

    Point a, b, c;
    std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    square_namespace::square sq (a, b, c);
    sq.print();
    return 0;
}