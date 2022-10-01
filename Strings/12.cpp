#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for(ll int i = a; i < b; i++)
#define mod 1000000007
#define beg(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second
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
/******************************** prince1801 *********************************/

void _solve(){
  string str;
  cin>>str;
  string ans ="";
  vector<int> arr(27);
    arr[0] = 0;
    
    int c = 0;
    int x = 2;
    int r = 0;
    fo(i,1,16){
        c++;
        if(c <= 3){
            r = r*10 +x;
            arr[i] = r;
            debug(i)
            debug(arr[i])
            if(c == 3){
                c = 0;
                r = 0;
                x++;
            }
        }
        
    }
    fo(i, 16, 20){
        c++;
        if(c <= 4){
            r = r*10 +x;
            arr[i] = r;
            debug(i)
            debug(arr[i])
            if(c==4){
                c = 0;
                r = 0;
                x++;
            }
        }
    }
    fo(i, 20, 23){
        c++;
        if(c <= 3){
            r = r*10 +x;
            arr[i] = r;
            debug(i)
            debug(arr[i])
            if(c==3){
                c = 0;
                r = 0;
                x++;
            }
        }
    }
    fo(i, 23, 27){
        c++;
        if(c <= 4){
            r = r*10 +x;
            arr[i] = r;
            debug(i)
            debug(arr[i])
            if(c==4){
                c = 0;
                r = 0;
                x++;
            }
        }
    }
    fo(i,0, str.length()){
        int x = str[i]-64;
        cout<<arr[x];
    }
    cout<<endl;
    //debug(arr);
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
  
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    _solve();
    
  }
  return 0;
}
