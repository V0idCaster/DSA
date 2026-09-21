#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// from here --------
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int carry = 0;

        while (t1 || t2 || carry) {
            int sum = carry;

            if (t1) {
                sum += t1->val;
                t1 = t1->next;
            }
            if (t2) {
                sum += t2->val;
                t2 = t2->next;
            }

            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
//to here ---------

ListNode* build(const vector<int>& v) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int x : v) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    ListNode* a = build({2, 4, 3});
    ListNode* b = build({5, 6, 4});
    printList(sol.addTwoNumbers(a, b));      // expect 7 -> 0 -> 8

    printList(sol.addTwoNumbers(build({5}), build({5})));   // expect 0 -> 1
    return 0;
}