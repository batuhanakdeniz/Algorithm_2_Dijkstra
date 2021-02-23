/*
Muhammed Batuhan Akdeniz
150150126
*/
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

#define INF 999


class Graph{
protected:
	int number_nodes;
	int** graph;	//Adjecency matrix
	int** temp_graph;	//temporary matrix
	list<int> path;		//For return process
	list<int> times;	//return process
public:	
	Graph(int size){
		number_nodes = size;
		graph = new int*[size];
		temp_graph = new int*[size];
		
		for(int i=0;i<size;i++)
			temp_graph[i] = new int[size],graph[i] = new int[size];		
		
		for(int i=0;i<size;i++){
			for(int k=0;k<size;k++){
				graph[i][k] = INF;
				temp_graph[i][k] = INF;			
				if(i==k)	temp_graph[i][k] = 0,graph[i][k] = 0;	//INF value is given for marrix and identity part of matrix is given as 0
			}
		}
	}
	void add_edge(int source,int dest, int weight){		//adding edges to graph and temporary graph
		graph[source][dest] = weight;
		temp_graph[source][dest] = weight;
	}	
	bool is_directed(int source, int destination){		//return true if source is directed to destination
		if(graph[source][destination] < INF && graph[source][destination] != 0)
			return true;
		else
			return false;		
	}	
	list<int> times_arrange(list<int> behind_, list <int> times_t){	//For +30 waiting time and remember last time
		list <int> temp;
		int last = behind_.back();
		for(list<int>::iterator iter = times_t.begin(); iter != times_t.end(); iter++)
	   		temp.push_back(*iter + last + 30);
	   	return temp;
	}
	void print_node_time(list<int>,list<int>);
	void Dijkstra(int ,int ,int ,int );
	list<int> find_path(int ,int);
	int min_Distance(int dist[], bool sptSet[]);
	void push_Path(int parent[], int j);
	int test_intersection(list<int> path_J,list<int> time_J,list<int> path_L,list<int> time_L);
	void delete_node(int);
	void back_delete_node(int);
};



void Graph::back_delete_node(int node){		//For go back to values before deleting
	for(int i=0;i<number_nodes;i++){
		for(int k=0;k<number_nodes;k++){
			if(i==node || k==node)
				graph[i][k]=temp_graph[i][k];					
		}
	}	
}

void Graph::print_node_time(list<int> path,list<int> time){	//Printing Node: Time:
	list<int>::iterator iter_path = path.begin();
	list<int>::iterator iter_time = time.begin();
		while(iter_path != path.end() && iter_time != time.end())
		{
			cout << "Node: " << *iter_path << " Time: " << *iter_time <<endl;
			iter_time++;
			iter_path++;
		}
	
}

void Graph::delete_node(int node){	//Deleting Node
	for(int i=0;i<number_nodes;i++){
		for(int k=0;k<number_nodes;k++){
			if(i==node || k==node)
				graph[i][k]=INF;					
		}
	}
}






void Graph::push_Path(int parent[], int j) // This gives path 
{ 
    
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
  	
    push_Path(parent, parent[j]); 
  	path.push_back(j);
}

