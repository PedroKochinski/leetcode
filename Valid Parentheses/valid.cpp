#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        vector<char> brackets;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                brackets.push_back(s[i]);
            }

            else if (s[i] == ')') {
                if (brackets.empty()) return false;
                if (brackets.back() == '(')
                    brackets.pop_back();
                else
                    return false;
            }

            else if (s[i] == '}') {
                if (brackets.empty()) return false;
                if (brackets.back() == '{')
                    brackets.pop_back();
                else
                    return false;
            } else if (s[i] == ']') {
                if (brackets.empty()) return false;
                if (brackets.back() == '[')
                    brackets.pop_back();
                else
                    return false;
            }
        }

        if (brackets.size() == 0)
            return true;
        else
            return false;
    }
};

int main() {
    Solution sol;
    cout << sol.isValid("(){[(])}") << endl;
}