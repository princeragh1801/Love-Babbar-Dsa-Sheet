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

vector<int> topView(Node *root){
    vector<int> ans;
    queue<pair<Node*, int>> q;
    map<int, int> mp;
    if(root){
        q.push({root, 0});
    }
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        root = it.first;
        int line = it.second;
        if(!mp[line]){mp[line] = root->data;}

        if(root->left){
            q.push({root->left, line-1});
        }
        if(root->right){
            q.push({root->right, line+1});
        }
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

vector<int> bottomView(Node* root){
    vector<int> ans;
    queue<pair<Node*, int>> q;
    map<int, int> mp;
    if(root){
        q.push({root, 0});
    }

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        root = it.first;
        int line = it.second;
        mp[line] = root->data;
        if(root->left){
            q.push({root->left, line-1});
        }
        if(root->right){
            q.push({root->right, line+1});
        }
    }

    for(auto it : mp){
        ans.push_back(it.second);
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
    vector<int>ans = bottomView(root);
    debug(ans);
    return 0;
}