int Graph::min_Distance(int dist[], bool sptSet[]) //Min distance to find nearest node, return nearest node
{ 
    // Initialize min value 
    int min = INF, min_index; 
  
    for (int v = 0; v < number_nodes; v++) 
        if ( sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
}

 
list<int> Graph::find_path(int source,int dest){//return value is path as list this part is mentioned in the report
	int distance[number_nodes];
	bool spt_set[number_nodes];
	int parent[number_nodes];

	
	
	for(int i=0;i<number_nodes;i++)
		parent[i] = -1,distance[i]=INF,spt_set[i] = false;
	distance[source] = 0;

		
	for(int i=0;i<number_nodes-1;i++){
		int u = min_Distance(distance,spt_set);
		spt_set[u] = true;
		bool neighboor;	
		for(int k=0;k<number_nodes;k++){
			neighboor = is_directed(u,k);
			if(!spt_set[k] && neighboor && graph[u][k] != 0 && distance[u] + graph[u][k] < distance[k]){
				parent[k] = u;
				distance[k] = distance [u] + graph[u][k];
			}
		}
	}

	
	push_Path(parent,dest);

	path.push_front(source);

	for(list<int>::iterator iter = path.begin(); iter != path.end(); iter++){
	   times.push_back(distance[*iter]);
	}	
	return path;
}


int Graph::test_intersection(list<int> path_J,list<int> time_J,list<int> path_L,list<int> time_L){// Testing is there any intersection
	list<int>::iterator iter_path_J = path_J.begin();
	list<int>::iterator iter_path_L = path_L.begin();
	
	for(list<int>::iterator iter_J = time_J.begin(); iter_J!=time_J.end();iter_J++){
		for(list<int>::iterator iter_L = time_L.begin(); iter_L!=time_L.end();iter_L++){
			if(*iter_J == *iter_L && *iter_path_J == *iter_path_L) return *iter_path_J;
			iter_path_L++;
			if(iter_path_L == path_L.end()){
				iter_path_L = path_L.begin();
				break;
			}

		}
		iter_path_J++;
		if(iter_path_J==path_J.end())	break;	
	}
	return 0;
}


void Graph::Dijkstra(int JH, int JD,int LH,int LD){
	//****************
	//Hotel to Destination
	list<int> path_J = find_path(JH,JD);
	list<int> time_J = times;            
	path.clear();
	times.clear();
	list<int> path_L = find_path(LH,LD);
	list<int> time_L = times;           
	path.clear();
	times.clear();
			
	int flag = test_intersection(path_J ,time_J ,path_L ,time_L );

	//**********Deleting Node Process
	if(flag!=0){
		delete_node(flag);
		path_J = find_path(JH,JD);
		if(path_J.back() != JD){
			path.clear();
			times.clear(); 						
			back_delete_node(flag);
			path_J = find_path(JH,JD);
			time_J = times;
			path.clear();
			times.clear(); 
			delete_node(flag);
			path_L = find_path(LH,LD);
			time_L = times;           
			path.clear();
			times.clear();					
		}
		else{
			time_J = times;  			
			path.clear();
			times.clear();
			back_delete_node(flag);
			path_L = find_path(LH,LD);
			time_L = times;           
			path.clear();
			times.clear();				
		}
 }
		
	
	
	//*************************************************************
	//Destination to Hotel
	list<int> ret_path_J = find_path(JD,JH);
	list<int> ret_time_J = times_arrange(time_J,times);
	path.clear();
	times.clear();

	list<int> ret_path_L = find_path(LD,LH);
	list<int> ret_time_L = times_arrange(time_L,times);
	path.clear();
	times.clear();
	
	flag = test_intersection(ret_path_J ,ret_time_J ,ret_path_L ,ret_time_L );


	//**********Deleting Node Process
	if(flag!=0){

		delete_node(flag);					
		ret_path_J = find_path(JD,JH);
		if(ret_path_J.back()!=JH){
			path.clear();					//PATH is a list to return from class
			back_delete_node(flag);			
			ret_path_J = find_path(JD,JH);
			ret_time_J = times_arrange(time_J,times);
			path.clear();
			times.clear(); 
			delete_node(flag);
			ret_path_L = find_path(LD,LH);
			ret_time_L = times_arrange(time_L,times);          
			path.clear();
			times.clear();				
		}
		else{
			ret_time_J = times_arrange(time_J,times);
			path.clear();
			times.clear();
			back_delete_node(flag);
			ret_path_L = find_path(LD,LH);
			ret_time_L = times_arrange(time_L,times);           
			path.clear();
			times.clear();			
		}
	}	

//************************************
//Printing No Solution
		if(ret_path_J.back() != JH || ret_path_L.back() != LH){
			cout << "No solution!" <<endl;
			return;	
		}
//Printing J	
	
		cout << "Joseph's Path, duration: "<< ret_time_J.back() <<endl;
		print_node_time(path_J,time_J);
			cout << "-- RETURN --" <<endl;
		print_node_time(ret_path_J,ret_time_J);
//************************************
//Printing L
		cout << "\nLucy's Path, duration: " << ret_time_L.back() <<endl;	
		print_node_time(path_L,time_L);
			cout << "-- RETURN --" <<endl;
		print_node_time(ret_path_L,ret_time_L);
//*************************************				
}



int main(int argc, char *argv[]){
	ifstream MyReadFile(argv[1]);
	int size;
	MyReadFile >> size;
	Graph graph(size);
	int JH, JD, LH, LD;
	MyReadFile >> JH >> JD>> LH >> LD;
	int Node1, Node2, weight;
	while(!MyReadFile.eof()){
		MyReadFile >> Node1 >> Node2 >> weight;
		graph.add_edge(Node1,Node2,weight);
	}
	graph.Dijkstra(JH,JD,LH,LD);
	MyReadFile.close();
	
	return 0;
}
