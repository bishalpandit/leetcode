// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// #include <algorithm>


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& a){
        
        // Your code here
        int i = 0, j = 0;
        
        while(j < n - 1 and a[j] == a[j + 1]) j++;
        
        j++;
        
        int x = a[j];
        
        while(j < n and i < j) {
            if(x == a[j]) {
                swap(a[i], a[j]);
                i++, j++;
            }
            else {
                i = j;
                j++;
                x = a[j];
            }
        }
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(n, a);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}  // } Driver Code Ends