// Last updated: 9/16/2025, 9:55:05 AM
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            string temp = "";
            int count = 1;
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == res[j - 1]) {
                    count++;
                } else {
                    temp += to_string(count) + res[j - 1];
                    count = 1;
                }
            }
            temp += to_string(count) + res.back();
            res = temp;
        }
        return res;
    }
};