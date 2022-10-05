// { Driver Code Starts
// Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
public:
    // Function to reverse a linked list.

    // Reverse  the linked list iteratively
    // Time complexity 0(N)
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *ptr = head;
        Node *q = NULL;
        Node *r = head->next;

        while(r != NULL){
            ptr->next = q;
            q = ptr;
            ptr = r;
            r = r->next;
        }
        ptr->next = q;
        q = ptr;
        ptr = r;
        head = q;
        return head;
    }
    

    // Try recursive 
    // Currently it doesn't work 
    
    struct Node *reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *ptr = head;
        Node *q = NULL;
        Node *r = head->next;
        if(ptr != NULL){
            ptr->next = q;
            q = ptr;
            ptr = r;
            r = r->next;
            reverseList(ptr);
        }
        return head;
    }

    // Time complexity 0(N)
    // Space complexity 0(N)
    struct Node *reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *ptr = head;
        int n = 0;
        while (ptr != NULL)
        {
            n++;
            ptr = ptr->next;
        }
        int arr[n];
        int i = 0;
        ptr = head;
        while(ptr != NULL){
            arr[i] = ptr->data;
            i++;
            ptr = ptr->next;
        }
        int i = n-1;
        ptr = head;
        while(ptr != NULL){
            ptr->data = arr[i];
            i--;
            ptr = ptr->next;
        }
        
        return head;
    }
};

// { Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T, n, l, firstdata;
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;

        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;

        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob.reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends