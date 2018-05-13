#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int vl) : val(vl), next(NULL) {}
};

int getLen(ListNode *);

ListNode * addToList(ListNode * head, int val)
{
    if (!head)
    {
        head = new ListNode(val);
        return head;
    }
    else
    {
        ListNode * iterator = head;
        while(iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = new ListNode(val);
        return head;
    }
}

void printList(ListNode * head)
{
    if (!head) return;
    ListNode * iterator = head;
    while(iterator != NULL)
    {
        cout << iterator->val << "->";
        iterator = iterator->next;
    }
    cout << "NULL" << endl;
}

ListNode * sum(ListNode * head1, ListNode * head2)
{
    ListNode * head = NULL;
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    int val = 0;
    int carry = 0;
    val = head1->val + head2->val;
    carry = val/10;
    val = val%10;
    head = new ListNode(val);
    if (carry != 0)
    {
        if (head1->next != NULL)
            head1->next->val = head1->next->val + carry;
        else if (head2->next != NULL)
            head2->next->val = head2->next->val + carry;
        else
        {
            head1->next = new ListNode(carry);
        }
    }
    head->next = sum(head1->next, head2->next);
    return head;
}

int getLength(ListNode * head)
{
    if (head == NULL) return 0;
    int length = 0;
    ListNode * iterator = head;
    while(iterator != NULL)
    {
        length++;
        iterator = iterator->next;
    }
    return length;
}

//10:13
ListNode * reverse(ListNode * head)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode * dummy = new ListNode(-1);
    dummy->next = head;
    ListNode * prev =  head;
    ListNode * current = prev->next;
    while(current != NULL)
    {
        prev->next = current->next;
        current->next = dummy->next;
        dummy->next = current;
        current = prev->next;
    }
    return dummy->next;
}

ListNode * reverseBetween(ListNode * head, int m, int n)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode * dummy = new ListNode(-1);
    dummy->next = head;
    assert(m >= 1);
    assert(n <= getLen(head));
    assert(m <= n);
    ListNode * newTail = dummy;
    for (int i = 0; i < m-1; ++i)
    {
        newTail = newTail->next;
    }
    ListNode * prev = newTail->next;
    ListNode * current = prev->next;
    for (int i = m; i < n; ++i)
    {
        prev->next = current->next;
        current->next = newTail->next;
        newTail->next = current;
        current = prev->next;
    }
    return dummy->next;
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

ListNode * toList(const vector<int> &nums)
{
    ListNode * head = NULL;
    ListNode * tail = NULL;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (head == NULL)
        {
            head = new ListNode(nums[i]);
            tail = head;
        }
        else
        {
            tail->next = new ListNode(nums[i]);
            tail = tail->next;
        }
    }
    return head;
}

vector<int> quickSort(vector<int> a)
{
    int size = a.size();
    if (size == 0 || size == 1) return a;
    int pivot = a[0];
    vector<int> upper, lower, equal;
    for (int i = 0; i < size; ++i)
    {
        if (a[i] == pivot)
        {
            equal.push_back(a[i]);
        }
        else if (a[i] > pivot)
        {
            upper.push_back(a[i]);
        }
        else
        {
            lower.push_back(a[i]);
        }
    }
    lower = quickSort(lower);
    upper = quickSort(upper);
    vector<int> result;
    result.insert(result.end(), lower.begin(), lower.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), upper.begin(), upper.end());
    return result;
}

ListNode* sortList(ListNode* head)
{
    if (head == NULL || head->next == NULL) return head;
    vector<int> nums;
    ListNode * it = head;
    while(it != NULL)
    {
        nums.push_back(it->val);
        it = it->next;
    }
    nums = quickSort(nums);
    return toList(nums);
}

ListNode * removeFromEnd(ListNode *head, int n)
{
    if (head == NULL) return head;
    ListNode * dummy = new ListNode(-1);
    dummy->next = head;
    ListNode * p, * q;
    p = dummy;
    q = dummy;
    int step = 0;
    while(step != n)
    {
        q = q->next;
        step++;
    }
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    ListNode * temp = p->next;
    p->next = p->next->next;
    delete temp;
    return head;
}

ListNode * rotateList(ListNode * head, int k)
{
    if (head == NULL) return NULL;
    if (k == 0) return head;
    int len = 1;
    ListNode * tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
        len++;
    }
    k = k%len;
    tail->next = head;
    int step = len - k;
    ListNode * it = tail;
    for (int i = 0; i < step; ++i)
    {
        it = it->next;
    }
    ListNode * newHead = it->next;
    it->next = NULL;
    return newHead;
}

ListNode * reorder(ListNode * head)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode * tail = head;
    while(tail->next != NULL)
        tail = tail->next;
    if (head->next == tail) return head;
    ListNode * newTail = head;
    while(newTail->next != tail)
        newTail = newTail->next;
    newTail->next = tail->next;
    tail->next = head->next;
    head->next = tail;
    ListNode * newHead = tail->next;
    tail->next = reorder(newHead);
    return head;
}

//10:23

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2);
bool isSorted(ListNode * head);
ListNode * mergeSort(ListNode * head)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode * p, * q;
    p = head;
    q = head->next;
    ListNode * newHead = head->next;
    while(p != NULL && q != NULL)
    {
        p->next = q->next;
        if (p->next == NULL) break;
        q->next = p->next->next;
        p = p->next;
        q = q->next;
    }
    head = mergeSort(head);
    newHead = mergeSort(newHead);
    head = mergeTwoLists(head, newHead);
    assert(isSorted(head));
    return head;
}

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2)
{
    assert(isSorted(l1));
    assert(isSorted(l2));
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

bool isSorted(ListNode * head)
{
    return true;
    if (head == NULL || head->next == NULL) return true;
    ListNode * it = head;
    while(it->next != NULL)
    {
        if (it->val > it->next->val) return false;
        it = it->next;
    }
    return true;
}

ListNode * getTail(ListNode * head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    ListNode * it = head;
    while(it->next != NULL)
    {
        it = it->next;
    }
    return it;
}

int main()
{
    ListNode * head = NULL;
    int len = 17;
    for (int i = 0; i <= len; ++i)
    {
        head = addToList(head, rand()%(3*len));
        //head = addToList(head, i);
    }
    return 0;
}
