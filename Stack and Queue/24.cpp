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
    //Function to find distance of nearest 1 in the grid for each cell.


    // Brute force approach
	vector<vector<int>>nearest1(vector<vector<int>>grid)
	{
	    // Code here
        int n = grid.size();


        int m = (grid[0].size());

        int i,j,x,y;
        vector<vector<int>> ans;
        for(i = 0; i < n; i++){
            vector<int> inner;
            for(j = 0; j < m; j++){
                int minimumdist = n;
                for(x = 0; x < n; x++){
                    
                    for(y = 0; y < m; y++){
                        if(grid[x][y] == 1){
                            int dist = abs(i - x) + abs(j-y);

                            minimumdist = min(dist, minimumdist);
                            if(dist == 0){
                                break;
                            }
                        }
                    }
                }
                inner.push_back(minimumdist);
            }

            ans.push_back(inner);
        }


        return ans;
	}
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
        int n = grid.size();
        int m = (grid[0].size());
        vector<vector<int>> ans(grid);

        int i,j,x,y;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(ans[i][j] == 1){
                    ans[i][j] = 0;
                }
                else{
                    ans[i][j] = n;
                }
            }
        }
        
	}
};

//{ Driver Code Starts.
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends