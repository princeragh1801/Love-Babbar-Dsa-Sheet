#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for (ll int i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl


void __print(vector<int> v){
    cout << "[ ";
    fo(i,0,2){
        cout<<v[i]<<" ";
    }
    cout << " ]" << endl;
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    // If the size is zero Simply return it
    if(intervals.size() == 0){return result;}

    // Sort the Array 0(nlogn)
    sort(intervals.begin(), intervals.end());
    
    result.push_back(intervals[0]);
    int j = 0;
    for(int i = 1; i < intervals.size(); i++)
    {
        // Overlaping condition
        if(result[j][1] >= intervals[i][0])
        {
            result[j][1] = max(result[j][1], intervals[i][1]);
        }

        // Non overlaping condition
        else
        {
            j++;
            result.push_back(intervals[i]);
        }
    }
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v;
        fo(i, 0, n)
        {
            vector<int> inner;
            fo(j, 0, 2)
            {
                int x;
                cin >> x;
                inner.pb(x);
            }
            v.pb(inner);
        }

        merge(v);

        // fo(i, 0, x.size())
        // {
        //     cout << "[ ";
        //     fo(j, 0, 2)
        //     {
        //         cout << x[i][j] << ", ";
        //     }
        //     cout << " ]" << endl;
        // }
    }

    return 0;
}
