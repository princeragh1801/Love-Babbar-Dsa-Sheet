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

    void debugList(Node *head){
        while(head){
            cerr<<head->data<<" ";
            head = head->next;
        }
        cerr<<endl;
    }
    //Function to sort the given linked list using Merge Sort.
    // Overall time complexity 0(nlogn)
    

    Node *findMid(Node *head){
        Node *slow = head;
        Node *fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Node *merge(Node *left, Node *right){

        if(left == NULL){
            return right;
        }

        if(right == NULL){
            return left;
        }
        
        Node *ans = new Node(0);
        Node *ptr = ans;
        while(left && right){
            if(left->data <= right->data){
                
                ptr->next = left;
                ptr = left;

                left = left->next;
            }
            else{
                
                ptr->next = right;
                ptr = right;
    
                right = right->next;
            }
        }
 

        while(left){
            
            ptr->next = left;
            ptr = left;
            
            left = left->next;
        }
        while(right){
           
            ptr->next = right;
            ptr = right;
           
            right = right->next;
        }
       ans = ans->next;
       return ans;
    }

    Node* mergeSort(Node* head) {
        // your code here
        if(!head || !head->next){
            return head;
        }

        Node *mid = findMid(head);

        Node *left = head;
        Node *right = mid->next;

        mid->next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);


        Node * result = merge(left, right);
        // debugList(result);
        return result;
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