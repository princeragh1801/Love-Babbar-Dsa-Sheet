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

// missing and duplicate number
void _solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &itr : v){cin>>itr;}
    int x = 0;
    for(auto it : v){
        x ^= it;
    }
    fo(i,1,n+1){
        x ^=i;
    }
    int rsb = x & -x;
    int num1 = 0, num2 = 0;
    for(auto it : v){
        if((rsb & it) == 0){
            num1 ^= it;
        }
        else{
            num2 ^= it;
        }
    }
    int duplicate = 0, missing = 0;
    fo(i,1,n+1){
        if((rsb&i) == 0){
            num1 ^= i;
        }
        else{
            num2 ^= i;
        }
    }
    fo(i,0,n){
        if(v[i] == x){
            duplicate = num1;
            missing = num2;
            break;
        }
        else if(v[i] == num2){
            duplicate = num2;
            missing = num1;
            break;
        }
    }
    cout<<missing<<" "<<duplicate<<endl;
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
