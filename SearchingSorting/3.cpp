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

// Approach -1
// Naive Approach
// Iterate through the array and check
// Linear Search
// Time Complexity 0(n)


int search(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] == target){
            return i;
        }
    }
    return -1;
}

// Approach - 2
// Binary Search
// If array is sorted 
// Time Complexity 0(logn)

// cyclic rototed array
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    if(nums[high] >= target){
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;

            }
            else if(nums[mid] > target){
                if(nums[mid] > nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                low = mid+1;
            }
        }
    }
    else{
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                if(nums[mid] < nums[n-1]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
    }
    
    return -1;
}
void _solve(){
    int n, target;
    cin>>n>>target;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    int x = search(v, target);
    cout<<x<<endl;
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
  
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    _solve();
    
  }
  return 0;
}
