// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    // Approach -1 
    // Brute Force Approach
    // Time Complexity 0(n^2)

    long long int inversionCount1(long long arr[], long long N)
    {
        // Your Code Here
        long long int j, i, inv_count = 0;
        for (i = 0; i < N - 1; i++)
        {
            for (j = i + 1; j < N; j++)
            {
                if (arr[i] > arr[j])
                {
                    inv_count++;
                }
            }
        }
        return inv_count;
    }


    // Approach -2 
    // Using multiset
    // Worst Case Time Complexity 0(n^2)
    // Space Complexity 0(n)
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int i, inv_count = 0;
        
        multiset<int> m;
        
        m.insert(arr[0]);
        multiset<int> ::iterator it;
        for (i = 1; i < N; i++)
        {
            m.insert(arr[i]);
            it = m.upper_bound(arr[i]);
            inv_count += distance(it, m.end());
        }
        return inv_count;
    }
};

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends