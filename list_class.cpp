#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int value;
    Node * next;
    Node(int vl) : value(vl), next(NULL) {}
};

class List
{
private:
    Node * head;
    Node * tail;
public:
    List(){head = NULL; tail = NULL;}
    List(const List &list)
    {
        Node * iterator = list.head;
        while(iterator != NULL)
        {
            if (head == NULL)
            {
                head = new Node(iterator->value);
                tail = head;
            }
            else
            {
                tail->next = new Node(iterator->value);
                tail = tail->next;
            }
            iterator = iterator->next;
        }
    }
    List(const vector<int> &myVector)
    {
        if (myVector.size() == 0)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = new Node(myVector[0]);
            tail = head;
            for (int i = 1; i < myVector.size(); ++i)
            {
                tail->next = new Node(myVector[i]);
                tail = tail->next;
            }
        }
    }
    virtual ~List()
    {
        Node * iterator = head;
        while(iterator != NULL)
        {
            Node * next = iterator->next;
            delete iterator;
            iterator = next;
        }
    }
    const List & operator= (const List &parameter)
    {
        if (this == &parameter) return *this;
        Node * iterator = head;
        while(iterator != NULL)
        {
            Node * next = iterator->next;
            delete iterator;
            iterator = next;
        }
        iterator = parameter.head;
        while(iterator != NULL)
        {
            if (head == NULL)
            {
                head = new Node(iterator->value);
                tail = head;
            }
            else
            {
                tail->next = new Node(iterator->value);
                tail = tail->next;
            }
            iterator = iterator->next;
        }
        return *this;
    }
    void append(int value)
    {
        if (head == NULL)
        {
            head = new Node(value);
            tail = head;
        }
        else
        {
            tail->next = new Node(value);
            tail = tail->next;
        }
    }
    void printList() const
    {
        Node * iterator = head;
        while(iterator != NULL)
        {
            cout << iterator->value << ", ";
            iterator = iterator->next;
        }
        cout << endl;
    }
    int getLength() const
    {
        int len = 0;
        Node * iterator = head;
        while(iterator != NULL)
        {
            len++;
            iterator = iterator->next;
        }
        return len;
    }
    Node * getHead() const {return head;}
    Node * getTail() const {return tail;}
};

List take(const List &myList, int k)
{
    List result;
    int len = myList.getLength();
    if (k > len || k <= 0) return result;
    Node * head = myList.getHead();
    Node * iterator = head;
    for (int i = 0; i < k; ++i)
    {
        result.append(iterator->value);
        iterator = iterator->next;
    }
    return result;
}

List createList(Node * head)
{
    List result;
    if (head == NULL) return result;
    Node * iterator = head;
    while(iterator != NULL)
    {
        result.append(iterator->value);
        iterator = iterator->next;
    }
    return result;
}

Node * reverse(Node * head)
{
    if (head == NULL || head->next == NULL) return head;
    Node * temp = reverse(head->next);
    Node * iterator = temp;
    while(iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = head;
    head->next = NULL;
    return temp;
}

List reverse(const List &myList)
{
    List result;
    int len = myList.getLength();
    if (len == 0) return result;
    Node * head = myList.getHead();
    result = reverse(createList(head->next));
    result.append(head->value);
    return result;
}

int main()
{
    vector<int> myVector(10, 0);
    for (int i = 0; i < myVector.size(); ++i)
    {
        myVector[i] = i+1;
    }
    List myList(myVector);
    myList.printList();
    //take(myList, 3).printList();
    //Node * head = reverse(myList.getHead());
    //createList(head).printList();
    reverse(myList).printList();
    return 0;
}
