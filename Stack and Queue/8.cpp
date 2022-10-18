// { Driver Code Starts
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




 // } Driver Code Ends
class Solution
{
    public:

    // Brute force approach 
    // Time 0(n^2)

    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement1(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans;
        long long i,j;
        for(i = 0; i < n; i++){
            int flag = 0;
            for(j = i+1; j < n; j++){
                if(arr[j] > arr[i]){
                    flag = 1;
                    ans.push_back(arr[j]);
                    break;
                }
            }
            if(flag == 0){
                ans.push_back(-1);
            }
        }
        return ans;
    }

    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans;
        stack<long long> s;
        
        long long i = n-1;
        while(i>=0){
            
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                if(s.top() <= arr[i]){
                    while(s.top() <= arr[i]){
                        s.pop();
                        if(s.empty()){
                            break;
                        }
                    }
                }
                if(s.empty()){
                    ans.push_back(-1);
                }
                else{
                    long long x = s.top();
                    ans.push_back(x);
                }
            }
            s.push(arr[i]);

            i--;
        }
        reverse(ans.begin(), ans.end());

        return ans;
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
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
  
}