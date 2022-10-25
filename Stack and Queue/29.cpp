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

class kStacks{
    int *arr;
    int *top;
    int* next;

    int noOfstacks, size;
    int freespot;
    public:
        kStacks(int N, int s){
            noOfstacks = N;
            size = s;
            arr = new int [size];
            next = new int [size];
            top = new int [noOfstacks];

            // initialise freespot
            freespot = 0;


            // intialise next 
            fo(i,0,size){
                next[i] = i+1;
            }
            next[size-1] = -1;

            // intialise top
            fo(i,0,noOfstacks){
                top[i] = -1;
            }
        }
        void push(int x, int sn);

        int pop(int sn);
};


void kStacks :: push(int x, int sn){
    // check for overflow
    if(freespot == -1){
        cout<<"Stack overflow "<<"\n";
        return;
    }

    // find free index
    int index = freespot;

    // update freespot
    freespot = next[index];

    // push the element to index
    arr[index] = x;
    cout<<"Pushed successfully to stack number "<<sn<<" "<<arr[index]<<endl;
    // update next[index]
    next[index] = top[sn-1];

    // update top of current stack
    top[sn-1] = index; 
}

// just reverse the push process
int kStacks :: pop(int sn){
    // check underflow condition
    if(top[sn-1] == -1){
        cout<<"Stack underflow "<<sn<<"\n";
        return -1;
    }

    int index = top[sn-1];

    top[sn-1] = next[index];

    next[index] = freespot;

    freespot = index;
    cout<<"Popped successfully to stack number "<<sn<<" "<<arr[index]<<endl;
    return arr[index];
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
    
    int size, n;
    cin>>size>>n;
    kStacks st(n, size);

    st.push(10, 1);
    st.push(3, 1);
    st.push(110, 2);
    st.push(56, 0);
    st.push(10, 1);
    st.push(98, 0);
    st.push(102, 2);
    st.pop(1);
    st.pop(2);
    st.pop(0);
    st.pop(1);
    st.pop(0);
    cout<<st.pop(0)<<"\n";
    st.pop(2);
    return 0;
}
