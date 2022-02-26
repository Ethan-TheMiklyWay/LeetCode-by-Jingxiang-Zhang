Shortest Path Visiting All Nodes - Hard

You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:


Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:


Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]



class Solution {
public:
    
    map<tuple<int,int> ,int> cache;  // node, mask
    vector<vector<int>> globe_graph;
        
    int shortestPathLength(vector<vector<int>>& graph) {
        /*
        tuple<int,int> ti = tuple<int,int>(2,3);
        
        state.insert(pair<tuple<int,int> ,int>(ti, 10));
        
        tuple<int,int> ai = tuple<int,int>(2,3);
        auto iter = state.find(ai);
        cout<<iter->second;
        return 0; 
        */
        globe_graph = graph;
        int length = graph.size();
        int end_mask = (1<<length) - 1;
        int min_length = 10000000;
        for(int i=0;i<length;i++){
            int temp_length = dp(i,end_mask);
            // cout<<temp_length<<endl;
            if(min_length>temp_length)
                min_length=temp_length;
        }
        return min_length;
        
    }
    
    int dp(int node, int mask){
        tuple<int,int> state = tuple<int,int>(node,mask);
        auto res = cache.find(state);
        if(res!=cache.end()){
            return res->second;
        }
        // cout<<"mask: "<<mask<<" .node: "<<node<<endl;
        if((mask & (mask-1)) == 0){
            // cout<<"origin"<<endl;
            return 0;
        }
        cache.insert(pair<tuple<int,int> ,int>(state, 10000000));
        // Avoid infinite loop in recursion
        
        vector<int> neighbors = globe_graph[node];
        for(int i=0;i<neighbors.size();i++){
            int neighbor = neighbors[i];
            if((mask & (1<<neighbor))!=0){
                int already_visit = 1 + dp(neighbor, mask);
                int not_visit = 1 + dp(neighbor, (mask^(1<<node)));
                res = cache.find(state);
                int now_state = res->second;
                //cout<<already_visit<<" "<<not_visit<<" "
                //    <<now_state<<endl;
                int min_step = already_visit;
                min_step = min_step < now_state?
                            min_step : now_state;
                min_step = min_step < not_visit?
                            min_step : not_visit;
                cache[state] = min_step;
            }
        }
        return cache[state];
    }
    
};