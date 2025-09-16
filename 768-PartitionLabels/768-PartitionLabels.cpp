// Last updated: 9/16/2025, 9:51:01 AM

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int>lastPosition;
        for (int i = 0; i < s.size(); i++){
            lastPosition[s[i]] = i;  // Store the last position of each character
        }
      vector<int> partitions;
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            end = max(end, lastPosition[s[i]]);  // Extend the end to the last occurrence of the current character
            if(i == end){  // If current index is the end of the partition
                partitions.push_back(end - start + 1);
                start = i + 1;  // Update start to the next character after the current partition
            }
        }
        return partitions;
    }
};