// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.

    // Approach - 1
    // Iterate through all the subarrays
    // check whether if there is any subarray exist whose sum is zero
    // Time complexity 0(n^3)
    int sum(vector<int> v){
        int s = 0;
        for(int i = 0; i < v.size(); i++){
            s+=v[i];
        }
        return s;
    }
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                vector<int> v;
                for(int k = j; k <= i; k++){
                    v.push_back(arr[k]);
                }
                if(sum(v) == 0){
                    return true;
                }
            }
        }
        return false;
    }

    // Approach -2
    // Similar to approach 1
    // Time Complexity 0(n^2)

    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        for(int i = 0; i < n; i++){
            int s = 0;
            for(int j = i; j < n; j++){
                s += arr[j];
                if(s == 0){
                    return true;
                }
            }
        }
        return false;
    }

    // Approach - 3
    // Take a variable currSum = 0
    // Push it to the set
    // Update currSum += arr[i]
    // Check whether the currSum is already exist in the set
    // if exist return true
    // Time Complexity 0(n)
    // Space Complexity 0(n)
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> s;
        int currSum = 0;
        for(int i = 0; i < n; i++){
            s.insert(currSum);
            currSum += arr[i];
            if(s.find(currSum) != s.end()){
                return true;
            }
            
        }
        return false;
    }
};

// { Driver Code Starts.
// Driver code
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
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends