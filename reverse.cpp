#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int value) : val(value), next(NULL) {}
};

ListNode * addToList(ListNode * head, int value)
{
    if (head == NULL)
    {
        head = new ListNode(value);
        head->next = NULL;
        return head;
    }
    else
    {
        ListNode * tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = new ListNode(value);
        tail = tail->next;
        return head;
    }
}

void print(ListNode * head)
{
    ListNode * it = head;
    while (it != NULL) {
        cout << it->val << "->";
        it = it->next;
    }
    cout << "NULL" << endl;
}

ListNode * reverseBetween(ListNode * head, int m, int n)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode * dummy = new ListNode(-1);
    dummy->next = head;
    ListNode * prev = dummy->next;
    ListNode * current = prev->next;
    ListNode * newHead = dummy;
    for (int i = 1; i < m; ++i)
    {
        newHead = newHead->next;
    }
    prev = newHead->next;
    current = prev->next;
    for (int i = m; i < n; ++i)
    {
        prev->next = current->next;
        current->next = newHead->next;
        newHead->next = current;
        current = prev->next;
    }
    return dummy->next;
}

ListNode * reorder(ListNode * head)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode * dummy = new ListNode(-1);
    dummy->next = head;
    ListNode * currentOdd, * currentEven;
    ListNode * headEven = head->next;
    currentOdd = head;
    currentEven = headEven;
    while(true)
    {
        currentOdd->next = currentOdd->next->next;
        if (currentOdd->next == NULL) break;
        currentOdd = currentOdd->next;
        currentEven->next = currentOdd->next;
        if (currentEven->next == NULL) break;
        currentEven = currentEven->next;
    }
    currentOdd->next = headEven;
    return dummy->next;
}

int main()
{
    int len = 10;
    ListNode * head = NULL;
    for (int i = 0; i < len; ++i)
    {
        //head = addToList(head, rand()%(9*len));
        head = addToList(head, i+1);
    }
    print(head);
    //print(reverseBetween(head, 2, 4));
    print(reorder(head));
    return 0;
}