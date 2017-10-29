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

//1 D Fenwick/ BIT wohooooo all hail O(logn) updates and reads
//Well written tutorial: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/


int read(int idx,vector<int> &tree) {
    int sum = 0;
    while(idx > 0) {
        sum+= tree[idx];
        idx -= (idx & -idx); // the trick is find the last position at which the binary representation of the idx is 1. And remove that and add one. Any index on the tree contains the numbers from that calculated positon to idx itself. So think of if it this way, tree[idx] = contains cum from idx-2^r+1 where r is the position at which binary represntation has last 1 till idx itself.
    }
    return sum;
}

void update(int idx, int val, vector<int> &tree) {
    while(idx<=tree.size()) {
        tree[idx] += val;
        idx += (idx & -idx); // here you go the other way round till the size of the tree.
    }
}


int main() {
    int n;
    n = 50;
    vector<int> freq(n,0);
    vector<int> cum(n,0);
    vector<int> tree(n,0);
    
    update(5,5,tree);
    cout << read(5,tree);
    
    cout << endl;
    
    update(10,10,tree);
    cout << read(10,tree);
    
    return 0;
    
    }
