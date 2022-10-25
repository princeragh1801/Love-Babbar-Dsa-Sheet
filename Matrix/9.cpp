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

// Time similar n*n*m;
// auxillary space 0(ans)

vector<int> commonEleInRow1(vector<vector<int>> Mat, int n, int m){
    vector<int> ans;
    unordered_set<int> s;
    fo(i,0,m){
        int x = Mat[0][i];
        int flag = 0;
        fo(j,1,n){
            flag = 0;
            fo(k,0,m){
                if(Mat[j][k] == x){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
            
        }
        if(flag == 1 && s.find(x) == s.end()){
            ans.push_back(x);
            s.insert(x);
        }
    }
    return ans;
}

// Time 0(n*m)
// Space 0(n)

vector<int> commonEleInRow(vector<vector<int>> Mat, int n, int m){
    vector<int> ans;
    unordered_map<int, int> mp;
    
    // pushing all the elements in map
    fo(i,0,m){
        mp[Mat[0][i]] = 1;
    }
    fo(i,1,n){
        fo(j,0,m){
            //checking if it is present in every row or not
            if(mp[Mat[i][j]] == i){
                mp[Mat[i][j]] = i+1;
                // if the element comes up to the last row that's means it is present in all the rows
                // that's what we actually want
                if(i == n-1 && mp[Mat[i][j]] == n){
                    ans.push_back(Mat[i][j]);
                }
            }
        }
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
    int n, m;
    cin>>n>>m;
    vector<vector<int>> Mat(n);
    fo(i,0,n){
        fo(j,0,m){
            int x;
            cin>>x;
            Mat[i].push_back(x);
        }
    }
    vector<int> ans = commonEleInRow(Mat, n, m);

    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
  
    return 0;
}
