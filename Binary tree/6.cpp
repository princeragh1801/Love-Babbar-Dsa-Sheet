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
    Node*left, *right;

    Node(int x){
        this->data = x;
        this->left = this->right = NULL;
    }
};

vector<int> leftView(Node*root){
    queue<Node*> q;
    if(root){
        q.push(root);
    }
    vector<int> ans;
    while(!q.empty()){
        queue<Node*> temp;
        root = q.front();
        ans.push_back(root->data);
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->left){
                temp.push(root->left);
            }
            if(root->right){
                temp.push(root->right);
            }
        }
        while(!temp.empty()){
            root = temp.front();
            q.push(root);
            temp.pop();
        }
    }
    return ans;
}
vector<int> rightView(Node* root){
    queue<Node*> q;
    if(root){
        q.push(root);
    }
    vector<int> ans;
    while(!q.empty()){
        root = q.front();
        ans.push_back(root->data);
        queue<Node*> temp;
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->right){
                temp.push(root->right);
            }
            if(root->left){
                temp.push(root->left);
            }
        }
        while(!temp.empty()){
            root = temp.front();
            temp.pop();
            q.push(root);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif
        
        /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    vector<int>ans = rightView(root);
    debug(ans);
    return 0;
}
