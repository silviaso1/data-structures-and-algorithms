/*Pede-se a implementação de uma função
recursiva que exiba os n primeiros termos de
uma PG (Progressão Geométrica), onde a1 é o
seu primeiro termo e q a razão.*/

#include <stdio.h>
void func(int n, int a1, int r, int i);

void main(){
    
    int n = 5, a1 = 3, r= 2, i = 0;
    
    func(n, a1, r, i);
}

void func(int n, int a1, int r, int i){
    
  if(i < n){
      
      printf("%d ", a1);
      func(n, a1*r, r, i + 1);
  }
}