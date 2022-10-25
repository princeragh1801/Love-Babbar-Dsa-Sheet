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


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.

    // Not done
    vector<int> spirallyTraverse1(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int i, j, k, l, m;
        vector<vector<int>> auxMat(r);
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                auxMat[i].push_back(0);
            }
        }
        for(i = 0; i < r/2+1; i++){
            for(j = i; j < c-i; j++){
                if(auxMat[i][j] == 0){
                    ans.push_back(matrix[i][j]);
                    auxMat[i][j] = 1;
                }
                
            }
            // debug(ans)
            for(k = i+1; k < r-i; k++){
                if(auxMat[k][j-1] == 0){
                    ans.push_back(matrix[k][j-1]);
                    auxMat[k][j-1] = 1;
                }
            }
            // debug(ans)
            for(l = c-(i+2); l >= i; l--){
                if(auxMat[k-1][l] == 0){
                    
                    ans.push_back(matrix[k-1][l]);
                    auxMat[k-1][l] = 1;
                }
            }
            // debug(ans)
            for(m = r-(i+2); m > i; m--){
                if(auxMat[m][i] == 0){
                    ans.push_back(matrix[m][i]);
                    auxMat[m][i] = 1;
                }
                
            }
            // debug(ans)
        }
        // debug(ans)
        return ans;
    }


    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int top = 0, down = r-1, left = 0, right = c-1;
        int dir = 0;
        while(top <= down && left <= right){
            if(dir == 0){
                for(int i = top; i <= right; i++){
                    ans.push_back(matrix[top][i]);
                }
                dir = 1;
                top++;
            }
            else if(dir == 1){
                for(int i = top; i <= down; i++){
                    ans.push_back(matrix[i][right]);
                }
                dir = 2;
                right--;
            }
            else if(dir == 2){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[down][i]);
                }
                dir = 3;
                down--;
            }
            else if(dir == 3){
                for(int i = down; i > left; i--){
                    ans.push_back(matrix[i][left]);
                }
                dir = 0;
                left++;
            }
            // debug(ans)
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

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
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends