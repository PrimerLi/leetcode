#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int vl) : val(vl), next(NULL) {}
};

ListNode * addToList(ListNode * head, int val)
{
    if (head == NULL)
    {
        head = new ListNode(val);
        return head;
    }
    else
    {
        ListNode * tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = new ListNode(val);
        tail = tail->next;
        return head;
    }
}

void printList(ListNode * head)
{
    ListNode * it = head;
    while(it != NULL)
    {
        cout << it->val << "->";
        it = it->next;
    }
    cout << "NULL" << endl;
}

int getLen(ListNode * head)
{
    int len = 0;
    ListNode * it = head;
    while(it != NULL)
    {
        len++;
        it = it->next;
    }
    return len;
}

ListNode * mergeLists(ListNode * h1, ListNode * h2)
{
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;
    if (h1->val < h2->val)
    {
        h1->next = mergeLists(h1->next, h2);
        return h1;
    }
    else
    {
        h2->next = mergeLists(h1, h2->next);
        return h2;
    }
}

/*ListNode * mergeLists(ListNode * h1, ListNode * h2)
{
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;
    ListNode * dummy = new ListNode(-1);
    ListNode * tail = dummy;
    while(h1 != NULL && h2 != NULL)
    {
        if (h1->val < h2->val)
        {
            tail->next = h1;
            h1 = h1->next;
        }
        else
        {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }
    if (h1 == NULL) tail->next = h2;
    else tail->next = h1;
    return dummy->next;
}*/

ListNode * sortList(ListNode * head)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode * p1 = head;
    ListNode * p2 = head;
    ListNode * pre = head;
    while(p2 != NULL && p2->next != NULL)
    {
        pre = p1;
        p1 = p1->next;
        p2 = p2->next->next;
    }
    pre->next = NULL;
    ListNode * h1 = sortList(head);
    ListNode * h2 = sortList(p1);
    return mergeLists(h1, h2);
}

ListNode * reverse(ListNode * head)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode * dummy = new ListNode(-1);
    dummy->next = head;
    ListNode * current, * prev;
    prev = dummy->next;
    current = prev->next;
    while(current != NULL)
    {
        prev->next = current->next;
        current->next = dummy->next;
        dummy->next = current;
        current = prev->next;
    }
    return dummy->next;
}

struct Pair
{
    int val;
    ListNode *pointer;
    Pair(int vl, ListNode * p) : val(vl), pointer(p) {}
};
ListNode * insertionSort(ListNode * head)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode * p1, *p2;
    p1 = head;
    while(p1 != NULL)
    {
        Pair minVal(p1->val, p1);
        p2 = p1;
        while(p2 != NULL)
        {
            if (p2->val < minVal.val)
            {
                minVal.val = p2->val;
                minVal.pointer = p2;
            }
            p2 = p2->next;
        }
        int temp = p1->val;
        p1->val = minVal.pointer->val;
        minVal.pointer->val = temp;
        p1 = p1->next;
    }
    return head;
}

int main()
{
    int len = 80;
    ListNode * head = NULL;
    for (int i = 0; i < len; ++i)
    {
        head = addToList(head, rand()%(5*len));
    }
    //printList(head);
    cout << "Merge sort starts... " << endl;
    sortList(head);
    cout << "Merge sort ends. " << endl;
    ListNode * head1 = NULL;
    for (int i = 0; i < len; ++i)
    {
        head1 = addToList(head1, rand()%(5*len));
    }
    //printList(head1);
    cout << "Insertion sort starts..." << endl;
    insertionSort(head1);
    cout << "Insertion sort ends. " << endl;
    return 0;
}
