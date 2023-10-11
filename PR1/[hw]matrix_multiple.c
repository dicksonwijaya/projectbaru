#include <stdio.h>
#define ROW 4
#define COL 3

int main(void)
{
	int i, j, k, sum;
	int m1[ROW][2] = {{1, 2},
					  {3, 4},
					  {5, 6},
					  {7, 8}};
	int m2[2][COL] = {{1, 2, 3},
					  {4, 5, 6}};

    int mult[ROW][COL];

	/*TO-DO*/
	/*You are given two input matrices, m1 and m2.
	Please implement matrix multiplication.*/

	for (i = 0; i < ROW; i++){
        for (j = 0; j < COL; j++){
            sum = 0;

            for (k = 0; k < 2; k++){
                sum += m1[i][k] * m2[k][j];
            }
            mult[i][j] = sum;
        }
    }

    //result
    printf("Multiplication Matrix:\n");
    for (i = 0; i < ROW; i++){
        for (j = 0; j < COL; j++){
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }

    return 0;
}
