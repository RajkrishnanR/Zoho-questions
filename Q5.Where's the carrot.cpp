
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;


bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y)
{
	return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) &&
			mat[x][y] == 1 && !visited[x][y];
}


void ShortestPath(vector<vector<int>> &mat, vector<vector<bool>> &visited,
				int i, int j, int x, int y, int &min_dist, int dist){
	if (i == x && j == y){
		min_dist = min(dist, min_dist);
		return;
	}
	
	visited[i][j] = true;
	
	if (isSafe(mat, visited, i + 1, j)) {
		ShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
	}
	
	if (isSafe(mat, visited, i, j + 1)) {
		ShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
	}
	
	if (isSafe(mat, visited, i - 1, j)) {
		ShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
	}
	
	if (isSafe(mat, visited, i, j - 1)) {
		ShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
	}
	
	visited[i][j] = false;
}


int ShortestPathLength(vector<vector<int>> &mat, pair<int, int> &src,
					pair<int, int> &dest){
	if (mat.size() == 0 || mat[src.first][src.second] == 0 ||
			mat[dest.first][dest.second] == 0)
		return -1;
	
	int row = mat.size();
	int col = mat[0].size();
	
	vector<vector<bool>> visited;
	visited.resize(row, vector<bool>(col));

	int dist = INT_MAX;
	ShortestPath(mat, visited, src.first, src.second, dest.first, dest.second,
			dist, 0);

	if (dist != INT_MAX)
		return dist;
	return -1;
}

int main()
{
	vector<vector<int>> mat =
	{{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
				{1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
				{1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
				{0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
				{1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
				{1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
				{1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
				{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
				{1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};

	pair<int, int> src = make_pair(0, 0);
	pair<int, int> dest = make_pair(3, 4);
	int dist = ShortestPathLength(mat, src, dest);
	if (dist != -1)
		cout << "Shortest Path is " << dist;
	
	else
		cout << "No shortest path";

	return 0;
}


