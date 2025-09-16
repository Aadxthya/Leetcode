// Last updated: 9/16/2025, 9:50:52 AM
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        
        // Loop through all numbers from 1 to N
        for (int i = 1; i <= N; i++) {
            string s = to_string(i);
            bool isGood = false;
            bool isValid = true;
            
            for (char c : s) {
                if (c == '3' || c == '4' || c == '7') {
                    isValid = false; // Invalid number when it has these digits
                    break;
                }
                if (c == '2' || c == '5' || c == '6' || c == '9') {
                    isGood = true; // Good number if it has these digits
                }
            }
            
            // Increase count if the number is good and valid
            if (isValid && isGood) {
                count++;
            }
        }
        
        return count;
    }
};
