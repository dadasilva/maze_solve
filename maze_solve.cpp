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
    int DFS(int index);
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

  //create nodes and adjacency vector the size of the maze
    Node* n = new Node;
    for(int i = 0; i < r*c; i++){
        n = new Node;
        n->visited = false;
        n->id = i;
        g->nodes.push_back(n);
    }

    //grab walls and coordinates | and print
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


    //g->Print();


  //fix each nodes of the list
  //by checking out of bounds and walls


  // - call DFS(0)*/
    g->DFS(0);
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

int Graph::DFS(int index) {
    //base case 1
    if(g->nodes->visited == true){return;}

    //base case 2
    if(//hit the end of the maze){
      cout << "PATH 0 0 \n";
    }
}

