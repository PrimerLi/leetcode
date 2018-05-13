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

Node * mergetLists(Node * head1, Node * head2)
{
    if (!head1) return head2;
    if (!head2) return head1;
    head1->next = mergetLists(head2, head1->next);
    return head1;
}

Node * reverse(Node * head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    Node * result = reverse(head->next);
    Node * iterator = result;
    while(iterator->next != NULL)
        iterator = iterator->next;
    iterator->next = head;
    head->next = NULL;
    return result;
}

Node * removeDuplicates(Node * head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    Node * previous;
    Node * current;
    previous = head;
    current = head->next;
    while(current != NULL)
    {
        if (previous->value == current->value)
        {
            previous->next = current->next;
            delete current;
        }
        else
            previous = current;
        current = current->next;
    }
    return head;
}

Node * createList(const vector<int> &myVector)
{
    Node * head = NULL;
    for (int i = 0; i < myVector.size(); ++i)
    {
        head = addToList(head, myVector[i]);
    }
    return head;
}

Node * rotateRight(Node * head, int k)
{
    if (head == NULL) return NULL;
    if (k == 0) return head;
    int len = 1;
    Node * iterator;
    iterator = head;
    while(iterator->next != NULL)
    {
        len++;
        iterator = iterator->next;
    }
    k = k%len;
    cout << "k = " << k << endl;
    iterator->next = head;
    iterator = iterator->next;
    for (int i = 0; i < k; ++i)
    {
        iterator = iterator->next;
    }
    head = iterator;
    Node * p;
    p = head;
    for (int i = 0; i < len-1; ++i)
    {
        p = p->next;
    }
    p->next = NULL;
    return head;

}

Node * swap(Node * head)
{
    if (head == NULL || head->next == NULL) return head;
    Node * current = head->next;
    head->next = current->next;
    current->next = head;
    return current;
}

Node * swapPairs(Node * head)
{
    if (head == NULL || head->next == NULL) return head;
    head = swap(head);
    head->next->next = swapPairs(head->next->next);
    return head;
}

int getListLength(Node * head)
{
    int len = 0;
    if (head == NULL) return 0;
    Node * iterator = head;
    while(iterator != NULL)
    {
        len++;
        iterator = iterator->next;
    }
    return len;
}

struct listEnds
{
    Node * head;
    Node * tail;
    Node * nextHead;
    listEnds(Node * hd, Node * tl, Node * nhd) : head(hd), tail(tl), nextHead(nhd) {}
};

struct listEnds take(Node * head, int k)
{
    if (head == NULL) return listEnds(NULL, NULL, NULL);
    if (k <= 0) return listEnds(NULL, NULL, NULL);
    int len = getListLength(head);
    if (k > len) return listEnds(NULL, NULL, NULL);
    Node *iterator = head;
    for (int i = 0; i < k-1; ++i)
    {
        iterator = iterator->next;
    }
    Node * nextHead = iterator->next;
    iterator->next = NULL;
    return listEnds(head, iterator, nextHead);
}

Node * reverseK(Node *head, int k)
{
    if (head == NULL || head->next == NULL) return head;
    if (k == 0) return head;
    if (k == 1) return head;
    int len = getListLength(head);
    if (k > len) return head;
    struct listEnds ends = take(head, k);
    head = reverse(ends.head);
    Node * tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = reverseK(ends.nextHead, k);
    return head;
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

Node * removeElements(Node * head, int value)
{
    if (head == NULL) return NULL;
    if (head->next == NULL)
    {
        if (head->value == value) return NULL;
        else return head;
    }
    if (head->value == value)
    {
        return removeElements(head->next, value);
    }
    else
    {
        head->next = removeElements(head->next, value);
        return head;
    }
}

int main()
{
    Node * head;
    head = NULL;
    head = addToList(head, 1);
    head = addToList(head, 1);
    head = addToList(head, 2);
    head = addToList(head, 3);
    printList(head);
    Node * newHead = removeElements(head, 30);
    printList(newHead);
    return 0;
}
