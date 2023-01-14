# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void check(int F[9][9], int ans[9][9], int tmp[9][9], int* halt) {
	if (!*halt) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (F[i][j] != tmp[i][j]) return;
		*halt = 1;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				printf("%d%c", ans[i][j], j == 8 ? '\n' : ' ');

	}
}

int adjust(int i, int j, int F[9][9], int tmp[9][9], int d) {
	int x, y, flag = 0;
	for(int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++) {
			x = i + dx;
			y = j + dy;
			if (x >= 0 && x < 9 && y >= 0 && y < 9){
				tmp[x][y] += d;				
				if (tmp[x][y] > F[x][y])
					flag = 1;
			}
		}
	if (flag)
		return 0;
	return 1;
}

void process(int i, int j, int F[9][9], int ans[9][9], int tmp[9][9], int* halt) {
	printf("%d %d\n", i, j);
	for (int i1 = 0; i1 < 9; i1++)
		for (int j1 = 0; j1 < 9; j1++)
			printf("%d%c", ans[i1][j1], j1 == 8 ? '\n' : ' ');
	printf("\n");
	for (int i1 = 0; i1 < 9; i1++)
		for (int j1 = 0; j1 < 9; j1++)
			printf("%d%c", tmp[i1][j1], j1 == 8 ? '\n' : ' ');
	printf("\n");

	if (!*halt){
		if (i == 8 && j == 8) {
			if (ans[i][j])
				adjust(i, j, F, tmp, -1);
			ans[i][j] = 0;
			check(F, ans, tmp, halt);

			ans[i][j] = 1;
			if (adjust(i, j, F, tmp, 1))
				check(F, ans, tmp, halt);
		}
		else {
			int ti = (j == 8) ? i + 1 : i;
			int tj = (j == 8) ? 0 : j + 1;

			if (ans[i][j])
				adjust(i, j, F, tmp, -1);
			ans[i][j] = 0;
			process(ti, tj, F, ans, tmp, halt);

			ans[i][j] = 1;
			if (adjust(i, j, F, tmp, 1))
				process(ti, tj, F, ans, tmp, halt);

		}
	}
}

int main() {
	int F[9][9] = { 0 };
	int ans[9][9] = { 0 };
	int tmp[9][9] = { 0 };
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &(F[i][j]));
	
	int halt = 0;
	process(0, 0, F, ans, tmp, &halt);

	if (!halt)
		printf("no solution\n");

	return 0;
}