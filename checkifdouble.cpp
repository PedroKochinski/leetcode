#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> response;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if ((i != j) && (nums[i] + nums[j] == target)) {
                    response.push_back(i);
                    response.push_back(j);
                    return response;
                }
            }
        }
        return response;
    }
};

int main() {
    Solution sol;
    vector<int> v = {3, 3};
    v = sol.twoSum(v, 6);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}