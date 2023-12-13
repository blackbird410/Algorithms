#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define YES 1
#define NO 0
#define WALL 1
#define MARKED -1

typedef struct Maze
{
	int board[SIZE][SIZE];
	int size;
} Maze;

void inputMaze(Maze *maze);
int solveMaze(Maze *maze);

int main()
{
	int answer;
	Maze maze;

	scanf("%d", &maze.size);
	inputMaze(&maze);
	answer = solveMaze(&maze);
	switch(answer)
	{
		case YES:
			printf("Yes\n");
			break;
		case NO:
			printf("No\n");
			break;
		default:
			break;
	}
	return 0;
}

void inputMaze(Maze *maze)
{
	int i, j;

	for (i = 0; i < maze->size; i++)
		for (j = 0; j < maze->size; j++)
			scanf("%d", &maze->board[i][j]);
}

int canBeMarked(Maze *maze, int i, int j)
{
	int n = maze->size;
	return (i < n - 1 && maze->board[i + 1][j] == MARKED ||
				i > 0 && maze->board[i - 1][j] == MARKED|| 
				j < n - 1 && maze->board[i][j + 1] == MARKED|| 
				j > 0 && maze->board[i][j - 1] == MARKED);
}

int solveMaze(Maze *maze)
{
	int i, j, flag = 1, n = maze->size;

	maze->board[0][0] = MARKED;
	while(flag)
	{
		flag = 0;
		if (maze->board[n - 1][n - 1] == MARKED)
            return YES;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (maze->board[i][j] == WALL || maze->board[i][j] == MARKED)
					continue;
				
				if (canBeMarked(maze, i, j))
				{
					maze->board[i][j] = MARKED;
					flag = 1;
				}
			}
		}
	}

	return (maze->board[n - 1][n - 1] == MARKED);
}
