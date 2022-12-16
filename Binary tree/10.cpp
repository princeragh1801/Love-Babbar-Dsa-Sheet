#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for(int i = a; i < b; i++)
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

#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

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
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    // function for  checking the current node is leaf node or not
    bool isLeaf(Node *root){
        if(root->left || root->right){
            return false;
        }
        return true;
    }

    // pushing the left boundary to our ans
    void leftBoundary(Node *root, vector<int> &ans){
        Node * curr = root->left;
        while(curr){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
            if(curr->left){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
    }
    // pushing the bottom(leaf nodes) boundary to our ans
    void BottomBoundary(Node *root, vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
        }
        if(root->left){BottomBoundary(root->left, ans);}
        if(root->right){BottomBoundary(root->right, ans);}
    }
    // pushing the right boundary in reverese order to our ans
    void rightBoundary(Node *root, vector<int> &ans){
        Node * curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        for(int i = temp.size()-1; i >= 0; i--){
            ans.push_back(temp[i]);
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        // if root is null
        if(!root){
            return ans;
        }
        // if root is not a leaf node
        if(!isLeaf(root)){ans.push_back(root->data);}
        leftBoundary(root, ans);
        
        BottomBoundary(root, ans);
        rightBoundary(root, ans);

        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends