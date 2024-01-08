#include "graph/graph.hpp"

int main()
{
    procon::Graph<int> G(5);

    G.add_directed_edge(0, 1);
    G.add_edge(1, 2);

    return 0;
}
