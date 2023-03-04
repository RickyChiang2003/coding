#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
# define SIZE 25


void print(int R, int C, int B[][SIZE]){
    for(int i = 0; i < R; i++)
	for(int j = 0; j < C; j++){
	    printf("%c", (B[i][j] == 1) ? 'o' : '_');
	    if(j == C-1)
		printf("\n");
	}
}


void input(int* R, int* C, int* flag, int B[][SIZE], int cond[][SIZE][SIZE]){
    scanf("%d%d", R, C);
    *flag = *R * *C;
    int L[2] = {*R, *C}, bars = 0;
    for(int l = 0; l < 2; l++)
	for(int i = 0; i < L[l]; i++){
	    scanf("%d", &bars);
	    for(int j = 0; j < bars; j++)
		scanf("%d", &(cond[l][i][j]));
	}
}


int bars_correct(int R, int C, int B[][SIZE], int cond[][SIZE][SIZE], int l, int n){
    int L[2] = {R, C};
    int barlen = 0;
    int black = 0;
    int flag = 0;
    int Il = (l == 0) ? 1 : 0;
    
    for(int i = 0; i < L[Il]; i++){
	int bar = (Il == 0) ? B[i][n] : B[n][i];
	if(bar == 1){
	    black = 1;
	    barlen++;
	}
	if(bar == -1 && black){
	    if(cond[l][n][flag] != barlen || !(cond[l][n][flag])){
		return 0;
	    }
	    barlen = 0;
	    black = 0;
	    flag++;
	}
    }
    if(black){
	if(cond[l][n][flag] != barlen || !(cond[l][n][flag]))
	    return 0;
	flag++;
    }
    if(cond[l][n][flag] != 0)
	return 0;

    return 1;
}


int valid(int R, int C, int B[][SIZE], int cond[][SIZE][SIZE]){
    int L[2] = {R, C};
    for(int l = 0; l < 2; l++)
	for(int i = 0; cond[l][i][0] != 0; i++){
	    if(!bars_correct(R, C, B, cond, l, i))
		    return 0;
	}
    return 1;

}


void findcell(int R, int C, int B[][SIZE], int *r, int *c){
    for(int i = 0; i < R; i++)
	for(int j = 0; j < C; j++)
	    if(B[i][j] == 0){
		*r = i, *c = j;
		return;
	    }
}


int paint(int R, int C, int flag, int B[][SIZE], int cond[][SIZE][SIZE]){
    if(flag == 0){
	if(valid(R, C, B, cond)){
	    print(R, C, B);
	    return 1;
	}

	flag++;
	return 0;
    }
    else{
	//1 for black, -1 for white
	flag--;
	int r, c;
       	findcell(R, C, B, &r, &c);
	B[r][c] = 1;
	if(paint(R, C, flag, B, cond))
	    return 1;
	B[r][c] = -1;
	if(paint(R, C, flag, B, cond))
	    return 1;

	flag++;
	B[r][c] = 0;
	return 0;
    }
}


int main(){
    int R, C, flag = 0;
    int cond[2][SIZE][SIZE] = {0};
    int B[SIZE][SIZE] = {0};
    
    input(&R, &C, &flag, B, cond);
    paint(R, C, flag, B, cond);


    return 0;
}

