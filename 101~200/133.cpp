Clone Graph - Medium


Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> node_corresponding;
    
    Node* cloneGraph(Node* node) {
        if(node){ // if node exist
            // create an entrance node
            Node* new_node = new Node(node->val);  
            // add it into the corresponding map
            node_corresponding.insert(pair<Node*, Node*>(node,new_node));
            
            travel_node(node, new_node);
            return new_node;
        }
        else{
            return nullptr;
        }
        
    }
    
    void travel_node(Node* node, Node* new_node){
        if(node && new_node){
            for(auto item:node->neighbors){
                map<Node*, Node*>::iterator itmap;
                // find if the node have already traveled before
                itmap = node_corresponding.find(item);
                if(itmap == node_corresponding.end()){ // node not exist
                    Node* temp_new_node = new Node(item->val);
                    new_node->neighbors.push_back(temp_new_node);
                    node_corresponding.insert(pair<Node*, Node*>
                                              (item,temp_new_node));
                    travel_node(item, temp_new_node);
                }
                else{ // node traveled
                    Node* temp_new_node = itmap->second; // this node exist
                    new_node->neighbors.push_back(temp_new_node);
                }
                
            }
        }
    }
    
};