/*********************************************************************
   PROGRAM:    Stack.h
   PROGRAMMER: Fabian Hueramo
   LOGON ID:   Z1857628
   DUE DATE:   11-20-19

   FUNCTION:   Header file for Stack class
*********************************************************************/
#ifndef STACK_H
#define STACK_H

#include <iostream>

//Struct Node
template <class T>
struct Node
    {
    T data;
    Node<T>* next;

    Node(const T& = T(), Node<T>* next = nullptr);
    };

//Struct Node Method definition
template <class T>
Node<T>::Node(const T& data, Node* next)
    {
    this->data = data;
    this->next = next;
    }

//Forward decleartion of the Stack template class
template <class T>
class Stack;

//Forward decleration of the operator << template function
template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);


template <class T>
class Stack
    {

    //friend decleration for template function
    friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);

    private:

	Node<T>* stkTop;                        //Points to first node in list
	size_t stkSize;				//Number of items stored in stack
	void copyList(const Stack<T>& other);   //Makes copy of linked list

    public:

	Stack();                                        //Default constructor
	~Stack();					//Destructor
	Stack(const Stack& other);			//Copy Constructor
	Stack<T>& operator=(const Stack<T>& other);	//Assignment operator

	void clear();                   //Sets stack to empty state
	size_t size() const;		//Returns stack size
	bool empty() const;		//Checks if stack is empty
	const T& top() const;		//Returns data stored in top node of stack
	void push(const T&);		//Inserts item at top of stack
	void pop();			//Removes node at top of stack
    };

//****************************************
//Function: Default constructor
//
//Purpose:  Sets stkTop to nullptr and
//	    stkSize to 0
//***************************************/
template <class T>
Stack<T>::Stack()
    {
    stkTop = nullptr;
    stkSize = 0;
    }

//****************************************
//Function: Destructor
//
//Purpose:  Calls clear method
//***************************************/
template <class T>
Stack<T>::~Stack()
    {
    clear();
    }

//****************************************
//Function: Copy Constructor
//
//Purpose:  Copies data from other
//***************************************/
template <class T>
Stack<T>::Stack(const Stack& other)
    {
    stkTop = nullptr;
    copyList(other);
    stkSize = other.stkSize;
    }

//****************************************
//Function: Copy Assignment Operator
//
//Purpose:  Overladed assignemet operator
//***************************************/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
    {
    if(this != &other)
	{
	clear();
	copyList(other);
	stkSize = other.stkSize;
	}
    return *this;
    }

//****************************************
//Function: Output operator
//
//Purpose:  Stack sent to standard output
//***************************************/
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs)
    {
    Node<T>* ptr;
    for(ptr = rhs.stkTop; ptr != nullptr; ptr = ptr->next)
	lhs << ptr->data << ' ';
    return lhs;
    }

//****************************************
//Function: Clear
//
//Purpose:  Sets stack back to empty state
//***************************************/
template <class T>
void Stack<T>::clear()
    {
    while(!empty())
        {
	pop();
	}
    }

//****************************************
//Function: size
//
//Purpose:  Returns size of stack
//***************************************/
template <class T>
size_t Stack<T>::size() const
    {
    return stkSize;
    }

//****************************************
//Function: Output operator
//
//Purpose:  Stack sent to standard output
//***************************************/
template <class T>
bool Stack<T>::empty() const
    {
    if(stkSize == 0)
	return true;
    else
	return false;
    }

//****************************************
//Function: top
//
//Purpose:  Returns data stored in top node
//	    of stack
//***************************************/
template <class T>
const T& Stack<T>::top() const
    {
    if(stkSize == 0)
	throw std::underflow_error("Stack undeflow on call to top()");

    return stkTop->data;
     }

//****************************************
//Function: push
//
//Purpose:  inserts item at top of stack
//***************************************/
template <class T>
void Stack<T>::push(const T& val)
    {
    Node<T>* newNode = new Node<T>(val, stkTop);

    stkTop = newNode;
    ++stkSize;
    }

//****************************************
//Function: pop
//
//Purpose:  Removes node at top of stack
//***************************************/
template <class T>
void Stack<T>::pop()
    {
    if(empty())
	throw std::underflow_error("Stack underflow on call to pop()");

    Node<T>* delNode = stkTop;
    stkTop = stkTop->next;

    delete delNode;
    --stkSize;
    }

//****************************************
//Function: copyList
//
//Purpose:  makes copy of linked list
//***************************************/
template <class T>
void Stack<T>::copyList(const Stack<T>& other)
    {
    Node<T>* ptr, * newNode, * last = nullptr;

    for(ptr = other.stkTop; ptr != nullptr; ptr = ptr-> next)
	{
	newNode = new Node<T>(ptr->data);

	if(last == nullptr)
	    stkTop = newNode;
	else
	    last->next = newNode;

	last = newNode;
	}
    }

    #endif
