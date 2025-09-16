// Last updated: 9/16/2025, 9:51:35 AM
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
    int n=arr.size();
    // int xori=0;

    // for(auto it: arr)
    // {
    //     xori^=it;
    // }

    // return xori;

    int low=1; int high=n-2;
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) // single element
        return arr[mid];


        // even ---> odd (Left half pairs)
        if((mid%2==0 && arr[mid]==arr[mid+1]) || (mid%2==1 && arr[mid]==arr[mid-1])) //We are in left half
        {
            // eliminate left half
            low=mid+1;
        } 
        // odd----->even (right half pairs)
        else // right half contains single element
        {   
            // eliminate the left half
            high=mid-1;
        }
      
    }

    return -1;
    }
};