const int UNVISITED = 0;
const int VISITED = 1;
#include <iostream>
using namespace std;
class Edge {
public:
	
	int start;
	int end;
	int weight;

	Edge() {
		start = 0;
		end = 0;
		weight = 0;
	}
	
	Edge(int start, int end, int weight) {
		this->start = start;
		this->end = end;
		this->weight = weight;
	}

	bool operator > (Edge oneEdge) {
		return this->weight > oneEdge.weight;
	}
	bool operator < (Edge oneEdge) {
		return this->weight < oneEdge.weight;
	}

	friend ostream& operator <<(ostream& cout,Edge& e){
		cout<<e.weight;
		return cout;
	}
};


class Graph {
public:
	
	int vertexNum;
	int edgeNum;
	int* markVisited;

	Graph(int vertexNum) {
		this->vertexNum = vertexNum;
		edgeNum = 0;
		markVisited = new int[vertexNum];

		for (int i = 0; i < vertexNum; i++) {
			markVisited[i] = UNVISITED;
		}
	}

	~Graph() {
		delete[] markVisited;
		//delete[] indegree;
	}

	virtual Edge getFirstEdge(int oneVertex) = 0;
	virtual Edge getNextEdge(Edge oneEdge) = 0;

	int getVertexNum() {
		return vertexNum;
	}

	int getEdgeNum() {
		return edgeNum;
	}

	bool isEdge(Edge oneEdge) {
		return (oneEdge.weight > 0 && oneEdge.weight != -1 && oneEdge.end >= 0);
	}

	int getStartVertex(Edge oneEdge) {
		return oneEdge.start;
	}

	int getEndVertex(Edge oneEdge) {
		return oneEdge.end;
	}

	int getWeight(Edge oneEdge) {
		return oneEdge.weight;
	}

	virtual void setEdge(int start, int end, int weight) = 0;
	virtual void delEdge(int start, int end) = 0;
};