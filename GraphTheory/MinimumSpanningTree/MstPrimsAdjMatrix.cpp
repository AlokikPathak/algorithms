#include<bits/stdc++.h>
using namespace std;

const int V=9;

/**
 * A function to find vertex with minimum key value
 * from a key[]
 *
 */
int minKey(int key[], bool mstSet[], int V) {
	
	int min = INT_MAX, min_index;
	
	for( int i=0; i<V; i++ ){
		
		if( mstSet[i] == false && key[i]<min ){
			
			min = key[i]; min_index=i;
		}
	}
	
	return min_index;

}


/**
 * A function to print the MST stored in parent[] 
 */
void printMST(int parent[], int graph[V][V]){
	cout<<"Edge\tWeight\n";
	
	int totalWeight = 0;
	
	for(int i=1; i<V; i++) {

		/**
		  * 1st: Printing the Parent Vertex of starting from 2nd Vertex, since 1st Vertex has no Parent i.e. -1 
		  * 2nd: The Current vertex
		  * 3rd: Weight of the Edge
		  */
		cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
		
		// Adding all the Edge Weights of MST	
		totalWeight+=graph[i][parent[i]];
	}
	

	cout<<"\nTotal Weight of MST: "<<totalWeight<<endl;
}

/**
 * Function to construct and print MST 
 * a graph represented using Adjacency Matrix 
 */
void primsMST(int graph[V][V]){
	
	// Array to store constructed MST
	int parent[V]; 
	
	// Array to store vertex's key value
	int key[V];
	
	// Array to store the wheather a vertex is in mstSet or Not
	bool mstSet[V];
	
	// Initialize all key as Infinite
	for(int i=0; i<V; i++){
		key[i]=INT_MAX;  mstSet[i]=false;
	}
	
	// Always include 1st vertex in mstSet[]
	key[0]=0; 

	
	parent[0]=-1; //Root of MST
	
	// The MST will have V vertices
	for(int i=0; i<V-1; i++){
		
		// Pick the minimum key vertex from the set of vertices not in mstSet
		int u = minKey(key, mstSet, V);
		
		// Add the picked vertex
		mstSet[u] = true;
		
		// Update the key value of all adjacent vertices of picked vertex not present in mstSet
		for(int v=0; v< V; v++){
			
			if( graph[u][v] && mstSet[v]==false && graph[u][v] < key[v] ){
				
				/***/
				parent[v]=u, key[v]= graph[u][v];
			}
		}
	}
	
	printMST(parent, graph);
	
}

int main(){
	
	
	
	int graph [V][V]= {

		{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0 , 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 14, 10, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0}
		
		
	};
	
	primsMST(graph);
	
	return 0;
	
	
	
}
