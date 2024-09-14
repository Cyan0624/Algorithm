#include <stdio.h>

int sudoku[9][9];
int stack[82][2];
int top = -1;

void Sudoku(int y, int x);  

int check(int n, int y, int x){
  for(int i = 0; i < 9; i++){
    if(sudoku[y][i] == n || sudoku[i][x] == n){
      return 1;
    }
  }

  for(int i = (y / 3) * 3; i < ((y / 3) + 1) * 3; i++){
    for(int j = (x / 3) * 3; j < ((x / 3) + 1) * 3; j++){
      if(sudoku[i][j] == n){
        return 1;
      }
    }
  }
  return 0;
}

int main(){

  //get input
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      scanf("%d", &sudoku[i][j]);
    }
  }

  //start solving
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(sudoku[i][j] == 0){
        Sudoku(i , j);
        i = stack[top][0];
        j = stack[top][1]-1;
      }
    }
  }

  //print out the result
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      printf("%d", sudoku[i][j]);
      if(j != 8){
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
}

void Sudoku(int y, int x){
  //get number of the position
  int n = sudoku[y][x];

  for(int i = n + 1; i < 10; i++){
    //put the number to find if there is any fitable number
    if(check(i, y, x) == 0){
      sudoku[y][x] = i;
      top++;
      stack[top][0] = y;
      stack[top][1] = x;
      return;
    }
  }

  //reset data
  sudoku[y][x] = 0;
  //if there is nofitable number recursively call
  top--;
  Sudoku(stack[top+1][0], stack[top+1][1]);
  return;
}

/* 
Error occured when put top-- in recursive line.
As Sudoku() is unfinished top-- didn't worked so it made out of bound error repeatedly
*/