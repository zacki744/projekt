#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility> 
#include <map>
//hej dino
// s h o l e n v a h ä n d e r 
//std::numeric_limits<int>::max() to infinity and beond
//node class


class Graph
{
private:
	class Node
	{
	public:
		std::string value;
		std::vector<std::pair<int, Node*>> next;
		Node(std::string name)
		{
			this->value = name;
		}
	};
	// variables
	int edges = 0;
	int nodes = 0; 
	// the list of pointers to all the nodes so we dont loos them :(
	std::vector<Node*> NodeList;
	int* parent;
	// a matrix that represents the graph
	std::vector<std::vector<int>> matrix;
	//helper funktion
	std::vector<std::string> split_by_delimiter(std::string text);
	void makeMatrix();
	int findIndex(std::string find);
	void union1(int i, int j);
	int find(int i);

public:
	Graph(std::string filename); // throws an exception as a string if not possible to open the file
	Graph(const Graph& other);
	Graph(Graph&& other);
	//Graph& operator=(const Graph& other) = delete;
	//Graph& operator=(Graph&& other) = delete;
	~Graph();
	int nrOfNodes() const;
	int nrOfEdges() const;
	void shortestPathFrom(std::string& from, std::string& to, std::vector<std::pair<int, std::string>>& shortestPath) const;
	void kruskalMST();
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

inline int Graph::find(int i)
{
	while (this->parent[i] != i)
		i = this->parent[i];
	return i;
}

// Skapar union av i och j. Retunerar
// falsk om i och j är i samma union in same redan
inline void Graph::union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	this->parent[a] = b;
}

inline int Graph::findIndex(std::string find)
{
	for (int i = 0; i < this->NodeList.size(); i++)
		if (this->NodeList[i]->value == find)
			return i;
	return -1;
}

inline void Graph::makeMatrix()
{
	 //make matrix
	this->nodes += 1;
	
	std::vector<int> temp;
	for (int i = 0; i < this->nodes; i++)
		this->matrix.push_back(temp);
	for (int i = 0; i < this->nodes; i++)
		for (int x = 0; x < this->nodes; x++)
			this->matrix[i].push_back(INT_MAX);

	//remake the graph to a matrix
	for (int i = 0; i < this->nodes - 1; i++)
	{
		for (std::pair<int, Node*> y: this->NodeList[i]->next)
		{
			int index = findIndex(y.second->value);
			this->matrix[i][index] = y.first;
		}
	}
	this->nodes--;
}

Graph::Graph(const Graph& other)
{
	this->NodeList = other.NodeList;
	this->edges = other.edges;
	this->matrix = other.matrix;
	this->edges = other.edges;
}

Graph::Graph(Graph&& other)
{
	this->NodeList = other.NodeList;
	this->edges = other.edges;
	this->matrix = other.matrix;
	this->edges = other.edges;
	
}

Graph::Graph(std::string filename) //opens graph-file
{
	std::ifstream File;
	if (std::ifstream File{"../../../Textfiler_med_grafer/" + filename})
	{
		std::string line;
		std::vector<std::string> conections;
		while (getline(File, line))
		{
			if (line.size() != 0)
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
		}
		this->nodes = this->NodeList.size();
		this->parent = new int[this->nodes];
		for (std::string node : conections)
		{
			std::vector<std::string> conections_list = split_by_delimiter(node);
			for (Node* x : this->NodeList)
			{
				if (x->value == conections_list[0])
				{
					Node* next_node = nullptr;
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
	makeMatrix();
	File.close();
}

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

inline void Graph::shortestPathFrom(std::string& from, std::string& to, std::vector<std::pair<int, std::string>>& shortestPath) const//Dijktras BFS
{
	return;
}

inline void Graph::kruskalMST()
{
	int mincost = 0; // lägsta kostnaden av MST.
	int V = this->nodes;

	//initierar uppsättningarna av osammanhängade uppsättningar
	for (int i = 0; i < V; i++)
		this->parent[i] = i;
	//insätter minimum kostnade bågar en efter en
	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (find(i) != find(j) && this->matrix[i][j] < min) {
					min = this->matrix[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		printf("Edge %d:(%d, %d) cost:%d \n",
			edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n minsta kostnaden= %d \n", mincost);
}
