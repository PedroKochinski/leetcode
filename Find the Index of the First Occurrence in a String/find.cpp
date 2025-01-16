#include <iostream>
using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int needle_index = 0;
        if (haystack.size() == 0 || needle.size() == 0) return -1;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                for (int j = 0; j < needle.size(); j++) {
                    if (haystack[i + j] == needle[j]) {
                        cout << needle[j] << " " << haystack[i + j] << endl;
                        needle_index++;
                    } else {
                        needle_index = 0;
                        break;
                    }
                }

                if (needle_index == needle.size()) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    cout << sol.strStr("mississipi", "iss") << endl;
    return 0;
}