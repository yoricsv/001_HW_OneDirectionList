#include <iostream>
#include <cstdlib> // for exit()

#include "main.h"

using namespace std;


int prompt_menu()
{
    if(!sub_action)
    {
        std::cout << "Choose what you want to do:" << std::endl;

        std::cout << "\t1 - ADDING AN ELEMENT:" << std::endl;

        std::cout << "\t2 - COUNT ITEMS IN A LIST:" << std::endl;

        std::cout << "\t3 - DISPLAYING ALL LIST ITEMS:" << std::endl;

        std::cout << "\t4 - DELETE SOME ELEMENT:" << std::endl;

        std::cout << "\t5 - REMOVE A LIST:" << std::endl;

        std::cout << "\t0 - CLOSE PROGRAM:" << std::endl;

        cin >> action;
        return action;
    }
    else
    {
        std::cout << "\t1 - Add a new element at the beginning\n";
        std::cout << "\t2 - Add a new element by index\n";
        std::cout << "\t3 - Add a new element to the end of the List\n";
        std::cout << "\t10 - Exit\n";

        std::cout << "\t4 - Get the number of items in a List\n";
        std::cout << "\t10 - Exit\n";

        std::cout << "\t5 - Show List\n";
        std::cout << "\t10 - Exit\n";

        std::cout << "\t6 - Delete the first element of the List\n";
        std::cout << "\t7 - Delete an element by index\n";
        std::cout << "\t8 - Delete the last element at the end of the List\n";
        std::cout << "\t10 - Exit\n";

        std::cout << "\t9 - Remove a List\n";
        std::cout << "\t10 - Exit\n";

        cin >> sub_action;
        return sub_action;
    }
}


struct Node
{
    int data;
    Node * next;
};

Node * head = nullptr;

int push_front(int position, int value) //void AddList(int value, int position)
{


node -> prev = p -> prev;
node -> next = p; //добавление элемента
p->prev=node;
}
cout<<"\nЁлемент добавлен...\n\n";
}


{
    Node * ptrList  = new Node;     //DoubleList *node=new DoubleList; //создание нового элемента

    ptrList -> data = value;        //node->data=value;     //присвоение элементу значени€
    if(head == nullptr)             //if (head==NULL)       //если список пуст
                                    //node->next=node;      //установка указател€ next
        head = ptrList;             //head=node;            //определ€етс€ голова списка
    }
    else
    {
        Node * current = head;              //DoubleList *p=head;
        for(int i = position; i > 1; i--)   //for(int i=position; i>1; i--)
            current = current -> next;      //p=p->next;

        ptrList -> next = head;             //p->prev->next=node;
        head = ptrList;
        ptrList = ptrList -> next;
        while(ptrList)
        {
            ptrList -> data.Pos++;
            ptrList = ptrList -> next;
        }
    }
    return 0;
}
int add_elem(int Pos, int Val, Node * head)
{
    Node * semi = head;
    cout << Pos;
    if (!head)
    {
        Add_to_beginning(Pos, Val, head);
        return 0;
    }
    if (Pos == 1)
    {
        Add_to_beginning(Pos, Val, head);
        return 0;
    }

    while ((semi) && (Pos > semi -> data.Pos))
    {
        semi = semi -> next;
    }
    if (!semi)
    {
        Add_to_end(Pos, Val, head);
        return 0;
    }
    Add_between(Pos, Val, head);
    return 0;
}

int insert(int Pos, int Val, Node *head)     //add item by index
{
    Node *semisemi = head;
    Node *ptrList = new Node;
    ptrList->data.Pos = Pos;
    ptrList->data.Val = Val;
    while ((semisemi) && (Pos > semisemi->data.Pos))
    {
        semisemi = semisemi->next;
    }
    ptrList = semisemi->next;
    semisemi -> next = ptrList;
    while ((Pos == semisemi -> next -> next -> data.Pos)
           && (!semisemi -> next -> next -> next))
    {
        semisemi->next->next->data.Pos++;
        semisemi->next->next = semisemi->next->next->next;
    }
    return 0;
}
int push_back(int Pos, int Val, Node *head)   // add item to the end
{
    Node * semisemi = head;
    Node *ptrList = new Node;
    ptrList->data.Pos = Pos;
    ptrList->data.Val = Val;
    while ((semisemi) && (Pos > semisemi -> next -> data.Pos))
    {
        semisemi = semisemi->next;
    }
    semisemi -> next = ptrList;
    return 0;

}

int pop_back(int Pos, Node * head)     //delete item to the end
{
if (!head)
{
    return 0;
}
Node * semi = head;
while ((Pos > semi -> data.Pos) && (!semi -> next))
{
    semi = semi -> next;
}
if (Pos = semi -> data.Pos)
{
    if (semi == head)         //begin
    {
        head = semi -> next;
        delete semi;
        return 0;
    }
    if (!semi -> next)            //end
    {
        semi = head;
        while (!semi -> next -> next)
        {
            semi = semi -> next;
        }
        delete(semi -> next);
        semi -> next = 0;
        return 0;
    }
    semi = head;
    while (Pos > semi -> next -> data.Pos)
    {
        semi = semi -> next;
    }
    semi->next = semi -> next -> next;
    Node *semisemi = semi -> next -> next;
    delete (semi->next);
    semi->next = semisemi;
    return 0;
}
cout << "Element with this Position not exist\n";
return 0;
}
int ShowList(Node * head)     // display list
{
    Node * show = head;
    if (!show)
    {
        cout << " List is empty \n";
        return 0;
    }
    cout << " Position\t Value\n";
    while (show)
    {
        cout << show -> data.Pos << "\t" << show -> data.Val << "\n";

        show = show -> next;
    }
    return 0;

}


/*
int main()
{

    int ans;
    int Pos, Val;

    List * head = 0;

    do
    {
        menu();
        cout << " Enter you choice\n";
        cin.clear();

        _flushall();
        cin >> (ans);

        switch (ans)
        {
        case 1:
            {
                cout << "Enter Position of new element\n";
                cin >> (Pos);

                if (Pos <= 0)
                {
                    cout << "Position can not be unpositive\n";
                    break;
                }

                cout << "Enter Value of new element\n";
                cin >> (Val);

                Add_elem(Pos, Val, &head);
            }
            break;
        case 2:
                ShowList(&head);
            break;
        case 3:
                Delete_el(Pos, &head);
            break;
        }
    }
    while (ans != 0);
    return 0;
}

*/





#ifndef USE_BY_STRUCT_NODE
class List
{
protected:
    List * head = nullptr;
public:
    virtual int getHead() = 0;
    virtual ~List(){}
    //virtual void addNode_Back();
    //virtual void printList();
    //virtual void deleteEndNode();
};
//void setHead(List* phead);
//void List::getHead(){this -> head = head;}
//void List::setHead(List* phead){this -> head = phead;}
class OneWay_Node : public List
{
private:
    OneWay_Node * next;
    int data;
public:
    OneWay_Node(int nodeValue, OneWay_Node next);               // CONSTRUCTOR //
    ~OneWay_Node(){if (this -> next != nullptr) delete[] next;} // DISTRUCTOR //

    int getHead() override;
    void addNode_Back(int nodeValue);
    void printList();
    void deleteEndNode();
};
class HalfDuplex_Node : public OneWay_Node
{
private:
    HalfDuplex_Node * next;
    HalfDuplex_Node * prev;
    int data;
public:
    HalfDuplex_Node(int nodeValue, HalfDuplex_Node next);           // CONSTRUCTOR //
    ~HalfDuplex_Node(){if (this -> next != nullptr) delete[] next;} // DISTRUCTOR //

    void addNode_Back(int nodeValue);
    void printList();
    void deleteEndNode();
};
OneWay_Node::OneWay_Node(int nodeValue, OneWay_Node next) // CONSTRUCTOR //
{
    this -> data = nodeValue;
    this -> next = &next;
}
void HalfDuplex_Node::addNode_Back(int nodeValue)
{
    HalfDuplex_Node* ptrNode = new HalfDuplex_Node(nodeValue);
    ptrNode->data = nodeValue;
    if (head == nullptr)
        setHead(ptrNode);
    else
    {
        // create a pointer to an auxiliary field
        // and assign to him the start of the list
        HalfDuplex_Node* current = head;
        // in a loop brute force all pointers up to the last item
        while (current->next)
        {
            // assign a pointer to null to the new item
            current = current->next;
        }
        // assign the last item a pointer to the new one
        current->next = ptrNode;
    }
}
void OneWay_Node::printList()
{
    if (head == nullptr)
        cout << "can't display the list. he is empty!";
    OneWay_Node * current;
    static int counter = 0;
    for (current = gethead();
        current->next;
        current = current->next)
    {
        cout << "the node number " << ++counter;
        cout << " contains " << current->data << " value." << endl;
    }
    cout << "the node number " << ++counter;
    cout << " contains " << current->data << " value.\n" << endl;
}
void HalfDuplex_Node::deleteEndNode()
{
    if (head == nullptr)
        cout << "there is nothing to delete. the list is empty!";
    HalfDuplex_Node* current;
    current = head;
    // brute each node pointer in a loop up to the end of list
    while (current)
    {
        static int counter = 0;
        cout << "the node number " << ++counter;
        cout << " contains " << current->data << " value.";
        cout << "\tpointer is " << current->next << endl;
        if (!current->next)
        {
            delete current->next;
            cout << "\nsuccess! the last node has been deleted.";
            cout << "\nthe new last node contains " << current->data << " value.";
            cout << "\tpointer is " << current->next << endl;
            break;
        }
        else
        {
            current = current->next;
        }
    }

}
#endif




typedef struct node
{
    struct node * next;
    int data;
};

node * head = nullptr;

void addNode(node head, int nodevalue)
{
    node * current = (node*) malloc (sizeof(node));
    current -> value = data;
    current -> next = (*head);
    (*head) = current;
}





void inser(node* head, unsigned n, int val)
{
    unsigned i = 0;
    node* tmp = null;
    //find an item. if we get to out of list go out from circle
    //we won't get an error, cos node will insert at the end of list
    while(i < n && head -> next)
    {
        head = head -> next;
        i++;
    }
    tmp = (*node) malloc(sizeof(node));
    tmp -> value = val;
    //if it isn't last node send a pointer to the next node
    if(head -> next)
        tmp -> hext = head -> next;
    // the other side, set a null
    else
        tmp -> next = null;
    head -> next = tmp;
}

void addNodeToEnd(node *head, int value)
{
    node * last = getlast(head);
    node * tmp = (node*) malloc(sizeof(node));
    tmp -> value = value;
    tmp -> next = nullptr;
    last -> next = tmp;
}

node* getlastbutone(node* head)
{
    if(head == null)
        exit(-2);
    if(head -> next == null)
        return null;
    while(head -> next -> next)
        head = head -> next;
    return head;
}

void poplastOneWay(node **head)
{
    node * lastbn = nullptr;
    //get null
    if(!head)
        exit(-1);
    //list clear
    if(!(*head))
        exit(-1);
    lastbn = getlastbutone(*head);
    //if list contain just an item
    if(lastbn == nullptr)
    {
        free(*head);
        *head = nullptr;
    }
    else
    {
        free(lastbn -> next);
        lastbn -> next = nullptr;
    }
}
int popbackDuplex(node **head)
{
    // current node
    node *pfwd = nullptr;
    //previous node
    node *pbwd = nullptr;
    //get node
    if(!head)
        exit(-1);
    //list clear
    if(!(*head))
        exit(-1);
    pfwd = * head;
    while(pfwd -> next)
    {
        pbwd = pfwd;
        pfwd = pfwd -> next;
    }
    if(pbwd == nullptr)
    {
        free(*head);
        *head = nullptr;
    }
    else
    {
        free(pfwd -> next);
        pbwd -> next = nullptr;
    }
}


