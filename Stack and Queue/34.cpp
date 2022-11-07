#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for(int i = a; i < b; i++)
#define mod 1000000007
#define beg(x) x.begin(), x.end()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<endl;
#else
#define debug(x)
#endif


void _print(int a){
    cerr<<a;
}

void _print(float a){
    cerr<<a;
}

void _print(double a){
    cerr<<a;
}

void _print(ll a){
    cerr<<a;
}

void _print(char a){
    cerr<<a;
}

void _print(bool a){
    cerr<<a;
}

void _print(string a){
    cerr<<a;
}

template<class T> void _print(vector<T> v){
    cerr<<"[ ";
    for(T it : v){
        _print(it);
        cerr<<" ";
    }
    cerr<<"]";
}

template<class T> void _print(set<T> s){
    cerr<<"[ ";
    for(T it : s){
        _print(it);
        cerr<<" ";
    }
    cerr<<"]";
}


template<class T> void _print(unordered_set<T> s){
    cerr<<"[ ";
    for(T it : s){
        _print(it);
        cerr<<" ";
    }
    cerr<<"]";
}

/*********************** prince1801 ************************/

// } Driver Code Ends
class Solution {
  public:

    // Naive approach 
    // Time 0(n*k)
    vector<int> sum_of_max_min1(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        for(int i = 0; i <= n-k; i++){
            int maxi = arr[i];
            int mini = arr[i];
            for(int j = i; j < i+k; j++){
                maxi = max(maxi, arr[j]);
                mini = min(mini, arr[i]);
            }
            ans.push_back(maxi+mini);
        }
        return ans;
    }

    // Sliding window approach
    // Time 0(n)
    // Space 0(n)
    vector<int> sum_of_max_min(vector<int> arr, int n, int k) {
        // your code here
        deque<int> mini, maxi;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!mini.empty() && mini.front() == i-k){
                mini.pop_front();
            }
            if(!maxi.empty() && maxi.front() == i-k){
                maxi.pop_front();
            }
            while(!mini.empty() && arr[i] <= arr[mini.back()]){
                mini.pop_back();
            }
            while(!maxi.empty() && arr[i] >= arr[maxi.back()]){
                maxi.pop_back();
            }

            if(mini.empty() || arr[mini.back()] <= arr[i]){
                mini.push_back(i);
            }
            if(maxi.empty() || arr[maxi.back()] > arr[i]){
                maxi.push_back(i);
            }
            if(i >= k-1){
                int x = arr[mini.front()] + arr[maxi.front()];
                ans.push_back(x);
            }
            
        }
        return ans;
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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.sum_of_max_min(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends