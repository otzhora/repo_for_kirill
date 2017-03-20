//
// Created by yriy on 21.03.17.
//

#ifndef KIRILL_LABA_1_TYPES_H
#define KIRILL_LABA_1_TYPES_H

//#include "func.h"

struct Point {
    double x;
    double y;

};

class equa
{
public:
    equa();

    equa(const Point& a, const Point& b);

    // debugg fund
    void print();

    double lenght();

    friend bool ortogonal(const equa& a, const equa& b);
private:
    double k;

    double b;

    double len;

    bool vert;
};

namespace square_namespace
{
    class square
    {
    public :

        square();

        // I assume that the points are given in order of bypass
        square(Point a1, Point a2, Point a3);

        ~square();

        void print();

    private:
        Point* points;
    };


}



#endif //KIRILL_LABA_1_TYPES_H
