/*
    1. First, it defines a class named Solution that has a member variable adj which is a pointer to a list of pairs. This list of pairs is used to represent the adjacency list of the graph.

    2. The Solution class also has a constructor that takes the number of vertices in the graph as an argument and creates an empty adjacency list of that size.

    3. The addEdge function is used to add an edge to the graph. It takes three arguments: the source vertex, the destination vertex, and the weight of the edge. It adds a pair of the destination vertex and weight to the adjacency list of the source vertex, and vice versa (since the graph is undirected).

    4. The ms_tree function is used to find the minimum spanning tree of the graph using Prim's algorithm. It takes two arguments: the number of vertices in the graph and a reference to a vector of pairs that will store the edges of the minimum spanning tree.

    5. Inside the ms_tree function, a priority queue is initialized with pairs of (weight, node) where weight is the weight of the edge and node is the destination node. This priority queue is used to keep track of the edges with the smallest weight.

    6. A vector vis is created to keep track of which nodes have been visited. It is initialized with all 0s.

    7. The algorithm starts by pushing a pair of (0, 0) into the priority queue, which represents the starting node with a weight of 0.

    8. A variable sum is initialized to 0, which will be used to keep track of the total weight of the minimum spanning tree.

    9. A loop is started that continues until the priority queue is empty. In each iteration, the pair with the smallest weight is popped from the priority queue.

    10. The node and weight of the popped pair are extracted.

    11.If the node has already been visited, the loop continues to the next iteration.

    12. Otherwise, the node is marked as visited, the weight is added to sum, and the edge is added to the minimum spanning tree vector mst (except for the first iteration, which starts from node 0).

    13. A loop is started over the adjacent nodes of the current node. For each adjacent node, if it has not been visited yet, a pair of (edge weight, adjacent node) is pushed into the priority queue.

    14. Once the loop over adjacent nodes is complete, the loop continues to the next iteration until the priority queue is empty.

    15. After the loop finishes, the total weight of the minimum spanning tree is returned.

    16. Finally, the main function creates a graph with 6 vertices and 7 edges, and adds those edges to the graph using the addEdge function.

    17. It then calls the ms_tree function to find the minimum spanning tree of the graph and stores the result in the mst vector.

    18. It then prints out the edges of the minimum spanning tree stored in the mst vector along with their weights.

    19. Finally, it prints out the total weight of the minimum spanning tree.
*/