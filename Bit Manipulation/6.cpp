//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int n = 100000001;
int arr[n];
int cntbit(int n)
{
    int ans = 0;
    while (n)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}
void cnt()
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = cntbit(i);
        arr[i] += arr[i - 1];
    }
}
class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.

    int cntbit(int n)
    {
        int ans = 0;
        while (n)
        {
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
    void cnt()
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < n; i++)
        {
            arr[i] = cntbit(i);
            arr[i] += arr[i - 1];
        }
    }
    int countSetBits(int n)
    {
        // Your logic here
        // cnt();
        return arr[n];
    }

    int powof2(int n){
        int c = 0;
        int i = 1;
        while(2*i <= n){
            c++;
            i *= 2;
        }
        return c;
    }
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0){return 0;}
        int x = powof2(n);
        int totalbitsTill2raisex = pow(2,x-1)*x;
        int remaining = n - (pow(2,x)) +1;
        int ans = totalbitsTill2raisex+remaining + countSetBits(n-pow(2,x));
        return ans;

    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    cnt();
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}

// } Driver Code Ends