#pragma once
#ifndef _LIST_TEMPLATE_H
#define _LIST_TEMPLATE_H


template <typename T>
class List
{
public:
    List();
    ~List();

    T&   operator [](const int index);  // overload operator [] (get pointer)

    void push_front (T data);            // add item at the begin
    void insert     (T data, int index); // add item by index
    void push_back  (T data);            // add item to the end

    void pop_front  ();	                 // delete first item
    void removeAt   (int index);         // delete item by index
    void pop_back   ();                  // delete item to the end

    void clear();                        // remove all list

    int  GetSize() {return Size;}        // get the number of items in a list

private:
    template <typename T>
    class Node
    {
    public:
       Node * pNext;
       T data;
       Node(T data = T(), Node * pNext = nullptr)
       {
           this -> data  = data;
           this -> pNext = pNext;
       }
    };
    int Size;
    Node <T> * head;
};

#endif // _LIST_TEMPLATE_H
