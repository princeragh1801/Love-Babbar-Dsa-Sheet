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

vector<int> elementsOcuursMorethanNbyK1(int arr[], int n, int k)
{
    vector<int> result;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto it : m)
    {
        if (it.second > n / k)
        {
            result.push_back(it.first);
        }
    }
    if (result.size() == 0)
    {
        return {-1};
    }
    return result;
}

vector<int> elementsOcuursMorethanNbyK(int arr[], int n, int k)
{
    vector<int> result;
    unordered_set<int> m;
    int x = n / k;

    fo(i, 0, n)
    {
        int count = 0;
        fo(j, i, n)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count > x && (m.find(arr[i]) == m.end()))
        {
            m.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }
    if (result.size() == 0)
    {
        return {-1};
    }
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        fo(i, 0, n) { cin >> arr[i]; }
        vector<int> v = elementsOcuursMorethanNbyK(arr, n, k);
        fo(i, 0, v.size()) { cout << v[i] << " "; }
        cout << endl;
    }

    return 0;
}
