#pragma once
#include <list>
#include <vector>
#include <queue>

class graph
{
	
private:
	struct node
	{
		int data;
		bool visited;
		std::list<node*> adj_table;
	};

public:

	graph();
	~graph();

    std::vector<node*> map_nodes;
	void BFS(node *start_node);
	void DFS(node *start_node);

};

void graph::BFS(node *start)
{
	if (!start)
		return;
	std::queue<node*> queue;
	queue.push(start);

	while (!queue.empty())
	{
		node *curr = queue.front();
		queue.pop();
		if (curr->visited == false)
		{
			//visit it
			curr->visited = true;
			for (auto it = curr->adj_table.begin(); it != curr->adj_table.end(); ++it)
			{
				if ((*it)->visited == false)
				    queue.push(*it);
			}
		}
	}
}


void graph::DFS(node *curr_node)
{
	if(!curr_node)
		return;

	if(curr_node->visited == false)
	{
		//visit it
		curr_node->visited = true;
		for (auto it = curr_node->adj_table.begin(); it != curr_node->adj_table.end(); ++it)
		{
			if ((*it)->visited == false)
			{
				graph::DFS(*it);
			}
		}
	}
}