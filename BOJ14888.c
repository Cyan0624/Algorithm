/*
https://www.acmicpc.net/problem/14888
*/

#include <stdio.h>

int main(){
  int N;
  int numbers[11];
  int Num_of_Operators[4]; // 0: +, 1: -, 2: *, 3 /
  //get input
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &numbers[i]);
  }
  scanf("%d %d %d %d", &Num_of_Operators[0], &Num_of_Operators[1], &Num_of_Operators[2], &Num_of_Operators[3]);

  return 0;
}
