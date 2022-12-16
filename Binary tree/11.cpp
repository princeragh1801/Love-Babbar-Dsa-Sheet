// Mirror of a tree

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

struct Node
{
    int data;
    Node *left, *right;
    Node(int  x){
        this->data = x;
        this->left = this->right = NULL;
    }
};


void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    
}

// here we are creating just another tree
// extra space is required
Node *mirror(Node *root, Node* mir){
    if(root == NULL){
        return mir;
    }
    
    mir = new Node(root->data);
    mir->left = mirror(root->right, mir->left);
    mir->right = mirror(root->left, mir->right);

    return mir;
}

// we can change in original tree to get our answer
// no extra space is required
Node* mirrorify(Node*root){
    if(!root){
        return NULL;
    }

    // here we just swaping the nodes
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    if(root->left){
        mirrorify(root->left);
    }
    if(root->right){
        mirrorify(root->right);
    }
    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif


/*      5
       / \
      3   6
     / \
    2   4

*/
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    inorder(root);
    cout<<endl;
    inorder(mirror(root, NULL));
    cout<<endl;
    inorder(mirrorify(root));
    return 0;
}
