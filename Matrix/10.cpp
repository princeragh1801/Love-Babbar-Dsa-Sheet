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

// brute force approach
// time 0(n^4)
// space 0(1)
int findMaxDiff(vector<vector<int>> Mat, int n){
    int maxDiff = INT_MIN;
    fo(i,0,n){
        fo(j,0,n){
            int x = Mat[i][j];
            fo(k,i+1,n){
                fo(l,j+1,n){
                    int curr = Mat[k][l] - x;
                    maxDiff = max(curr, maxDiff);
                }
            }
        }
    }
    return maxDiff;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin>>n;
    vector<vector<int>> Mat(n);
    fo(i,0,n){
        fo(j,0,n){
            int x;
            cin>>x;
            Mat[i].push_back(x);
        }
    }
    cout<<findMaxDiff(Mat, n)<<endl;
    return 0;
}
