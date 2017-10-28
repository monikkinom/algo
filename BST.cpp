#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007

using namespace std;

template<class T>
struct Node {
    T value;
    Node *left;
    Node *right;
    
    
    Node(T val) {
        this->value = val;
    }
    
    Node(T val, Node<T> left, Node<T> right) {
        this->value = val;
        this->left = left;
        this->right = right;
    }
};

template<class T>
class BST {
private:
    Node<T> *root;
    
    void addHelper(Node<T> *node, T val){
        if(node->left) {
            
        }
    }
    
public:
    void add(T val) {
        if(!root){
            this->root = new Node<T>(val);
        }
        else
        {
            
        }
    }
    
};

int main() {
    
    
    
    return 0;
    
    }
