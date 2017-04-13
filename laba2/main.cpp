#include <iostream>
#include "class.h"
using namespace std;


int main() {
    String s1;
    s1.print();
    s1.strcpy_("lalalala");
    s1.print();
    String s2(s1);
    s2.print();
    String s3(5);
    s3.print();
    cout << s2[1] << endl;
    s2+=3;
    s2.print();
    String s4;
    s4 = s1 + s2;
    s4.print();
    return 0;
}