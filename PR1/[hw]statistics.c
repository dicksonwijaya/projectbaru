#include <stdio.h>
#include <math.h>
#define SIZE 99 // 陣列大小

//function prototypess
void printArray(int array[]);

int sum(int array[]);
int max(int array[]);
int min(int array[]);

float stdev(int array[]);

int median(int array[]);
int mode(int array[]);

int main(void)
{
	// 宣告一個99個元素的整數陣列，數值範圍介於1~9之間Declare a 99-element integer array with values ​​ranging from 1 to 9
	int values[SIZE] = {6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
						7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
						6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
						7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
						6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
						7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
						5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
						7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
						7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
						4, 5, 6, 1, 6, 5, 7, 8, 7};

	printf("[values]\n"); //print the arrays
	printArray(values);

	printf("\n***** Statistical Results *****\n");

	printf("\nSum : %d\n", sum(values));
	float sumval = sum(values);

	printf("Mean : %.2f\n", sumval/SIZE); //calculate mean=sum of n/n
	printf("Std.dev; : %.2f\n", stdev(values));
	printf("Max : %d\n", max(values));
	printf("Min : %d\n", min(values));
	printf("Median : %d\n", median(values));
	printf("Mode : %d\n", mode(values));

	return 0;
}

// 將陣列內容在螢幕顯示出來Display the array contents on the screen
void printArray(int array[])
{
	int i;
	for (i = 0; i < SIZE; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

//calculate sum, max, min, median, std.dev;,mode
int sum(int array[]){
	int i, sumval=0;
	for(i =0; i < SIZE; i++){
		sumval += array[i];
	}
	return sumval;
}

int max(int array[]){
	int i, maxim=0;
	for(i = 0; i<SIZE; i++){
		if(maxim<array[i]){
			maxim = array[i];
		}
	}
	return maxim;
}

int min(int array[]){
	int i;
	int minim = array[0];
	for(i = 0; i<SIZE; i++){
		if(minim>array[i]){
			minim = array[i];
		}
	}
	return minim;
}

int median(int array[]){

	int i,j;
	int temp= 0;
	int median=100/2;
	for(i =0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			if(array[j] > array[i]){
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	return array[median];
}

float stdev(int array[]){

	int i;
	float standard = 0;
	float temp=0;
	float sumval = sum(array);
	float mean = sumval/SIZE;

	for (i = 0; i < SIZE; i++) {
        temp+=pow(array[i]-mean,2);
	}
	temp /= SIZE;
	return sqrt(temp);
}

int mode(int array[]) {

	int count[9][2] = {{ 1, 0},
					   { 2, 0},
					   { 3, 0},
					   { 4, 0},
					   { 5, 0},
					   { 6, 0},
					   { 7, 0},
					   { 8, 0},
					   { 9, 0}};
	int i = 0;
	int j = 0;


	for (i = 0; i < SIZE; ++i) {
		if(array[i] == 1){
			count[0][1]++;
		}
		if(array[i] == 2){
			count[1][1]++;
		}
		if(array[i] == 3){
			count[2][1]++;
		}
		if(array[i] == 4){
			count[3][1]++;
		}
		if(array[i] == 5){
			count[4][1]++;
		}
		if(array[i] == 6){
			count[5][1]++;
		}
		if(array[i] == 7){
			count[6][1]++;
		}
		if(array[i] == 8){
			count[7][1]++;
		}
		if(array[i] == 9){
			count[8][1]++;
		}
	}

	int maximal = 0;
	for(i=0; i<9 ; ++i){
		if(maximal < count[i][1]){
			maximal = count[i][1];
			j = i;
		}
	}
	return count[j][0];
}

