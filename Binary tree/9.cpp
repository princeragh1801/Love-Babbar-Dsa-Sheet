// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.

    // at each point difference of height is <= 1 so it is a balanced binary tree
    // Not done
    // 0(N^2)
    int leftheight(Node *root){
        if(!root){
            return 0;
        }
        int lh = leftheight(root->left);
        int rh = leftheight(root->right);
        return 1+lh+rh;
    }
    int rightheight(Node *root){
        if(!root){
            return 0;
        }
        int rh = rightheight(root->right);
        int lh = rightheight(root->left);
        return 1+rh+lh;
    }

    bool isBalanced1(Node *root)
    {
        //  Your Code here
        if(!root){
            return true;
        }
        int lh = leftheight(root);
        int rh = rightheight(root);
        if(abs(lh-rh) > 1){
            return false;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right){
            return false;
        }
        return true;
    }

    // Approach 2
    // 0(N)
    // done
    int height(Node *root){
        if(!root){
            return 0;
        }
        int lh = height(root->left);
        if(lh == -1){return -1;}
        int rh = height(root->right);
        if(rh == -1){return -1;}
        
        if(abs(lh-rh) > 1){
            return -1;
        }
        return max(lh, rh)+1;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return height(root) != -1;
    }
};


// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   ios_base::sync_with_stdio(false);cin.tie(NULL);
     #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("error.txt", "w", stderr);
      freopen("output.txt", "w", stdout);
      #endif
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends