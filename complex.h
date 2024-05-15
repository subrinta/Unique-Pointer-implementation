#pragma once
#include <iostream>

class complex
{
private:
    int _real;
    int _img;
public:
    complex(int a, int b) : _real(a), _img(b) {};
    friend std::ostream & operator<< (std::ostream & out, const complex & c);
    int real() const { return _real; }
    int img() const {return _img; }
};

std::ostream & operator<< (std::ostream & out, const complex & c)
{
    out << c._real << " + i" << c._img;
    return out;
}