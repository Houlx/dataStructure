#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include "Graph1.h"
using namespace std;

class AdjGraph :public Graph {
public:
	int** matrix;
public:
	AdjGraph(int vertexNum) :Graph(vertexNum) {
		int i, j;
		matrix = (int**)new int*[vertexNum];
		for (i = 0; i < vertexNum; i++) {
			matrix[i] = new int[vertexNum];
		}
		for (i = 0; i < vertexNum; i++) {
			for (j = 0; j < vertexNum; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	~AdjGraph() {
		for (int i = 0; i < vertexNum; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	Edge getFirstEdge(int oneVertex) {
		Edge tmpEdge;
		tmpEdge.start = oneVertex;
		for (int i = 0; i < vertexNum; i++) {
			if (matrix[oneVertex][i] != 0) {
				tmpEdge.end = i;
				tmpEdge.weight = matrix[oneVertex][i];
				break;
			}
		}
		return tmpEdge;
	}

	Edge getNextEdge(Edge oneEdge) {
		Edge tmpEdge;
		tmpEdge.start = oneEdge.start;
		for (int i = oneEdge.end + 1; i < vertexNum; i++) {
			if (matrix[oneEdge.start][i] != 0) {
				tmpEdge.end = i;
				tmpEdge.weight = matrix[oneEdge.start][i];
				break;
			}
		}
		return tmpEdge;
	}

	void setEdge(int start, int end, int weight) {
		if (matrix[start-1][end-1] == 0) {
			edgeNum++;
		}
		matrix[start-1][end-1] = weight;
	}

	void delEdge(int start, int end) {
		if (matrix[start-1][end-1] != 0) {
			edgeNum--;
		}
		matrix[start - 1][end - 1] = 0;
	}

	void print() {
		for (int i = 0; i < vertexNum; i++) {
			for (int j = 0; j < vertexNum; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void DFS() {
		int i, v, u;
		stack<int> s;
		for (i = 0; i < getVertexNum(); i++) {
			markVisited[i] = UNVISITED;
		}
		for (i = 0; i < getVertexNum(); i++) {
			if (markVisited[i] == UNVISITED) {
				s.push(i);
				cout << i + 1 << " ";
				markVisited[i] = VISITED;
				while (!s.empty()) {
					v = s.top();
					s.pop();
					for (Edge e = getFirstEdge(v); isEdge(e); e = getNextEdge(e)) {
						u = getEndVertex(e);
						if (markVisited[u] == UNVISITED) {
							s.push(u);
							cout << u + 1 << " ";
							markVisited[u] = VISITED;
						}
					}
				}
			}
		}
	}

	void BFS(int v) {
		queue<int> q;
		cout << v + 1 << " ";
		markVisited[v] = VISITED;
		q.push(v);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (Edge e = getFirstEdge(v); isEdge(e); e = getNextEdge(e)) {
				int u1 = markVisited[getEndVertex(e)];
				v = getEndVertex(e);
				if (u1 == UNVISITED) {
					cout << v + 1 << " ";
					markVisited[v] = VISITED;
					q.push(v);
				}
			}
		}
	}

	void BFS() {
		int v;
		for (v = 0; v < getVertexNum(); v++) {
			markVisited[v] = UNVISITED;
		}
		for (v = 0; v < getVertexNum(); v++) {
			if (markVisited[v] == UNVISITED) {
				BFS(v);
			}
		}
	}


};

void Dijkstra(AdjGraph& G, int s, int* D, int* Path)
{
	for (int i = 0; i < G.getVertexNum(); i++)
	{
		G.markVisited[i] = 0;
		D[i] = 10000;
		Path[i] = -1;
	}

	G.markVisited[s] = VISITED;
	D[s] = 0;
	Path[s] = s;
	int i, j;
	for (Edge e = G.getFirstEdge(s); G.isEdge(e); e = G.getNextEdge(e))
	{
		int endVertex = e.end;
		D[endVertex] = e.weight;
		Path[endVertex] = s;
	}

	for (i = 0; i < G.getVertexNum() - 1; i++)
	{
		int MIN = 10000;
		int k = 0;
		for (j = 0; j < G.getVertexNum(); j++)
		{
			if (G.markVisited[j] == 0 && D[j] < MIN)
			{
				MIN = D[j];
				k = j;
			}
		}
		G.markVisited[k] = 1;
		for (Edge e = G.getFirstEdge(k); G.isEdge(e); e = G.getNextEdge(e))
		{
			int endVertex = e.end;
			if (G.markVisited[endVertex] == 0 && D[endVertex] > (D[k] + e.weight))
			{
				D[endVertex] = D[k] + e.weight;
				Path[endVertex] = k;
			}
		}
	}
}

void Floyd(AdjGraph &G, int* adj[], int* path[]) {
	int i, j, v;
	int n = G.getVertexNum();
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) {
				adj[i][j] = 0;
				path[i][j] = i;
			}
			else {
				adj[i][j] = 1000;
				path[i][j] = -1;
			}
		}
	}
	for (v = 0; v < n; v++) {
		for (Edge e = G.getFirstEdge(v); G.isEdge(e); e = G.getNextEdge(e)) {
			adj[v][e.end] = G.getWeight(e);
		}
	}
	for (v = 0; v < n; v++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (adj[i][j] > (adj[i][v] + adj[v][j])) {
					adj[i][j] = adj[i][v] + adj[v][j];
					path[i][j] = v;
				}
			}
		}
	}
}

void DFS(AdjGraph& G,int v)
{
	cout << v << " ";
	G.markVisited[v] = VISITED;
	for (Edge e = G.getFirstEdge(v); G.isEdge(e); e = G.getNextEdge(e))
	{
		if (G.markVisited[e.end] == 0)
		{
			DFS(G,e.end);
		}
	}
}
bool TopologySort(AdjGraph& G, int* sortArray) {
	int n = G.getVertexNum();
	int* inDegree = new int[n];
	int v;
	Edge e;

	//all set 0 and unvisited
	for (v = 0; v < n; v++) {
		inDegree[v] = 0;
		G.markVisited[v] = UNVISITED;
	}

	//count all node's indegree
	for (v = 0; v < n; v++) {
		for (e = G.getFirstEdge(v); G.isEdge(e); e = G.getNextEdge(e)) {
			inDegree[e.end]++;
		}
	}

	for (int i = 0; i < n; i++) {
		//find position that doesn't have indegree
		for (v = 0; v < n; v++) {
			if (inDegree[v] == 0 && G.markVisited[v] == UNVISITED) {
				break;
			}
		}
		//now v is the node that has no indegree
		//if all nodes have indegree it suggests failed
		if (v == n) {
			cout << "has round" << endl;
			int m;
			for (m = 0; m < n; m++) {
				if (inDegree[m] != 0 && G.markVisited[m] == UNVISITED) {
					break;
				}
			}
			DFS(G, m);
			return false;
		}
		//put into topo aray and mark visited
		G.markVisited[v] = VISITED;
		sortArray[i] = v;
		//delete v's outdegree(other nodes' indegree with it)
		for (e = G.getFirstEdge(v); G.isEdge(e); e = G.getNextEdge(e)) {
			inDegree[e.end]--;
		}
	}
	delete[] inDegree;
	return true;
}

int main() {
	AdjGraph graph(6);
	graph.setEdge(1, 2, 6);
	graph.setEdge(2, 1, 6);
	graph.setEdge(1, 3, 1);
	graph.setEdge(3, 1, 1);
	graph.setEdge(1, 4, 5);
	graph.setEdge(4, 1, 5);
	graph.setEdge(2, 3, 5);
	graph.setEdge(3, 2, 5);
	graph.setEdge(3, 4, 5);
	graph.setEdge(4, 3, 5);
	graph.setEdge(2, 5, 3);
	graph.setEdge(5, 2, 3);
	graph.setEdge(3, 5, 6);
	graph.setEdge(5, 3, 6);
	graph.setEdge(5, 6, 6);
	graph.setEdge(6, 5, 6);
	graph.setEdge(3, 6, 4);
	graph.setEdge(6, 3, 4);
	graph.setEdge(4, 6, 2);
	graph.setEdge(6, 4, 2);
	graph.print();
	cout << endl;

	int D[10] = { 0 };
	int path[10] = { 0 };
	Dijkstra(graph, 0, D, path);
	for (int i = 0; i < graph.getVertexNum(); i++) {
		cout << D[i] << " ";
	}
	cout << endl << endl;


	int** adj = (int**)new int*[6];
	int** pathFloyd = (int**)new int*[6];
	for (int i = 0; i < 6; i++) {
		adj[i] = new int[6];
		pathFloyd[i] = new int[6];
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			adj[i][j] = 0;
			pathFloyd[i][j] = 0;
		}
	}

	Floyd(graph, adj, pathFloyd);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	AdjGraph topo(4);
	topo.setEdge(1, 2, 1);
	topo.setEdge(1, 3, 1);
	topo.setEdge(4, 3, 1);
	topo.setEdge(2, 4, 1);
	topo.setEdge(3, 2, 1);

	int sortArray[4] = { 0 };
	TopologySort(topo, sortArray);
}