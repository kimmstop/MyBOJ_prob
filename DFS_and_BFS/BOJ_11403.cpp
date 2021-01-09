#include <stdio.h>

int N, map[100][100]={0}, ansmap[100][100] = { 0 };
int stack[1000] = { 0 }, visit[100] = {0}, top = 0;

void push(int v);
int pop();
void DFS(int startv);
void addpath(int newv);
void addcircle(int newv);

int main()
{	
	scanf("%d", &N);
	for(int i = 0; i< N; i++){
		for(int j = 0; j< N;j++){
			scanf(" %d", &map[i][j]);
		}
	}
	for(int i = 0;i < N; i++){
			push(i);
			visit[i] = 1;
			DFS(i);
			top = 0;
			memset(stack,0,4000);
			memset(visit,0,400);
	}
	for(int i = 0;i<N;i++){
		for(int j =0;j<N;j++){
			printf("%d ", ansmap[i][j]);
		}
		printf("\n");
	}
}


void push(int v)
{
	stack[top++] = v;
}

int pop()
{
	int ret = stack[--top];
	return ret;
}

int isinstack(int newv)
{
	for(int i = 0;i<top;i++){
		if(newv == stack[i])
			return 1;
	}
	return 0;
}


void DFS(int startv)
{
	int curv = startv;
	for(int i = 0;i < N; i++){
		if(map[curv][i] == 1){
			if(visit[i] == 1){
				if(isinstack(i)){
					ansmap[i][i] = 1;
				}
        			continue;     
			}
			else{
				addpath(i);
			}
			push(i);
			visit[i] = 1;
			DFS(i);
			pop();
			
		}
		
	}
}

void addpath(int newv)
{
	for(int i = 0; i< top; i++){
		ansmap[stack[i]][newv]=1;
	}
}





