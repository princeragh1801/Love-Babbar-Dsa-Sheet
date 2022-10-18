#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for(ll int i = a; i < b; i++)
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


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.

    // Brute force approach
    // Time 0(n^2)
    long long getMaxArea1(long long arr[], int n)
    {
        // Your code here
        long long maxArea = 0;

        for(int i = 0; i < n; i++){
            int left = i;
            int right = i;
            while((arr[left] >= arr[i]) && left >= 0){
                left--;
            }
            while(arr[right] >= arr[i] && right < n){
                right++;
            }
            long long l = arr[i];
            long long b = right - left -1;
            
            long long area = l*b;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }

    vector<int> rightInd(long long arr[], int n){
        stack<pair<int, int>> st;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = -1;
            long long x = arr[i];
            pair<int, int> p;
            p.first = arr[i];
            p.second = i;

            while(!st.empty() && st.top().first > x){
                ans[st.top().second] = i;
                st.pop();
            }
            st.push(p);
        }
        return ans;
    }

    vector<int> leftInd(long long arr[], int n){
        stack<pair<int, int>> st;
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            ans[i] = -1;
            long long x = arr[i];
            pair<int, int> p;
            p.first = arr[i];
            p.second = i;

            while(!st.empty() && st.top().first > x){
                ans[st.top().second] = i;
                st.pop();
            }
            st.push(p);
        }
        return ans;
    }

    // Time 0(n)
    // Space 0(N)
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long maxArea = 0;
        vector<int>left = leftInd(arr, n);
        vector<int>right = rightInd(arr, n);
        
        for(int i = 0; i < n; i++){
            long long l = arr[i];
            long long b = right[i]-left[i]-1;
            if(right[i] == -1){
                b = n - left[i]-1;
            }
            long long area = l*b;
            maxArea = max(area, maxArea);
        }
        

        return maxArea;
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
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends