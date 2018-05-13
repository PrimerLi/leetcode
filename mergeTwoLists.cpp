#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << ", ";
        head = head->next;
    }
    cout << endl;
}

ListNode* mergeTwoSortedLists(ListNode* head1, ListNode* head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    if (head1->val < head2->val)
    {
        head1->next = mergeTwoSortedLists(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeTwoSortedLists(head1, head2->next);
        return head2;
    }
}

ListNode* append(ListNode* head, int value)
{
    if (head == NULL)
    {
        head = new ListNode(value);
        return head;
    }
    ListNode* iterator;
    iterator = head;
    while(iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = new ListNode(value);
    return head;
}

int main()
{
    ListNode* head1;
    head1 = NULL;
    head1 = append(head1, 1);
    head1 = append(head1, 2);
    head1 = append(head1, 10);
    head1 = append(head1, 30);
    cout << "List 1: " << endl;
    printList(head1);

    ListNode* head2;
    head2 = NULL;
    head2 = append(head2, -10);
    head2 = append(head2, 100);
    head2 = append(head2, 1200);
    cout << "List 2: " << endl;
    printList(head2);

    ListNode* combined;
    combined = mergeTwoSortedLists(head1, head2);
    cout << "Combined list: " << endl;
    printList(combined);
    return 0;
}
