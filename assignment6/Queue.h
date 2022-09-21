/************************************************************
  Program:	Queue.h
  Name:		Fabian Hueramo
  ZID:		Z1857628
  Due Date:	2018-11-14
  Function:	Header file for Queue class
************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <class T>
class Queue;

//friend prototype
template <class T>
std::ostream&operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
    {

    //friend declerations
    friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

    private:
        int qFront = 0;     //element at front of queue
	int qBack = 0;      //element at back of queue
	T* qArray;          //points to first element of array
	size_t qSize;       //size of queue
	size_t qCapacity;   //capacity of queue

    public:
	Queue();                       		//default constructor
	~Queue();	 			//destructor
	Queue(const Queue<T>& other);		//copy constructor
	Queue<T>& operator=(const Queue<T>&);   //copy assignment operator

	void clear();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;

	const T& front() const;
	const T& back() const;

	void push(const T&);
	void pop();

	void reserve(size_t);


    };

//*********************************************
//Default Constructer
//
//Purpose: declares new Queue class object
//*********************************************/
template <class T>
Queue<T>::Queue()
    {
    qCapacity = 0;
    qSize = 0;
    qArray = nullptr;
    qFront = 0;
    qBack = qCapacity - 1;
    }

//*********************************************
//Destructor
//
//Purpose: deletes qArray
//*********************************************/
template <class T>
Queue<T>::~Queue()
    {
    delete[] qArray;
    }

//*********************************************
//Function: Copy Contructor
//
//Purpose:  Assigns a new Queue class object
//	    to other
//*********************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
    {
    this->qCapacity = other.qCapacity;
    this->qSize = other.qSize;
    this->qArray = new T[qCapacity];

    for(size_t i = 0; i < qCapacity; ++i)
	this->qArray[i] = other.qArray[i];

    this->qFront = other.qFront;
    this->qBack = other.qBack;
    }

//*********************************************
//
//Copy Assigment Operator
//
//*********************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
    {
    if(this != &rhs)
	{
	delete[] qArray;
	qSize = rhs.qSize;
	qCapacity = rhs.qCapacity;
	qFront = rhs.qFront;
	qBack = rhs.qBack;

        qArray = new T[qCapacity];
	for(size_t i=0; i < qCapacity; ++i)
	    {
            qArray[i] = rhs.qArray[i];
            }
	}
    return *this;
    }

//*********************************************
//Function: reserve
//
//Purpose:  reserves additional capacity
//	    for que array
//*********************************************/
template <class T>
void Queue<T>::reserve(size_t val)
    {
    if(val < qSize || val == qCapacity)
	return;

    T* tempArray = new T[val];

    int current = qFront;
    for(size_t i = 0; i < qSize; i++)
	{
	tempArray[i] = qArray[current];
	current = (current + 1) % qCapacity;
	}

    qCapacity = val;
    qFront = 0;
    qBack = qSize - 1;
    delete[] qArray;
    qArray = tempArray;
    }
//*********************************************
//Function: clear()
//
//Purpose: clears the data members of class object
//********************************************/
template <class T>
void Queue<T>::clear()
    {
    qSize = 0;
    qFront = 0;
    qBack = qCapacity - 1;
    }

//*********************************************
//Function: size()
//
//Purpose: return qSize
//*********************************************/
template <class T>
size_t Queue<T>::size() const
    {
    return qSize;
    }

//*********************************************
//Function: capacity()
//
//Purpose:  return capacity
//*********************************************/
template <class T>
size_t Queue<T>::capacity() const
    {
    return qCapacity;
    }

//*********************************************
//Function: empty()
//
//Purpose:  checks if queue is empty
//*********************************************/
template <class T>
bool Queue<T>::empty() const
    {
    if(qSize == 0)
	return true;
    else
        return false;
    }

//*********************************************
//Function: front()
//
//Purpose:  returns element at front of queue
//*********************************************/
template <class T>
const T& Queue<T>::front() const
    {
    if(empty())
	throw std::underflow_error("Queue underflow on call to front()");
    else
	return qArray[qFront];
    }

//*********************************************
//Function: back()
//
//Purpose:  returns elememt at back of queue
//*********************************************/
template <class T>
const T& Queue<T>::back() const
    {
    if(empty())
	throw std::underflow_error("Queue underflow on call to back()");
    else
	return qArray[qBack];
   }

//*********************************************
//Function: push()
//
//Purpose:  inserts an item at front of stack
//*********************************************/
template <class T>
void Queue<T>::push(const T& val)
    {
    if(qSize == qCapacity)
	{
	if(qCapacity == 0)
	    reserve(1);
	else
	    reserve(qCapacity * 2);
	}
    qBack = (qBack + 1) % qCapacity;
    qArray[qBack] = val;
    ++qSize;
    }

//*********************************************
//Function: pop()
//
//Purpose:  removes item at front of queue
//*********************************************/
template <class T>
void Queue<T>::pop()
    {
    if(empty())
	throw std::underflow_error("Queue underflow on call to pop()");

    qFront = (qFront + 1) % qCapacity;
    --qSize;
    }

//*********************************************
//Function: operator<<
//
//Purpose:  prints queue on standard output
//*********************************************/
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs)
    {
    size_t current, i;

    for(current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
	{
	lhs << rhs.qArray[current] << ' ';
	current =(current + 1) % rhs.qCapacity;
	}
    return lhs;
    }



#endif
