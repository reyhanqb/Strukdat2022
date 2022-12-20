#include <bits/stdc++.h>
#include <list>
#include <queue>
#include <string.h>

using namespace std;

typedef pair <int, int> int_pair;

class Graph{
	int V;
	list<pair<int, int>> adj[21];
	string nama[21] = {"Rumah", "Kebab Atung", "Masjid Arrohman", "Alfamart", 
  "Apotek", "Elud Bakery", "Masjid At Taubah", "Lazatto", "Pangkas Rambut",
  "Puskesmas", "Bimbel CF", "Warung Mpok", "Servis AC", "Bengkel May", "Indomaret",
  "MI Al-Falah", "Warung Madura", "Masjid An Nur", "KB Kiddie Cloud", 
  "Musholla Baiturrasyidin", "Toko Frozen Food SS"
  };
	public:
	Graph(int v){
	    V = v;
	}
	
 void printNames(){
    for (int i = 0; i < 21; i++)
    { 
      cout << i << " : " << nama[i] << endl;
    }
  }
	
	void addEdge(int u, int v, int w){
	    adj[u].push_back(make_pair(v, w));
	}
	
	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	        for(auto const &j: adj[i]){
	            cout << i << " " << j.first << " " << j.second  << endl;
	        }
	    }
	}
	
	void dijkstraAlgo(int start){
		priority_queue<int_pair, vector<int_pair>, greater<int_pair> >
        q;
		q.push(make_pair(1, start));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = INT_MAX;
		}
		dist[start] = 1;
		
		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			
			list<pair<int,int>> :: iterator i;
			for(i = adj[u].begin(); i != adj[u].end(); i++){
				int v = (*i).first;
				int w = (*i).second;
				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		cout << "Vertex Distance from Source\n";
    for (int i = 1; i <= V; ++i)
        cout <<  i << " " << dist[i] << " " << endl;
	}
	
};
int main(){
	Graph g(20);
	
	g.printNames();
	
	cout << endl;
	
    g.addEdge(0, 1, 1);			g.addEdge(13, 15, 7);
    g.addEdge(1, 2, 3);			g.addEdge(14, 15, 8);
    g.addEdge(2, 3, 4);			g.addEdge(14, 16, 9);
    g.addEdge(1, 7, 3);			g.addEdge(16, 17, 11);
    g.addEdge(3, 4, 3);			g.addEdge(15, 17, 7);
    g.addEdge(4, 5, 2);			g.addEdge(18, 19, 9);
    g.addEdge(5, 6, 5);		        g.addEdge(19, 20, 11);
    g.addEdge(2, 7, 5);		        g.addEdge(12, 18, 4);
    g.addEdge(7, 8, 6);			
    g.addEdge(8, 9, 10);		
    g.addEdge(9, 10, 5);		
    g.addEdge(7, 10, 9);		
    g.addEdge(0, 11, 2);		
    g.addEdge(0, 12, 6);		
    g.addEdge(12, 13, 8);		
    g.addEdge(14, 13, 8);
  
	
	cout << "Start : ";
	int start;
	cin >> start;
    g.dijkstraAlgo(start);
}
