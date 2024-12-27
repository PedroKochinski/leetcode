#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        for (int i = 0; i < s.size() / 2; i++) {
            int j = s.size() - (i + 1);
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> v = {3, 3};
    cout << sol.isPalindrome(-12421) << endl;

    return 0;
}