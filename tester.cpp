#include "Graph.h"

int main()
{
	Graph theBestGraph("graph01.txt");
	//std::string from = "z";
	//std::string to = "t";
	//std::pair<int, std::string > temp;
	//temp.first = 1;
	//temp.second = from;
	//std::vector<std::pair<int, std::string>> d;
	//d.push_back(temp);
	//node.shortestPathFrom(from, to, d);
	//Graph node2(node);
	std::cout << theBestGraph.nrOfEdges() << "\t" << theBestGraph.nrOfNodes() << std::endl;
	//Graph node1("graph03.txt");
	//Graph node2("graph02.txt");
	//Graph node3("graph04.txt");
	theBestGraph.kruskalMST();
	//node1.kruskalMST();
	//node2.kruskalMST();
	//node3.kruskalMST();
	//node.kruskalMST();
	
}
