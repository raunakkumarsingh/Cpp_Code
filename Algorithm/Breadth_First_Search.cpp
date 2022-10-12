#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
enum color{WHITE,GRAY,BLACK};   //the colors are an indication that at what stage the current node is
class Graph
{
private:
    int no_of_vertices;
    unordered_map<int,vector<int>> adjlist; //unordered_map is used to get rid of the situation when same edge is inserted again and again
    vector<int> parent;             //the parent of a node from which it is getting discovered
    vector<int> color;              //the current state of the node
    vector<int> distance;

public:
    Graph(int v)
    {
        no_of_vertices=v;
        parent.resize(no_of_vertices,-1);
        color.resize(no_of_vertices,WHITE);
        distance.resize(no_of_vertices,-1);
    }
    void add_edge(int x,int y)          //for undirected edges
    {
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    void bfs(int src)
    {
        color[src]=GRAY;
        distance[src]=0;
        parent[src]=-1;
        queue<int> q;
        q.push(src);                            //the source is pushed into the queue
        while(q.empty()!=true)                  
        {
            int temp=q.front(); 
            q.pop();
            for(auto i:adjlist[temp])           //now the neighbours of one node are checked
            {
                if(color[i]==WHITE)             //if they are not visited yet, then it will be psuhed into the queue
                {
                    color[i]=GRAY;
                    distance[i]=distance[temp]+1;   //the distance of this node will be 1 more than it's parent
                    parent[i]=temp;
                    q.push(i);
                }
            }
            color[temp]=BLACK;
        }
    }
    void show_distances()           //function to show the distances of each of the nodes
    {
        for(int i=0;i<no_of_vertices;i++)
        {
            cout<<distance[i]<<" ";
        }
    }

};
int main()
{
    int v,e;
    cin>>v;
    cin>>e;
    int x,y;
    Graph obj(v);
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        obj.add_edge(x,y);
    }
    int src;
    cin>>src;
    obj.bfs(src);
    obj.show_distances();
    return 0;
}