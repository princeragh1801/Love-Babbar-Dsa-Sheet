//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.

        // Approach -1
        // Take an auxillary array 
        // Compare and push all the elements
        // After push the elements in arr1, arr2
        // Time Complexity 0(n)
        // Space Complexity 0(n+m)
        void merge1(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int temp[n+m];
            int i = 0, j = 0, k = 0;
            while(i < n && j < m){
                if(arr1[i] <= arr2[j]){
                    temp[k++]=arr1[i++];
                }
                else{
                    temp[k++] = arr2[j++];
                }
            }
            while(i < n){
                temp[k++] = arr1[i++];
            }
            while(j < m){
                temp[k++] = arr2[j++];
            }
            
            k = 0;
            for(i = 0; i < n; i++){
                arr1[i] = temp[k++];
            }
            for(i = 0; i < m; i++){
                arr2[i] = temp[k++];
            }
            
        } 

        // Approach - 2
        // Compare and swap the values
        // Always keep both the arrays sorted
        // Time Complexity Similar to 0(n^2logn)
        void merge2(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i = 0, j = 0;
            while(i < n){
                if(arr1[i] > arr2[j]){
                    swap(arr1[i], arr2[j]);       
                    sort(arr2, arr2+m);
                }
                i++;
            }
            
        } 

        // Approach - 3
        // It is Similar to Approach -2 but 
        // Here we increment j if arr1[i] < arr2[j] simply increment i
        // Else swap(arr2[j], arr1[k])
        // Increment j decrement k
        // No extra space required
        // Time Complexity O((n+m)log(n+m))
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i = 0, j = 0, k = n-1;
            while(i <= k && j < m){
                if(arr1[i] <= arr2[j]){      
                    i++;
                }
                else{
                    swap(arr1[k--], arr2[j++]); 
                }
                
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        } 

        // [Using Euclidean Division Lemma] Linear Time Complexity(Read it)
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
        cout<<endl;
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends