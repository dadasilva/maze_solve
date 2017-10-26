/*
/maze_solve.cpp
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
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
    for(int i = 0; i < r; i++){
        for(int k = 0; k < c; k++){
            if(k%c != 0){
                Node* n = new Node;
                n->visited = false;
                n->id = k;
                g->nodes.push_back(n);
            }
            else if(i%r != 0){
                Node* n = new Node;
                n->visited = false;
                n->id = i;
                g->nodes.push_back(n);
            }
            else if(k/c != 1 or k/c != 0){
                Node* n = new Node;
                n->visited = false;
                n->id = i=k;
                g->nodes.push_back(n);
            }
            else if(i/r != 1 or i/r != 0){
                Node* n = new Node;
                n->visited = false;
                n->id = i;
                g->nodes.push_back(n);
            }
        }
    }



    //grab wall coordinates | and print
    //place them in g initialize
    while(cin >> token){
        cout << token;
        cin >> token;
        wRow = atoi(token);
        cout << " "<< wRow << " ";
        cin >> token;
        wCol = atoi(token);
        cout << wCol << endl;

        g->nodes[wRow]->adj.push_back(wCol);
        g->nodes[wCol]->adj.push_back(wRow);
    }


  //fix each nodes of the list
  //by checking out of bounds and walls


  // - call DFS(0)
    int index = 0;
    bool p;
    for(int i = 0; i < g->nodes.size(); i++){
        if(!g->nodes[i]->visited){
            //look up
            if(index - c > 0){
                p = g->DFS(index);
                if(p){cout<< "PATH "<< index << endl;}
                index++;
            }
            //look down
            if(index + c < r*c){
                p = g->DFS(index);
                if(p){cout<< "PATH "<< index << endl;}
                index++;
            }
            //look right
            if((index - 1)/c != 0){
                p = g->DFS(index);
                if(p){cout<< "PATH "<< index << endl;}
                index++;
            }
            //look right
            if((index + 1)/c != 0){
                p = g->DFS(index);
                if(p){cout<< "PATH "<< index << endl;}
                index++;
            }

        }
    }
    cout << "total" << index << endl;


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

