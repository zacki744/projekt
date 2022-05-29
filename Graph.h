#pragma once
#ifndef GRAPH_H 
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility> 


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
	int* parent = nullptr;
	// a matrix that represents the graph
	std::vector<std::vector<int>> matrix;
	//helper funktion
	std::vector<std::string> split_by_delimiter(std::string text);
	void makeMatrix();
	int findIndex(std::string find) const;
	void union1(int i, int j);
	int find(int i);
	int minDistance(int dist[], bool sptSet[]) const;
	void printPath(int parent[], int j, std::vector<int>& returnVect) const;

public:
	Graph(std::string filename); // throws an exception as a string if not possible to open the file
	Graph(const Graph& other);
	Graph(Graph&& other);
	Graph& operator=(const Graph& other);
	Graph& operator=(Graph&& other);
	~Graph();
	int nrOfNodes() const;
	int nrOfEdges() const;
	void shortestPathFrom(std::string& from, std::string& to, std::vector<std::pair<int, std::string>>& shortestPath) const;
	void kruskalMST();
};

#endif 