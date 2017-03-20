//
// Created by yriy on 21.03.17.
//

#include "types.h"
#include "func.h"
#include <iostream>
#include <cmath>
using namespace std;

equa::equa(): k(0), b(0), len(0), vert(false) {}

equa::equa(const Point &a, const Point &b) {
    if((b.x - a.x) == 0)
        vert = true;
    this->k = (b.y - a.y) / (b.x - a.x);
    this->b = b.y - this->k * b.x;
    this->len = sqrt((b.x-a.x)*(b.x-a.x) + (b.y - a.y)*(b.y - a.y));
}

void equa::print() {
    cout << "k: " << k << " b: " << b << " len: " << len << endl;
}

double equa::lenght() {
    return len;
}

bool ortogonal(const equa& a, const equa& b)
{
    if(a.k * b.k == -1 || (a.vert && b.k == 0) || (b.vert && a.k == 0))
        return true;
    return false;
}

square_namespace::square::square() {
    points = new Point[3];
}

square_namespace::square::square(Point a1, Point a2, Point a3) {
    equa u1(a1, a2), u2(a2, a3);
    if (u1.lenght() == u2.lenght() && ortogonal(u1, u2))
    {
        this->points = new Point[3];
        this->points[0] = a1;
        this->points[1] = a2;
        this->points[2] = a3;
        cout << "correct square" << endl;
    } else{
        this->points = new Point[3];
        this->points[0] = Point();
        this->points[1] = Point();
        this->points[2] = Point();
        cout << "THIS SQUARE DOES NOT EXIST!!!!" << endl;
    }

}

void square_namespace::square::print() {
    for(int i = 0; i < 3; i++)
        cout << "point " << i + 1 << " " << points[i].x << " " << points[i].y << endl;
}

square_namespace::square::~square() {
    delete points;
}