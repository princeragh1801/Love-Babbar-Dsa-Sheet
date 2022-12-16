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


class Solution{
  public:
    /*You are required to complete this method */
    void sol(string str, int ind, int n, vector<int> &v){
        if(ind == n){
            return;
        }
        
        if(str[ind] < '0' || str[ind] > '9'){
            v.push_back(-1);
            return;
        }
        int x = str[ind]-48;
        v.push_back(x);
        sol(str, ind+1, n, v);
    }
    int atoi(string str) {
        //Your code here
        int n = str.length();
        vector<int> v;
        int ans = 0;
        int sign = 1;
        int ind = 0;
        if(str[0] == '-'){
            ind++;
            sign = -1;
        }
        sol(str, ind, n, v);
        debug(v)
        for(auto it : v){
            if(it == -1){
                return -1;
            }
            ans = (ans*10)+ it;
        }
        
        return sign*ans;
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
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends