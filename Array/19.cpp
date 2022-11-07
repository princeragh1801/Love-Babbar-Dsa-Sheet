#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    // Approach -1 
    // Brute Force Approach
    // Time Complexity 0(n^2)

    long long int inversionCount1(long long arr[], long long N)
    {
        // Your Code Here
        long long int j, i, inv_count = 0;
        for (i = 0; i < N - 1; i++)
        {
            for (j = i + 1; j < N; j++)
            {
                if (arr[i] > arr[j])
                {
                    inv_count++;
                }
            }
        }
        return inv_count;
    }


    // Approach -2 
    // Using multiset
    // Worst Case Time Complexity 0(n^2)
    // Space Complexity 0(n)
    long long int inversionCount2(long long arr[], long long N)
    {
        // Your Code Here
        long long int i, inv_count = 0;
        
        multiset<int> m;
        
        m.insert(arr[0]);
        multiset<int> ::iterator it;
        for (i = 1; i < N; i++)
        {
            m.insert(arr[i]);
            it = m.upper_bound(arr[i]);
            inv_count += distance(it, m.end());
        }
        return inv_count;
    }

    // Merge sort approach 
    // Time complexity 0(nlogn)
    // Overall time complexity 0(nlogn)
    
  
    // Merging array
    // Time 0(high-low)
    // Space 0(high-low)
    long long merge(long long int v[], long long low, long long mid, long long high){
        long long i = low,j = mid;
        vector<long long> aux(high+1-low);
        long long k = 0;
        long long inv_cnt = 0;
        // copying all the elements of v in aux in sorted order
        while(i <= mid-1 && j <= high){
            if(v[i] <= v[j]){
                aux[k++] = v[i++];
                
            }
            else{
                aux[k++] = v[j++];
                inv_cnt = inv_cnt + (mid-i);
            }
        }
        while(i <= mid-1){
            aux[k++] = v[i++];
        }
        while(j <= high){
            aux[k++] = v[j++];
        }
      
        j = 0;
        for(i = low; i < high+1; i++){
            v[i] = aux[j++];
        }
        return inv_cnt;
    }
    
    long long mergeSort(long long v[], long long low, long long high){
        long long inv_cnt = 0;
        if(high > low){
    
        // Defining mid
        long long mid = (low+high)/2;
    
        // Partitioning the array
        // from low to mid
        inv_cnt += mergeSort(v, low, mid);
        
        // from mid+1 to high
        inv_cnt += mergeSort(v, mid+1, high);
    
        // Merge array
        inv_cnt += merge(v, low, mid+1, high);
        }

        return inv_cnt;
    
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N-1);
    }

};

// { Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends