//{ Driver Code Starts
// C program to delete a given key from
// linked list.
#include<bits/stdc++.h>
using namespace std;

/* structure for a node */
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

Node *pre=NULL;

/* Function to delete a given node from the list */
//void deleteNode(struct Node *head, int key);
void deleteNode(Node **head,int data);
void reverse(Node **head);

/* Function to reverse the linked list */
//static void reverse(struct Node** head_ref);

/* Function to insert a node at the beginning of
a Circular linked list */

void push(struct Node **head_ref, int data)
{
	// Create a new node and make head as next
	// of it.

        struct Node *curr = new Node(data);

        curr->next=curr;
    
    	if(*head_ref==NULL)
        {
            *head_ref=curr;
            curr->next=*head_ref;
            pre=*head_ref;
    
        }
        else
        {
            curr->next=*head_ref;
            pre->next=curr;
            pre=pre->next;
    
    
        }
}

/* Function to print nodes in a given
circular linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		do
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		while (temp != head);
	}
    else
    cout<<"empty"<<endl;

	printf("\n");
}
/* Driver program to test above functions */
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
	/* Initialize lists as empty */
	int t,a,delnode;
	cin>>t;
	while(t--)
	{
        pre=NULL;
	   Node *head=NULL;
      
        int n;
	    cin>>n;
	    while(n--)
	    {
	        cin>>a;
	        push(&head,a);
	    }    
	/* Created linked list will be 2->5->7->8->10 */
	cin>>delnode;

	deleteNode(&head, delnode);
	
	reverse(&head);

	printList(head);
}
	return 0;
}

// } Driver Code Ends


/* structure for a node 
struct Node
{
	int data;
	struct Node *next;
};
*/

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{

// Your code goes here
    Node *prev = *head;
    Node *ptr = prev->next;
    if(head == NULL){
        return;
    }
    while (ptr)
    {
        if(ptr->data == key){
            prev->next = ptr->next;
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    if(!head_ref){
        return;
    }
    
    Node *temp = *head_ref;
    while(temp->next != *head_ref){
        temp = temp->next;
    }
    Node *last = temp;
    Node *prev = last;
    Node *ptr = *head_ref;
    Node *post = ptr->next;
    do
    {
        ptr->next = prev;
        prev = ptr;
        ptr = post;
        post = post->next;
    } while (post != last);
    ptr->next = prev;
    prev = ptr;
    last->next = ptr;
    *head_ref = last;
}
