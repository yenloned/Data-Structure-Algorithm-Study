# Graph
## What is Graph?
Graph is a **non-linear** data structure that contains nodes/vertices and edges. One of the example is [Tree](https://github.com/yenloned/Data-Structure-Algorithm-Study/tree/main/Tree)


## Mathematical Representation
A graph **G** is an ordered pair of a set **V of vertices** and a set **E of edges**.

G = ( V , E ) [order matters here]

## Computer Science Representation
### Vertex List
It is a list used to store every nodes/vertices in the graph.<br>
For Example, Array = [A,B,C,D,E,F,G,H]

### Adjacency Matrix
We can have a 2D matrix or array of size **V*V** where V is the number of nodes/vertices.

In the array, we will have the index of 0 to V-1.<br>
By expanding the array, there will be all combinations of every nodes/vertices.<br>
#### **Unweighted Graph**
  - The value of that combination will be 1 (or True) if it existed. For example, **Array[0][1] will be 1** if { A, B } is connected. 
  - The value can be anything but 0. However, it should be the same for other existed combination since it is a Unweighted Graph.
#### **Weighted Graph**
- The value of that combination will be the weight value (priority) if it existed.
- For non-existed combination, a very large (INT_MAX) or any unexpected value can be used.
#### **Time Complexity**
- For finding adjacent nodes/vertices:
  - It will first scanning the Vertex List to find the index of the node/vertex with **O(v)** time.
  - Then, it will scan each combination of that index in the matrix we create, which also take **O(v)** time.
  - Therefore, finding adjacent nodes/vertices in Adjacency Matrix will take **Time Complexity of O(v)**.
- In some cases, we could perform this operation in **Time Complexity of O(1)** if we know the index of both adjacent nodes/vertices.
    - For Example: Finding if two nodes/vertices are connected. (if both the index are given)
    - However, the **Time Complexity of O(1)** can still be achieved if only the node/vertex names are given, by taking a extra **Space Complexity of O(v)** for [Hash Table](https://github.com/yenloned/Data-Structure-Algorithm-Study/tree/main/Array%20%26%20Hashing).

#### **Space Complexity**
- For storing the Adjacency Matrix, it would take **Space Complexity of O(v^2)** since we stored every combinations in a 2D Array.

### Adjacency List
In above method, Adjacency Matrix, would store a lot of wasted space of non-existed combination.<br>
Adjacency List would fix this issue by only storing the existed combination by **Pointers, Array and Linked List**.

We will create **the size of v** of Array that contains Linked List.<br>
In each Linked List, there will store the index of according combination. For Example:
```
struct Node {
    int data;
    int weight;
    struct Node* next;
}
struct Node *A[8]

A[0]: [1, next] -> [2, next] -> [3, next]
A[1]: [0, next] -> [4, next] -> [5, next]
.
.
.
A[7]: [3, next] -> [6, next] -> [4, next] -> [5, next]
```

#### **Time Complexity**
- For finding adjacent nodes/vertices:
  - It will take **Time Complexity of O(v)** in worst case since we must scan one of the index in Array.
  - However, it is only the worst case. If implementing in a real-world example, Adjacency List will have much faster searching time compare with Adjacency Matrix in average.
- If we know the index of both adjacent nodes/vertices
  - Same as finding adjacent nodes/vertices

#### **Space Complexity**
- Since Adjacency List will store only the existed combination (number of edges), it will only take **Space Complexity of O(e)**.
- In real world graph, most graph will be sparse which the number of edges is smaller than v^2.

#### Why we don't use Array instead of Linked List?
- Because we would take a extra time and memory if we want to create a new path. (recreate a static size memory).

## Direction and number of edges
For Graph, it is **most likely** either all directed edges or all undirected edges.<br>
### Directed Graph / Digraph
* There will be direction between two nodes/vertices. For example, Linked List ( A-> B or represented as (A,B))
#### Maximum Number of Edges (Simple Graph)
* Let n be the numbers of nodes/vertices, the maximum number of edges will be **n(n-1)**

### Undirected Graph
* There will be no pointing / direction between two nodes/vertices. For example, A - B or represented as {A,B}

#### Maximum Number of Edges (Simple Graph)
* Let n be the numbers of nodes/vertices, the maximum number of edges will be **(n(n-1))/2**

## Example of Direction Graph usage
### Direct Graph / Digraph
World Wide Web (www) will be one of the example using Direct Graph.<br>
* PageA will contain the URL of PageB, and PageB may or may not contain the URL of PageA.
  * Therefore, Web-Crawling can use of the concept of Graph Traversal, act of visiting all nodes/vertices in a graph.

### Undirected Graph
Social Network will be one of the example using Undirected Graph.<br>
* If A is the friend of B, B will also be the friend of A. <br>

## Weighted and Unweighted Edge
Under some cases, edges will be assigned with Weight, which represent the priority to connection with.
* For example, a geographic graph that each edges indicate the distance length.

In other words, a Unweighted Graph is basically a Weight Graph with all edges in equal weight.

## Edge Properties
### Self Loop
Sometimes, a node/vertex might have the connection of itself.
- For Example, a web page that contains the URL of itself.
### MultiEdge
Sometimes, there will be multiple connection between two nodes/vertices.
- For Example, the multiple flights between two cities.
### Simple Graph
A graph with no self loop and multiedges will be called Simple Graph.
### Dense
A graph with many edges (No strict definition)
### Sparse
A graph with few edges (No strict definition)
### Path / Walk
A sequence of nodes/vertices where each adjacent pair is connected by an edge.<br>
Usually, "Path" will be called as "Simple Path"
- For Example, { A, B, C, D, E, D }
### Simple Path
A Path / Walk that have no repeated nodes/vertices.
- For Example { A, B, C, D }
### Trail
A Path / Walk that have repeated nodes/vertices.
- For Example, { A, B, C, D, C, B }
### Closed Walk / Cycle
A Path / Walk that starts and ends at the same node/vertex.
- For Example, { A, B, C, D, C, B, A }
### Simple Cycle
A Closed Walk / Cycle with no repeated nodes/vertices other than start and end.
- For Example, { A, B, C, D, A }
### Acyclic Graph
A graph with no cycle.
- For Example, a tree with undirected edges / a directed acyclic graph (DAG)
### Strongly Connected
A Directed Graph which contains a path from any vertex to any other vertices.
- If it is Undirected Graph, it is simply called "Connected"
### Weakly Connected
A Directed Graph which contains no path from any vertex to any other vertices.
- If it is Undirected Graph, it is simply called "Not Connected"



