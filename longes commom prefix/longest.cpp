#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string output = strs[0];
        int out_size = strs[0].size();
        for (int i = 0; i < strs.size(); i++) {
            string elem = strs[i];
            for (int j = i; j < strs.size(); j++) {
                string elem2 = strs[j];
                if (i != j) {
                    int curr_prefix_len = 0;
                    string new_output = "";
                    for (int k = 0; k < elem.size(); k++) {
                        if (elem[k] == elem2[k]) {
                            new_output += elem[k];
                            curr_prefix_len += 1;
                        } else {
                            if (curr_prefix_len <= out_size) {
                                output = new_output;
                                out_size = curr_prefix_len;
                            }
                            break;
                        }
                    }

                    if (curr_prefix_len == 0) {
                        // cout << "no common prefix" << endl;
                        return "";
                    }
                    // cout << output << " " << out_size << endl;
                }
            }
        }
        return output;
    }
};

int main() {
    vector<string> lixo = {"fliwer"};
    Solution sol;
    cout << sol.longestCommonPrefix(lixo) << endl;
    return 0;
}