/*
/maze_solve.cpp
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Node{
  int id;
  bool visited;
  vector <int> adj;
}

class Graph{
  vector <Node*> nodes;
  bool/int DFS(int index, int MazeEnd);
}

main(){
  //read in rows an columns

  //create new instance of graph
  Graph g = new Graph;
  //create a vector the size of the maze
  g->nodes(r*c);
  //place them in g initialize

  //fix each nodes of the list
  //by checking Out Of Bounts and walls
  // - call DFS(0)

}

bool/int Graph::DFS(int index, int MazeEnd){
  //base case 1
  if(g->nodes->visited == true){return;}

  //base case 2
  if(//hit the end of the maze){
    cout << "PATH 0 0 \n";
  }
}
