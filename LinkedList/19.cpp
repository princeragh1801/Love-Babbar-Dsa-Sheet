#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for(ll int i = a; i < b; i++)
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
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}
// We can do that push all the elements in an array and check in it in 0(n^2)


// Another approach is that we took a set
// This uses 0(N) extra space

vector<pair<int, int>> findPairs1(Node *head, int k){
    unordered_set<int> s;
    vector<pair<int, int>> ans;
    while(head){
        int target = k - head->data;
        if(s.find(target) != s.end()){
            pair<int, int> p;
            p.first = target;
            p.second = head->data;
            ans.push_back(p);
        }
        s.insert(head->data);
        head = head->next;
    }
    return ans;
}


// If list is already sorted
// We can do it without using any extra space
vector<pair<int, int>> findPairs(Node *head, int k){
    
    vector<pair<int, int>> ans;
    Node *start = head;
    Node* end = head;
    while(end->next != NULL){
        end = end->next;
    }
    while(start != end){
        if(start->data + end->data == k){
            pair<int, int> p;
            p.first = start->data;
            p.second = end->data;
            ans.push_back(p);
            start = start->next;
            if(start != end){
                end = end->prev;
            }
        }
        else if(start->data +end->data < k){
            start = start->next;
        }
        else{
            end = end->prev;
        }
    }
    return ans;
}
void _solve(){
  ll n;
  cin>>n;
  vector<ll> v(n);
  for(auto &itr : v){cin>>itr;}
  
}

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
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
        int k;
        cin>>k;
        vector<pair<int, int>> v = findPairs(head, k);
        for(auto it : v){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
  return 0;
}
