#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int value) : val(value), next(NULL) {}
};

int getLen(ListNode * head)
{
    int count = 0;
    ListNode * it = head;
    while(it != NULL)
    {
        count++;
        it = it->next;
    }
    return count;
}

ListNode * getIntersection(ListNode *headA, ListNode * headB)
{
    ListNode * it1, * it2;
    it1 = headA;
    it2 = headB;
    if (headA == NULL || headB == NULL) return NULL;
    while(it1 != it2)
    {
        if (it1 == NULL) it1 = headB;
        else it1 = it1->next;
        if (it2 == NULL) it2 = headA;
        else it2 = it2->next;
    }
    return it1;
}

ListNode * addToList(ListNode * head, int value)
{
    if (head == NULL)
    {
        head = new ListNode(value);
        return head;
    }
    else
    {
        ListNode * it = head;
        while(it->next != NULL)
        {
            it = it->next;
        }
        it->next = new ListNode(value);
        return head;
    }
}

int main()
{
    ListNode * headA, * headB;
    headA = addToList(headA, 1);
    headA = addToList(headA, 2);
    headA = addToList(headA, 3);
    headB = addToList(headB, -1);
    //headB->next = headA->next->next;
    ListNode * inter = getIntersection(headA, headB);
    if (inter == NULL) cout << "NO intersection. " << endl;
    else cout << inter->val << endl;
    return 0;
}
