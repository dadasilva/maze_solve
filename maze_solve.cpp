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
  int id;
  bool visited;
  vector <int> adj;
};

class Graph{
  vector <Node*> nodes;
  int DFS(int index, int MazeEnd);
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

    //grab walls and coordinates
    while(cin >> token){
        cout << token;
        cin >> token;
        wRow = atoi(token);
        cout << " "<< wRow << " ";
        cin >> token;
        wCol = atoi(token);
        cout << wCol << endl;
    }

    //create new instance of graph
  Graph* g = new Graph;

  //create an adjacency vector the size of the maze
  g->nodes(r*c);
  //place them in g initialize

  //fix each nodes of the list
  //by checking Out Of Bounts and walls
  // - call DFS(0)*/
    return 0;

}

int Graph::DFS(int index, int MazeEnd) {
    /*/base case 1
    if(g->nodes->visited == true){return;}

    //base case 2
    if(//hit the end of the maze){
      cout << "PATH 0 0 \n";
    }*/
}

