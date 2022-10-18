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

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

// Time 0(n^K)

vector<long long> printFirstNegativeInteger1(long long int A[],
                                             long long int N, long long int K) {
                  vector<long long> ans;
                  long long i = 0, j = 0;
                  
                  while(i < N-K+1){
                    j = i;
                    long long x = 0;
                    while(j < (i+K)){
                        if(A[j] < 0){
                            x = A[j];
                            
                            break;
                        }
                        j++;
                    }
                  
                    ans.push_back(x);   
                    i++;
                  }        
                  return ans;          
                            
 }

//  Efficient approach
//  Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(K)
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> ans;
    long long i = 0, j = 0;

    queue<int> q;
    int counter = 1;
    while(i < N){
        if(A[i] < 0){
            q.push(A[i]);
            counter = 0;
        }
        if(counter >= K){
            q.push(0);
        }
        counter++;
        i++;
    }     
    
    i = 0;
 
    while(i <N-K+1 && !q.empty()){
        ans.push_back(q.front());
        if(q.front() == 0){
            q.pop();
        }
        if(A[i] == q.front()){
            q.pop();

        }

        i++;
    }
    return ans;
                            
}