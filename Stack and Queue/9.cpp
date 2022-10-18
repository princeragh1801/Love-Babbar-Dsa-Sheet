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
int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixToPostFix(string str){
    string ans = "";
    stack<char> s;
    fo(i,0,str.length()){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ||( str[i] >= '0' && str[i] <= '9')){
            ans += str[i];
        }
        else if(str[i] == '('){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            while(s.top() != '('){
                char c = s.top();
                ans += c;
                s.pop();
            }
            s.pop();
            
        }
        else {
            while(!s.empty() && (prec(str[i]) <= prec(s.top()))){
                char c = s.top();
                ans += c;
                s.pop();
            }
            s.push(str[i]);
        }
        
    }
    while(!s.empty()){
        char c = s.top();
        ans += c;
        s.pop();
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
  string str;
  cin>>str;
  string ans = infixToPostFix(str);
  cout<<ans<<endl;
  return 0;
}
