#include <iostream>
#include <cstring>
using namespace std;

int G[6][6] = { //6x6 2D array for adjacency matrix
  {0, 3, 0, 0, 0, 1},
  {3, 0, 2, 1, 10, 0},
  {0, 2, 0, 3, 0, 5},
  {0, 1, 3, 0, 5, 0},
  {0, 10, 0, 5, 0, 4},
  {1, 0, 5, 0, 4, 0}
  };

int main() {
  int edges = 0;  //number of edges

  int selected[6]; //selected vertices
  memset(selected, false, sizeof(selected));
  selected[0] = true;

  cout << " Edges" << " | " << "Weight" <<"\n";

  int x;  //rows
  int y;  //columns

  while (edges < 5){
    int min = 10000;
    x = 0;
    y = 0;

    for (int i = 0; i < 6; i++){

      if (selected[i]==true){

        for (int j = 0; j < 6; j++){

          if (selected[j]==false && G[i][j]){  

            if (min > G[i][j]){
                x = i;
                y = j;
                min = G[x][y];
            }
          }
        }
      }
    }

    selected[y] = true;
    edges++;

    cout << " " << x << ", " << y << "  | " << "  " << G[x][y] << "\n";
  }

  return 0;
}
