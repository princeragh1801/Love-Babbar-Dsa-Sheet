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
void recursivelyPrint1toN(int n, int it){
    if(it > n){
        return;
    }
    cout<<it<<" ";
    recursivelyPrint1toN(n, it+1);
    
}
void recursivelyPrintNto1(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" ";
    recursivelyPrintNto1(n-1);
    
}
int sumOfN(int n){
    if(n == 1){
        return 1;
    }
    return n + sumOfN(n-1);
}

int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n*fact(n-1);
}

void reverseArray(int arr[], int low, int high){
    if(low >= high){
        return;
    }
    swap(arr[low], arr[high]);
    reverseArray(arr,low+1, high-1);
}
int checkPallin(string &str, int low , int high){
    if(low >= high){
        return 1;
    }
    if(str[low] != str[high]){
        return 0;
    }

    checkPallin(str, low+1, high-1);
}
int fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
void _solve(){
    int n;
    cin>>n;
    int arr[n];
    fo(i,0,n){cin>>arr[i];}
    string str;
    cin>>str;
    recursivelyPrint1toN(n, 1);
    cout<<endl;
    recursivelyPrintNto1(n);
    cout<<endl;
    cout<<sumOfN(n)<<endl;
    cout<<fact(n)<<endl;
    reverseArray(arr, 0, n-1);
    fo(i,0,n){cout<<arr[i]<<" ";}cout<<endl;
    cout<<checkPallin(str, 0, str.length()-1)<<endl;
    cout<<fibonacci(n)<<endl;
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
