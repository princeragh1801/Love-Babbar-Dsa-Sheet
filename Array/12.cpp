#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define ll long long
#define pb push_back
#define fi first
#define se second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// Approach -1
// Simply Sort the given array
// Check nums[i] == nums[i+1]
// return nums[i];
// Time Complexity 0(nlogn)
int findDuplicate1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int d = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            d = nums[i];
            break;
        }
    }
    return d;
}

// Approach - 2
// Take a set
// Check if element is already in it or not
// if yes return element
// else push it to the set
// Time Complexity 0(n)
// Space Complexity 0(n)
int findDuplicate2(vector<int> &nums)
{
    unordered_set<int> st;
    for (auto it : nums)
    {
        if (st.count(it))
        {
            return it;
        }
        st.insert(it);
    }
}

// Approach - 3
// Time Complexity 0(n)
// No extra space required
int findDuplicate(vector<int> &nums)
{
    int curr = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        curr = abs(nums[i]);
        if (nums[curr] < 0)
        {
            ans = curr;
            break;
        }
        nums[curr] *= -1;
    }
    // Restore numbers
    for (auto &num : nums)
    {
        num = abs(num);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        fo(i, 0, n)
        {
            int x;
            cin >> x;
            v.pb(x);
        }
        cout << findDuplicate(v) << endl;
    }

    return 0;
}
