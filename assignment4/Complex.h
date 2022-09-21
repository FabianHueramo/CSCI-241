/************************************************************
  Program:	Complex.h
  Name:		Fabian Hueramo
  ZID:		Z1857628
  Due Date:	2018-10-22
  Function:	Header file for Complex class
************************************************************/

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>


class Complex
    {
    //friend declerations
    friend std::ostream &operator << (std::ostream &, const Complex &);
    friend std::istream &operator >> (std::istream &, Complex &);

    private:
        double a;  //real part
        double b;  //imaginary part

    public:
        Complex(double = 0, double = 0);
        void setComplex(double, double);
        void getComplex(double& , double&) const;
        void setRealPart(double);
        double getRealPart() const;
        void setImaginaryPart(double);
        double getImaginaryPart() const;
        Complex operator+ (const Complex &) const;
        Complex operator* (const Complex &) const;
        bool operator== (const Complex &) const;
    };
#endif
