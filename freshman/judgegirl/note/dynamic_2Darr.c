# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
//this one is better
int main() {
	int R, C;
	scanf("%d%d", &R, &C);
	int** arr = calloc(R, sizeof(*arr));
	for (int i = 0; i < R; i++)
		arr[i] = calloc(C, sizeof(*(arr[i])));

	// code

	for (int i = 0; i < R; i++)
		free(arr[i]);
	free(arr);
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
//this one is not good
int main() {

	const int sizex = 3;
	const int sizey = 2;

	int** ia = (int**)malloc(sizey * sizeof(void*));
	//int* arr = (int*)malloc(length * sizeof(int));
	//has two problems.The cast and that you're using the type instead of variable as argument for sizeof. Instead, do like this:
	//int* arr = malloc(length * sizeof(*arr));

	for (int y = 0; y != sizey; ++y)
		ia[y] = (int*)malloc(sizex * sizeof(int*));

	// code

	for (int y = 0; y != sizey; ++y)
		free(ia[y]);
	free(ia);

}
*/