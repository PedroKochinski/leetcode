#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int max = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++){ // O(n)
            while(charSet.find(s[right]) != charSet.end()){ // found element, worst case it is the last one so we must delete every other element in the set until we find the repeated char, so it is O(n)
                charSet.erase(s[left]);
                left+=1;
            }
            charSet.insert(s[right]);
            if(right-left+1 >= max) max = right-left+1;
        }
        //total complexity = O(2n) = O(n)
    return max;
    }
};