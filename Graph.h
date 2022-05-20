#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility> 

class Graph
{
private:
	// for you to decide
public:
	Graph(std::string filename); // throws an exception as a string if not possible to open the file
	Graph(const Graph& other) = delete;
	Graph(Graph&& other) = delete;
	Graph& operator=(const Graph& other) = delete;
	Graph& operator=(Graph&& other) = delete;
	~Graph();
	int nrOfNodes() const;
	int nrOfEdges() const;
	void shortestPathFrom(std::string& from, std::string& to, std::vector<std::pair<int, std::string>>& shortestPath) const;
};



//Dijkstra(G, w, s)
//{
//	INITIALIZE - SINGLE - SOURCE(G, s);
//	S = 0;
//	Q = G.V;
//	while Q = !0;
//	u = EXTRACT - MIN(Q);
//	S = S U{ u };
//	for each vertex v e G.Adj[u]
//	{
//		RELAX(u, v, w);
//	}
//}