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

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        this->data = x;
        this->left = this->right = NULL;
    }
};

Node *stringToBT(string str){
    int x = str[0]-48;
    int j = 1;
    while(str[j] >= '0' && str[j] <= '9'){
        int t = str[j]-48;
        x = x*10 +t;
        j++;
    }
    Node *root = new Node(x);
    stack<Node*> st;
    st.push(root);
    int i = j;
    while(i < str.length()){
        if(str[i] == '('){
            i++;
        }
        else if(str[i] == ')'){
            i++;
            st.pop();
        }
        else{
            int x = str[i]-48;
            j = i+1;
            while(str[j] >= '0' && str[j] <= '9'){
                int t = str[j]-48;
                x = x*10 +t;
                j++;
            }
            Node *temp = new Node(x);
            root = st.top();
            if(!root->left){
                root->left = temp;
            }
            else{
                root->right = temp;
            }
            st.push(temp);
            i = j;
        }
    }
    root = st.top();
    return root;
}

void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif
    string str;
    cin>>str;
    Node *root = stringToBT(str);
    inorder(root);
    return 0;
}
