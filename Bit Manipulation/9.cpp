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
/*
// It is the normal way to do it we can also use bits and perform 
bool all(vector<string> universal, vector<vector<string>> st){
    map<string , int> mp;
    fo(i,0, st.size()){
        for(auto it : st[i]){
            mp[it]++;
        }
    }
    for(auto it : universal){
        if(!mp[it]){
            return false;
        }
    }
    return true;
}

void sub(vector<string> universal, vector<vector<string>> &skillset, vector<vector<string>> &output, int index, int n, vector<int> &curr, vector<vector<int>> &arr){
    if(index == n){
        // debug(index)
        // debug(all(universal, output));
        if(all(universal, output)){
            arr.push_back(curr);
            debug(curr)
            int x = output.size();
            cout<<"Minimum required for this "<<x<<endl;
            cout<<"One possible output "<<endl;
            
            fo(i,0,x){
                for(auto it : output[i]){
                    cout<<it<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        // debug(curr)
        // debug(output);
        return;
    }

    // take 
    output.push_back(skillset[index]);
    curr.push_back(index);
    sub(universal, skillset, output, index+1, n, curr, arr);
    output.pop_back();
    curr.pop_back();

    // not take
    sub(universal, skillset, output, index+1, n, curr, arr);
}

void _solve(){
    // input done
    int n;
    cin>>n;
    vector<string> universal(n);
    
    for(auto &it : universal){
        cin>>it;
    }
    debug(universal)
    int noOfCan;
    cin>>noOfCan;
    vector<vector<string>> skillset;
    fo(i,0,noOfCan){
        int x;
        cin>>x;
        vector<string> inner(x);
        for(auto &it : inner){
            cin>>it;
        }
        skillset.push_back(inner);
    }
    debug(skillset)
    vector<vector<string>> output;
    vector<int> curr;
    vector<vector<int>> result;
    sub(universal, skillset, output, 0, noOfCan, curr, result);
    int mini = noOfCan;
    for(auto it : result){
        int x = it.size();
        mini = min(mini, x);
    }
    debug(mini)
}
*/

// use bit mask do it again
void _solve(){
    // input done
    int n;
    cin>>n;
    vector<string> universal(n);
    
    for(auto &it : universal){
        cin>>it;
    }
    debug(universal)
    int noOfCan;
    cin>>noOfCan;
    vector<vector<string>> skillset;
    fo(i,0,noOfCan){
        int x;
        cin>>x;
        vector<string> inner(x);
        for(auto &it : inner){
            cin>>it;
        }
        skillset.push_back(inner);
    }
    debug(skillset)
    vector<vector<string>> output;
    vector<int> curr;
    vector<vector<int>> result;
    
    int mini = noOfCan;
    for(auto it : result){
        int x = it.size();
        mini = min(mini, x);
    }
    debug(mini)
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
