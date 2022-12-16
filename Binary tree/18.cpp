//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:

    Node *tree(int in[], int inSt, int inEnd, int pre[], int preSt, int preEnd, unordered_map<int, int> &mp){
        if(preSt > preEnd || inSt > inEnd){
            return NULL;
        }

        // creating a new node
        Node *root = new Node(pre[preSt]);
        int inRoot = mp[root->data];
        int numLeft = inRoot - inSt;

        // connecting left
        root->left = tree(in, inSt, inRoot, pre, preSt+1, preSt+numLeft, mp);

        // connecting right
        root->right = tree(in, inRoot+1, inEnd, pre, preSt+numLeft+1, preEnd, mp);

        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[in[i]] = i;
        }
        Node * root = tree(in, 0, n-1, pre, 0, n-1, mp);
        return root;
    }
};

//{ Driver Code Starts.
int main()
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
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends