//{ Driver Code Starts
// driver
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
#define //debug(x)
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




/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:

    // int reverseNum(int n){
    //     int newNumber = 0;
    //     while(n>0){
    //         int lastdigit = n%10;
    //         newNumber = newNumber*10 +lastdigit;
    //         n/=10;
    //     }
    //     return newNumber;
    // }


    // This code perfectly work for small size linked list
    // 100 test cases passed out of 200

    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists1(struct Node* first, struct Node* second)
    {

        ll firstNumber = 0;
        while(first){
            int digit = first->data;
            firstNumber = firstNumber*10 + digit;
            first = first->next;
        }

        ll secondNumber = 0;
        while(second){
            int digit = second->data;

            secondNumber = secondNumber*10 + digit;
            second = second->next;
        }

        ll newNumber = firstNumber+secondNumber;
        Node *head = new Node(newNumber%10);

        newNumber /=10;
        while(newNumber > 0){
            int lastdigit = newNumber%10;
            Node *temp = new Node(lastdigit);
        
            temp->next = head;
            head = temp;

            newNumber /= 10;
        }
        return head;
    }



    // That approch works for all the testcases
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here

        vector<ll> A;
        vector<ll> B;
        while(first){
            A.push_back(first->data);
            first = first->next;
        }
       

        while(second){
            B.push_back(second->data);
            second = second->next;
        }
        ll n = A.size()-1, m = B.size()-1;
        
        int carry = 0;
        int number = 0;
        number = A[n]+B[m];
        n--;
        m--;
        carry = number/10;
        number = number%10;
        Node *head = new Node(number);
        head->next = NULL;
        while(n >= 0 && m >= 0){
            number = A[n]+B[m]+carry;
            n--;
            m--;
            carry = number/10;
            number = number%10;
            Node *temp = new Node(number);
            temp->next = head;
            head = temp;
        }

        while(n >= 0){
            number = A[n]+carry;
            carry = number/10;
            number = number%10;
            Node *temp = new Node(number);
            temp->next = head;
            head = temp;
            n--;
        }

        while(m >= 0){
            number = B[m]+carry;
            carry = number/10;
            number = number%10;
            Node *temp = new Node(number);
            temp->next = head;
            head = temp;
            m--;
        }
        while(carry > 0){
            number = carry%10;
            carry = carry/10;
            Node *temp = new Node(number);
            temp->next = head;
            head = temp;
        }
        return head;
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends