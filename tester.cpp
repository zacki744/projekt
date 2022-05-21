#include "Graph.h"

int main()
{
	Graph node("../../../Textfiler_med_grafer/graph03.txt");
	std::cout << node.nrOfEdges() << "\t" << node.nrOfNodes();
}
