/*
/maze_solve.cpp
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <iomanip>


using namespace std;

class Node{
public:
  int id;
  bool visited;
  vector <int> adj;
};

class Graph{
public:
    vector <Node*> nodes;
    bool DFS(int index);
    int end;
    void Print();
};

int main(int argc, char **argv){

    //read in rows and columns
    fstream input;
    char token[1000];
    cin.getline(token, 1000);
    input.open(*argv);
    int r;
    bool rr = false;
    int c;

    //grab rows and columns
    int i = 0;
    char *pch;
    pch = strtok(token, " ");
    while(pch != NULL){
        if(i == 1){r = atoi(pch);}
        if(i == 3){c = atoi(pch);}
        printf ("%s ",pch);
        pch = strtok(NULL, " ");
        i++;
    }
    cout << endl;

    //create new instance of graph
  Graph* g = new Graph;

    // create nodes for graph and adjacency vector the size of the maze
    // fix each nodes of the list mapping each node to thier neighbor nodes
    // and excluding the out of bounds and walls (top, btm, right, left)
    int index = -1;
    for(int i = 0; i < r; i++){
        for(int k = 0; k < c; k++){
            //top
            index++;
            if(i == 0) {
                if(k == 0){
                    //top right corner node
                    //cout << "top right corner\n" << index;
                    Node *n = new Node;
                    n->visited = false;
                    n->id = index;
                    g->nodes.push_back(n);
                    g->nodes[index]->adj.push_back(index + 1);
                    g->nodes[index]->adj.push_back(index + c);
                    continue;
                }
                //top left corner node
                if(k == c - 1){
                    //cout << "top left corner\n" << index;
                    Node *n = new Node;
                    n->visited = false;
                    n->id = index;
                    g->nodes.push_back(n);
                    g->nodes[index]->adj.push_back(index - 1);
                    g->nodes[index]->adj.push_back(index + c);
                    continue;
                }
                    //non corner top nodes
                else{
                    //cout << "top\n" << index;
                    Node *n = new Node;
                    n->visited = false;
                    n->id = index;
                    g->nodes.push_back(n);
                    g->nodes[index]->adj.push_back(index - 1);
                    g->nodes[index]->adj.push_back(index + 1);
                    g->nodes[index]->adj.push_back(index + c);
                    continue;
                }
            }
            //bottom
            if(i == r - 1){
                if(k == 0){
                    //bottom right corner node
                    //cout << "btm right corner\n" << index;
                    Node *n = new Node;
                    n->visited = false;
                    n->id = index;
                    g->nodes.push_back(n);
                    g->nodes[index]->adj.push_back(index+1);
                    g->nodes[index]->adj.push_back(index-c);
                    continue;
                }
                //bottom left corner node
                if(k == c - 1){
                    //cout << "btm left corner\n" << index;
                    Node *n = new Node;
                    n->visited = false;
                    n->id = index;
                    g->nodes.push_back(n);
                    g->nodes[index]->adj.push_back(index-1);
                    g->nodes[index]->adj.push_back(index-c);
                    continue;
                }
                    //non corner bottom nodes
                else{
                    //cout << "btm \n" << index;
                    Node *n = new Node;
                    n->visited = false;
                    n->id = index;
                    g->nodes.push_back(n);
                    g->nodes[index]->adj.push_back(index-1);
                    g->nodes[index]->adj.push_back(index+1);
                    g->nodes[index]->adj.push_back(index-c);
                    continue;
                }
            }
            //right side
            if(k == 0){
                if(i > 0 and i < r - 1){
                    //cout << "right\n" << index;
                    Node *n = new Node;
                    n->visited = false;
                    n->id = index;
                    g->nodes.push_back(n);
                    g->nodes[index]->adj.push_back(index-c);
                    g->nodes[index]->adj.push_back(index+1);
                    g->nodes[index]->adj.push_back(index+c);
                    continue;
                }

            }
            //left side
            if(k == c-1){
                //all non corner left nodes
                if(i > 0 and i < r - 1){
                    //cout << "left \n" << index;
                    Node *n = new Node;
                    n->visited = false;
                    n->id = index;
                    g->nodes.push_back(n);
                    g->nodes[index]->adj.push_back(index-c);
                    g->nodes[index]->adj.push_back(index-1);
                    g->nodes[index]->adj.push_back(index+c);
                    continue;
                }
            }
            else{
                //all center
                //cout << "mid\n" << index;
                Node *n = new Node;
                n->visited = false;
                n->id = index;
                g->nodes.push_back(n);
                g->nodes[index]->adj.push_back(index-c);
                g->nodes[index]->adj.push_back(index+1);
                g->nodes[index]->adj.push_back(index-1);
                g->nodes[index]->adj.push_back(index+c);
                continue;
            }
        }
    }

    //grab wall coordinates | print | break links
    //place them in g initialize
    while (cin >> token) {
        cout << token;
        cin >> token;
        int v1 = atoi(token);
        cout << " " << v1 << " ";
        cin >> token;
        int v2 = atoi(token);
        cout << v2 << endl;

        //breaks the v2 link from v1
        vector <int>::iterator v1b = g->nodes[v1]->adj.begin();
        vector <int>::iterator v1e = g->nodes[v1]->adj.end();
        g->nodes[v1]->adj.erase(remove(v1b, v1e, v2), v1e);

        //breaks the v1 link from v2
        vector <int>::iterator v2b = g->nodes[v2]->adj.begin();
        vector <int>::iterator v2e = g->nodes[v2]->adj.end();
        g->nodes[v2]->adj.erase(remove(v2b, v2e, v1), v2e);
    }

    g->end = r*c;
    //g->Print(); //for node debugging
    //call DFS and Print Path
    vector <int>::iterator it;
    for(int i = 0; i < g->nodes.size(); i++){
        g->DFS(i);
    }

    return 0;

}

bool Graph::DFS(int index) {
    Node *n;
    int i;
    n = nodes[index];

    //base case 1
    if(n->visited){return false;}
    n->visited = true;

    //base case 2
    if(index == 0) {
        cout << "PATH " << n->id << endl;
        return true;
    }

    for(i = 0; i < n->adj.size(); i++){
        if(DFS(n->adj[i]) == true){
            cout << "PATH " << n->id << endl;
            return true;
        }
    }
    return false;

}

//used for debugging the nodes and walls for the maze
void Graph::Print(){
    int i , j;
    Node *n;

    for (i = 0; i < nodes.size(); i++) {
        n = nodes[i];
        cout << "Node " << i << ": " << n->id << ":";
        for (j = 0; j < n->adj.size(); j++) {
            cout << " " << n->adj[j];
        }
        cout << endl;
    }
}