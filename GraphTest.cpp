#include "Graph.cpp"
//#include "Graph.h"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>


int main()
{
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Graph* graph = nullptr;
	std::pair<std::string, std::string> from_to[6];
	from_to[0].first = "s";
	from_to[0].second = "z";
	from_to[1].first = "a";
	from_to[1].second = "e";
	from_to[2].first = "vertice 01";
	from_to[2].second = "vertice 07";
	from_to[3].first = "avort";
	from_to[3].second = "cecil";
	from_to[4].first = "cecil";
	from_to[4].second = "avort";
	from_to[5].first = "a";
	from_to[5].second = "e";

	for (int i = 0; i < 6; i++)
	{
		try
		{
			graph = new Graph("graph0" + std::to_string(i + 1) + ".txt");
			
			std::cout << "graph0" + std::to_string(i + 1) + ".txt"<<std::endl;
			std::cout << "Nodes " << graph->nrOfNodes() << std::endl;
			std::cout << "Edges " << graph->nrOfEdges() << std::endl;

			std::vector<std::pair<int, std::string>> vect;
			std::string from = from_to[i].first;
			std::string to = from_to[i].second;
			graph->shortestPathFrom(from, to, vect);

			if (vect.size() > 0)
			{
				std::cout << "Total kost from " << from << " to " << to << " is " << vect[vect.size() - 1].first << std::endl;

				std::cout << "The path from is :";

				for (unsigned i = 0; i < vect.size() - 1; i++)
				{
					std::cout << vect[i].second << "( " << vect[i].first << " )->";

				}
				std::cout << vect[vect.size() - 1].second << "( " << vect[vect.size() - 1].first << " )" << std::endl;
			}
			else
			{
				std::cout << "No path from " << from << " to " << to << std::endl;
			}
			std::cout << std::endl << std::endl;
		}
		catch (std::string e)
		{
			std::cout << e << std::endl;
		}
		graph->kruskalMST();
		delete graph;
	}

	

	return 0;
}

