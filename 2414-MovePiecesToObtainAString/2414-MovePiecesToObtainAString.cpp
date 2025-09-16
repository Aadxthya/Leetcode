// Last updated: 9/16/2025, 9:48:51 AM
class Solution {
public:
    bool canChange(string start, string target) {
      int n = start.length();
      int i=0;
      int j=0;
      while(i<n || j<n)
      {
        while(start[i]=='_' && i<n)
        {
            i++;
        }
        while(target[j]=='_' && j<n)
        {
            j++;
        }
        if(i==n || j==n)
        {
            return i==n && j==n; 
        }
        if(start[i]!=target[j])
        {
            return false;
        }
        if(start[i]=='L' && i<j)
        {
            return false;
        }
        if(start[i]=='R' && j<i)
        {
            return false;
        }
        i++;
        j++;
      }  
      return true;
    }
};