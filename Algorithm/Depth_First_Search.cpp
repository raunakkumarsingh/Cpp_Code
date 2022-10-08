#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
enum color{WHITE,GRAY,BLACK};   //the colors are an indication that at what stage the current node is
class Graph
{
private:
    int no_of_vertices;
    int time=0;                 //the time variable which is ultimately showing that when one node is getting discovered or the total work is finished
    unordered_map<int,vector<int>> adjlist; //unordered_map is used to get rid of the situation when same edge is inserted again and again
    vector<int> parent;             //the parent of a node from which it is getting discovered
    vector<int> color;              //the current state of the node
    vector<int> discovered;         //the time when the node is discovered
    vector<int> finished;           //the time when all the discovering from that particular node is done

    void dfs_visit(int u)           //the recursive function of dfs visit
    {
        time++;
        discovered[u]=time;
        color[u]=GRAY;
        for(auto i:adjlist[u])
        {
            if(color[i]==WHITE)
            {
                parent[i]=u;
                dfs_visit(i);
            }
        }
        color[u]=BLACK;
        time++;
        finished[u]=time;
    }
public:
    Graph(int v)
    {
        no_of_vertices=v;
        parent.resize(no_of_vertices,-1);
        color.resize(no_of_vertices,WHITE);
        discovered.resize(no_of_vertices,0);
        finished.resize(no_of_vertices,0);
    }
    void add_edge(int x,int y)          //for undirected edges
    {
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    void dfs()
    {
        for(int i=0;i<no_of_vertices;i++)
        {
            if(color[i]==WHITE)
            {
                dfs_visit(i);
            }
        }
    }
    void show_distances()           //function to show the discovering time of each of the nodes
    {
        for(int i=0;i<no_of_vertices;i++)
        {
            cout<<discovered[i]<<" ";
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
    obj.dfs();
    obj.show_distances();
    return 0;
}