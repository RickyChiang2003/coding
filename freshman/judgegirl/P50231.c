# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
/*

int find(int x, int y, int k, int s, int hash[20001][11][3], int c, int kase) {
    int f = (77 * k + 2222) % s;
    int flag = 0;
    for (int i = 0; i <= c; i++) {
        if (hash[f][i][0] == k) {
            if (kase == 0)
                printf("%d", k);
            else
                printf(" %d", k);
            hash[f][i][0] = -1;
            return i;
        }
    }
    for (int i = 0; i <= c; i++) {
        if (hash[f][i][0] == -1) {
            hash[f][i][0] = k;
            hash[f][i][1] = x;
            hash[f][i][2] = y;
            return -1;
        }
    }
}

int main() {
    int kase = 0;
    int n, s, c;
    scanf("%d%d%d", &n, &s, &c);
    int hash[20001][11][3];  //(k, x, y) [20001]
    for (int i = 0; i <= s; i++) {
        for (int j = 0; j <= c; j++) {
            hash[i][j][0] = -1;
        }
    }
    int tower[105][105][105];  // tower[105][105][105]
    int depth[105][105];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= i; k++) {
                scanf("%d", &tower[i][j][k]);
                depth[j][k] = (j == i || k == i) ? i : depth[j][k];
            }

    int p1[2], p2[2], flag = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int index = find(i, j, tower[depth[i][j]][i][j], s, hash, c, kase);
            //printf("%d\n",index);
            if (index != -1) {
                kase = 1;
                int f = (77 * tower[depth[i][j]][i][j] + 2222) % s;
                int x = hash[f][index][1];
                int y = hash[f][index][2];
                depth[x][y]++;
                depth[i][j]++;
                p1[0] = i, p1[1] = j;
                p2[0] = x, p2[1] = y;
                flag = 1;
            }
        }
    
    while (flag >= 1 && (depth[p1[0]][p1[1]] < n || depth[p2[0]][p2[1]] < n)) {
        int i = p1[0], j = p1[1];
        int i2 = p2[0], j2 = p2[1];
        int index1 = -1, index2 = -1;
        flag = 0;
        if (depth[i][j] < n)
            index1 = find(i, j, tower[depth[i][j]][i][j], s, hash, c, kase);
        if (depth[i2][j2] < n)
            index2 = find(i2, j2, tower[depth[i2][j2]][i2][j2], s, hash, c, kase);
        if (index1 != -1) {
            flag++;
            kase = 1;
            int f = (77 * tower[depth[i][j]][i][j] + 2222) % s;
            int x = hash[f][index1][1];
            int y = hash[f][index1][2];
            depth[x][y]++;
            depth[i][j]++;
            p1[0] = i, p1[1] = j;
            p2[0] = x, p2[1] = y;
        }
        if (index2 != -1) {
            flag++;
            kase = 1;
            int f = (77 * tower[depth[i2][j2]][i2][j2] + 2222) % s;
            int x = hash[f][index2][1];
            int y = hash[f][index2][2];
            depth[x][y]++;
            depth[i2][j2]++;
            p1[0] = i2, p1[1] = j2;
            p2[0] = x, p2[1] = y;
        }
    }
}*/