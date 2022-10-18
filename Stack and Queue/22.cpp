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

// Work on it
class Dequeue{
    int front;
    int rear;
    int size = 500;
    int *arr;
    public:
    Dequeue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty(Dequeue dq){
        if(dq.front == dq.rear){
            return true;
        }
        return false;
    }

    bool isFull(Dequeue dq){
        if(dq.front == -1 && dq.rear == dq.size-1){
            return true;
        }
        return false;
    }
    void pushLast(Dequeue &dq, int x){
        if(dq.rear == dq.size -1){
            return;
        }
        dq.rear++;
        dq.arr[dq.rear] = x;
    }
    int popLast(Dequeue &dq ){
        if(isEmpty(dq)){
            return -1;
        }
        int x = dq.arr[dq.rear];
        dq.rear--;
        return x;
    }
    int popFirst(Dequeue &dq){
        if(isEmpty(dq)){
            return -1;
        }
        dq.front++;
        int x = dq.arr[dq.front];
        return x;
    }
    void pushFirst(Dequeue &dq, int x){
        if(dq.front == -1){
            return;
        }
        int z = dq.rear;
        dq.rear++;
        dq.arr[dq.rear] = dq.arr[z];
        int y = z;
        while (y != dq.front)
        {
            y--;
            dq.arr[z] = dq.arr[y];
            z--;
            y--;
        }
        dq.arr[y] = x;
    }
    void print(Dequeue dq){
        while(dq.rear != dq.front){
            cout<<dq.arr[dq.rear]<<" ";
            dq.rear--;
        }
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
    Dequeue dq;
    
    dq.pushLast(dq, 45);
    dq.pushLast(dq, 95);
    dq.pushLast(dq, 87);
    dq.pushLast(dq, 40);
    dq.pushLast(dq, 34);
    dq.pushLast(dq, 12);
    dq.pushLast(dq, 55);
    
    dq.print(dq);
  return 0;
}
