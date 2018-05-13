#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T value;
    Node *next;
    Node(T vl) : value(vl), next(NULL) {}
};

template <class T>
Node<T> * append(Node<T> * head, T value)
{
    if (head == NULL)
    {
        head = new Node<T>(value);
        return head;
    }
    else
    {
        Node<T> * iterator;
        iterator = head;
        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = new Node<T>(value);
        return head;
    }
}

template <class T>
void printList(Node<T> * head)
{
    if (head == NULL) return;
    Node<T> * iterator;
    iterator = head;
    while(iterator != NULL)
    {
        cout << iterator->value << ", ";
        iterator = iterator->next;
    }
    cout << endl;
}

template <class T>
bool hasCycle(Node<T> * head)
{
    Node<T> * fast;
    Node<T> * slow;
    fast = head;
    slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main()
{
    Node<int> * head;
    head = NULL;
    for (int i = 0; i < 10; ++i)
        head = append(head, i+1);
    printList(head);
    cout << hasCycle(head) << endl;

    Node<int> * iterator;
    iterator = head;
    while(iterator->next != NULL) iterator = iterator->next;
    iterator->next = head;
    cout << hasCycle(head) << endl;
    return 0;
}
