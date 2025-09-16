// Last updated: 9/16/2025, 9:48:40 AM
class Solution {
public:
    int appendCharacters(string s, string t) {
         int i = 0, j = 0;
    int len_s = s.size(), len_t = t.size();
    
    while (i < len_s && j < len_t) {
        if (s[i] == t[j]) {
            j++;
        }
        i++;
    }
    
    return len_t - j;
    }
};