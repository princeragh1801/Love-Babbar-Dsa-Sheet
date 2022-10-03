// Quick sort implementation

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

// Understand it first
int partition(vector<ll> &v, int low, int high){

    int pivot = v[high-1];
    int i = low-1;
    fo(j,low,high-1){
        if(v[j] <= pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high-1]);
    return (i+1);
}

void quikSort(vector<ll> &v, int low, int high){
    if(low >= high){
        return;
    }

    
    debug(v)
    int x = partition(v, low, high);
    quikSort(v, low, x);
    
    quikSort(v, x+1, high);
    // partition(v, low, high, pivot);
}
void _solve(){
  ll n;
  cin>>n;
  vector<ll> v(n);
  for(auto &itr : v){cin>>itr;}
  quikSort(v, 0, n);
  debug(v);
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
  
  int test_case_;
  cin>>test_case_;
  while(test_case_--)
  {
    _solve();
    
  }
  return 0;
}
