#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int main() {
    ListNode *head = new ListNode(1);
    ListNode *test = head;
    ListNode second(2);
    ListNode third(3);
    head->next = &second;
    cout << head->next->val << " " << test->next->val << endl;
    head->next = &third;
    cout << head->next->val << " " << test->next->val << endl;
    return 0;
}