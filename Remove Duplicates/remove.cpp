#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int prev;
        int count = 0;
        int i = 0;
        while (i < nums.size() - 1 - count) {
            cout << nums[i] << " == " << nums[i + 1] << endl;
            if (nums[i] == nums[i + 1] &&
                i < nums.size() - count) {  // found duplicate
                count += 1;
                for (int k = i; k < nums.size() - 1; k++) {  // removes it
                    nums[k] = nums[k + 1];
                }
            } else
                i += 1;
        }
        return nums.size() - count;  // returns the lenght of the new array
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = sol.removeDuplicates(nums);
    cout << "array: ";
    for (int j = 0; j < k; j++) {
        cout << nums[j] << ", ";
    }
    cout << endl;
    return 0;
}