// Last updated: 9/16/2025, 9:54:32 AM
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();

        while (i < n) {
            int lineLen = words[i].length();
            int j = i + 1;

            // Try to fit as many words as possible
            while (j < n && lineLen + 1 + words[j].length() <= maxWidth) {
                lineLen += 1 + words[j].length();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Last line or single word in line
            if (j == n || gaps == 0) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            }
            else {
                int totalSpaces = maxWidth;
                for (int k = i; k < j; ++k) {
                    totalSpaces -= words[k].length();
                }

                int space = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(space + (extra-- > 0 ? 1 : 0), ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
