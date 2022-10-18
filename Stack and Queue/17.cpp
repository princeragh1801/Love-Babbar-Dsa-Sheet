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

class Mystack{
    public:
    stack<int> s;
    void insert_at_bottom(int x);
    
};

void Mystack :: insert_at_bottom(int x){
    if(s.empty()){
        s.push(x);
    }
    else{
        
        int y = s.top();
        
        s.pop();
        insert_at_bottom(x);
        s.push(y);
    }
}
void print(stack<int> st){
        while(!st.empty()){
            int x = st.top();
            cout<<x<<" ";
            st.pop();
        }
        cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
  Mystack *st = new Mystack;
  st->s.push(10);
  st->s.push(12);
  st->s.push(17);
  st->s.push(20);
  st->s.push(120);
  st->s.push(103);
  print(st->s);
  st->insert_at_bottom(181);
  print(st->s);
  return 0;
}
