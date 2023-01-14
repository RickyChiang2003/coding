# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //atoi(), itoa(); abs() 絕對值;
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdint.h> //int8_t // uint8_t (不是unit啦ㄎㄅ)

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

void adjust(int i, int j, int tmp[9][9], int d) {
	int x, y;
	for(int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++) {
			x = i + dx;
			y = j + dy;
			if (x >= 0 && x < 9 && y >= 0 && y < 9)
				tmp[x][y] += d;
		}
}

void process(int i, int j, int F[9][9], int ans[9][9], int tmp[9][9], int* halt) {
	/*
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			printf("%d%c", tmp[i][j], j == 8 ? '\n' : ' ');
	*/
	if (!*halt){
		if (i == 8 && j == 8) {
			if (ans[i][j])
				adjust(i, j, tmp, -1);
			ans[i][j] = 0;
			check(F, ans, tmp, halt);

			ans[i][j] = 1;
			adjust(i, j, tmp, 1);
			check(F, ans, tmp, halt);
		}
		else {
			//printf("i = %d, j = %d\n", i, j);
			int ti = (j == 8) ? i + 1 : i;
			int tj = (j == 8) ? 0 : j + 1;

			if (ans[i][j])
				adjust(i, j, tmp, -1);
			ans[i][j] = 0;
			process(ti, tj, F, ans, tmp, halt);

			ans[i][j] = 1;
			adjust(i, j, tmp, 1);
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