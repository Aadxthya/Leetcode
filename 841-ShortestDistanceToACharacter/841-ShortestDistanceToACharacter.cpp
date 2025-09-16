// Last updated: 9/16/2025, 9:50:43 AM
class Solution {
public:
    vector<int> shortestToChar(string s, char c) 
    {
        int n = s.size(), pos = -n;;
        vector<int> answer(n, n);        
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                pos = i;
            }
            answer[i] = i - pos;
        }
        for (int i = pos - 1; i >= 0; i--)
        {
            if (s[i] == c)
            {
                pos = i;
            }
            answer[i] = min(answer[i], pos - i);
        }
        return answer;
    }
};