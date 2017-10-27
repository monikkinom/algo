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

int main() {
    
    int N,M;
    
    cin >> N >> M;
    
    int a,b;
    
    vector<list<int> > graph(N+1);
    fore(i,0,M) {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    vector<bool> vis(N,false);
    
    int i=1;
    std::stack<int> stk;
    stk.push(i);
    vis[i]=1;
    while(!stk.empty()) {
            int top = stk.top();
            stk.pop();
            for(auto itr = graph[top].begin(); itr!=graph[top].end(); ++itr) {
                if(!vis[*itr]){
                    stk.push(*itr);
                    vis[i]=1;
                }
            }
        }
    
    return 0;
    
    }
