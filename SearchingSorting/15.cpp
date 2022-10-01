//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.

    // Naive Approach
    // Time 0(n^2)
    // Space 0(n)
    int minSwaps(vector<int> &nums)
    {
        // Code here
        vector<int> v(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            v[i] = nums[i];
        }
        int operations = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != v[i])
            {
                int j = i + 1;
                while (nums[j] != v[i] && j < nums.size())
                {
                    j++;
                }
                swap(nums[i], nums[j]);
                operations++;
            }
        }
        return operations;
    }


     // Approach - 2
    // Expected Time Complexity: O(nlogn)
    int minSwaps(vector<int> &nums)
    {
        // Code here
        vector<int> v(nums.size());
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            v[i] = nums[i];
            m[nums[i]] = i + 1;
        }
        sort(v.begin(), v.end());
        int operations = 0;
        // debug(v)
        for (int i = 0; i < nums.size(); i++)
        {
            if (v[i] != nums[i])
            {
                int j = m[v[i]];
                m[v[i]] = i + 1;
                m[nums[i]] = j;
                // debug(nums[i])
                // debug(nums[j-1])
                // debug(v[i])
                swap(nums[i], nums[j - 1]);
                operations++;

                // debug(operations)
                // debug(nums)
            }
        }
        return operations;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends