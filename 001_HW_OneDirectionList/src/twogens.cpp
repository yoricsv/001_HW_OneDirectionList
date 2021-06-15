#include <iostream>

using namespace std;

template <typename T>                                                       //*// template <typename T>
class List                                                                  //*// class List
{                                                                           //*// {
private:                                                                    //*// private:
    // Объявление структуры узла для использования в классе Iterator
                                                                            //*//   template <typename T>
    struct Node                 // Структура узла односвязного списка       //*//   class Node
    {                                                                       //*//   {
                                                                            //*//   public:
        T m_t;                  // Значение узла                            //*//       T data;
        Node* m_next;           // Указатель на следующий узел              //*//       Node * pNext;

        Node() : m_next(NULL)   // Конструктор узла                         //*//       Node(T data = T(), Node * pNext = nullptr)
        {                                                                   //*//       {
                                                                            //*//           this -> data  = data;
                                                                            //*//           this -> pNext = pNext;
        }                                                                   //*//       }
        Node(const T& t) : m_t(t), m_next(NULL) {}
    };                                                                      //*//   };

                                                                            //*// 	int Size;
    Node * m_head;              // Голова односвязного списка               //*// 	Node <T> * head;

    class Iterator              // Класс итератора односвязного списка
    {
    private:
        Node * current;
    public:
        Iterator(Node * node) : current(node){}

        bool operator == (const Iterator & other) const // Проверка на равенство
        {
            if(this == & other)
                return true;
            return current == other.current;
        }
        bool operator != (const Iterator & other) const // Проверка на неравенство
        {
            return !operator == (other);
        }

        T operator * () const                           // Получение значения текущего узла
        {
            if(current)
                return current -> m_t;
            return T();
        }                                               // Иначе достигнут конец списка. Уместно возбудить исключение
            void operator ++ ()                         // Переход к следующему узлу
            {
                if(current)
                    current = current -> m_next;
            }                                           // Иначе достигнут конец списка. Уместно возбудить исключение
     };

public:                                                                     //*//   public:
    List();                       // Конструктор списка                     //*//       List();
    ~List();                      // Диструктор списка                      //*//       ~List();

                                                                            //*//       T&   operator [](const int index);  // перегруженный []

                                                                            //*//       void push_front(T data);        // добавление в начало
                                                                            //*//       void insert(T data, int index); // добавление по индексу
    void     append( const T& t); // Добавление узла в список               //*//       void push_back(T data);         // добавление в конец

                                                                            //*//       void pop_front();               // удаление первого
                                                                            //*//       void removeAt(int index);       // удаление по индексу
    void     remove();            // Удаление последнего узла из списка     //*//       void pop_back();                // удаление последнего
                                                                            //*//       void clear();                   // очистить список

    T        head()  const;       // Получить головной элемент списка
    Iterator begin() const;       // Получить итератор на начало списка
    Iterator end()   const;       // Получить итератор на конец списка

    size_t   size()  const;       // Получить размер списка                 //*//       int GetSize(){return Size;} // получить количество елементов
};                                                                          //*//   };



template <typename T>                                                       //*//   template <typename T>
List <T>::List() : m_head(NULL)                                             //*//   List <T>::List()
{                                                                           //*//   {
                                                                            //*//   	Size = 0;
                                                                            //*//   	head = nullptr;
}                                                                           //*//   }

template <typename T>                                                       //*//   template <typename T>
List <T>::~List()                                                           //*//   List <T>::~List()
{                                                                           //*//   {
    while(m_head)
        remove();                                                           //*//   	clear();
}                                                                           //*//   }


                                                                            //*//   template <typename T>
                                                                            //*//   T & List <T>::operator [] (const int index)
                                                                            //*//   {
                                                                            //*//   	int counter = 0;
                                                                            //*//   	Node <T> * current = this -> head;
                                                                            //*//   	while (current != nullptr)
                                                                            //*//   	{
                                                                            //*//   		if (counter == index)
                                                                            //*//   			return current -> data;
                                                                            //*//   		current = current -> pNext;
                                                                            //*//   		counter++;
                                                                            //*//   	}
                                                                            //*//   }

                                                                            //*//   template <typename T>
                                                                            //*//   void List <T>::push_front(T data)
                                                                            //*//   {
                                                                            //*//   	head = new Node<T>(data, head);
                                                                            //*//   	Size++;
                                                                            //*//   }

                                                                            //*//   template <typename T>
                                                                            //*//   void List <T>::insert(T data, int index)
                                                                            //*//   {
                                                                            //*//   	if (index == 0)
                                                                            //*//   		push_front(data);
                                                                            //*//   	else
                                                                            //*//   	{
                                                                            //*//   		Node <T> * previous = this -> head;
                                                                            //*//   		for (int i = 0; i < index - 1; i++)
                                                                            //*//   			previous = previous->pNext;
                                                                            //*//   		Node <T> * newNode = new Node <T>(data, previous -> pNext);
                                                                            //*//   		previous -> pNext = newNode;
                                                                            //*//   		Size++;
                                                                            //*//   	}
                                                                            //*//   }

template <typename T>                                                                           //*//   template <typename T>
void List <T>::append(const T &t)   // Не забудем проверить, что память удалось выделить        //*//   void List <T>::push_back(T data)
{                                                                                               //*//   {
                                                                                                //*//       if (head == nullptr)
    if(Node * node = new Node(t))   // Создаем новый узел для значения                          //*//           head = new Node <T>(data);
                                                                                                //*//       else
    {                                                                                           //*//       {
                                                                                                //*//           Node <T> * current = this -> head;
                                                                                                //*//           while (current -> pNext != nullptr)
        node -> m_next = m_head;    // Новый узел привязывается к старому головному элементу    //*//               current = current -> pNext;
        m_head = node;              // Новый узел сам становится головным элементом             //*//           current -> pNext = new Node <T>(data);
    }                                                                                           //*//       }
                                                                                                //*//       Size++;
}                                                                                               //*//   }
                                                                                                //*//   template <typename T>
                                                                                                //*//   void List <T>::pop_front()
                                                                                                //*//   {
                                                                                                //*//       Node <T> * temp = head;
                                                                                                //*//       head = head -> pNext;
                                                                                                //*//       delete temp;
                                                                                                //*//       Size--;
                                                                                                //*//   }

                                                                                                //*//   template <typename T>
                                                                                                //*//   void List <T>::removeAt(int index)
                                                                                                //*//   {
                                                                                                //*//       if (index == 0)
                                                                                                //*//           pop_front();
                                                                                                //*//       else
                                                                                                //*//       {
                                                                                                //*//           Node <T> * previous = this -> head;
                                                                                                //*//           for (int i = 0; i < index - 1; i++)
                                                                                                //*//               previous = previous->pNext;
                                                                                                //*//          Node <T> * toDelete = previous -> pNext;
                                                                                                //*//          previous -> pNext = toDelete -> pNext;
                                                                                                //*//          delete toDelete;
                                                                                                //*//           Size--;
                                                                                                //*//       }
                                                                                                //*//   }








template <typename T>                                                                       //*//   template <typename T>
void List <T>::remove()                                                                     //*//   void List <T>::pop_back()
{                                                                                           //*//   {
    if(m_head)                          // Если список не пуст:
    {
        Node* newHead = m_head->m_next; // Сохраняем указатель на новый узел, станет новым
        delete m_head;                  // Освобождаем память, для удаляемого узла          //*//       removeAt(Size - 1);
        m_head = newHead;               // Назначаем новый головной элемент
    }                                   // Иначе могли бы возбудить исключение
}                                                                                           //*//   }


                                                                                            //*//   template <typename T>
                                                                                            //*//   void List <T>::clear()
                                                                                            //*//   {
                                                                                            //*//       while (Size)
                                                                                            //*//           pop_front();
                                                                                            //*//   }


template <typename T>
typename List <T>::Iterator List <T>::begin() const
{
    return Iterator(m_head);      // Итератор пойдет от головного элемента...
}

template <typename T>
typename List <T>::Iterator List <T>::end() const
{
    return Iterator(NULL);        // ... и до упора, т.е. NULL
}


template <typename T>
size_t List <T> ::size() const
{
    size_t s = 0;
    for(Iterator it = begin(); it != end(); ++it)
        ++s;
//    for(Node * n = m_head; n != NULL; n = n -> m_next)   // Но можно и без итераторов
//        ++s;
    return s;
}




//// DEFINE CLASS LIST BEGIN //
//class List
//{
//private:
//    // head of list (pointer to first Node)
//    struct Node;
//    Node * head;
//    // type of data contain in list
//    int  * data;
//public:
//    // CONSTRUCTOR BEGIN //
//    List(int value)
//    {
//        // allocate in HEAP place for temporary node
//        Node * ptrNode = new Node;
//        // transmit data
//        tmpNode -> data = NodeValue;
//        // set pointer to zero for the last node
//        tmpNode -> next = NULL;
//        this -> head = nullptr;
//        this -> data = value;
//    }
//    // CONSTRUCTOR END //

//    // "SETTER" ADD NEW NODE ELEMENT BEGIN //
//    void addNodeToEnd(int NodeValue)
//    {
//        // allocate in HEAP place for temporary node
//        Node * tmpNode = new Node;
//        // transmit data
//        tmpNode -> data = NodeValue;
//        // set pointer to zero for the last node
//        tmpNode -> next = NULL;
//        // check this is the first node?
//        if (head == NULL)
//            // in the header, set the pointer to the first node
//            head = tmpNode;
//        else
//        {
//            // create a pointer to an auxiliary field
//            // and assign to him the start of the List
//            Node * current = head;
//            // in a loop brute force all pointers up to the last item
//            while (current -> next)
//            {
//                // assign a pointer to null to the new item
//                current = current -> next;
//            }
//            // assign the last item a pointer to the new one
//            current -> next = tmpNode;
//        }
//    }
//    // "SETTER" ADD NEW NODE ELEMENT END //

//    // "GETTER" DISPLAY ALL LIST ITEMS BEGIN //
//    void outputList()
//    {
//        if (head == NULL)
//            cout << "Can't display the list. He is empty!";
//        // create a pointer to an auxiliary field
//        Node* current;
//        // assign a pointer to the start of List
//        // each node gets a pointer to the next up to the last
//        // brute each node pointer in a loop
//        for(current =   head;
//            current ->  next;
//            current =   current -> next)
//        {
//            // display data from each element
//            cout << current -> data << endl;
//        }
//        // display data from each element
//        cout << current -> data << endl;
//     }
//    // "GETTER" DISPLAY ALL LIST ITEMS END //

////    ~List()
////    {
////        delete nd;
////    }
//};
// DEFINE CLASS LIST END //


//    typedef struct Node
//    {
//        // pointer on next node
//        struct Node* next;
//        // type of data contain in list
//        int data;
//    };
//    // DEFINE NODE STRUCT END //

//    // assign null to the header pointer
//    Node* head = NULL;

//    void addNodeToStart(Node **head, int NodeValue)
//    {
//        // create auxiliary variable and assign a pointer to the current item
//        Node *current = (Node*) malloc (sizeof(Node));
//        current -> value = data;
//        current -> next = (*head);
//        (*head) = current;
//    }

//    int printList(Node **head)
//    {
//        Node* prev = NULL;
//        int val;
//        if(head == NULL)
//            exit(-1);
//        prev = (*head);
//        val = prev->value;
//        (*head) = (*head) -> next;
//        free(prev);
//        return val;
//    }

//    Node* getNth(Node* head, int n)
//    {
//        int counter = 0;
//        while (counter < n && head)
//        {
//            head = head -> next;
//            counter++;
//        }
//        return head;
//    }

//    Node* getLast(Node* head)
//    {
//        if(head == NULL)
//            return NULL;
//        while(head -> next)
//            head = head -> next;
//        return head;
//    }

//    void addNodeToEnd(Node *head, int value)
//    {
//        Node* last = getLast(head);
//        Node *tmp = (Node*) malloc(sizeof(Node));
//        tmp -> value = value;
//        tmp -> next = NULL;
//        last -> next = tmp;
//    }

//    Node* getLastButOne(Node* head)
//    {
//        if(head == NULL)
//            exit(-2);
//        if(head -> next == NULL)
//            return NULL;
//        while(head -> next -> next)
//            head = head -> next;
//        return head;
//    }

//    void popLast(Node **head)
//    {
//        Node *lastbn = NULL;
//        //Get NULL
//        if(!head)
//            exit(-1);
//        //List clear
//        if(!(*head))
//            exit(-1);
//        lastbn = getLastButOne(*head);
//        //if list contain just an item
//        if(lastbn == NULL)
//        {
//            free(*head);
//            *head = NULL;
//        }
//        else
//        {
//            free(lastbn -> next);
//            lastbn -> next = NULL;
//        }
//    }

//    int popBack(Node **head)
//    {
//        // current Node
//        Node *pFwd = NULL;
//        //previous Node
//        Node *pBwd = NULL;
//        //get Node
//        if(!head)
//            exit(-1);
//        //List clear
//        if(!(*head))
//            exit(-1);
//        pFwd = *head;
//        while(pFwd -> next)
//        {
//            pBwd = pFwd;
//            pFwd = pFwd -> next;
//        }
//        if(pBwd == NULL)
//        {
//            free(*head);
//            *head = NULL;
//        }
//        else
//        {
//            free(pFwd -> next);
//            pBwd -> next = NULL;
//        }
//    }

//    void inser(Node* head, unsigned n, int val)
//    {
//        unsigned i = 0;
//        Node* tmp = NULL;
//        //find an item. If we get to out of list go out from circle
//        //We won't get an error, cos node will insert at the end of list
//        while(i < n && head -> next)
//        {
//            head = head -> next;
//            i++;
//        }
//        tmp = (*Node) malloc(sizeof(Node));
//        tmp -> value = val;
//        //If it isn't last Node send a pointer to the next Node
//        if(head -> next)
//            tmp -> hext = head -> next;
//        // the other side, set a NULL
//        else
//            tmp -> next = NULL;
//        head -> next = tmp;
//    }

//    int deleteNth(Node** head, int n)
//    {
//        if(n == 0)
//            return pop(head);
//        else
//        {
//            Node* prev = getNth(*head, n - 1);
//            Node *elm = prev -> next;
//            int val = elm -> value;
//            prev -> next = elm -> next;
//            free(elm);
//            return val;
//        }
//    }

//    void deleteList(Node** head)
//    {
//        while((*head) -> next)
//        {
//            pop(head);
//            *head = (*head) -> next;
//        }
//        free(*head);
//    }

//    // ANALOGUE OF POP FUNCTION //
//    void deleteList(Node** head)
//    {
//        Node* prev = NULL;
//        while((*head) -> next)
//        {
//            prev = (*head);
//            (*head) = (*head) -> next;
//            free(prev);
//        }
//        free(*head);
//    }

//    void fromArray(Node** head, int* arr, size_t size)
//    {
//        size_t i = size - 1;
//        if(arr == NULL || size == 0)
//            return;
//        do
//        {
//            push(head, arr[i]);
//        }
//        while(i-- != 0);
//    }

//    int* toArray(const Node *head)
//    {
//        int leng = length(head);
//        int *values = (int*) malloc(leng*sizeof(int));
//        while(head)
//        {
//            values[--leng] = head -> value;
//            head = head -> next;
//        }
//        return values;
//    }

//    void printLinkedList(const Node *head)
//    {
//        while(head)
//        {
//            printf("%d", head -> value);
//            head = head -> next;
//        }
//        print("\n");
//    }

//#endif

// MAIN FUNCTION BEGIN //
int main()
{
    // CODE/INSTRUCTIONS BEGIN //
    //*//   List<int> lst;
    //*//   lst.push_front(5);
    //*//   lst.push_front(7);
    //*//   lst.push_front(101);

    //*//   for (int i = 0; i < lst.GetSize(); i++)
    //*//       cout << lst[i] << endl;

    //*//   cout << endl << "pop_back " << endl << endl;

    //*//   lst.pop_back();

    //*//   for (int i = 0; i < lst.GetSize(); i++)
    //*//       cout << lst[i] << endl;



    List<int> newList;

    newList.append(124);
    newList.append(42);
    newList.append(11);
    newList.remove();
    newList.size();

    newList.end();
    // CHECK OPERATION OF PROGRAMM //
    return 0;
    // CODE/INSTRUCTIONS END //
}
// MAIN FUNCTION END //
