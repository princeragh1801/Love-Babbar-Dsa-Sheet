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

/*********************** prince1801 ************************/



ll sum(vector<ll> v){
    int s = 0;
    for(auto it: v){
        s +=it;
    }
    return s;

}

// Generate all the subsets and store them in result
void subset(vector<ll> arr, ll n, vector<ll> output, ll index, vector<vector<ll>> &ans){
    
    // Base case
    if(index >= n){
        debug(output)
        ans.push_back(output);
        return;
    }

    // Exclude
    subset(arr, n, output, index+1, ans);

    // Include
    output.push_back(arr[index]);
    subset(arr, n, output, index+1, ans);
    
}
void _solve(){
  ll n, a, b;
  cin>>n>>a>>b;
  vector<ll> v(n);
  for(auto &itr : v){cin>>itr;}
  vector<ll> output;
  ll index = 0;
  vector<vector<ll>> ans;
  subset(v, n, output, index, ans);
    ll cnt = 0;
  for(auto it: ans){
    ll s = sum(it);
    if(s >= a && s <= b){
        cnt++;
    }
  }
  debug(cnt);
  cout<<cnt<<endl;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
  
  int test_case_ = 1;
  //cin>>test_case_;
  while(test_case_--)
  {
    _solve();
    
  }
  return 0;
}
