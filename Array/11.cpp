#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for(int i = a; i < b; i++)
#define mod 1000000007

// Approach -1
// take sum of all the subarrays 
// find max 
// return max
// Time complexity 0(n^3)
int largestSubarraySum2(int arr[], int n){
    int maxSum = 0;
    fo(i, 0, n){
        fo(j, i, n){
            int s = 0;
            fo(k, i, j+1){
                s+=arr[k];
            }
            maxSum = max(maxSum, s);
        }
    }
    return maxSum;
}

// Time Complexity 0(n^2)
// Similar as privios one 
int largestSubarraySum1(int arr[], int n){
    int maxSum = 0;
    fo(i, 0, n){
        int s = 0;
        fo(j, i, n){     
            s+=arr[j];
            maxSum = max(maxSum, s);
        }
    }
    return maxSum;
}

// Best Approach to solve this problem
// Kadane's Algorithm
// Take two variable currMax and maxSum
// Iterate through array and update it
// At last simply return the currMax
// Time Complexity 0(n)
int largestSubarraySum(int arr[], int n){
    int maxSum = 0;
    int currMax = 0;
    fo(i, 0, n){
        maxSum += arr[i];
        currMax = max(maxSum, currMax);
        if(maxSum < 0){
            maxSum = 0;
        }
    }
    return currMax;
}


int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        fo(i,0, n){
            cin>>arr[i];
        }

        cout<<largestSubarraySum(arr, n)<<endl;
        // fo(i, 0, n){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
    }
    
    return 0;
}