int deletenth(node** head, int n)
{
    if(n == 0)
        return pop(head);
    else
    {
        node* prev = getnth(*head, n - 1);
        node *elm = prev -> next;
        int val = elm -> value;
        prev -> next = elm -> next;
        free(elm);
        return val;
    }
}

void deletelistFirstMethod(node** head)
{
    while((*head) -> next)
    {
        pop(head);
        *head = (*head) -> next;
    }
    free(*head);
}
void deletelistSecondMethod(node** head)
{
    node * prev = nullptr;
    while((*head) -> next)
    {
        prev = (*head);
        (*head) = (*head) -> next;
        free(prev);
    }
    free(*head);
}

int* toarray(const node *head)
{
    int leng = length(head);
    int *values = (int*) malloc(leng*sizeof(int));
    while(head)
    {
        values[--leng] = head -> value;
        head = head -> next;
    }
    return values;
}
void fromarray(node** head, int* arr, size_t size)
{
    size_t i = size - 1;
    if(arr == null || size == 0)
        return;
    do
    {
        push(head, arr[i]);
    }
    while(i-- != 0);
}

node * getnth(node* head, int n)
{
    int counter = 0;
    while (counter < n && head)
    {
        head = head -> next;
        counter++;
    }
    return head;
}
node * getlast(node* head)
{
    if(head == null)
        return null;
    while(head -> next)
        head = head -> next;
    return head;
}
int outputList(node **head)
{
    node* prev = null;
    int val;
    if(head == null)
        exit(-1);
    prev = (*head);
    val = prev->value;
    (*head) = (*head) -> next;
    free(prev);
    return val;
}
void printlinkedlist(const node *head)
{
    while(head)
    {
        printf("%d", head -> value);
        head = head -> next;
    }
    print("\n");
}




