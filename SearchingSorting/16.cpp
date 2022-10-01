#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for(ll int i = a; i < b; i++)
#define mod 1000000007
#define beg(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second
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
/******************************** prince1801 *********************************/

void _solve(){
  ll n,q;
  cin>>n>>q;
  vector<pair<ll, ll>> VP;
  
  fo(i,0,n){
    pair<ll,ll> p;

    ll a,b;
    cin>>a>>b;
    p.first = a;
    p.second = b;
    VP.pb(p);
  }
  sort(beg(VP));
  vector<pair<ll,ll>> ranges;
//   fo(i,0,n){
//     debug(VP[i].first)
//     debug(VP[i].second)
//   }
  ll i = 0;
  ll totalElements = 0;
  while(i < n){
    pair<ll,ll> p;
    p.first=VP[i].first;
    ll currMax = VP[i].second;
    if(currMax >= VP[i+1].first && i < n){
        while(currMax >= VP[i+1].first  && i < n){
            

            currMax = max(currMax, VP[i+1].second);
            //  debug(currMax)
            //  debug(VP[i+1].second)
            i++;
        }
        
        // i--;
    }
    // debug(currMax)
    p.second = currMax;
    debug(p.first);
    debug(p.second);
    totalElements += p.second-p.first;
    ranges.pb(p);
    i++;
  }
  totalElements++;
  debug(totalElements)
  fo(i,0,q){
    ll k;
    cin>>k;
    ll j = 0;
    ll ans = -1;
   
    while(j < ranges.size() && k <= totalElements){
       //ll x = ranges[j].first + k;
    //    debug(ranges[j].first)
    //    debug(k)
    //    debug(ranges[j].second)
       if(k <= ranges[j].second-ranges[j].first){
            ans = ranges[j].first+k-1;
            //debug(ans)
            break;
       }
       k -= (ranges[j].second-ranges[j].first+1);
       j++;
    }
   debug(ans)
    cout<<ans<<endl;
  }
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
/*
1
10 30
229 464
985 989
467 560
698 858
730 977
803 909
669 824
639 657
603 685
251 518
1583
270
207
1755
616
239
1263
365
165
1808
1305
1118
1369
344
648
298
1575
1069
1875
203
1318
1090
1958
1202
502
1822
193
151
978
819
*/ 

/*
1
10 30
386 812
871 980
532 882
671 829
206 521
986 996
585 867
328 832
68 938
54 749
230
1852
1002
1444
324
212
347
1096
1684
1562
625
497
779
1613
1282
1422
231
1687
1550
201
198
1649
1041
512
1282
1454
918
937
1436
1309
*/ 