#include <stdio.h>

int main(){
  int N, K;
  scanf("%d %d", &N, &K);
  int bag[N+1][K+1];
  int object[N+1][2];

  for(int i = 1; i < N+1; i++){
    scanf("%d %d", &object[i][0], &object[i][1]); 
  }
  
  for(int i = 0; i < N+1; i++){
    for(int j = 0; j < K+1; j++){
      if(i == 0 || j == 0){
        bag[i][j] = 0;
      }
      else if(object[i][0] <= j){
        bag[i][j] = bag[i-1][j] < (bag[i-1][j - object[i][0]] + object[i][1]) ? (bag[i-1][j - object[i][0]] + object[i][1]): bag[i-1][j];
      }
      else{
        bag[i][j] = bag[i-1][j];
      }
    }
  }

  printf("%d", bag[N][K]);

  return 0;
}
