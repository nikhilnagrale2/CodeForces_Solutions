/*
  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2

  Copyright       :   Study and Solve. :) 
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
	map<T, list<T>> l;

public:
	void addEdge(int x, int y)
	{
		l[x].push_back(y);
		// l[y].push_back(x);
	}

	int bfs(T src, T dest)
	{
		map<T, int> dist;
		map<T, T> parent;
		queue<T> q;

		for (auto node_pair : l)
		{
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}

		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while (!q.empty())
		{
			T node = q.front();
			q.pop();
			// cout << node << " ";
			for (int nbr : l[node])
			{
				if (dist[nbr] == INT_MAX)
				{
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
					parent[nbr] = node;
				}
			}
		}

		for (auto node_pair : l)
		{
			cout << node_pair.first << " and dist " << dist[node_pair.first] << endl;
		}

		T temp = dest;
		while (temp != src)
		{
			cout << temp << "<--";
			temp = parent[temp];
		}
		cout << src << endl;

		return dist[dest];
	}
};

int main()
{
	int board[50] = {0};

	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	Graph<int> g;
	for (int i = 0; i < 37; i++)
	{
		for (int dice = 1; dice <= 6; dice++)
		{
			int j = i + dice;
			j += board[j];
			if (j <= 36)
			{
				g.addEdge(i, j);
			}
		}
	}
	g.addEdge(36, 36);

	cout << g.bfs(0, 36) << endl;

	return 0;
}