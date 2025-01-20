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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = curr;
        int counter = 1;
        while (curr) {
            if (counter % 2 == 0) {
                int val = curr->val;
                curr->val = prev->val;
                prev->val = val;
            }
            counter++;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);

    Solution sol;
    head = sol.swapPairs(head);

    printList(head);

    return 0;
}