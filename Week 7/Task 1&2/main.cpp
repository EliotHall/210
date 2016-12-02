#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <fstream>

using namespace std;

class Node
{
   //Here we need to store a list of edges, or pointers to the other Nodes
   //We can use a vector of pointers to show edges or if the Node is
   //connected to other Nodes...

   public:
       //Constuctor
       Node(int value)
       {
           this->value=value;
       }

       //Deconstructor
       ~Node()
       {
           cout << "node destroyed" << endl;
       }
    int value;
    vector <Node*> edges;
    bool visited = false;

    //Displays the address that each edge is pointing to, to prove it is a vector of pointers and not just values
    void displayEdges()
    {
        for (int i = 0; i < edges.size(); i++)
        {
            cout << "\t" << edges[i]->value;
        }
        cout << endl;
    }

};

class Graph
{
public:
     //Here we need to store the Nodes (nodes)

     map <int,Node*> mapofNodes;

     //Graph deconstructor
     ~Graph()
     {
         cout << "Graph destroyed!" << endl;

         //auto is your friend!! =D
         //&i acts similar to a pointer, except it can't point at invalid memory
         for( auto &i : mapofNodes )
            delete i.second;

     }

     void addNode(int val)
     {

        mapofNodes[val] = new Node(val);
     }

      void addEdge(int x, int y)
    {

        Node* n = mapofNodes.find(x)->second;
        Node* m = mapofNodes.find(y)->second;

        n->edges.push_back(m);
        m->edges.push_back(n);
    }

    void displayNodes()
    {
        //Auto is basically a replacement for <int, Node*>
        for( auto i : mapofNodes )
        {
            cout << i.first << " -> " << i.second << endl;
            i.second->displayEdges();
        }
    }

    void BFS(Node* n)
{
    vector<int> results;
    queue<Node*> q;
    int temp;

    q.push(n);
    cout << "BFS!" << endl;

    while (!q.empty())
    {
        //cout << "Value of n is: " << n->value << endl;
        Node* test = q.front();
        temp = test->value;

        //Saves the order of the nodes visited
        if (find(results.begin(), results.end(), n->value) == results.end())
        {
            results.push_back(temp);
        }

        //cout << temp << endl;
        n->visited = true;
        q.pop();

        //cout << "TESTING! " << endl;
        //Goes through each edges and checks if it's already been visited
        for (int i = 0; i < n->edges.size(); i++)
        {
            if (!n->edges[i]->visited)
            {
                //cout << n->edges[i]->value << " ";
                q.push(n->edges[i]);
            }
        }
        //cout << endl;
        if (!q.empty())
        n = q.front();

    }
    //Prints to the text file and clears the nodes of their "visited" tags
    fstream test;
    test.open("BFS.txt");
    for (int i = 0; i < results.size(); i++)
    {
        test << results[i] <<endl;
    }
    test.close();

    for( auto i : mapofNodes )
    {
        i.second->visited = false;
    }

}



    void DFS(Node* n)
    {
        vector<int> results;
        stack<Node*> s;
        int temp;

        s.push(n);
        cout << "DFS!" << endl;

        while (!s.empty())
        {
            //cout << "Value of n is: " << n->value << endl;
            Node* test = s.top();
            temp = test->value;
            //cout << temp << endl;

            //Saves the order of the nodes visited
            if (find(results.begin(), results.end(), n->value) == results.end())
            {
                results.push_back(temp);
            }

            n->visited = true;
            s.pop();

            //cout << "TESTING! " << endl;
            //Goes through each edges and checks if it's already been visited
            for (int i = n->edges.size() - 1; i > -1; i--)
            {
                if (!n->edges[i]->visited)
                {
                    //cout << n->edges[i]->value << " ";
                    s.push(n->edges[i]);
                }
            }
            //cout << endl;
            if (!s.empty())
            n = s.top();

        }
    //Prints to the text file and clears the nodes of their "visited" tags
    fstream test;
    test.open("DFS.txt");
    for (int i = 0; i < results.size(); i++)
    {
        test << results[i] <<endl;
    }
    test.close();

    for( auto i : mapofNodes )
    {
        i.second->visited = false;
    }
}
};

int main()
{
    Graph g;// = new Graph();
    g.addNode(1);
    g.addNode(2);
    g.addNode(7);
    g.addNode(12);
    g.addNode(19);
    g.addNode(21);
    g.addNode(25);
    g.addNode(32);
    g.addNode(39);
    g.addNode(40);

    g.addEdge(1,2);
    g.addEdge(1,7);
    g.addEdge(2,12);
    g.addEdge(2,19);
    g.addEdge(7,21);
    g.addEdge(19,21);
    g.addEdge(19,25);
    g.addEdge(19,40);
    g.addEdge(25,32);
    g.addEdge(25,39);
    g.addEdge(39,40);

    g.displayNodes();
    Node* n = g.mapofNodes[1];
    g.DFS(n);
    g.BFS(n);
}

