/*
/maze_solve.cpp
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
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
    int wRow = 0;
    int wCol =0;

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

  //create nodes for graph and adjacency vector the size of the maze
    int index = -1;
    for(int i = 0; i < r; i++){
        for(int k = 0; k < c; k++){
            //top
            index++;
            if(i == 0) {
                if(k == 0){
                    //top right corner node
                    cout << "top right corner\n" << index;
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
                    cout << "top left corner\n" << index;
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
                    cout << "top\n" << index;
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
                    cout << "btm right corner\n" << index;
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
                    cout << "btm left corner\n" << index;
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
                    cout << "btm \n" << index;
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
                    cout << "right\n" << index;

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
                    cout << "left \n" << index;
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
                cout << "mid\n" << index;
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

    g->Print();

    //grab wall coordinates | and print
    //place them in g initialize
        while (cin >> token) {
            cout << token;
            cin >> token;
            wRow = atoi(token);
            cout << " " << wRow << " ";
            cin >> token;
            wCol = atoi(token);
            cout << wCol << endl;

            g->nodes[wRow]->adj.push_back(wCol);
            g->nodes[wCol]->adj.push_back(wRow);
        }

  //fix each nodes of the list
  //by checking out of bounds and walls


  // - call DFS(0)
    int dfindex = 0;
    bool p;
    for(int i = 0; i < g->nodes.size(); i++){
        p = g->DFS(dfindex);
        if(p){cout<< "PATH "<< index << endl;}
        dfindex++;
    }
    cout << "total" << dfindex << endl;


    return 0;

}

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

bool Graph::DFS(int index) {
    Node *n;
    int i;
    //base case 1
    n = nodes[index];
    if(n->visited){return false;}

    n->visited = true;
    //base case 2
    for(i = 0; i < n->adj.size(); i++){
        DFS(n->adj[i]);
        return true;
    }
}

