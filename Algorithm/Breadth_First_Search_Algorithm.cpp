//Concept of breadth first search is to visit all the nodes at the present depth before moving on to the nodes at the next depth level.

//We use extra memory usually a queue to track the child nodes that were encountered but not explored yet.

//BFS of a Graph is similar to BFS of a tree except that graph may contain cycles , thus to avoid this we maintain a visited boolean array, where 0 means not visited and 1 means visited

vector<int> BFS(vector<vector<int>>&adjacency_list,int start_node,int number_of_nodes)
{
    //Maintaining a Queue Data Structure 
    queue<int>q;
    //Creating a visited array of size of number_of_nodes initialized to 0
    vector<int>visited_array(number_of_nodes,0);
    //As we start from the start_node we push it first into the queue
    q.push(start_node);
    //Storing our nodes as we go on with our BFS Algorithm
    vector<int>bfsVector;
    visited_array[start_node]=1;
    //Continuing our Algorithm until our queue is not empty
    while(!q.empty())
    {
        //Here we take the front element from queue and pop it.
        int node=q.front();
        bfsVector.push_back(node);
        q.pop();
        //Pushing all the adjacent nodes of the popped node, which are not visited, into the queue
        for(auto &it:adjacency_list[node])
        if(!visited_array[it])
        {
            //Marking this adjacent node as visited and pushing into the queue
            visited_array[it]=1;
            q.push(it);
        }
    }
    //Returning our bfsVector, this returns the nodes visited using the BFS Algorithm 
    return bfsVector;
}