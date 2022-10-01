// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    // Time Complexity 0(n^2)
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        vector<long long int> v;
        long long int p = 1;
        for(int i = 0; i < n; i++){
            long long int p = 1;
            for(int j = 0; j < n; j++){
                if(i != j){
                    p *=nums[j];
                }
                
            }
            v.push_back(p);
        }
        return v;
    }
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        vector<long long int> v;
        long long int p = 1;
        long long int temp = 1;
        for(int i = 0; i < n; i++){
            p *=nums[i];
            if(nums[i] != 0){
                
            }
        }
        if(p == 0){
            for(int i = 0; i < n; i++){
                if(nums[i] == 0){
                    
                }
            }
        }
        for(int i = 0; i < n; i++){
            v.push_back(p/nums[i]);
        }
        return v;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends