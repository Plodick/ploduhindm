#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;
const int N=3;
void print (float **A, float *b, int n)
{
    for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < n; j++)
        {
            cout << setprecision(2) << setw(7) << A[i][j];
        }
      // cout << " | " << setprecision(2) << setw(7) << b[i] << endl;
      cout << endl;
     }
     cout << endl;
}
int main()
{

   /* float a1[N][N] = {
        {1,0,0},
        {1,-2,1},
        {0,1,-2}
    };
    float b1[N] = {1,2,3};*/

    float **A = new float* [N];
    float *b = new float [N];
    float *x = new float [N];
    for (int i=0; i<N; i++)
         A[i] = new float [N];
    A[0][0] = 81;
    A[1][1] = 50; A[2][2] = 38;
    A[0][1] = A[1][0] = -45;
    A[0][2] = A[2][0] = 45;
    A[1][2] = A[2][1] = -15;
    b[0] = 531;
    b[1] = -460;
    b[2] = 193;

    //конец инициализации

    long double** L = new long double*[N];
    for (int i=0; i<N; i++)
        L[i] = new long double[N];
	long double* y = new long double[N];
	long double s=0;
	for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
        {
                L[i][j]=0;
        }
	for (int i = 0; i < N; i++)
     {
         for (int j = 0; j < N; j++)
         {
             if (i==j)
             {
                for(int k=0; k<i; k++)
                    s+=L[i][k]*L[i][k];
                 L[i][i]=sqrt(A[i][i]-s);

                 s = 0;
             }
             if (j<i)
             {
                 for (int k=0; k<j; k++)
                     s+=L[i][k]*L[j][k];
                 L[i][j] = (A[i][j]-s)/L[j][j];
                 s = 0;
             }
         }
     }
	for (int i = 0; i < N; i++)
    {
        x[i]=0;
        y[i]=0;
    }

    y[0]=b[0]/L[0][0];
    for (int i = 1; i < N; i++)
    {
        for(int j=0; j < i; j++)
			s += L[i][j]*y[j];

        y[i] = (b[i] - s)/L[i][i];
        s = 0;
    }

	x[N-1] = y[N-1]/L[N-1][N-1];
    for (int i=N-2;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
			s += L[j][i]*x[j];

        x[i] = (y[i] - s)/L[i][i];
        s = 0;
    }
    delete[] y;
    for(int i=0; i<N; i++)
        delete[] L[i];
    delete[] L;

    //вывод результатов
    for (int i=0; i<N; i++)
        cout << "x(" << i+1 << ") = " << setprecision(2) << x[i] << endl;
     for (int i = 0; i < N; i++)
        delete []A[i];
    delete [] b;
    delete [] x;
    return 0;
}
