#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility> 
//hej dino
// s h o l e n v a h ä n d e r 
//std::numeric_limits<int>::max() to infinity and beond


class Graph
{
private:

	// variables
	int edges = 0;
	int nodes = 0; 

	//node class
	class Node
	{
	public:
		std::string value;
		std::vector<std::pair<int, Node*>> next;
		std::string color;
		Node(std::string name)
		{
			this->value = name;
		}
	};

	// the list of pointers to all the nodes so we dont loos them :(
	std::vector<Node*> NodeList;

	//helper funktion
	std::vector<std::string> split_by_delimiter(std::string text);
	//{
	//	std::vector<std::string> words{};
	//	size_t pos = 0;
	//	while ((pos = text.find('#')) != std::string::npos) {
	//		words.push_back(text.substr(0, pos));
	//		text.erase(0, pos + 1);
	//	}
	//	words.push_back(text);
	//	return words;
	//}

public:
	Graph(std::string filename); // throws an exception as a string if not possible to open the file
	//Graph(const Graph& other) = delete;
	//Graph(Graph&& other) = delete;
	//Graph& operator=(const Graph& other) = delete;
	//Graph& operator=(Graph&& other) = delete;
	~Graph();
	int nrOfNodes() const;
	int nrOfEdges() const;
	void shortestPathFrom(std::string& from, std::string& to, std::vector<std::pair<int, std::string>>& shortestPath) const;
};


inline std::vector<std::string> Graph::split_by_delimiter(std::string text)
{
	std::vector<std::string> words{};
	size_t pos = 0;
	while ((pos = text.find('#')) != std::string::npos) {
		words.push_back(text.substr(0, pos));
		text.erase(0, pos + 1);
	}
	words.push_back(text);
	return words;
}

Graph::Graph(std::string filename) //opens graph-file
{
	std::ifstream File;
	if (std::ifstream File{ filename })
	{
		std::string line;
		std::vector<std::string> conections;
		bool next = false;
		while (File >> line)
		{
			if (line.find('#') != std::string::npos)
			{
				conections.push_back(line);
			}
			else
			{
				this->NodeList.push_back(new Node(line));
			}
		}
		this->nodes = this->NodeList.size();
		for (std::string node : conections)
		{
			std::vector<std::string> conections_list = split_by_delimiter(node);
			for (Node* x : this->NodeList)
			{
				if (x->value == conections_list[0])
				{
					Node* next_node;
					for (Node* x : this->NodeList)
					{
						if (x->value == conections_list[1])
						{
							next_node = x;
							break;
						}
					}
					std::pair<int, Node*> temp;
					temp.first = std::stoi(conections_list[2]);
					temp.second = next_node;
					x->next.push_back(temp);
					this->edges++;
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "fili cant open!" << std::endl;
	}
	for(Node * x: this->NodeList)
	{
		std::cout << x->value << std::endl;
	}

	File.close();
}

//Graph::Graph(const Graph& other)
//{
//
//}
//Graph::Graph(Graph&& other)
//{
//
//}
//
Graph::~Graph()
{
	for (Node* x : this->NodeList)
	{
		delete x;
	}
	//radera wallah
}

inline int Graph::nrOfNodes() const
{
	return this->nodes;
}

inline int Graph::nrOfEdges() const
{
	return this->edges;
}

inline void Graph::shortestPathFrom(std::string& from, std::string& to, std::vector<std::pair<int, std::string>>& shortestPath) const
{
	//bah använda snabbaste vägen bruh bete dig pågud
}
