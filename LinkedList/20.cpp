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

// Base Approach is that use three nested loops and check for all possible cases

// It is more efficient than previos but it uses extra space
// It uses two nested loops only 
void countTriplets1(Node *head, int k){
    
    Node *first = head;
    
    int ans = 0;
    while(first->next->next){
        unordered_set<int> s;
        Node *second = first->next;
        while(second){
            int target = k -(first->data+second->data);
            if(s.find(target) != s.end()){
                ans++;
                cout<<first->data<<" "<<target<<" "<<second->data<<endl;
            }
            s.insert(second->data);
            second = second->next;
        }
        first = first->next;
    }
    cout<<endl;
    cout<<ans<<endl;
}

// If list is sorted
// We can get the result without using extra space
void countTriplets(Node *head, int k){
    
    Node *first = head;
    Node *second = head->next;
    Node *last = head;

    while(last->next != NULL){
        last = last->next;
    }

    int ans = 0;
    while(first != last){
        second = first->next;
        Node *last1 = last;
        while(second != last1){
            int x = first->data + second->data+last1->data;
            if(x == k){
                ans++;
                cout<<first->data<<" "<<second->data<<" "<<last1->data<<endl;

                // Here we are considering that their is no common element in list
                second = second->next;
                if(second != last1){
                    last1 = last1->prev;
                }
                
            }
            else if(x > k){
                last1 = last1->prev;
            }
            else{
                second = second->next;
            }
        }
        first = first->next;
    }
    cout<<endl;
    cout<<ans<<endl;
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
        countTriplets(head, k);
    }
  return 0;
}
