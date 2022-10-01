//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:

    // Naive Approach 
    // Take an auxillary array
    // Push the elements insorted order 
    // return aux[k-1]
    // Time complexity 0(n+m)
    // Space complexity 0(n+m)
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0, j = 0;
        int aux[n+m];
        int x = 0;
        while(i < n && j < m){
            
            if(arr1[i] <= arr2[j]){
                aux[x++] =arr1[i++];
            }
            else{
                aux[x++] = arr2[j++];
            }
           
        }
        while(i < n){
            aux[x++] = arr1[i++];
        }
        while(j < m){
            aux[x++] = arr2[j++];
        }
        return aux[k-1];
    }

    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0, j = 0;
        int cnt = 0;
        while(i < n && j < m){
            if(cnt == k-1){
                return min(arr1[i], arr2[j]);
            }
            if(arr1[i] <= arr2[j]){
                i++;
            }
            else{
                j++;
            }
            cnt++;
        }
        if(i < n){
            return arr1[i+(k-cnt)];
        }
        else{
            return arr2[j+(k-cnt)];
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends