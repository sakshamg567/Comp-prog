#include<bits/stdc++.h>
using namespace std;


void brute_force(int *arr, int size){
   int best = 0;
   for(int i = 0; i < size; i++){
      for(int j = i; j < size; j++){
         int sum = 0;
         for(int k = i; k <= j; k++){
            sum += arr[k];
         }
         best = max(best, sum);
      }
   }
   cout<<best<<endl;
}

void better(int *arr, int size){
   int best = 0;
   for(int i = 0; i < size; i++){
      int sum = 0;
      for(int j = i; j < size; j++){
         sum += arr[j];
         best = max(best, sum);
      }
   }
   cout<<best<<endl;
}

// kadane's algorithm
void optimal(int *arr, int size){
   int best = 0, sum = 0;
   for(int i = 0; i< size; i++){
      sum = max(sum+arr[i], arr[i]);
      best = max(best, sum);
   }
   cout<<best<<endl;
}

int main(){
   int arr[] = {-1,2,4,-3,5,2,-5,2};
   brute_force(arr,8);
   better(arr,8);
   optimal(arr,8);
}