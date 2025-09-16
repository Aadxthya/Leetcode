// Last updated: 9/16/2025, 9:55:37 AM
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[]= {"", "M", "MM", "MMM"};
        
        return thousands[num/1000]+hundreds[num/100%10]+tens[num/10%10]+ones[num%10];
    }
};