//https://www.codingninjas.com/studio/problems/clone-graph_8230812?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
std::unordered_map<graphNode*, graphNode*> mp;
graphNode* solve(graphNode *node) {
    graphNode* new_node = new graphNode(node->data);
    mp[node] = new_node;
    
    for (auto neighbour : node->neighbours) {
        if (mp.find(neighbour) != mp.end()) {
            new_node->neighbours.push_back(mp[neighbour]);
        } else {
            new_node->neighbours.push_back(solve(neighbour));
        }
    }
    
    return new_node;
}
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	 mp.clear();
    return solve(node);
}
