//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {


	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */



// One approach is that 
// We can use extra space 
// push all the elements in an array and sort it made another list return it's head

// Time 0(n+m)l0g(n+m)
// Space 0(n+m)
Node *flatten1(Node *root)
{
   // Your code here

   vector<int> v;
   while(root){
    v.push_back(root->data);
    Node *q = root;
    while(q->bottom){
        v.push_back(q->bottom->data);
        q = q->bottom;
    }
    root = root->next;
   }
   sort(v.begin(), v.end());
    Node *head = new Node(v[0]);
    Node *ptr = head;
    for(int i = 1; i < v.size(); i++){
        Node *temp = new Node(v[i]);
        ptr->bottom = temp;
        ptr = temp;
    }
    return head;

}


// This approach uses merging
Node *merge(Node *left, Node *right){
    if(!left){
        return right;
    }
    if (!right)
    {
        return left;
    }

    Node *result = new Node(-1);
    Node *ptr = result;

    while(left && right){
        if(left->data <= right->data){
            ptr->bottom = left;
            ptr = left;
            left = left->bottom;
        }
        else{
            ptr->bottom = right;
            ptr = right;
            right = right->bottom;
        }
    }
    while(left){
        ptr->bottom = left;
        ptr = left;
        left = left->bottom;
    }

    while(right){
        ptr->bottom = right;
        ptr = right;
        right = right->bottom;
    }
    ptr->bottom = NULL;
    result = result->bottom;
    return result;
    
}
Node *flatten(Node *root)
{
   // Your code here
    Node *result = NULL;

    while(root){
        result = merge(result, root);
        root = root->next;
    }

    return result;
}

