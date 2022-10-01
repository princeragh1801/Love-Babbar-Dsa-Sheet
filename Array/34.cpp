//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    // Approach - 1
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        //Using two pointers which help in finding the index with which
    //the elements need to be swapped if they are not in correct position. 
        sort(arr.begin(), arr.end());

    }

    // Approach - 2
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        //Using two pointers which help in finding the index with which
    //the elements need to be swapped if they are not in correct position. 
        map<int, int> m;
        int i = 0;
        for(i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }
        
        for(auto it:m){
            if(it.second >= 2){
                while(it.second){
                    arr[i++] = it.first;
                    it.second--;
                }
            }
            else{
                arr[i++] = it.first;
            }
            
        }
    }

    // Approach - 3
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        //Using two pointers which help in finding the index with which
    //the elements need to be swapped if they are not in correct position. 
        int low = 0, mid = 0, high = arr.size()-1;

        while(mid < high){
            if(arr[mid] <= a){
                swap(arr[mid++], arr[low++]);
            }
            else if(arr[mid] >= a && arr[mid] <= b){
                mid++;
            }
            else{
                swap(arr[high--], arr[mid]);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        
        vector<int> array(N);
        unordered_map<int,int> ump;
        
        for(int i=0;i<N;i++){
            cin>>array[i];
            ump[array[i]]++;
        }
        
        int a,b;
        cin>>a>>b;
        
        vector<int> original = array;

        int k1=0,k2=0,k3=0;
        int kk1=0;int kk2=0;int kk3=0;
        
        for(int i=0; i<N; i++)
        {
            if(original[i]>b)
                k3++;
            else if(original[i]<=b and original[i]>=a)
                k2++;
            else if(original[i]<b)
                k1++;
        }
        
        Solution ob;
        ob.threeWayPartition(array,a,b);
      
        for(int i=0;i<k1;i++)
        {
            if(array[i]<b)
            kk1++;
        }
        
        for(int i=k1;i<k1+k2;i++)
        {
            if(array[i]<=b and array[i]>=a)
            kk2++;
            
        }
        
        for(int i=k1+k2;i<k1+k2+k3;i++)
        {
            if(array[i]>b)
            kk3++;
        }
        bool ok = 0;
        if(k1==kk1 and k2 ==kk2 and k3 == kk3)
            ok = 1;
        
        for(int i=0;i<array.size();i++)
            ump[array[i]]--;
        
        for(int i=0;i<array.size();i++)
            if(ump[array[i]]!=0)
                ok=0;
        
        if(ok)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        
    }
    
    return 0;
}

// } Driver Code Ends