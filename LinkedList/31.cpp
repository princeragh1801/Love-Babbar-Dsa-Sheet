//{ Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
// } Driver Code Ends



//you have to complete this function

node * partition(node *left, node *right){
    int x = left->data;
    node *ptr = left;
    int cnt = 0;
    while(ptr != right){
        if(ptr->data <= x){
            cnt++;
        }
        ptr = ptr->next;
    }
    ptr = left;
    while(cnt > 1){
        ptr = ptr->next;
        cnt--;
    }
    node *mid = new node(x);
    mid->next = ptr->next;
    ptr->next = mid;
    ptr = mid->next;
    while(left != mid && ptr != right){
        if(left->data > x && ptr->data <= x){
            swap(left->data, ptr->data);
            left = left->next;
            ptr = ptr->next;
        }
        else if(left->data <= x){
            left = left->next;
        }
        else if(ptr->data > x){
            ptr = ptr->next;
        }
    }
    return mid;
}
void quickSort(struct node **headRef) {
    node *left = *headRef;
    node *right = NULL;
    node *mid = partition(left, right);
    
}