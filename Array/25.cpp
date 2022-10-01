//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
     // Approach - 1
    // Iterate through all the subarrays
    // compare the product of subarrays
    // return the maximum value
    // Time complexity 0(n^3)
    long long p(vector<int> v){
        long long x = 1;
        for(int i = 0; i < v.size(); i++){
            x *= v[i];
        }
        
        return x;
    }
	long long maxProduct(vector<int> arr, int n) {
	    // code here
        long long maxP = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                vector<int> v;
                for(int k = j; k <= i; k++){
                    v.push_back(arr[k]);
                }
                long long x = p(v);
                maxP =max(maxP, x);
            }
        }
        return maxP;
	}

    // Approach -2
    // Best Approach to solve this problem
	long long maxProduct1(vector<int> arr, int n) {
	    // code here
        long long maxP = INT_MIN;
        for(int i = 0; i < n; i++){
            long long product = 1;
            for(int j = i; j < n; j++){
                product*=arr[j];
                maxP =max(maxP, product);
            }
        }
        return maxP;
	}


    // Best Approach to solve this problem
    // Time Complexity 0(n)
	long long maxProduct2(vector<int> arr, int n) {
	    // code here
        long long maxProduct = arr[0];
        long long minVal = arr[0];
        long long maxVal = arr[0];
        for(int i = 1; i < n; i++){

            // When multiplied by -ve number,
            // maxVal becomes minVal
            // and minVal becomes maxVal.
            if(arr[i] < 0){
                swap(maxVal, minVal);
            }

            // maxVal and minVal stores the
            // product of subarray ending at arr[i].

            maxVal = max(1ll*arr[i], maxVal*arr[i]);
            minVal = min(1ll*arr[i], minVal*arr[i]);

            // Max Product of array.
            maxProduct = max(maxProduct, maxVal);
        }
        return maxProduct;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends