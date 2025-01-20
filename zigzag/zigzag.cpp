#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        unordered_map<int, string> zigzag;
        int map_idx = 1;
        int flag = 1;
        for(int i = 0; i < s.size(); i++){
            cout << map_idx << endl;
            zigzag[map_idx] += s[i];
            if(map_idx == numRows) flag = -1;
            if(map_idx == 1) flag = 1;
            if(map_idx + flag < numRows) map_idx+=flag;
        }
        string res = "";
        for(int i = 1; i <= numRows; i++){
            res += zigzag[i];
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.convert("AB", 1) << endl;

}
