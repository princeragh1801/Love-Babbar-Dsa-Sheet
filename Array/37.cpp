//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:

    // Brute force approach
    // Time 0(n+m)
    // Space 0(n+m)
    double MedianOfArrays1(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        vector<int> aux;
        int i = 0, j = 0;
        int n = array1.size(), m = array2.size();
        while(i < n && j < m){
            if(array1[i] <= array2[j]){
                aux.push_back(array1[i++]);
            }
            else{
               aux.push_back(array2[j++]);
            }
        }

        while(i < n){
            aux.push_back(array1[i++]);
        }

        while(j < m){
            aux.push_back(array2[j++]);
        }
        n = aux.size();
        double ans;

        if(n%2 == 0){
            ans = (1.0*(aux[n/2] + aux[n/2 - 1]))/2;
        }
        else{
            ans = aux[n/2];
        }
        return ans;
    }

    // here we can optimise our space
    // time 0(n+m)
    // space 0(1)
    double MedianOfArrays2(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int i = 0, j = 0;
        int n = array1.size(), m = array2.size();
        int indexWeWant = (n+m)/2;
        int cnt = 0;
        int ele1 = 0, ele2 = 0;
        while(i < n && j < m){
            int x;
            if(array1[i] <= array2[j]){
                x = array1[i];
                i++;
            }
            else{
               x = array2[j];
               j++;
            }
            cnt++;
            if(cnt == indexWeWant){
                ele1 = x;
            }
            if(cnt == indexWeWant+1){
                ele2 = x;
            }
        }
        while(i < n){
            if(cnt <= indexWeWant){
                cnt++;
            }
            if(cnt == indexWeWant){
                ele1 = array1[i];
            }
            else if(cnt == indexWeWant+1){
                ele2 = array1[i];
            }
            i++;
        }

        while(j < m){
            if(cnt <= indexWeWant){
                cnt++;
            }
            if(cnt == indexWeWant){
                ele1 = array2[j];
            }
            else if(cnt == indexWeWant+1){
                ele2 = array2[j];
            }
            j++;
        }
        double ans;
        if((n+m)%2 == 0){
            ans = (1.0*(ele1+ele2))/2;
        }
        else{
            ans = ele2;
        }
        return ans;
    }

    // Binary search approach
    // It's correct but giving runtime error(do check it)
    // Time Complexity: O(min(log m, log n))
    // Space Complexity 0(1)
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        
        
        
        
        int n = array1.size(), m = array2.size();
        if(n < m){
            return MedianOfArrays(array2, array1);
        }
        int low = 0, high = array1.size();
        int total = (n+m+1)/2;
       
        double ans;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        while(low <= high){
            int cut1 = (low+high)/2;
            int cut2 = total - cut1;
            
            l1 = (cut1 > 0) ? array1[cut1-1]:INT_MIN;
            l2 = (cut2 > 0) ? array2[cut2-1] : INT_MIN;
            
            r1 = (cut1 < n) ? array1[cut1] : INT_MAX;
            r2 = (cut2 < m) ? array2[cut2] : INT_MAX;

            // condition
            if(l1 <= r2 && l2 <= r1){
                ans = (max(l1, l2)+min(r1,r2))/2.0;
                if((n+m)%2 != 0){
                    ans = max(l1, l2);
                }
                break;
            }
            else if(l1 > r2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

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
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends