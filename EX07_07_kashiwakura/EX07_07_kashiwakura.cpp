#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
using namespace std;

class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};

class Box :Solid {
private:
    double width;
    double height;
    double depth;
public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetWidth() {
        return width;
    }
    double GetHeight() {
        return height;
    }
    double GetDepth() {
        return depth;
    }
    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }
};

class Cylinder :Solid {
private:
    double radius;
    double height;
public:
    Cylinder(
        double radius,   //底辺の半径
        double height) { //高さ
        this->radius = radius;
        this->height = height;
    }
    double GetRadius() {
        return radius;
    }
    double GetHeight() {
        return height;
    }
    double GetSurface()
    {
        return radius * 2.0f * M_PI * height + radius * radius * M_PI * 2.0f;
    }
    double GetVolume()
    {
        return radius * radius * M_PI * height;
    }
};

class Cone :Solid {
private:
    double bottom;
    double height;
public:
    Cone(
        double bottom,   //底辺の半径
        double height) { //高さ
        this->bottom = bottom;
        this->height = height;
    }
    double GetBottom() {
        return bottom;
    }
    double GetHeight() {
        return height;
    }
    double GetSurface()
    {
        return M_PI * bottom * (sqrt(pow(height, 2.0f) + pow(bottom, 2.0f)) + bottom);
    }
    double GetVolume()
    {
        return bottom * bottom * M_PI * height / 3.0f;
    }
};

class Sphere :Solid {
private:
    double radius;
public:
    Sphere(
        double bottom) { //半径
        this->radius = bottom;
    }
    double GetRadius() {
        return radius;
    }
    double GetSurface()
    {
        return 4.0f * M_PI * radius * radius;
    }
    double GetVolume()
    {
        return (4.0f / 3.0f) * M_PI * radius * radius * radius;
    }
};

int main()
{
    Box box{ 5,4,3 };
    Cylinder cylinder{ 3,10 };
    Cone cone{ 5,10 };
    Sphere sphere{ 5 };
    cout << "Boxの体積 = " << box.GetVolume() << endl;
    cout << "Boxの表面積 = " << box.GetSurface() << endl;
    cout << "Cylinderの体積 = " << cylinder.GetVolume() << endl;
    cout << "Cylinderの表面積 = " << cylinder.GetSurface() << endl;
    cout << "Coneの体積 = " << cone.GetVolume() << endl;
    cout << "Coneの表面積 = " << cone.GetSurface() << endl;
    cout << "Sphereの体積 = " << sphere.GetVolume() << endl;
    cout << "Sphereの表面積 = " << sphere.GetSurface() << endl;
}
