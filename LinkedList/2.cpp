//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


class Solution
{
    public:

    // Approach - 1
    // Extra 0(N) space required
    // struct node *reverse1(struct node *head, int k)
    // {
    //     // Complete this method
    //     vector<int> v;
    //     node *ptr = head;
    //     while (ptr != NULL)
    //     {
    //         v.push_back(ptr->data);
    //         ptr = ptr->next;
    //     }
    //     int x = 0;
    //     while (x + k <= v.size())
    //     {
            
    //         reverse(v.begin() + x, v.begin() + x + k);
    //         // debug(v);
    //         x += k;
    //     }
    //     if(x + k > v.size()-k){
    //         reverse(v.begin()+x, v.end());
    //     }
    //     // debug(v)
    //     ptr = head;
    //     // reverse(v.end() - k + 1, v.end());
    //     for (auto it : v)
    //     {
    //         ptr->data = it;
    //         ptr = ptr->next;
    //     }
    //     return head;
    // }



    struct node *revs(node*head){
        if(!head || !head->next){
            return head;
        }
        node *ptr = head;
        node *q = NULL;
        node* r = head->next;
        while(ptr){
            ptr->next = q;
            q = ptr;
            ptr = r;
            if(r){
                r = r->next;
            }
            
        }
        head = q;
        return q;
    }
    struct node *reverse(struct node *head, int k)
    { 
        // Complete this method
        node *start = head;
        node *end = head;
        
        node *prev = NULL;
        while(start && end){
            
            int i = 1;
            while(i < k && end){
                end = end->next;
                i++;
            }
            node *temp = end;
            if(end != NULL){
                
                temp = end->next;
                end->next = NULL;
            }
            
            
            if(prev == NULL){
                head = revs(start);
            }
            else{
                prev->next = revs(start);
            }
            prev = start;
            start = temp;
            end = temp;
        }
        // printList(head);
        return head;

    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
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
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        // head = ob.revev(head);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends

