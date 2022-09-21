/*********************************************************************
   PROGRAM:    NIUString.cpp
   PROGRAMMER: Fabian Hueramo
   LOGON ID:   z1857628
   DUE DATE:   2018-10-30

   FUNCTION:   Contains definitions for methods, constructors, and
	       functions of class NIUString
*********************************************************************/
#include "NIUString.h"
#include <string.h>

/**********************************************
default constructor

purpose:  initializes a new NIUString object
          to an empty string with a capacity of 0
*********************************************/
NIUString::NIUString()
    {
    strSize = 0;
    strCapacity = 0;
    strArray = nullptr;
    }


/**********************************************
constructor

purpose:    initializes a new NIUString object to
            C String other

*********************************************/
NIUString::NIUString(const char* other)
    {
    strSize = strlen(other);
    strCapacity = strSize;
    if(strCapacity ==0)
	{
	strArray = nullptr;
	}
    else
	{
	strArray = new char[strSize];
	for(size_t i=0; i < strSize; i++)
	    {
	    strArray[i] = other[i];
	    }
	}
    }


/**********************************************
another constructor

purpose:    initializes a new NIUString object to
            the same string as the existing
	    NIUString object other

*********************************************/
NIUString::NIUString(const NIUString& other)
    {
    strSize = other.size();
    strCapacity = other.strCapacity;
    if(strCapacity == 0)
	{
	strArray = nullptr;
	}
    else
	{
	strArray = new char[strCapacity];
	for(int i = 0; i < strSize; i ++)
	    {
	    strArray[i] = other[i];
	    }
	}
    }


/**********************************************

purpose:    calls the clear() method

*********************************************/
NIUString::~NIUString()
    {
    clear();
    }


/**********************************************
Overloaded assignment operator

purpose:    assigns NIUString object other to
	    object that called the function(this)

*********************************************/
NIUString& NIUString::operator=(const NIUString& other)
    {
    if(this != &other)
	{
	delete this->strArray;
	this->strSize = other.size();
	this->strCapacity = this->strSize;
	if(this->strCapacity == 0)
	    {
	    this->strArray = nullptr;
	    }
	else
	    {
	    this->strArray = new char[this->strCapacity];
	    for(int i = 0; i < this->strSize; i++)
		{
		this->strArray[i] = other[i];
	        }
	    }
	}
    return *this;
    }


/**********************************************
Overloaded assignment operator

purpose:    assigns C string other to an object
	    that called the method(this)

*********************************************/
NIUString& NIUString::operator=(const char* other)
    {
    delete this->strArray;
    this->strSize = strlen(other);
    this->strCapacity = this->strSize;
    if(this->strSize == 0)
	{
	this->strArray = nullptr;
	}
    else
	{
	this->strArray = new char[this->strCapacity];
	for(int i = 0; i < this->strSize; i++)
	    {
	    this->strArray[i] = other[i];
	    }
        }
        return *this;
    }


/**********************************************

purpose:    returns string capacity

*********************************************/
size_t NIUString::capacity()const
    {
    return strCapacity;
    }

/**********************************************

purpose:    returns string size

*********************************************/
size_t NIUString::size() const
    {
    return strSize;
    }

/*********************************************

purpose:    returns true if string size is 0

*********************************************/
bool NIUString::empty() const
    {
    if(strSize == 0)
        {
	return true;
	}
    return false;
    }

/**********************************************

purpose:    sets string size and capacity to 0
            and deletes the string array

*********************************************/
void NIUString::clear()
    {
    strSize = 0;
    strCapacity = 0;
    delete[]strArray;
    strArray = nullptr;
    }

/**********************************************

purpose:    modifies an objects string capacity
	    without changing its size or contents

*********************************************/
void NIUString::reserve(size_t n)
    {
    if((n < strSize) || (n == strCapacity))
	{
	return;
	}
    else
	{
        strCapacity = n;
        char* temp;
        if(strCapacity == 0)
	    {
	    temp = nullptr;
	    }
	else
	    {
	    temp = new char[strCapacity];
            for(int i = 0; i < strSize; i++)
	        {
	        temp[i] = strArray[i];
	        }
            delete this->strArray;
            strArray = new char[strCapacity];
	    strArray = temp;
            }
	}
    }

/**********************************************

purpose:    returns true if the characters stored
	    in string array of object that called
	    method are identical to characters
	    stored in string array of NIUString
	    object rhs

*********************************************/
bool NIUString::operator==(const NIUString& rhs) const
    {
    if(this->strSize != rhs.size())
	{
	return false;
	}
    else
	{
        for(int i = 0; i < this->strSize; i++)
            {
            if(this->strArray[i] != rhs[i])
	        {
	        return false;
	        }
	    }
	}
    return true;
    }

/*********************************************

purpose:    returns true if charaters stored
	    in string array of object that called
	    the method are identical to characaters
	    of C string pass in as rhs

*********************************************/
bool NIUString::operator==(const char* rhs) const
    {
    if(this->strSize != strlen(rhs))
	{
	return false;
	}
    else
	{
        for(int i = 0; i < this->strSize; i++)
	    {
	    if(this->strArray[i] != rhs[i])
	        {
	        return false;
	        }
	    }
	}
    return true;
    }

/**********************************************

purpose:    returns element pos of the string array

*********************************************/
const char& NIUString::operator[](size_t pos) const
    {
    return strArray[pos];
    }

/**********************************************
constructor

purpose:    returns element pos of the string array

*********************************************/
char& NIUString::operator[](size_t pos)
    {
    return strArray[pos];
    }
////////////////////////////////////////////////////////////////////////////////
//
//FRIEND DEFINITIONS
//
///////////////////////////////////////////////////////////////////////////////
/**********************************************

purpose:    loops through characters of the string
	    array of teh NIUString object passed in
	    as rhs and print them one at a time using
	    stream object passed in as lhs

*********************************************/
std::ostream& operator<<(std::ostream& lhs, const NIUString& rhs)
    {
    for(int i = 0; i < rhs.size(); i++)
	{
	lhs << rhs[i];
	}
    return lhs;
    }

/**********************************************

purpose:    should return true if the characters of
	    the C string passed in as lhs are identical
	    to the characters stored in the string
	    array of the NIUString object passed in as rhs

*********************************************/
bool operator==(const char* lhs, const NIUString& rhs)
    {
    if(strlen(lhs) != rhs.size())
	{
	return false;
	}
    else
	{
        for(int i = 0; i < rhs.size(); i++)
	    {
	    if(lhs[i] != rhs[i])
	        {
	        return false;
	        }
	    }
	}
    return true;
    }

