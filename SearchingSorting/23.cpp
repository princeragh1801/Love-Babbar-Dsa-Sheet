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

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool allocatePage(int A[], int n, int maxPage, int student){
        int cnt = 1;
        int total = 0;
        for(int i = 0; i < n; i++){
            if(A[i] > maxPage){
                return false;
            }
            
            if(total+A[i] > maxPage){
                cnt++;
                total = A[i];
            }
            else{
                total += A[i];
            }
        }
        if(cnt > student){
            return false;
        }
        return true;
    }
    // Time 0(Nlogn)
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N){
            return -1;
        }
        int total = 0;
        int mini = A[0];
        for(int i = 0; i < N; i++){
            total += A[i];
            mini = min(mini, A[i]);
        }
        int low = mini;
        int high = total;
        int ans = total;
        int flag = 0;
        while(low <= high){
            int mid = (low+high)/2;
            
           
            if(allocatePage(A, N, mid, M)){
                high = mid-1;
                flag = 1;
            }
            else{
                low = mid+1;
            }
            
        }
        if(flag == 0){
            return -1;
        }
        return low;
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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends