//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
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
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends


// Briute force
int kthSmallest1(int mat[MAX][MAX], int n, int k)
{
    //Your code here
    vector<int> aux;
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            aux.push_back(mat[i][j]);
        }
    }
    sort(aux.begin(), aux.end());
    return aux[k-1];
}


int lessThanX(int arr[], int n, int x){
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] <= x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
// binary search based approach 
int kthSmallest2(int mat[MAX][MAX], int n, int k)
{
    //Your code here
    int low = mat[0][0], high = mat[n-1][n-1], mid;
    while(low <= high){
        mid = (low+high)/2;
        int totalEle = 0;
        for(int i = 0; i < n; i++){
            int cnt = lessThanX(mat[i], n, mid);
            totalEle += cnt;
        }
        if(k > totalEle){
            low = mid+1;
        }
        else {
            high = mid-1;
        }
        
    }
    return low;
}

// min heap based approach (priority queue)
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    //Your code here
    priority_queue <int, vector<int>, greater<int>> g;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            g.push(mat[i][j]);
        }
    }
    while(k > 1){
        g.pop();
        k--;
    }
    return g.top();
}
