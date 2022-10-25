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

// if matrix is not sorted
// time 0(n*m)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

// time max(logn, logm)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = n-1, mid;
    int elementInrow = -1;
    while(low <= high){
        mid = (low+high)/2;
        if(matrix[mid][0] <= target && matrix[mid][m-1] >= target){
            break;
        }
        else if(matrix[mid][0] > target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    low = 0, high = m-1;
    int mid1 = 0;
    while(low <= high){
        mid1 = (low+high)/2;
        if(matrix[mid][mid1] == target){
            return true;
        }
        else if(matrix[mid][mid1] > target){
            high = mid1-1;
        }
        else{
            low = mid1+1;
        }
    }
    // for(int i = 0; i < m; i++){
    //     if(matrix[mid][i] == target){
    //         return true;
    //     }
    // }
    return false;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
  
  
  return 0;
}
