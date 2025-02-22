#include<bits/stdc++.h>
using namespace std;

//sum till n natural numbers
int sum_n(int num){
   return num*(num+1)/2; 
}

//sum of square of n natural numbers;
int sum_sq(int num){
   return num*(num+1)*(2*num + 1)/6;
}

//sum of AP
int S_AP(int a, int d, int n){
   return (n/2 * (2*a + (n-1) * d));
}

// sum of GP
int S_GP(int a, int k, int num){
   return (a*(pow(k,num) - 1 )/(k-1));
}

int main(){
   int num;
   int a, d;
   cout<< "a, d, num : ";
   cin >> a >> d >> num;
   cout<<endl<<sum_n(num)<<endl;
   cout<<sum_sq(num)<<endl;
   cout<<S_AP(a,d,num)<<endl;
   cout<<S_GP(a,d,num)<<endl;
   return 0;
}