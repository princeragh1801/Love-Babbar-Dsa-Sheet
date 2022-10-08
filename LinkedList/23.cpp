//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.

    // This approach uses hashing
    // And we are swapping the data here basically
    Node* segregate1(Node *head) {
        
        // Add code here
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        Node *ptr = head;
        while(ptr){
            if(ptr->data == 0){
                cnt0++;
            }
            else if(ptr->data == 1){
                cnt1++;
            }
            else{
                cnt2++;
            }
            ptr = ptr->next;
        }
        ptr = head;
        while(cnt0--){
            ptr->data = 0;
            ptr = ptr->next;
        }
        while(cnt1--){
            ptr->data = 1;
            ptr = ptr->next;
        }
        while(cnt2--){
            ptr->data = 2;
            ptr = ptr->next;
        }
        return head;
    }


    // Time Complexity: O(n)
    // No extra space 
    Node* segregate(Node *head) {
        if(!head || !(head->next)){
            return head;
        }
        Node *zeroD = new Node(0);
        Node *oneD = new Node(0);
        Node *twoD = new Node(0);
        
        Node *zero = zeroD;
        Node *one = oneD;
        Node *two= twoD;
        Node *ptr = head;
        while(ptr){
            if(ptr->data == 0){
                zero->next = ptr;
                zero = zero->next;
            }
            else if(ptr->data == 1){
                one->next = ptr;
                one = one->next;
            }
            else{
                two->next = ptr;
                two = two->next;
            }
            ptr = ptr->next;
        }
        zero->next = oneD->next ? oneD->next:twoD->next;
        one->next = twoD->next;
        two->next = NULL;
        head = zeroD->next;

        delete zeroD;
        delete oneD;
        delete twoD;

        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends