#include <iostream>
using namespace std;

void multiply(int *A[], int *B[], int *C[], int n)
{
   if (n == 1)
   {
      C[0][0] += A[0][0] * B[0][0];
      return;
   }
   int half = n / 2;

   int *a11[half], *a12[half], *a21[half], *a22[half];
   int *b11[half], *b12[half], *b21[half], *b22[half];
   int *c11[half], *c12[half], *c21[half], *c22[half];

   for (int i = 0; i < half; i++)
   {
      a11[i] = &A[i][0];
      a12[i] = &A[i][half];
      a21[i] = &A[i + half][0];
      a22[i] = &A[i + half][half];

      b11[i] = &B[i][0];
      b12[i] = &B[i][half];
      b21[i] = &B[i + half][0];
      b22[i] = &B[i + half][half];

      c11[i] = &C[i][0];
      c12[i] = &C[i][half];
      c21[i] = &C[i + half][0];
      c22[i] = &C[i + half][half];
   }

   multiply(a11, b11, c11, half);
   multiply(a12, b21, c11, half);
   multiply(a11, b12, c12, half);
   multiply(a12, b22, c12, half);
   multiply(a21, b11, c21, half);
   multiply(a22, b21, c21, half);
   multiply(a21, b12, c22, half);
   multiply(a22, b22, c22, half);
}

int main()
{
   int A[4][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
   int B[4][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
   int C[4][4] = {0};
   int *ptr1[4], *ptr2[4], *ptr3[4];
   for (int i = 0; i < 4; i++)
   {
      ptr1[i] = A[i];
      ptr2[i] = B[i];
      ptr3[i] = C[i];
   }

   multiply(ptr1, ptr2, ptr3, 4);

   // Print result
   for (int i = 0; i < 4; i++)
   {
      for (int j = 0; j < 4; j++)
         cout << C[i][j] << " ";
      cout << endl;
   }
   return 0;
}