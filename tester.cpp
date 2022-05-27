#include "Graph.h"

int main()
{
	Graph node("graph01.txt");
	//std::string from = "cecil";
	//std::string to = "avort";
	//std::pair<int, std::string > temp;
	//temp.first = 1;
	//temp.second = from;
	//std::vector<std::pair<int, std::string>> d;
	/*d.push_back(temp);
	node.shortestPathFrom(from, to, d);*/
	//Graph node2(node);
	//std::cout << node.nrOfEdges() << "\t" << node.nrOfNodes();
	node.kruskalMST();
}
