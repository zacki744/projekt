#include "Graph.h"

int main()
{
	Graph node("graph01.txt");
	std::string from = "z";
	std::string to = "t";
	std::pair<int, std::string > temp;
	temp.first = 1;
	temp.second = from;
	std::vector<std::pair<int, std::string>> d;
	d.push_back(temp);
	node.shortestPathFrom(from, to, d);
	//Graph node2(node);
	//std::cout << node.nrOfEdges() << "\t" << node.nrOfNodes();
	//Graph& node1 = node;
	//Graph& node2(node);
	//Graph& node3 = node2;
	//node.kruskalMST();
	//node1.kruskalMST();
	//node2.kruskalMST();
	//node3.kruskalMST();
	//node.kruskalMST();
	
}
