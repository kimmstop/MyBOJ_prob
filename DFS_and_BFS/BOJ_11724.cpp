#include <stdio.h>

int N,M, map[1001][1001]= {0}, visit[1001] = {0};

int stack[1001] = { 0 }, top = 0;

void push(int vertex);
void DFS(int startv);


int main()
{
	scanf("%d %d", &N, &M);
	int u,v, ans=0;
	for(int i = 1; i <=  M; i++){
		scanf(" %d %d", &u, &v);
		map[u][v] = 1;
		map[v][u] = 1;
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(visit[i] == 0){
				DFS(i);
				ans++;
				top = 0;
			}
		}
	}
	printf("%d", ans);
}

void push(int vertex)
{
	stack[top++] = vertex;
}

void DFS(int startv)
{
	push(startv);
	visit[startv] = 1;
	for(int i = 1; i <= N; i++){
		if(map[startv][i] == 1 && visit[i] == 0){
			DFS(i);
		}
	}
		
}