// MAIN FUNCTION BEGIN //
int main()
{
    // CODE/INSTRUCTIONS BEGIN //

    //OneWay_Node newlist;

    //newlist.addNodeToEnd(124);
    //newlist.addNodeToEnd(42);
    //newlist.addNodeToEnd(11);
    //newlist.addNodeToEnd(6);
    //newlist.addNodeToEnd(46);

    //newlist.printList();
    //newList.deleteEndNode();

    List<int> lst;

    lst.push_front(10);
    lst.push_front(2523);
    lst.push_front(1201);

    for (int i = 0; i < lst.GetSize(); i++)
        cout << lst[i] << endl;

    cout << endl << "pop_back " << endl << endl;

    lst.pop_back();

    for (int i = 0; i < lst.GetSize(); i++)
        cout << lst[i] << endl;


    PromptMenu::showMenu(action, lst);
    while(true)
    {
        PromptMenu::showMenu(action, lst);

         switch(program_state)
         {
         case(CREATE_ARRAY):
             {
                 action = prompt_menu();

//                 unsigned typeOfFillIn = 0;
//                 std::cout << "Before creating an Array, choose your preferred type, fill it in:" << std::endl;
//                 std::cout << "\t1 - auto (random):" << std::endl;
//                 std::cout << "\t2 - manually:" << std::endl;
//                 std::cout << "\t3 - close program" << std::endl;

//                 std::cin >> typeOfFillIn;
//                 switch(typeOfFillIn)
//                 {
//                 case(AUTO):
//                         program_state = AUTO_FILL_ARRAY_IN;
//                     break;
//                 case(MANUALLY):
//                         program_state = MANUALLY_FILL_ARRAY_IN;
//                     break;
//                 case(EXIT):
//                         program_state = EXIT;
//                     break;
//                 default:
//                         program_state = CREATE_ARRAY;
//                     break;
//                 }
             }
             break;
         case(AUTO_FILL_ARRAY_IN):
             {
//                 std::cout << "To create a Dynamic Array, enter its length:" << std::endl;
//                 std::cin >> default_size;
//                 SafeArray dynArr(default_size);
//                 dynArr.autoFillArrayIn();

//                 std::cout << "\nChoose action:\n";
//                 std::cout << "\t1 - change some value," << std::endl;
//                 std::cout << "\t2 - display some element" << std::endl;
//                 std::cout << "\t3 - display all items" << std::endl;
//                 std::cout << "\t4 - close program" << std::endl;
//                 std::cin >> action;

//                 if (action == CHANGE_VALUE_IN_ARRAY)
//                 {
//                     unsigned    index = 0;
//                     int         value = 0;

//                     std::cout << "First, enter which element you want to change:" << std::endl;
//                     std::cout << "After pressing Enter, type the value:" << std::endl;
//                     std::cin >> index >> value;

//                     dynArr[index] = value;

//                     std::cout << "The item has been changed! New value is:" << std::endl;
//                     dynArr.printArray(index);

//                     action = GET_SOME_ELEMENT_OUT;
//                 }

//                 if (action == GET_SOME_ELEMENT_OUT)
//                 {
//                     unsigned    index = 0;

//                     std::cout << "What's the item do you want to see?" << std::endl;
//                     std::cin >> index;

//                     std::cout << "Your element is:" << std::endl;
//                     dynArr.printArray(index);
//                 }

//                 if (action == GET_ELEMENTS_OUT)
//                 {
//                     std::cout << "Your Array is:" << std::endl;
//                     dynArr.printArray();
//                 }

//                 std::cout << "Programm is finished. Have a nice day!" << std::endl;
//                 program_state = EXIT;
             }
             break;
         case(MANUALLY_FILL_ARRAY_IN):
             {
//                 std::cout << "To create a Dynamic Array, enter its length:" << std::endl;
//                 std::cout << "\nI would recommend you don't create array with more than 20 elements,";
//                 std::cout << "\nbecause you have to fill it in manually =) " << std::endl;
//                 std::cin >> default_size;
//                 SafeArray dynArr(default_size);
//                 dynArr.fillArrayIn();

//                 std::cout << "\nChoose action:\n";
//                 std::cout << "\t1 - change some value," << std::endl;
//                 std::cout << "\t2 - display some element" << std::endl;
//                 std::cout << "\t3 - display all items" << std::endl;
//                 std::cout << "\t4 - close program" << std::endl;
//                 std::cin >> action;

//                 if (action == CHANGE_VALUE_IN_ARRAY)
//                 {
//                     unsigned    index = 0;
//                     int         value = 0;

//                     std::cout << "First, enter which element you want to change:" << std::endl;
//                     std::cout << "After pressing Enter, type the value:" << std::endl;
//                     std::cin >> index >> value;

//                     dynArr[index] = value;

//                     std::cout << "The item has been changed! New value is:" << std::endl;
//                     dynArr.printArray(index);

//                     action = GET_SOME_ELEMENT_OUT;
//                 }

//                 if (action == GET_SOME_ELEMENT_OUT)
//                 {
//                     unsigned    index = 0;

//                     std::cout << "What's the item do you want to see?" << std::endl;
//                     std::cin >> index;

//                     std::cout << "Your element is:" << std::endl;
//                     dynArr.printArray(index);
//                 }

//                 if (action == GET_ELEMENTS_OUT)
//                 {
//                     std::cout << "Your Array is:" << std::endl;
//                     dynArr.printArray();
//                 }

//                 std::cout << "Programm is finished. Have a nice day!" << std::endl;
//                 program_state = EXIT;
             }
             break;
         case(EXIT):
             {
                 exit(0);
             }
             break;
         default:
             {
                 program_state = CREATE_ARRAY;
             }
             break;
         }
    }
    return 0;
}
