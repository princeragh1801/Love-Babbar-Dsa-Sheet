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

vector<vector<int>> rotate90(vector<vector<int>> &Mat, int r, int c){
    vector<vector<int>> ans;
    int i,j;
    for(i = 0; i < c; i++){
        vector<int> inner;
        for(j = r-1; j >= 0; j--){
            inner.push_back(Mat[j][i]);
        }
        ans.push_back(inner);
    }
    return ans;
}


int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
    int n,m;
    cin>>n>>m;
    vector<vector<int>> Mat(n);
    fo(i,0,n){
        fo(j,0,n){
            int x;
            cin>>x;
            Mat[i].push_back(x);
        }
    }

    Mat = rotate90(Mat, n, m);
    fo(i,0,n){
        fo(j,0,n){
            cout<<Mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
  
  return 0;
}
