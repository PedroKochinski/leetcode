#include <iostream>
using namespace std;

// Definição da estrutura ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = curr;

        int size = 0;
        while (curr != nullptr) {
            size += 1;
            curr = curr->next;
        }

        if (size - n == 0) {
            return head->next;
        }

        curr = head;
        int count = 0;

        while (curr != nullptr) {
            if (count == size - n) {
                prev->next = curr->next;
            }
            prev = curr;
            curr = curr->next;
            count += 1;
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

    printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, 2);

    printList(head);

    return 0;
}