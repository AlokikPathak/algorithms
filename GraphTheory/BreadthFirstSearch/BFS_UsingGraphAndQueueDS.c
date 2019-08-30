#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

// Structure for storing queue
struct Queue{
    int front, rear, size;
    unsigned int capacity; //Stores the capacity of Queue
    int *array;
};
// Function to create Queue of a specific capacity
// Initialize the size of Queue as 0
struct Queue* createQueue(unsigned int capacity){
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity-1; //refer enqueue function
    // Create Integer array of size 'capacity'
    queue->array =(int*) malloc((queue->capacity)*sizeof(int));
    return queue;
}
// Queue is full when size becomes equal to capacity
// Overflow
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}
// Queue is empty when size is 0
// Underflow
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

//Function to add item in Queue
//It alters rear and size
void enqueue(struct Queue* queue, int item) {
    if(isFull(queue))
        return;
    //Circular Indexing Technique reduce complexity to O(1);
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
  //  printf("\nEnqueued %d", item);
}

//Function to remove item from queue
//It removes item from queue
void dequeue(struct Queue* queue) {
    if(isEmpty(queue))
        return;
    int item = queue->array[queue->front];
    // Circular indexing , after last index queue->front will be point to Null Index i.e index before 0th Index(empty queue)
    // Reduce the Complexity to O(1)
    queue->front = (queue->front+1)%queue->capacity;
    queue->size--;
}

//Function to get front item of queue
int getFront(struct Queue* queue) {
    // Checking underflow condition
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear item of queue
int getRear(struct Queue* queue) {
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

// Structure for storing Graph
struct Graph{
	int vertexNum;
	int** edges;
};

// Constructs a graph with V vertices and E edges
void createGraph( struct Graph* G, int V) {
	int i,j;
	G->vertexNum = V;
	// Creating V number of Integer Pointers(Array of Integer Pointers) and assign it G->edges
	G->edges = (int**) malloc(V * sizeof(int*));
	for( i=0; i<V; i++) {
		// Create Pointer to array of int of size V and assign it G->edges[i] Pointers
		G->edges[i] = (int*) malloc(V*sizeof(int));
		// Initialize all vertex as independent i.e 0
		// If there is a edge, it will be '1' i.e. G->edges[i][j]=0
		for( j=0; j<V; j++) {
			G->edges[i][j] = 0;
		}
	}
}

// Adds the given edge to the graph
void addEdge( struct Graph* G, int src, int dst) {
	G->edges[src][dst] = 1;
}

// Prints graph in Adjacency list format
void printGraph( struct Graph* G, int V) {
	printf("Graph's Adjacency List Representation: ");
	int i,j;
	for( i=0; i<V; i++) {
		printf("\n%d -> ",i);
		for(  j=0; j<V; j++) {
			// if there is an edge between Vertex i and vertex j, G->edges[i][j] = j
			if( G->edges[i][j]  != 0 ) {
				printf(" ");
				printf("%d", j);
			}
		}
	}
}



void breadthFirstSearch(struct Graph* G, int V, int src ) {
    int i;
    // Visited Array to prevent node to be revisited
    bool visited[V];
    // All vertex are initialized as not visited
    for(i=0; i<V; i++)
        visited[i] = false;
    // Queue to store all unvisited vertex sequentially
    struct Queue* queue = createQueue(V);
    // Mark the current node as visited and enqueue it
    visited[src] = true;
    enqueue(queue, src);
    while(!isEmpty(queue)) {
        // Dequeue a vertex from Queue and print it
        src = getFront(queue);
        dequeue(queue);
        printf("%d ",src);
        // Get all the vertices connected to dequeued vertex
        // If the vertex is not visited then, enqueue & mark it as visited
        for(i=0; i<V; i++) {
            int edgeExists = G->edges[src][i];
            // Checking if there is as edge i.e. edgeExists!=0 and is vertex i.e. 'i' is not visited
            if( edgeExists && visited[i]==false ) {
                visited[i] = true;
                enqueue(queue,i);
            }
        }
    }

}


int main() {

	int V, E, gsrc,i;
	int src, dst, weight;
	struct Graph G;

	printf("Enter no. of vertices in Graph: ");
	scanf("%d",&V);
	printf("\nEnter no. of Edges in Graph: ");
	scanf("%d",&E);

	createGraph(&G, V);

	for( i=0; i<E; i++ ) {
		printf("\nEdge %d Source: ", i+1);
		scanf("%d",&src);
		printf("\nEnter %d destination: ", i+1);
		scanf("%d", &dst);
		addEdge(&G, src, dst);
	}

	printf("\nEnter the source vertex for BFS Traversal: ");
	scanf("%d", &gsrc);

	printGraph(&G, V);
	printf("\nBFS from source: %d\n",gsrc);
	breadthFirstSearch(&G, V, gsrc);

	return 0;

}
