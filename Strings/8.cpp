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
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 0; i < n; i++){
            string curr = "";
            int j = 0;
            while(j < ans.length()){
                int cnt = 0;
                int k = j;
                while(ans[j] == ans[k]){
                    cnt++;
                    k++;
                }
                char x = 48+cnt;
                curr += x;
                curr += ans[j];
                j += cnt;
            }
            ans = curr;
        }
        return ans;
    }
};
void _solve(){
    int n;
    cin>>n;
    string ans = "1";
        for(int i = 0; i < n; i++){
            string curr = "";
            int j = 0;
            while(j < ans.length()){
                int cnt = 0;
                int k = j;
                while(ans[j] == ans[k]){
                    cnt++;
                    k++;
                }
                char x = 48+cnt;
                curr += x;
                curr += ans[j];
                j += cnt;
            }
            ans = curr;
        }
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
