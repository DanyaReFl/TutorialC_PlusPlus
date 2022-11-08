#pragma once
#include <iostream>
#include <cmath>

struct centre
{
    double x;
    double y;
};
enum Color
{
    none ,
    red ,
    orange ,
    yellow ,
    green ,
    cyan ,
    blue ,
    purple
};

class shape
{
public:
    centre centreShape;
    Color colorShape;
    void colorCentre();
};

class circle : public shape {
private:
    double radius;
public:
    circle();

    void Square();

    void desShape();
};

class rectangle : public shape {
private:
    double width;
    double height;
public:
    rectangle();

    void Square();

    void desShape();

};

class square : public shape {
private:
    double edge;
public:

    square ();

    void Square();

    void desShape();

};

class triangle : public shape {
private:
    double edge;
public:

    triangle ();

    void Square();

    void desShape();

};





