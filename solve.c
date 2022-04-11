#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

int n = 0, m = 0;

int **map;

void print() {	
	system("cls");
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 5; j++) {
			if( map[i][j] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%d ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			} else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("%d ", map[i][j]);
			} 
		}
		printf("\n");
		
		
	}
} 
 
bool dfs(int **map, int x, int y){
	if( x <= -1 or x >= n or y <= -1 or  y >= m) 
		return false;
	
	print();
		
	Sleep(200);
	
	if( map[x][y] == 0) {
		map[x][y] = 1;
		dfs(map, x - 1, y);
		dfs(map, x, y - 1);
		dfs(map, x + 1, y);
		dfs(map, x , y + 1);
		return true;
	}
	
	return false;
	
}

int main() {

	
	scanf("%d %d", &n, &m);
	
	map = (int **)malloc(sizeof(int *) * n);
	
	for(int i = 0; i < n; i++) {
		map[i] = (int *)malloc(sizeof(int) * m);
	}
	
	// 0으로 초기화 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			int data;
			scanf("%d", &data);
			map[i][j] = data;
		}
			
			
	int result = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if( dfs(map, i, j) ) {
				result += 1;
			}
		}
	}
	
	printf("%d", result);
	
	
	
	return 0;
}
