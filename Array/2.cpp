//{ Driver Code Starts
/* Driver program to test above function */
// Max Min in an array
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
   // Simple Approach Iterate through Entire Array Compare Get desired result
   // Time Complexity 0(n)
    int findSum(int A[], int N)
    {
    	//code here.
        int maxi = A[0];
        int mini = A[0];
        for(int i = 0; i < N; i++){
            if(A[i]>maxi){
                maxi = A[i];
            }
            if(A[i]<mini){
                mini =A[i];
            }
        }
        return maxi+mini;
    }

    // Time Complexity 0(nlogn)
    // Simply sort the Array
    int findSum1(int A[], int N)
    {
    	//code here.
        sort(A, A+N);
        int maxi = A[0];
        int mini = A[N-1];
        
        return maxi+mini;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends