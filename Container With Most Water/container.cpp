#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int area = 0;

        int i = 0;
        int j = height.size() - 1;
        /*solucao usando two-pointer*/
        while (i < j) {
            int base = j - i;
            int altura = min(height[i], height[j]);
            area = base * altura;
            if (area >= maxArea) maxArea = area;
            if (height[i] < height[j])
                i += 1;
            else
                j -= 1;
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> h = {8,7,2,1};
    cout << sol.maxArea(h) << endl;
    return 0;
}