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



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif
    int a, b;
    cin>>a>>b;
    cout<<(a&b)<<"\n";
    cout<<(a|b)<<"\n";
    cout<<(a^b)<<"\n";
    

    // !~ (One's complement this basically toggle all the bits/ change the bit to 0 if it is 1 and change the bit to the 1 if it is 0)
 
    // cout<<(~a)<<"\n";

    // Left shift operator basically if we leftshift a number by k so are multiplying that number by 2 k times
    a = a<<3;
    cout<<a<<endl;

    // Similar here >> (right shift) if we right shift a number by k so we are dividing 2 k times
    a = a>>3;
    cout<<a<<"\n";

    bitset<32> bit1(a);
    cout<<bit1<<"\n";

    return 0;
}
