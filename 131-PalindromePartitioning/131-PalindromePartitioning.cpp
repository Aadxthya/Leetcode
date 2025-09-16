// Last updated: 9/16/2025, 9:53:37 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    unordered_map<char,int> freq;  // step 1: frequency map

    bool isPalindrome(const string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void backtrack(string &s, int start) {
        int n = s.size();
        if(start == n) {
            result.push_back(path);
            return;
        }

        // step 2 & 3: use two pointers to try all substrings starting at 'start'
        for(int end = start; end < n; end++) {
            if(isPalindrome(s, start, end)) {
                // choose substring s[start..end]
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // build frequency map
        for(char c : s) freq[c]++;

        // each char itself is a palindrome, but we explore longer substrings too
        backtrack(s, 0);
        return result;
    }
};
