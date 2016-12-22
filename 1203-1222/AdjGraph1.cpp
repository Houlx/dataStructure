#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include "Graph1.h"
using namespace std;

template <class T>
class MinHeap {
private:
	T* heapArray;
	int currentSize;
	int maxSize;
public:
	MinHeap(int size, int max = 100) {
		heapArray = new T[max];
		currentSize = 0;
		maxSize = max;
	}

	int getCurrentSize(){
		return currentSize;
	}
	bool isEmpty() {
		return currentSize == 0;
	}

	void initHeap() {
		for (int i = currentSize / 2 - 1; i >= 0; i--) {
			siftDown(i);
		}
	}

	void visit(){
		for(int i=0;i<currentSize;i++)
			cout<<heapArray[i]<<" ";
	}

	void siftUp(int position) {
		int child = position;
		int parent = (child - 1) / 2;
		T temp = heapArray[position];
		while (parent >= 0 && child >= 1) {
			if (heapArray[parent] > temp) {
				heapArray[child] = heapArray[parent];
				child = parent;
				parent = (child - 1) / 2;
			}
			else {
				break;
			}
		}
		heapArray[child] = temp;
	}

	bool insert(const T& item) {
		if (currentSize < maxSize) {
			heapArray[currentSize] = item;
			currentSize++;
		}
		siftUp(currentSize - 1);
		return true;
	}

	void siftDown(int left) {
		int i = left;
		int j = 2 * i + 1;
		T temp = heapArray[i];

		while (j < currentSize) {
			if ((j<currentSize - 1) && (heapArray[j]>heapArray[j + 1])) {
				j++;
			}if (temp>heapArray[j]) {
				heapArray[i] = heapArray[j];
				i = j;
				j = 2 * j + 1;
			}
			else {
				break;
			}
		}
		heapArray[i] = temp;
	}

	T& removeMin() {
		T temp;
		if (currentSize == 0) {
			cout << "cannot delete" << endl;
			return temp;
		}
		else {
			temp = heapArray[0];
			heapArray[0] = heapArray[currentSize - 1];
			currentSize--;
			if (currentSize > 1) {
				siftDown(0);
			}
			return temp;
		}
	}
};


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


//Edge* Prim(AdjGraph& G, int s) {
//	int i, j;
//	Edge* MST;
//	int* nearest;
//	int* neighbor;
//
//	int n = G.getVertexNum();
//
//	nearest = new int[n];
//	neighbor = new int[n];
//	MST = new Edge[n - 1];
//
//	for (i = 0; i < n; i++) {
//		neighbor[i] = s;
//		nearest[i] = 32767;
//	}
//
//	Edge e;
//	for (i=0, e = G.getFirstEdge(s); G.isEdge(e); e = G.getNextEdge(e),i++) {
//		nearest[i] = e.weight;
//	}
//
//	neighbor[s] = -1;
//	for (i = 1; i < n; i++) {
//
//		int min = 32767;
//		
//		int v = -1;
//
//		for (j = 0; j<n ; j++) {
//			if ((nearest[j] < min) && (neighbor[j] >= -1)) {
//				min = nearest[j];
//				v = j;
//			}
//		}
//
//		if (v >= 0) {
//			neighbor[v] = -1;
//			Edge tempEdge(neighbor[v], v, nearest[v]);
//			MST[i] = tempEdge;
//			for (Edge e = G.getFirstEdge(v); G.isEdge(e); e = G.getNextEdge(e)) {
//				int u = e.end;
//				if ((neighbor[u] != -1) && (nearest[u] > e.weight)) {
//					neighbor[u] = v;
//					nearest[u] = e.weight;
//				}
//			}
//		}
//
//	}
//	delete[] neighbor;
//	delete[] nearest;
//	return MST;
//}


void Prim(AdjGraph g)
{
	int n=g.getVertexNum();
    bool *u=new bool[n];
    int *nearest=new int[n];
    int *end1=new int[n];
    for (int i=0;i<n;i++)
    {
        u[i]=false;
        nearest[i]=100;
        end1[i]=-1;
    }
    u[0]=true;
    int min,t,s;
    for (int k=0;k<n-1;k++)
    {
        for (int i=0;i<n;i++)
        {
            nearest[i]=100;
            end1[i]=-1;
        }

        for (int i=0;i<n;i++){
			if(u[i]){
				for (int j=0;j<n;j++)
                    if(u[j]==0 &&g.matrix[i][j]>0 && g.matrix[i][j]< nearest[i])
                {
                    nearest[i]=g.matrix[i][j];
                    end1[i]=j;
                }
			}
        }
        min=100;t=-1;s=-1;
        for (int i=0;i<n;i++)
            if (u[i] && nearest[i]<min)
            {
                min=nearest[i];
                s=i;
                t=end1[i];
            }
        cout<<s<<"->"<<t<<":"<<min<<" ";
        u[t]=true;
    }
}

class UFSets {
private:
	int n;
	int* root;
	int* next;
	int* length;
public:
	UFSets(int size) {
		n = size;
		root=new int[n];
		next=new int[n];
		length=new int[n];
		for (int i = 0; i < n; i++) {
			root[i] = next[i] = i;
			length[i] = 1;
		}
	}

	int find(int v) {
		return root[v];
	}

	void merge(int v, int u) {
		if (root[u] == root[v]) {
			return;
		}
		else if (length[root[v]] < length[root[u]]) {
			int rt = root[v];
			length[root[u]] += length[rt];
			root[rt] = root[u];
			for (int j = next[rt]; j != rt; j = next[j]) {
				root[j] = root[u];
			}
			swap(next[rt], next[root[u]]);
		}
		else {
			int rt = root[u];
			length[root[v]] += length[rt];
			root[rt] = root[v];
			for (int j = next[rt]; j != rt; j = next[j]) {
				root[j] = root[v];
			}
			swap(next[rt], next[root[v]]);
		}
	}
};

Edge* Kruskal(AdjGraph& G) {
	int n = G.getVertexNum();
	UFSets set(n);
	Edge *MST = new Edge[n - 1];
	MinHeap<Edge> h(G.getEdgeNum());
	Edge edge;

	for (int i = 0; i < G.getVertexNum(); i++) {
		for (edge = G.getFirstEdge(i); G.isEdge(edge); edge = G.getNextEdge(edge)) {
			if (G.getStartVertex(edge) < G.getEndVertex(edge)) {
				h.insert(edge);
			}
		}
	}

	int edgeNum = 0;
	while (edgeNum < n - 1) {
		if (!h.isEmpty()) {
			edge = h.removeMin();
			int v = edge.start;
			int u = edge.end;
			if (set.find(v) != set.find(u)) {
				set.merge(v, u);
				MST[edgeNum++] = edge;
			}
		}
		else {
			cerr << "no min tree" << endl;
			return NULL;
		}
	}
	return MST;
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

	graph.DFS();
	cout << endl;
	graph.BFS();
	cout<<endl;

	Edge* edges=Kruskal(graph);
	cout << endl;
	for (int i = 0; i < graph.getVertexNum()-1 ; i++) {
		cout << edges[i] << " ";
	}

	cout<<endl;
	Prim(graph);	
}