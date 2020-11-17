
from collections import deque

row = [-1, 0, 0, 1]
col = [0, -1, 1, 0]

def isValid(mat, visited, row, col):
	a = (row >= 0) and (row < M)
	b = (col >= 0) and (col < N)
	e = mat[row][col] == 1
	f = visited[row][col]
	return a and b and e and not f

def BFS(mat, i, j, x, y):
	visited = [[False for x in range(N)] for y in range(M)]
	q = deque()
	visited[i][j] = True
	q.append((i, j, 0))
	min_dist = float('inf')

	while q:
		(i, j, dist) = q.popleft()

		if i == x and j == y:
			min_dist = dist
			break

		for k in range(4):
			if isValid(mat, visited, i + row[k], j + col[k]):
				visited[i+row[k]][j+col[k]] = True
				q.append((i+row[k], j+col[k], dist+1))

	if min_dist != float('inf'):
		print("The shortest path from src to dest has length ", min_dist)
	else:
		print("Dest can not be reach from given src")

if __name__ == '__main__':
	# input maze
	mat = [
		[1, 1, 1, 1, 1, 0, 0, 1, 1, 1],
		[0, 1, 1, 1, 1, 1, 0, 1, 0, 1],
		[0, 0, 1, 0, 1, 1, 1, 0, 0, 1],
		[1, 0, 1, 1, 1, 0, 1, 1, 0, 1],
		[0, 0, 0, 1, 0, 0, 0, 1, 0, 1],
		[1, 0, 1, 1, 1, 0, 0, 1, 1, 0],
		[0, 0, 0, 0, 1, 0, 0, 1, 0, 1],
		[0, 1, 1, 1, 1, 1, 1, 1, 0, 0],
		[1, 1, 1, 1, 1, 0, 0, 1, 1, 1],
		[0, 0, 1, 0, 0, 1, 1, 0, 0, 1]
	]

	M = N = 10

	BFS(mat, 0, 0, 7, 5)