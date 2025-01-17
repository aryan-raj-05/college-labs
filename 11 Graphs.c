#include <stdio.h>

#define MAX 128

int a[MAX][MAX], n;
int visited[MAX];
int stack[MAX], top = -1;
int queue[MAX], front = -1, rear = -1;

void dfs(int v) {
	visited[v] = 1;
	stack[++top] = v;

	for (int i = 1; i <= n; i++) {
		if (a[v][i] == 1 && visited[i] == 0) {
			printf("%d ", i);
			dfs(i);
		}
	}
}

void bfs (int v) {
	visited[v] = 1;
	queue[++rear] = v;

	while (front != rear) {
		int cur = queue[++front];
		for (int i = 1; i <= n; i++) {
			if (a[cur][i] == 1 && visited[i] == 0) {
				queue[++rear] = i;
				visited[i] = 1;
				printf("%d ", i);
			}
		}
	}
}

int main() {
	int choice;

	printf("Enter no of vertices in graph: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) 
		visited[i] = 0;

	printf("\n1.bfs\n2.dfs\3.exit");
	scanf("%d", &choice);
	int start;

	switch (choice) {
		case 1:
			printf("enter starting vertex: ");
			scanf("%d", &start);
			printf("Node reachable from starting vertex are:");
			bfs(start);
			for (int i = 1; i <= n; i++)
				if (visited[i] == 0)
					printf("node not reachable is: %d\n", i);
			break;
		case 2:
			printf("enter starting vertex: ");
			scanf("%d", &start);
			printf("nodes reachable from start: ");
			dfs(start);
			break;
		case 3: return 0;
	}
}