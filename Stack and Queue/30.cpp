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

class nQueue{
    int *arr;
    int *front;
    int *rear;
    int *next;

    int size, N;
    int freespot;

    public:
        nQueue(int n, int s);

        void enqueue(int x, int qn);

        int dequeue(int qn);
};

nQueue :: nQueue(int n, int s){
    size = s;
    N = n;
    arr = new int [size];
    front = new int [N];
    rear = new int [N];
    next = new int [size];

    // initialise front and rear
    fo(i,0,N){
        front[i] = rear[i] = -1;
    }
    fo(i,0,size){
        next[i] = i+1;
    }
    next[size-1] = -1;

    // initialise freespot
    freespot = 0;
}

void nQueue ::enqueue(int x, int qn){
    if(freespot == -1){
        cout<<"No space left to enqueue"<<endl;
        return;
    }

    // initialise index
    int index = freespot;

    // push the element to queue
    arr[index] = x;

    // update freespot
    freespot = next[index];

    // update next[index]
    next[index] = rear[qn-1];

    // update rear
    rear[qn-1] = index;

    cout<<"Enqueue successfully "<<arr[index]<<endl;
}

int nQueue :: dequeue(int qn){
    // queue underflow condition
    if(front[qn-1] == rear[qn-1]){
        cout<<"can't dequeue"<<endl;
        return  -1;
    }

    int index = rear[qn-1];

    rear[qn-1] = next[index];

    next[index] = freespot;

    freespot = index;
    cout<<"Dequeue successfully "<<arr[index]<<endl;
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
  
  nQueue q(3, 10);

  q.enqueue(120, 0);
  q.enqueue(10, 1);
  q.enqueue(67, 0);
  q.enqueue(98, 2);
  q.enqueue(87, 1);
  q.enqueue(65, 0);
  q.enqueue(90, 2);
  
  q.enqueue(80, 1);

  q.dequeue(2);
  q.dequeue(2);
  q.dequeue(2);
  q.dequeue(2);
  return 0;
}
