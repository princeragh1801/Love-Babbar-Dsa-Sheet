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

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Basically we are using two pointer approach
// at last if fast is not null that means our slow pointer will be pointing on mid-1
// simply move it to next
// slow pointer is at mid point
// Time 0(N)

ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode*fast = head->next;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

        }
        if(fast != NULL){
            slow = slow->next;
        }
        return slow;
}

// It is another approach basically count the nodes
// Mid is n/2 basically
// iterate through head upto mid 
// return pointer
ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
      int cnt = 0;
        while(slow){
            cnt++;
            slow = slow->next;
        }
        int mid = cnt/2;
        slow = head;
        while(slow && mid--){
            slow = slow->next;
        }

        return slow;
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
  
  int test_case_;
  cin>>test_case_;
  while(test_case_--)
  {
    _solve();
    
  }
  return 0;
}
