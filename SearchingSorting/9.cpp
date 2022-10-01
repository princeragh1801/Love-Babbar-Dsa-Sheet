//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:

    // Approach -1
    // Sort the array and check it
    // Time complexity 0(nlogn)
    int *findTwoElement(int *arr, int n) {
        // code here
        int missing = -1, repeating = -1;
        sort(arr, arr+n);
        int count = 1;
        int i = 1;
        while(i <= n){
            if(arr[i] == arr[i+1]){
                repeating = arr[i];
                arr[i] = 0;
                break;
            }
            i++;
            count++;
        }
        sort(arr, arr+n);
        for(int i = 0; i < n; i++){
            if(arr[i] != i+1){
                missing = i+1;
            }
        }
        arr[0] = repeating;
        arr[1] = missing;
        return arr;
    }


    // Time Complexity 0(n)
    // Space Complexity 0(n)
    int *findTwoElement(int *arr, int n) {
        // code here
        int aux[n+1] = {0};
        for(int i = 0; i < n; i++){
            aux[arr[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(aux[i] == 0){
                arr[1] = i;
            }
            if(aux[i] == 2){
                arr[0] = i;
            }
        }
        return arr;
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
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends