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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* dummy = head;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                dummy->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                dummy->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        if (list1)
            dummy->next = list1;
        else if (list2)
            dummy->next = list2;
        return head->next;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(2);
    // l1->next = new ListNode(2);
    // l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(1);
    // l2->next = new ListNode(3);
    // l2->next->next = new ListNode(4);
    printList(l1);
    printList(l2);
    Solution sol;
    printList(sol.mergeTwoLists(l1, l2));
    return 0;
}