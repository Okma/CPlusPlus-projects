
#include <iostream>
#include <algorithm>
using namespace std;

class WDGraph {
private:
	int ** dist;
	int ** next;
	int size;
public:
	// Constructor for double arrays
	WDGraph(int numNodes) {
		dist = new int*[numNodes];
		for (int i = 0; i < numNodes; i++) {
			dist[i] = new int[numNodes];
			fill(dist[i], dist[i] + numNodes, 100);
		}
		next = new int*[numNodes];
		for (int i = 0; i < numNodes; i++)
			next[i] = new int[numNodes];
		size = numNodes;
	}

	// Add in an edge relationship between 'from' and 'to'
	void addEdge(int from, int to, int weight) {
		dist[from - 1][to - 1] = weight;
		next[from - 1][to - 1] = to;
	}

	// After all edges have been added, calculate shortest paths between all edges
	void executeOrder66() {
		for (int k = 0; k < size; k++)
			for (int j = 0; j < size; j++)
				for (int i = 0; i < size; i++)
					if (dist[i][k] + dist[k][j] < dist[i][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						next[i][j] = next[i][k];
					}
	}

	// After order 66, given a 'from' and 'to', return the shortest path
	void calculatePath(int from, int to) {
		int totalWeight = 0;

		// Path is circular to itself
		if (from == to) {
			cout << "Cost = " << totalWeight << endl;
			cout << from << '-' << to << endl;
			return;
		}

		// No path exists from 'from' to 'to'
		if (next[from - 1][to - 1] < 1 || next[from - 1][to - 1] > size) {
			cout << "NO PATH" << endl;
			return;
		}
		else {

			// display the cost
			totalWeight = dist[from - 1][to - 1];
			cout << "Cost: " << totalWeight << endl;

			// show the path
			do {
				cout << from << "-";
				from = next[from - 1][to - 1];
			} while (from != to);
			cout << from << endl;
		}
	}
};

int main() {
	int nodes, edges, queries;
	cin >> nodes >> edges >> queries;
	WDGraph * graph = new WDGraph(nodes);
	int from, to, weight;

	// Add 'edges' amount of edge relationships
	while (edges != 0) {
		cin >> from >> to >> weight;
		if (to > nodes || to < 1 || from > nodes || from < 1) {
			cout << "Invalid Input. First or second input too high or too low." << endl;
		}
		else if (to == from) {
			cout << "Invalid Input. Inputs are identical." << endl;
		}
		else {
			graph->addEdge(from, to, weight);
			edges--;
		}
	}

	// Find all shortest paths
	graph->executeOrder66();

	// Then perform 'queries' amount of queries
	while (queries != 0) {
		cin >> from >> to;
		if (to > nodes || to < 1 || from > nodes || from < 1) {
			cout << "Invalid Input. First or second input too high or too low." << endl;
		}
		else {
			graph->calculatePath(from, to);
			queries--;
		}
	}

	cout << "All queries concluded. Enter any key to quit." << endl;
	cin >> to;

	return 0;
}