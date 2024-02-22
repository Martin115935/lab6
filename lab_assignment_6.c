#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	
	//This is the start of my binary seach
	int a,b,c=-1;
	a = (low+high)/2;
	b = numbers[a];
	if(low>high) {
		return -1;
	}
	
	if(b < value) {
		c = search(numbers,a+1,high,value);
		if(c>-1) {
			return c;
		}
	}
	if(b > value) {
		c =search(numbers,low,a-1,value);
		if(c>-1) {
			return c;
		}
	}
	
	if(b == value) {
		return a;
	}
	
	
	
	
	return -1;

}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
