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

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 1){
        return strs[0];
    }
    string ans = "";
    int x = min(strs[0].length(), strs[1].length());
    for(int i = 0; i < x; i++){
        if(strs[0][i] != strs[1][i]){
            break;
        }
        ans += strs[0][i];
    }
    
    for(int i = 2; i < strs.size(); i++){
        string curr = "";
        for(int j = 0; j < strs[i].length(); j++){
            if(strs[i][j] != ans[j]){
                break;
            }
            curr += ans[j];
        }
        ans = curr;
    }

    return ans;
}
void _solve(){
    int n;
    cin>>n;
    vector<string> str(n);
    fo(i,0,n){
        cin>>str[i];
    }
  string ans = longestCommonPrefix(str);
  cout<<ans<<endl;
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
