// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    // Try to solve the problem without using any extra space.
    Node *compute1(Node *head)
    {
        // your code goes here
        if(!head || !head->next){
            return head;
        }
        vector<int> aux;
        Node *ptr = head;
        while(ptr){
            aux.push_back(ptr->data);
            ptr = ptr->next;
        }
        int n = aux.size();
        int currMax = aux[n-1];
        for(int i = n-2; i >= 0; i--){
            if(aux[i] < currMax){
                aux[i] = -1;
            }
            else{
                currMax = aux[i];
            }
        }
        ptr = head;
        for(auto it : aux){
            if(it != -1){
                ptr = ptr->next;
                ptr->data = it;
                
            }
        }
        ptr->next= NULL;
        head = head->next;
        return head;
    }


  
    // Basically we reverse the list first
    // then we take an currMin variable and checking if a value greater than it found put it in the new list 
    // point the last pointer's next to the null
    // again reverse the list 
    // this is the desired result we are looking for

    // No extra space
    //  Time 0(n)
    Node *reverse(Node*head){

        if(!head || !head->next){
            return head;
        }
        Node *ptr = head;
        Node *prev = NULL;
        Node *post = head->next;
        while(ptr){
            ptr->next = prev;
            prev = ptr;
            ptr = post;
            if(post){
                post = post->next;
            }
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if(!head || !head->next){
            return head;
        }
        
        head = reverse(head);
        Node *newList = new Node(-1);
        Node *ptr = newList;
        int currMin = -1;
        while(head){
            if(head->data >= currMin){
                ptr->next = head;
                ptr = head;
                currMin = head->data;
            }
            head = head->next;
        }
        ptr->next = NULL;
        newList = newList->next;
        head = reverse(newList);
        return head;
    }
    
};
   


// { Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends