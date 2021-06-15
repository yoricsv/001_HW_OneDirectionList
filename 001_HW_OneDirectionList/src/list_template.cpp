#include "list_template.h"

// CONCTRUCTOR //
template <typename T>
List <T>::List()
{
    Size = 0;
    head = nullptr;
}

// DISTRUCTOR //
template <typename T>
List <T>::~List()
{
    clear();
}

// SQUARE BRACKET [] OPERATOR OVERLOAD ()
template <typename T>
T & List <T>::operator [] (const int index)
{
    int counter = 0;
    Node <T> * current = this -> head;
    while (current != nullptr)
    {
        if (counter == index)
            return current -> data;
        current = current -> pNext;
        counter++;
    }
}

// ADD ITEM AT THE BEGIN //
template <typename T>
void List <T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}









// add item by index
template <typename T>
void List <T>::insert(T data, int index)
{
    if (index == 0)
        push_front(data);
    else
    {
        Node <T> * previous = this -> head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->pNext;
        Node <T> * newNode = new Node <T>(data, previous -> pNext);
        previous -> pNext = newNode;
        Size++;
    }
}

// add item to the end
template <typename T>
void List <T>::push_back(T data)
{
    if (head == nullptr)
        head = new Node <T>(data);
    else
    {
        Node <T> * current = this -> head;
        while (current -> pNext != nullptr)
            current = current -> pNext;
        current -> pNext = new Node <T>(data);
    }
    Size++;
}

// delete first item
template <typename T>
void List <T>::pop_front()
{
    Node <T> * temp = head;
    head = head -> pNext;
    delete temp;
    Size--;
}
// delete item by index
template <typename T>
void List <T>::removeAt(int index)
{
    if (index == 0)
        pop_front();
    else
    {
        Node <T> * previous = this -> head;
        for (int i = 0; i < index - 1; i++)
            previous = previous->pNext;
        Node <T> * toDelete = previous -> pNext;
        previous -> pNext = toDelete -> pNext;
        delete toDelete;
        Size--;
    }
}
// delete item to the end
template <typename T>
void List <T>::pop_back()
{
    removeAt(Size - 1);
}
// remove all list
template <typename T>
void List <T>::clear()
{
    while (Size)
        pop_front();
}

// GET THE NUMBER OF ITEMS IN A LIST //
int  GetSize()
{
    return Size;
}
