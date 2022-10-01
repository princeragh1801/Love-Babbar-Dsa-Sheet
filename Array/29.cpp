// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.

    // Approach -1
    // Brute Force Approach
    // Check for all possible triplets
    // If found true else false
    // Time Complexity  0(n^3)
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    if(A[i]+A[j]+A[k]==X){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // Approach - 2
    // Time Complexity  0(n^2)
    // Space Complexity 0(1)
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        
        for(int i = 0; i < n-2; i++){
            unordered_set<int> s;
            for(int j = i+1; j < n; j++){
                int x = X-(A[i]+A[j]);
                if(s.find(x) != s.end()){
                    return true;
                }
                s.insert(A[j]);
            }
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends