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
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> cloned;
        return cloneGraphHelper(cloned, node);
    }
    Node* cloneGraphHelper(unordered_map<Node*, Node*>& clonedBuds, Node* node){
        if(!node){
            return nullptr;
        }
        if(clonedBuds.find(node) != clonedBuds.end()){
            return clonedBuds[node];
        }

        Node* toReturn = new Node(node->val);
        clonedBuds[node] = toReturn;
        for(int i = 0; i < node->neighbors.size(); i++){
            toReturn->neighbors.push_back(cloneGraphHelper(clonedBuds, node->neighbors[i]));
        }
        return toReturn;
    }
};
