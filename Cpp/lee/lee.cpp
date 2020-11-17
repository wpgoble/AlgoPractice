#include <iostream>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

// M x N matrix
#define M 10
#define N 10

struct Node
{
	// (x, y) represents matrix cell coordinates 
	// dist represetns its min distance from src
	int x;
	int y;
	int dist;
};

int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

// Can we go to (row, col) from curr position?
bool isValid(int mat[][N], bool visited[][N], int row, int col);

// Find the shortest possible path from src(i, j) to 
// dest (x,y)
void BFS(int mat[][N], int i, int j, int x, int y);

int main()
{
	// input maze 
	int mat[M][N] = 
	{
		{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
		{0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
		{0, 0, 1, 0, 0, 1, 1, 0, 0, 1}
	};

	BFS(mat, 0, 0, 7, 5);
	return 0;
}


// Can we go to (row, col) from curr position?
bool isValid(int mat[][N], bool visited[][N], int row, int col)
{
	return (row >= 0) && (row < M) && (col >=0) && (col < M)
		&& mat[row][col] && !visited[row][col];
}

// Find the shortest possible path from src(i, j) to 
// dest (x,y)
void BFS(int mat[][N], int i, int j, int x, int y)
{
	bool visited[M][N];							// tracks visited cells
	memset(visited, false, sizeof(visited));	// initilizes all cells to false
	Node temp;
	queue<Node> q;

	visited[i][j] = true;						//mark cell as visited and enque it
	temp.x = i;
	temp.y = j;
	temp.dist = 0;
	q.push(temp);

	int min_dist = INT_MAX;
	while(!q.empty())
	{
		Node node = q.front();
		q.pop();

		// get current cell
		int i = node.x;
		int j = node.y;
		int dist = node.dist;

		// if we found dest, update dist and stop
		if(i == x && j == y)
		{
			min_dist = dist;
			break;
		}

		// check for all 4 possible movements from current cells 
		// and enqueue each valid movement
		for(int k = 0; k < 4; k++)
		{
			// check if it is possible to go to position 
			// (i + row[k], j + col[k]) from curr position
			if(isValid(mat, visited, i+row[k], j+col[k]))
			{
				// mark next cell as visited and enque it
				Node marked;
				marked.x = i + row[k];
				marked.y = j + col[k];
				marked.dist = dist + 1;

				visited[i+row[k]][j+col[k]] = true;
				q.push(marked);
			}
		}
	}

	if(min_dist != INT_MAX)
	{
		cout << "The shortest path from the source to destination " 
			<< "has length " << min_dist << endl;
	}
	else
	{
		cout << "Destination can not be reached from given source\n";
	}
}