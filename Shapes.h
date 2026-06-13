#pragma once
#define _USE_MATH_DEFINES
#include <string>
#include <cmath>
using namespace std;

class Shape3D {
protected:
    wstring name;
public:
    Shape3D() : name(L"Shape3D") {}
    Shape3D(const wstring& n) : name(n) {}
    Shape3D(const Shape3D& other) : name(other.name) {}
    virtual double volume() const = 0;
    wstring getName() const { return name; }
    virtual wstring toString() const {
        return name + L": об'єм = " + to_wstring(volume());
    }
    virtual ~Shape3D() {}
};

class Sphere : public Shape3D {
private:
    double radius;
public:
    Sphere() : Shape3D(L"Куля"), radius(0) {}
    Sphere(double r) : Shape3D(L"Куля"), radius(r) {}
    Sphere(const Sphere& other) : Shape3D(other), radius(other.radius) {}
    double volume() const override {
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }
    wstring toString() const override {
        return name + L" (r=" + to_wstring(radius) + L"): об'єм = " + to_wstring(volume());
    }
};

class Box : public Shape3D {
private:
    double a, b, c;
public:
    Box() : Shape3D(L"Паралелепіпед"), a(0), b(0), c(0) {}
    Box(double a_, double b_, double c_) : Shape3D(L"Паралелепіпед"), a(a_), b(b_), c(c_) {}
    Box(const Box& other) : Shape3D(other), a(other.a), b(other.b), c(other.c) {}
    double volume() const override {
        return a * b * c;
    }
    wstring toString() const override {
        return name + L" (" + to_wstring(a) + L"x" + to_wstring(b) + L"x" + to_wstring(c) + L"): об'єм = " + to_wstring(volume());
    }
};

class Cone : public Shape3D {
private:
    double radius, height;
public:
    Cone() : Shape3D(L"Конус"), radius(0), height(0) {}
    Cone(double r, double h) : Shape3D(L"Конус"), radius(r), height(h) {}
    Cone(const Cone& other) : Shape3D(other), radius(other.radius), height(other.height) {}
    double volume() const override {
        return (1.0 / 3.0) * M_PI * radius * radius * height;
    }
    wstring toString() const override {
        return name + L" (r=" + to_wstring(radius) + L", h=" + to_wstring(height) + L"): об'єм = " + to_wstring(volume());
    }
};

class Cylinder : public Shape3D {
private:
    double radius, height;
public:
    Cylinder() : Shape3D(L"Циліндр"), radius(0), height(0) {}
    Cylinder(double r, double h) : Shape3D(L"Циліндр"), radius(r), height(h) {}
    Cylinder(const Cylinder& other) : Shape3D(other), radius(other.radius), height(other.height) {}
    double volume() const override {
        return M_PI * radius * radius * height;
    }
    wstring toString() const override {
        return name + L" (r=" + to_wstring(radius) + L", h=" + to_wstring(height) + L"): об'єм = " + to_wstring(volume());
    }
};

class ShapeContainer {
private:
    Shape3D** items;
    int count;
    int capacity;
public:
    ShapeContainer() : items(nullptr), count(0), capacity(0) {}

    void add(Shape3D* shape) {
        if (count == capacity) {
            int newCapacity = (capacity == 0) ? 4 : capacity * 2;
            Shape3D** newItems = new Shape3D * [newCapacity];
            for (int i = 0; i < count; i++)
                newItems[i] = items[i];
            delete[] items;
            items = newItems;
            capacity = newCapacity;
        }
        items[count++] = shape;
    }

    wstring getAllInfo() const {
        wstring result;
        for (int i = 0; i < count; i++) {
            result += to_wstring(i + 1) + L") " + items[i]->toString() + L"\r\n";
        }
        return result;
    }

    int getCount() const { return count; }

    Shape3D* findMinVolume() const {
        if (count == 0) return nullptr;
        Shape3D* minShape = items[0];
        for (int i = 1; i < count; i++) {
            if (items[i]->volume() < minShape->volume())
                minShape = items[i];
        }
        return minShape;
    }

    ~ShapeContainer() {
        for (int i = 0; i < count; i++)
            delete items[i];
        delete[] items;
    }
};
