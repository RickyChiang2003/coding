#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void find(int n, int a[9][9], int b[11][11]){
	if (n == 81){
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (a[i][j] != 0) 
					return;
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
				printf("%d%c", b[i][j], j == 9 ? '\n' : ' ');
		exit(0);		
	}

	int r = n / 9, c = n % 9, temp = 0, flag = 0;
	for (int i = 0; i < r - 1; i++)
		for (int j = 0; j < 9; j++)
			if (a[i][j] != 0) 
				flag = 1;
	if (flag == 1) 
		return;

	b[r + 1][c + 1] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (r + i > 0 && r + i <= 9 && c + j > 0 && c + j <= 9){
				a[r - 1 + i][c - 1 + j]--;
				if (a[r - 1 + i][c - 1 + j] < 0) 
					flag = 1;
			}
	
	if (flag == 0)
		find(n + 1, a, b);
	
	b[r + 1][c + 1] = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (r + i > 0 && r + i <= 9 && c + j > 0 && c + j <= 9)
				a[r - 1 + i][c - 1 + j]++;

	find(n + 1, a, b);
}

int main() {
	int a[9][9], b[11][11] = {0};
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &a[i][j]);
	find(0, a, b);
	printf("no solution\n");
	return 0;
}
