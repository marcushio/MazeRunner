#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define WALL '*'  
#define OPEN ' '  
#define BREAD '.'
#define PERSON 'X'

#define MAX_MAZE_SIZE 30
                       
int size;      // number of rows/cols in maze

void initializeMaze( char maze[][size] );
void outputMaze(  char maze[][size] ); 
void getMazeSize();
bool solveMaze(char maze[][size], int x, int y); 
bool isValid(char maze[][size], int x, int y); 

int main() {

  getMazeSize();

  char maze[size][size];  // allocate memory to store the maze

  initializeMaze( maze ); // read the maze configuration
                          // from standard input
  outputMaze( maze );

  solveMaze(maze,0,0); //Let's try to solve the maze starting from 0,0

}


void initializeMaze ( char maze[][size]   )  
{
  char nextChar;

  for ( int row = 0; row < size; row++ ) {

    for ( int col = 0; col < size; col++ ) {

       scanf ( "%c", &maze[row][col] );
    }
    scanf ("%*c");   // read the newline char following the row
  }
}


void outputMaze( char maze[][size] )  
{
  printf ("The maze is: \n");
  for ( int row = 0; row < size; row++ )
  {
    for ( int col = 0; col < size; col++ )

      printf ( "%c", maze[row][col] );

    printf ( "\n" );
  }
  printf ( "\n" );
}


// read in the number of rows/columns in the maze grid
// from the standard input
void getMazeSize() {

  scanf ("%d", &size);

  scanf ("%*c");   // read the new line following the number

  if ( size > MAX_MAZE_SIZE  ) {
     printf ( "That is an illegal grid size\n" );
     exit(1);
  }
}

bool solveMaze(char maze[][size], int x, int y){
  //base case we reached our goal
  if(x == size-1 && y == size-1){
    maze[x][y] = PERSON; 
    outputMaze(maze); 
    return true;   
  }
  //base case our move isn't valid
  if(!isValid(maze,x,y)){
     return false;
  }
  maze[x][y]=PERSON; 
  bool endFound; 
  endFound = solveMaze(maze,x+1,y);
    if (endFound) 
      return true; 
  endFound = solveMaze(maze,x-1,y);
    if (endFound) 
      return true; 
  endFound = solveMaze(maze,x,y+1);
    if (endFound) 
      return true;
  endFound = solveMaze(maze,x,y-1);
    if (endFound)
      return true; 
  maze[x][y] = BREAD;
  if(!endFound && x==0, y==0)//we've backtracked to the beginning with no result.
    outputMaze(maze); 
  return false;  
}

bool isValid(char maze[][size], int x, int y){
  if(x >= 0 && x < size && y>=0 && y < size && (maze[x][y] == OPEN || maze[x][y] == BREAD))
    return true; 
  return false; 
}
