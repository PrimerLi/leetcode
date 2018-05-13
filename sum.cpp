#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node(int vl) : value(vl), next(NULL) {}
};

Node * addToList(Node * head, int value)
{
    if (!head)
    {
        head = new Node(value);
        return head;
    }
    else
    {
        Node * iterator = head;
        while(iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = new Node(value);
        return head;
    }
}

void printList(Node * head)
{
    if (!head) return;
    Node * iterator = head;
    while(iterator != NULL)
    {
        cout << iterator->value << ", ";
        iterator = iterator->next;
    }
    cout << endl;
}

Node * sum(Node * head1, Node * head2)
{
    Node * head = NULL;
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    int value = 0;
    int carry = 0;
    value = head1->value + head2->value;
    carry = value/10;
    value = value%10;
    head = new Node(value);
    if (carry != 0)
    {
        if (head1->next != NULL)
            head1->next->value = head1->next->value + carry;
        else if (head2->next != NULL)
            head2->next->value = head2->next->value + carry;
        else
        {
            head1->next = new Node(carry);
        }
    }
    head->next = sum(head1->next, head2->next);
    return head;
}

int main()
{
    Node * head1 = NULL;
    Node * head2 = NULL;
    head1 = addToList(head1, 9);
    head1 = addToList(head1, 9);
    head1 = addToList(head1, 9);
    head2 = addToList(head2, 1);
    Node * head = sum(head1, head2);
    printList(head);
    return 0;
}
