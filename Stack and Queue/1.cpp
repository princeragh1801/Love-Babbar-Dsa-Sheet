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

/*Implementation of stack from scratch */

const int maxi = 100;
class myStack{
    int top;
    public:
    int arr[maxi];
    myStack(){top = -1;}
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(top == maxi-1){
            return true;
        }
        return false;
    }
    void push(int x){
        if(isFull()){
            return;
        }
        top++;
        arr[top] = x;
        cout<<"Pushed "<<x<<"\n";
    }
    void pop(){
        if(isEmpty()){
            cout<<"Can't pop"<<"\n";
            return;
        }
        int x = arr[top];
        top--;
        cout<<"Poped "<<x<<"\n";
    }
    
};

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
  
  myStack st;
    int n;
    cin>>n;
    fo(i,0,n){
        int x;
        cin>>x;
        st.push(x);
    }
  
    while(!st.isEmpty()){
        st.pop();
    }
  return 0;
}
