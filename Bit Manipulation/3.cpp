//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // here we are  checking for only set bits
    // time 0(number of set bits)
    int setBits1(int N) {
        // Write Your Code here
        int cntBit = 0;
        while(N){
            cntBit++;
            N = (N&(N-1));
        }
        return cntBit;
    }

    // In this we are checking for all the bits
    // time 0(number of bits)
    int setBits(int N) {
        // Write Your Code here
        int cntBit = 0;
        while(N){
            cntBit += (N&1);
            N = N>>1;
        }
        return cntBit;
    }
};

//{ Driver Code Starts.
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends