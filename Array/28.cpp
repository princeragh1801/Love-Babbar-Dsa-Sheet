//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    // Time Complexity 0(nlogn)
    // Space 0(N)
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
       sort(arr, arr+N);
       vector<int> v;
       for(int i = 0; i < N; i++){
        if(arr[i] != arr[i-1]){
            v.push_back(arr[i]);
        }
       }
       int maxCount = 1;
       int count = 1;
       for(int i = 1; i < v.size(); i++){
        if(v[i] != v[i-1]+1){
            count = 0;
        }
        count++;
        maxCount = max(maxCount, count);
       }
       return maxCount;
    }

    // Time Complexity: O(N).
    // Auxiliary Space: O(N).
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      set<int> s;
      int mini = INT_MAX;

      for(int i = 0; i < N; i++){
        if(arr[i]<mini){
            mini = arr[i];
        }
        s.insert(arr[i]);
      }
      int count = 1;
      int prev = mini;
      int maxCount = 1;
      for(auto it : s){
        if(it != prev+1){
            count = 1;
        }
        else{
            count++;
            maxCount = max(maxCount, count);
        }
        prev = it;
      }
      return maxCount;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends