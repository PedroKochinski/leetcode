#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        int carry_in = 0;
        int remainder = 0;
        int sum = 0;
        while (l1 || l2 || carry_in) {
            sum = carry_in;
            int x, y;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            remainder = sum % 10;
            carry_in = sum / 10;
            dummy->next = new ListNode(remainder);
            dummy = dummy->next;
        }
        return head->next;
    }
};

void printList(ListNode* l) {
    while (l) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    // l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    printList(l1);
    printList(l2);
    Solution sol;
    ListNode* res;
    res = sol.addTwoNumbers(l1, l2);
    printList(res);
}