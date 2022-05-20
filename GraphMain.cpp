#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Graph* graph = nullptr;
	std::string filename;
	std::string from;
	std::string to;
	std::vector<std::pair<int, std::string>> vect;
	bool done = false;
	std::string cont;

	std::cout << "Input the filename containing the graph";
	std::getline(std::cin, filename);

	graph = new Graph(filename);

	while (!done)
	{
		std::cout << "Shortest path from? ";
		std::getline(std::cin, from);
		std::cout << "Shortest path to? ";
		std::getline(std::cin, to);

		graph->shortestPathFrom(from, to, vect);

		if (vect.size() > 0)
		{
			std::cout << "Total cost from " << from << " to " << to << " is " << vect[vect.size() - 1].first << std::endl;

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
		vect.clear();
		std::cout << "Do you want to fins out more shortest path in the graph (Y,N)?";
		std::getline(std::cin, cont);
		if (cont == "N")
			done = true;

	}
	return 0;
}