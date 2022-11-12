#pragma once
#include <iostream>
#include <cmath>

struct Centre
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

class Shape
{
public:
    Centre centreShape;
    Color colorShape;
    void colorCentre();
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle();

    void Square();

    void desShape();
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle();

    void Square();

    void desShape();

};

class Square : public Shape {
private:
    double edge;
public:

    Square ();

    void SquareS();

    void desShape();

};

class Triangle : public Shape {
private:
    double edge;
public:

    Triangle ();

    void Square();

    void desShape();

};





