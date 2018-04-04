class Solution {
//solution to Course Schedule II problem on leetcode : https://leetcode.com/problems/course-schedule-ii/
public:
    
    bool issue=false;
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int> > graph(numCourses);
        int n = numCourses;
        for(auto iter = prerequisites.begin(); iter!=prerequisites.end(); ++iter) {
            graph[iter->first].push_back(iter->second);
        }
        vector<int> result;
        vector<bool> vis(n);
        vector<bool> rec(n);
        
        for(int i=0;i<n; i++) {
            if(!vis[i]){
                dfs(i,vis,rec, graph,result);
            }
        }
        if(!issue){
        return result;
        }
        vector<int> res;
        return res;
    }
    
    void dfs(int v, vector<bool>& vis, vector<bool>& recstack, vector<list<int> >& graph, vector<int>& result) {
        vis[v]=true;
        recstack[v]=true;
        for(auto iter = graph[v].begin(); iter!= graph[v].end(); iter++){
            if(!vis[*iter]){
                dfs(*iter,vis,recstack,graph,result);
            }
            else if(recstack[*iter]){
                issue=true;
            }
        }
        recstack[v]=false;
        result.push_back(v);
    }
    
    
};
