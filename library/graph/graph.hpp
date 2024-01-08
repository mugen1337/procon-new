#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>

namespace procon
{

template <typename T = int>
struct Edge
{
	int from;
	int to;
	T cost;
	int idx;

	Edge() = default;
	Edge(int _from, int _to, T _cost = 1, int _idx = -1)
	: from(_from), to(_to), cost(_cost), idx(_idx)
	{

	}

	operator int() const
	{
		return to;
	}
};

template <typename T = int>
struct Graph
{
	std::vector<std::vector<Edge<T>>> G;
	int nEdges;

	Graph() = default;

	explicit Graph(int nVertices)
	: G(nVertices), nEdges(0)
	{

	}

	int size()
	{
		return static_cast<int>(G.size());
	}

	inline const std::vector<Edge<T>> &operator[](int k) const 
	{
		return G[k];
	}

	inline std::vector<Edge<T>> &operator[](int k)
	{
		return G[k];
	}

	void add_directed_edge(int from, int to, T cost = 1)
	{
		G[from].emplace_back(from, to, cost, nEdges++);
	}

	void add_edge(int from, int to, T cost = 1)
	{
		G[from].emplace_back(from, to, cost, nEdges);
		G[to].emplace_back(to, from, cost, nEdges++);
	}
};

}

#endif // !__GRAPH_HPP__
