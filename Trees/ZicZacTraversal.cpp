class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	// somewhat similar to level order traversal
    	Node* node = root;
    	queue<Node*> q;
    	// push the first node into queue
    	q.push(node);
    	// final result
    	vector<int> res;
    	// direction of traversal
    	bool leftToRight = true;
    	while(!q.empty()){
            // get size for each level
    	    int size = q.size();
    	    // maintain vector to store values on each level
    	    vector<int> level(size);
    	    
    	    // looping through elements on each level
    	    for(int i = 0; i<size; i++){
    	        Node* front = q.front();
    	        // check for the direction
    	        int index = leftToRight ? i : (size-i-1);
    	        level[index] = front->data;
    	        if(front->left) q.push(front->left);
    	        if(front->right)q.push(front->right);
    	        q.pop();
    	    }
    	    
    	    // store in final res
    	    for(int i : level){
    	        res.push_back(i);
    	    }
    	    // flip once a level is traversed
    	    leftToRight = !leftToRight;
    	}
    	return res;
    }
};
