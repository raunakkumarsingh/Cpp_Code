#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
enum color{WHITE,GRAY,BLACK};
#define INFINITE 999999
class Node
{
public:
    char data;
    int distance;
    int color;
    Node* parent;
    Node(char val)
    {
        data=val;
    }
};
class Compare_nodes
{
public:
    bool operator()(Node* temp_u,Node* temp_v)
    {
        return (temp_u->data < temp_v->data);
    }
};
class Graph
{
private:
    map<Node*,list<Node*>,Compare_nodes> adjlist;
    list<Node*> node_list;
    Node* find_node_in_list(char val)
    {
        Node* temp=NULL;
        for(auto i=node_list.begin();i!=node_list.end();i++)
        {
            if((*i)->data==val)
            {
                temp=*i;
                break;
            }
        }
        return temp;
    }
    void graph_bfs(Node* temp)
    {
        for(auto i=node_list.begin();i!=node_list.end();i++)
        {
            Node* temp_u=*i;
            temp_u->color=WHITE;
            temp_u->distance=INFINITE;
            temp_u->parent=NULL;
        }
        temp->color=GRAY;
        temp->distance=0;
        temp->parent=NULL;
        queue<Node*> q_obj;
        q_obj.push(temp);
        while(q_obj.empty()!=true)
        {
            Node* temp_u=q_obj.front();
            q_obj.pop();
            list<Node*> i=(adjlist[temp_u]);
            for(auto j=i.begin();j!=i.end();j++)
            {
                Node* temp_v=*j;
                if(temp_v->color==WHITE)
                {
                    temp_v->color=GRAY;
                    temp_v->distance=temp_u->distance +1;
                    temp_v->parent=temp_u;
                    q_obj.push(temp_v);
                }
            }
            temp_u->color=BLACK;
        }
    }

public:
    void push_edge(char val_u,char val_v)
    {
        Node* temp_u=NULL;
        Node* temp_v=NULL;
        if(node_list.empty()==true)
        {
            temp_u=new Node(val_u);
            temp_v=new Node(val_v);
            node_list.push_back(temp_u);
            node_list.push_back(temp_v);
            adjlist[temp_u].push_back(temp_v);
            adjlist[temp_v].push_back(temp_u);
        }
        else
        {
            temp_u=find_node_in_list(val_u);
            temp_v=find_node_in_list(val_v);
            if(temp_u==NULL && temp_v==NULL)
            {
                temp_u=new Node(val_u);
                temp_v=new Node(val_v);
                node_list.push_back(temp_u);
                node_list.push_back(temp_v);
            }
            else if(temp_u!=NULL && temp_v==NULL)
            {
                temp_v=new Node(val_v);
                node_list.push_back(temp_v);
            }
            else if(temp_u==NULL && temp_v!=NULL)
            {
                temp_u=new Node(val_u);
                node_list.push_back(temp_u);
            }
            else
            {
                //both the nodes are already created and are found in the variables temp_u, temp_v
            }
            adjlist[temp_u].push_back(temp_v);
            adjlist[temp_v].push_back(temp_u);
        }
    }
    void show_graph_data()
    {
        for(auto i=adjlist.begin();i!=adjlist.end();i++)
        {
            Node* temp_u=i->first;
            list<Node*> j=i->second;
            cout<<temp_u->data<<"-->";
            for(auto k=j.begin();k!=j.end();k++)
            {
                Node* temp_v=*k;
                cout<<temp_v->data<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(char val)
    {
        Node* temp=find_node_in_list(val);
        graph_bfs(temp);
    }
    void show_bfs_result()
    {
        for(auto i=node_list.begin();i!=node_list.end();i++)
        {
            Node* temp=*i;
            cout<<temp->data<<"("<<temp->distance<<")"<<" ";
        }
    }
};
int main()
{
    Graph obj;
    obj.push_edge('s','r');
    obj.push_edge('s','w');
    obj.push_edge('r','v');
    obj.push_edge('w','t');
    obj.push_edge('w','x');
    obj.push_edge('t','x');
    obj.push_edge('t','u');
    obj.push_edge('x','u');
    obj.push_edge('x','y');
    obj.push_edge('u','y');
    
    cout<<"Adjacency-list representation of the graph:"<<endl;
    obj.show_graph_data();
    cout<<endl;
    obj.bfs('s');
    cout<<"The distances of the nodes after BFS:"<<endl;
    obj.show_bfs_result();
    return 0;
}