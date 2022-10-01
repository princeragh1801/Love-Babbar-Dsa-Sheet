//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    // Naive approach
    // Time 0(n^3)
    long long countTriplets1(long long arr[], int n, long long sum)
    {
        // Your code goes here
        long long ans = 0, i, j, x, s;
        // unordered_set<int> s;
        // sort(arr,arr+n);
        map<int, int> m;
        for (i = 0; i < n - 1; i++)
        {

            for (j = i + 1; j < n; j++)
            {

                for (x = j + 1; x < n; x++)
                {
                    s = arr[i] + arr[j] + arr[x];
                    if (s < sum)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }


    // Approach -2
    // Time 0(n^2)
    long long countTriplets(long long arr[], int n, long long sum)
    {
        // Your code goes here
        long long ans = 0, i, j, x, s, k;
        sort(arr,arr+n);
        for (i = 0; i < n - 2; i++)
        {
            j = i+1;
            k = n-1;
            
           
            while(j <= k){
                int sum1 = arr[i]+arr[j]+arr[k];
                if(sum1 < sum){
                    ans += (k-j);
                    j++;
                    
                    
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends