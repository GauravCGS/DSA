vector<int> leftView(Node *root)
{
   // Your code here
   Node* node = root;
   int level = 0;
   queue<Node*> q;
   map<int, int> m;
   vector<int>res;
   if(node == NULL) return res;
   q.push(node);
   while(!q.empty()){
       
       int size = q.size();
       for(int i = 0; i < size; i++){
        Node* temp = q.front();
        if(i == 0) res.push_back(temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        q.pop();
       }
       level++;
   }
//   for(auto i : m){
//       cout<<i.first<<" : "<<i.second<<" "<<endl;
//       res.push_back(i.second);
//   }
   return res;
}
