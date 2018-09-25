#include <iostream>
#include <unistd.h>

using namespace std;

#define M 5      // Matrix sizes
#define K 6
#define N 8

int matrix_A [M][K] = { {1,4,3,7,9,1}, {2,5,4,8,6,3}, {3,6,5,8,2,3},                      
						{3,8,8,1,4,1}, {1,5,4,5,7,9} };     
int matrix_B [K][N] = { {1,5,6,5,7,9,8,2}, {1,2,3,5,5,6,7,8}, {3,5,9,7,3,1,4,1},
						{8,3,1,2,6,5,2,4}, {3,8,8,1,4,1,3,3}, {8,7,6,5,4,3,2,1} };     
int c [M][N];  // this is where the answer will be placed 


int main(int argc,char* argv[])
{
	int numThreads = 1;
	 if (argc > 1)
		numThreads = atoi(argv[1]);
	
	#pragma omp parallel for num_threads(numThreads) private(i)

for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			c[i][j] = 0;
			for(int k = 0; k < K; k++)
			{
				c[i][j] += matrix_A[i][k] * matrix_B[k][j];
				usleep(5000);
			}
		}
	}



		
	for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < N; j++)
			{
			cout << c[i][j] << " ";
			}
			cout << endl;
		}

	 return 0;
}