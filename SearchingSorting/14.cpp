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

    // Time complexity 0(n^2)
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        vector<long long int> v;
        long long int p;
        for(int i = 0; i < n; i++)
        {
            p = 1;
            for(int j = 0; j < n; j++)
            {
                if(j != i)
                {
                    p*= nums[j];
                }
            }
            v.push_back(p);
        }
        return v;
    }

    // Time Complexity 0(n)
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        vector<long long int> v(n);
        long long int p = 1;
        int flag = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0){
                p*=nums[i];
            }
            else {
                flag++;
            }
        }
        if(flag >= 2){
            for(int i = 0; i < n; i++){
                v[i] = 0;
            }
        }
        else if(flag == 1){
            for(int i = 0; i < n; i++){
                if(nums[i] == 0){
                    v[i] = p;
                }
                else{
                    v[i] = 0;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                v[i] = p/nums[i];
            }
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