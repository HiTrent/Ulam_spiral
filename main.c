#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int isPrime(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0) return 0;

	return 1;
}

int main()
{
    while(1)
    {
        printf("Number of rows = ");
        int n; scanf("%d", &n);

        if(n % 2 != 0 && n > 0)
        {
            int **matrix = (int**)malloc(n * sizeof(int*));
            for(int i = 0; i < n; i++)
                matrix[i] = (int*)malloc(n * sizeof(int));

            int num = 0; //Counter
            int k = 4;   //Type of motion along the matrix
            int x = n/2; //Matrix center
            int y = n/2; //Matrix center

            while(1)
            {
                matrix[x][y] = ++num;
                switch(k)
                {
                    case 1: x++; break; //Down
                    case 2: y--; break; //Left
                    case 3: x--; break; //Up
                    case 4: y++; break; //Right
                }

                if(num == n * n) break;
                if(x == y && x < n/2) k = 1;
                else if(x + y == n - 1 && x < y) k = 2;
                else if(x + 1 == y && x >= n/2) k = 3;
                else if(x + y == n - 1 && x > y) k = 4;
            }

            printf("\n\n");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
					printf("%5d", matrix[i][j]);

                printf("\n\n");
            }

            printf("\n\n");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(isPrime(matrix[i][j])) printf("%5d", matrix[i][j]);
                    else printf("%5c", ' ');
                }

                printf("\n\n");
            }

            printf("\n\n");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(isPrime(matrix[i][j])) printf("%5c", '*');
                    else printf("%5c", ' ');
                }

                printf("\n\n");
            }

            for(int i = 0; i < n; i++)
                free(matrix[i]);
            free(matrix);
        }

        else printf("You must enter an odd positive number.");

        printf("\n");
        system("pause");
        system("cls");
    }
}
