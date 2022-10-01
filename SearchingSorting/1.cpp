// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 // Approach -1
 // Iterate throught the array
 // Two pointer approach
 // Time Complexity 0(n)
 
vector<int> find1(int arr[], int n , int x )
{
    // code here
    int first = -1, last = -1;
   int i = 0, j = n-1;
   vector<int> ans;
   while(i <= j){
    if(arr[i] == x && arr[j] == x){
        first = i;
        last = j;
        break;
    }
    if(arr[i] != x){
        i++;
    }
    else if(arr[j] != x){
        j--;
    }
   }
   ans.push_back(first);
   ans.push_back(last);
   return ans;
}

// Approach - 2
// Better Approach to solve it 
// Sorted Array
// Binary Search
// Time Complexity 0(logn)

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans;
    int first = -1, last = -1;

    int low = 0, high = n -1, mid = 0;
    
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] == x){
            int in = mid;
            while(arr[mid] == x){
                mid--;
            }
            first = mid+1;
            mid = in;
            while(arr[mid] == x){
                mid++;
            }
            last = mid-1;
            break;
        }

        else if(arr[mid] > x){
            high = mid-1;
        }
        else{
            low = mid +1;
        }
    }

    ans.push_back(first);
    ans.push_back(last);
    return ans;
}
// { Driver Code Starts.

int main()
{
    #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends