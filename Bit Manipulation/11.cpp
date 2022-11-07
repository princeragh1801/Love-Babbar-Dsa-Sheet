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

// i have to do it using bit mask 
void _solve(){
    int n;
    cin>>n;
    vector<string> words(n);
    for(auto &it : words){
        cin>>it;
    }
   
    int puzzles;
    cin>>puzzles;
    vector<int> ans;
    while(puzzles--){
        string str;
        cin>>str;
        // we have check for each puzzle how much words is satisfied 
        // we have to check first letter of the puzzle should be present in the word 
        // then we have to check all the letters of the word should be present in the puzzle
        // count the number of words satisfying each puzzle
        unordered_set<char> st;
        for(auto it : str){
            st.insert(it);
        }
        int x = 0;
        fo(i,0,n){
            int flag = 1;
            
            int flag2 = 0;
            for(auto it : words[i]){
                if(st.find(it) == st.end()){
                    flag = 0;
                    break;
                }
                if(str[0] == it){
                    flag2 = 1;
                }
            }
            
          
            if(flag == 1 && flag2 == 1){
                x++;
            }
            debug(flag)
        }
        cout<<x<<" ";
        ans.push_back(x);
    }
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
