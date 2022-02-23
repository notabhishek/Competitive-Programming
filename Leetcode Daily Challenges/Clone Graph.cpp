class Solution {
public:
    map< Node* , Node*> vis;
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if(vis.find(node)!=vis.end())
            return vis[node];
        Node *copy = new Node(node->val);
        vis[node] = copy;
        copy->neighbors.resize(node->neighbors.size());
        for(int i = 0; i < copy->neighbors.size(); ++i) {
            copy->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        return copy;
    } 
};
