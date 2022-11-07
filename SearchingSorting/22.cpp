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
bool canPlaceCows(vector<int> v, int dist, int cows){
    
    int cnt = 0;
    int n = v.size();
    cnt = 1;
    int indOfprevCow = 0;
    fo(i,1,n){
        if(v[i]-v[indOfprevCow] >= dist){
            indOfprevCow = i;
            cnt++;
        }
        if(cnt == cows){
            return true;
        }
    }

    return false;
}
void _solve(){
    int n, c;
    cin>>n>>c;
    vector<int> v(n);
    for(auto &itr : v){cin>>itr;}
    sort(beg(v));

    int low = v[0];
    int high = v[n-1];
    int maxDist = v[n-1]-v[0];
    int dist = 0;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if(canPlaceCows(v, mid, c)){
            dist = max(mid, dist);
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<dist<<endl;
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
