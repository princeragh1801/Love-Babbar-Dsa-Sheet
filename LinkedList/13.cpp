//{ Driver Code Starts
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


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    // Overall time complexity 0(nlogn)
    
    int isSorted(vector<ll> v, ll n){
        fo(i,1,n){
            if(v[i] < v[i-1]){
                return 0;
            }
        }
        return 1;
    }
    
    // Merging array
    // Time 0(high-low)
    // Space 0(high-low)
    void merge(vector<ll> &v, ll low, ll mid, ll high){
        ll i = low,j = mid+1;
        vector<ll> aux(high+1-low);
        ll k = 0;
        // copying all the elements of v in aux in sorted order
        while(i <= mid && j <= high){
            if(v[i] > v[j]){
                aux[k++] = v[j++];
            }
            else{
                aux[k++] = v[i++];
            }
        }
        while(i <= mid){
            aux[k++] = v[i++];
        }
        while(j <= high){
            aux[k++] = v[j++];
        }
      
        j = 0;
        fo(i,low,high+1){
            v[i] = aux[j++];
        }
    }
    
    void mergeSort1(vector<ll> &v, ll low, ll high){
    
        // Base case
        if(low >= high){
            return;
        }
    
        // Defining mid
        int mid = (low+high)/2;
    
        // Partitioning the array
        // from low to mid
        mergeSort1(v, low, mid);
        
        // from mid+1 to high
        mergeSort1(v, mid+1, high);
    
        // Merge array
        merge(v, low, mid, high);
    
        // This is for if got array sorted simply return
        if(isSorted(v, v.size())){
            return;
        }
    
    }
    // Try it without using vector/array
    Node* mergeSort(Node* head) {
        // your code here
        vector<ll> v;
         Node *temp = head;
         while(temp){
            v.push_back(temp->data);
            temp = temp->next;
         }
         ll low = 0;
         ll high = v.size()-1;
        mergeSort1(v, low, high);
        debug(v)
        temp = head;
        int i = 0;
        while(temp){
            temp->data = v[i++];
            temp = temp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends