//*****************************************************************
// FILE:      NIUString.h
// AUTHOR:    Fabian Hueramo
// LOGON ID:  Z1857628
// DUE DATE:  2018-10-30
//
// PURPOSE:   Contains declarations of NIUString class
//*****************************************************************
#ifndef NIUSTRING_H
#define NIUSTRING_H
#include <iostream>

class NIUString
    {
    //friend declerations
    friend std::ostream& operator<<(std::ostream& lhs, const NIUString& rhs);
    friend bool operator==(const char* lhs, const NIUString& rhs);

    private:
        char* strArray = nullptr;  //used to allocate array of char
	size_t strCapacity = 0;    //traks number of elements in string array
	size_t strSize;            //stores current length of Cstring stored in strArray

    public:
	//constructers
	NIUString();
	NIUString(const char*);
	NIUString(const NIUString&);

	//methods
	~NIUString();
	NIUString& operator=(const NIUString&);
	NIUString& operator=(const char*);
	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	void clear();
	void reserve(size_t n);
	bool operator==(const NIUString&) const;
	bool operator==(const char*) const;
	const char& operator[](size_t) const;
	char& operator[](size_t);
    };

#endif
