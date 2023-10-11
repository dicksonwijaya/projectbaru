#include <stdio.h>
#define SIZE 10
#define ROW 4
#define COL 5
#define DEPTH 2

int main(void)
{
	int i, j, k;

	int matrix_3d[ROW][COL][DEPTH] = {{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}},
									  {{11, 12}, {13, 14}, {15, 16}, {17, 18}, {19, 20}},
									  {{21, 22}, {23, 24}, {25, 26}, {27, 28}, {29, 30}},
									  {{31, 32}, {33, 34}, {35, 36}, {37, 38}, {39, 40}}};

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" {");
			for (k = 0; k < DEPTH; k++)
			{
				printf("%3d", matrix_3d[i][j][k]);
			}
			printf("}");
		}
		printf("\n");
	}

	printf("\n");
	//memory addresses of all elements
	int elsize = sizeof(int);
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			for (k = 0; k < DEPTH; k++){
				int address = (i * COL * DEPTH) + (j * DEPTH) + k;
				address *= elsize;

				printf("matrix_3d[%d][%d][%d] is located at %p\n", i, j, k, (void *)&matrix_3d[i][j][k]);
			}
		}
	}

	/*TO-DO*/

	/*actual memory address*/
	/*matrix_3d[0:3, 0:4, 0:1] is a row-major array.
	Identify the memory location of the array element matrix_3d[3][1][1].*/

	int row = 3;
    int column = 1;
    int index = 1;

    //A[i][j][k] = base + size * (row * n column * n width) + (column * n width) + index
    int base = (int)&matrix_3d[0][0][0];
    int elesize = sizeof(int);
    int ncolumn = COL;
    int nwidth = DEPTH;
    int address = base + (row * ncolumn * nwidth + column * nwidth + index) * elesize;

    printf("\nmatrix_3d[3][1][1] is located at: %p\n", (void *)address);
    printf("%p + (%d * %d * %d) + (%d * %d) + %d = %p\n",(void *)base,row,ncolumn,nwidth,column,nwidth,index,(void *)address);


    // using &
    int *addAND = &matrix_3d[row][column][index];
    printf("\nmemory address using & symbol: %p\n", (void *)addAND);

	return 0;
}
