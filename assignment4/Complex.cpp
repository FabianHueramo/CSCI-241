//*****************************************************************
// FILE:      Complex.cpp
// AUTHOR:    Fabian Hueramo
// LOGON ID:  Z1857628
// DUE DATE:  2018-10-22
//
// PURPOSE:   Contains definitions for Complex class
//*****************************************************************/
#include "Complex.h"

//Sets real and imaginary values to new values
Complex::Complex(double newReal, double newImaginary)
    {
    this->a = newReal;
    this->b = newImaginary;
    }

//Assigns method parameters to corresonding data members
void Complex::setComplex(double newReal, double newImaginary)
    {
    this->a = newReal;
    this->b = newImaginary;
    }

//Gets real and imaginary parts of object that called the function
void Complex::getComplex(double& real, double& imaginary) const
    {
    real = this->a;
    imaginary = this->b;
    }

//Assigns real part to value of newReal
void Complex::setRealPart(double newReal)
    {
    this->a = newReal;
    }

//Returns real part
double Complex::getRealPart() const
    {
    return a;
    }

//Assigns imaginary part to value newImaginary
void Complex::setImaginaryPart(double newImaginary)
    {
    this->b = newImaginary;
    }

//Returns imaginary part
double Complex::getImaginaryPart() const
    {
    return b;
    }

//Adds real parts together and imaginary parts together
Complex Complex::operator+(const Complex &rhs) const
    {
    Complex result;
    result =((this->a + rhs.a),(this->b + rhs.b));

    return result;
    }

//Multiplies real parts together and imaginary parts together
Complex Complex::operator*(const Complex &rhs) const
    {
    Complex result;
    result = ((this->a * rhs.a),(this->b * rhs.b));

    return result;
    }

//Checks if real parts match and imaginary parts match
bool Complex::operator==(const Complex &rhs) const
    {
    return (this->a == rhs.a && this->b == rhs.b);
    }

//Prints a Complex object as an ordered pair
std::ostream& operator<<(std::ostream &stream, const Complex &complx)
    {
    stream  << "(" << complx.a << " ," << complx.b << ")";
    return stream;
    }

//Reads input entered by user as an ordered pair
std::istream& operator>> (std::istream &lhs, Complex &rhs)
    {
    char temp;	/* Temporary placeholder to consume unwanted chars */

    lhs >> temp;
    lhs >> rhs.a;
    lhs >> temp;
    lhs >> rhs.b;
    lhs >> temp;

    return lhs;
    }
