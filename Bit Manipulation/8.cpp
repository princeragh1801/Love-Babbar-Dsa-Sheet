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

// grey code pattern means for every consecutive string of length n is exactly differ in only one bit
vector<string> greycode1(int n){
    if(n == 1){
        vector<string> base;
        base.push_back("0");
        base.push_back("1");
        return base;
    }

    vector<string> res = greycode1(n-1);
    vector<string> myres;
    for(int i = 0; i < res.size(); i++){
        string str = res[i];
        str = '0'+str;
        myres.push_back(str);
    }
    for(int i = res.size()-1; i >= 0; i--){
        string str = res[i];
        str = '1'+str;
        myres.push_back(str);
    }
    return myres;
}


vector<string> greycode(int n){
    vector<string> res;
    res.push_back("0");
    res.push_back("1");

    while(n > 1){

        vector<string> temp;
        for(int i = 0; i < res.size(); i++){
            string str = res[i];
            str = '0'+str;
            temp.push_back(str);
        }
        for(int i = res.size()-1; i >= 0; i--){
            string str = res[i];
            str = '1'+str;
            temp.push_back(str);
        }
        res = temp;
        n--;
    }
    return res;
}
void _solve(){
    int n;
    cin>>n;
    vector<string> ans = greycode(n);
    debug(ans)
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
