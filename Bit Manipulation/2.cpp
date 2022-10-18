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

// some basic problems on bitwise operators

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
    // set kth bit / on kth bit

    int k;
    cin>>k;
    int mask = 1;
    mask = mask<<k;
    bitset<32> bit1(a);
    bitset<32> bit2(mask|a);
    cout<<bit1<<"\n";
    cout<<bit2<<"\n";
    

    // Off kth bit 
    mask = 1;
    mask = mask<<k;
    mask = ~mask;
    bit2 = mask&a;
    cout<<bit2<<"\n";

    // toggle the bit
    // read more about it
    // mask = 1;
    // mask = mask<<k;
    // bit2 = mask^a;
    // cout<<bit2<<"\n";


    // check the nth bit is set or not
    mask = 1;
    mask = mask<<k;
    mask = mask&a;
    mask = mask&a;
    if(mask){
        yes;
    }
    else{
        no;
    }
    
    // multiply a number by 2
    a = a<<1;
    cout<<a<<endl;

    // divide a number by 2
    a = a>>1;
    cout<<a<<endl;

    // xor numbers from 1 to n (direct method) 0(n)
    int ans = 1;
    fo(i,2,b+1){
        ans = ans^i;
    }
    cout<<ans<<endl;

    // 0(1)
    if(b%4 == 0){
        ans = b;
    }
    else if(b%4 == 3){
        ans = 0;
    }
    else if(b%4 == 2){
        ans = b+1;
    }
    else{
        ans = 1;
    }
    cout<<ans<<endl;

    // how to know a number is power of 2 or not

    // basically do n&n-1 if it gives 0 that means true else false
    // if a number is power of two then its all bits are off exept the most significant one and a number previous to it i.e n-1 has all the bits on so if we take and of that two number it's result come out to be 0
    if(b&b-1){
        no;
    }
    else{
        yes;
    }

    // count set bits 
    int cnt = 0;
    while(b){
        cnt += (b&1);
        // right shift by 1 and check whether the last bit is on or not
        b = b>>1;
    }
    cout<<cnt<<endl;
    b = 1023;
    cnt = 0;
    while(b){
        b = b&(b-1);//the approach is basically that is we didn't check for unset bit we only check for all the set bits
        cnt++;
    }
    cout<<cnt<<endl;
    // position of rsb
    // Direct method
    int pos = 1;
    b = 1024;
    while(!(b&1)){
        pos++;
        b = b>>1;
    }
    cout<<pos<<endl;

    // using xor
    // basically we turn off all the bits except the rsb
    // then right shift untill number become 0 count the position
    b = 1024;
    b = (b&b-1)^b;
    pos = 0;
    while(b){
        b = b>>1;
        pos++;
    }
    cout<<pos<<endl;
  return 0;
}
