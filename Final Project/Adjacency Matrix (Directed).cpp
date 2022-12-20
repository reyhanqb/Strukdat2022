#include<bits/stdc++.h>

using namespace std;

class Graph {
    private:
        int v;
        string nama[100];
        vector<vector<int>> adj;
        vector<int> dfsResult;
        vector<int> dijkstraRes;
        int dfsWeight;

    public:
        Graph(int v) {
            this->v = v;
            vector<int> l (v+1, -1);
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }
        void nameVertex(int i, string nama){
	    this->nama[i]=nama;
	    vector<int>arr;
	    arr.push_back(i);
	    sort(arr.begin(), arr.end());
	    }

        void addEdge(int u, int v, int w){
            adj[u][v] = w;
        }
        
        void BFS(int start, int end){
            cout << endl;
            cout << "=== BFS ===" << endl;
            vector<int> visit (v+1, 0);
            vector<int> dist (v+1, INT_MAX);
            vector<int> domain (v+1, 0);
            queue<int> q;

            dist[start] = 0;
            q.push(start);
            visit[start] = true;

            while (!q.empty())
            {
                int curr = q.front();
                for (int it = 1; it <= v; it++)
                {
                        if(adj[curr][it] != -1 && adj[curr][it] + dist[curr] < dist[it]){
                            dist[it] = adj[curr][it] + dist[curr];
                            domain[it] = curr;
                            q.push(it);
                        }
                }
                q.pop();
            }
            vector<int> result;
            int i = end;
            while(true){
                result.push_back(i);
                if(i == start) break;
                i = domain[i];
            }

            for (int i = result.size()-1; i >= 0; i--)
            {
                cout << nama[result[i]] <<"(V" <<  result[i] << ")"<< ", ";
            }
            
            cout << endl << "Weight = " << dist[end] << endl;
            
        }
        
        void DFS(int start, int end){
            cout << endl;
            cout << "=== DFS === "<< endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );
            
            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << nama[dfsResult[i]] <<"(V" <<  dfsResult[i] << ")"<< ", ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
            }
            visited[start] = true;
            path.push_back(start);
            bool flag = false;
            for ( int it = 1; it <= v; it++)
            {
                if(!visited[it] && adj[start][it] != -1){
                    int wtemp = currWeight;
                    wtemp += adj[start][it];
                    flag = true;
                    solveDFS(it, end, path, visited, wtemp);
                }
            }
        }
         void printMatrix(){
        	cout << "=== Adjacency Matrix ===" << endl<<endl;
            for (int i = 1; i <= v; i++)
            {
                for ( int j = 1; j <= v; j++)
                {
                	
                    if(adj[i][j] == -1)cout << ".  ";
                    else if (adj[i][j] < 10) cout << adj[i][j] << "  ";
                    else cout << adj[i][j] << " ";
                    
                }
                cout << endl;
            }
            cout << endl;
        }
};

int main(){
    Graph g(21);
    g.nameVertex(0, "Rumah");
    g.nameVertex(1, "Kebab Atung"); 		g.nameVertex(12, "Servis AC");
    g.nameVertex(2, "Masjid Arrohman");	    g.nameVertex(13, "Bengkel May");
    g.nameVertex(3, "Alfamart");  			g.nameVertex(14, "Indomaret");
    g.nameVertex(4, "Apotek"); 			    g.nameVertex(15, "MI Alfalah");
    g.nameVertex(5, "Elud Bakery"); 		g.nameVertex(16, "Warung Madura");
    g.nameVertex(6, "Masjid At Taubah"); 	g.nameVertex(17, "Masjid An Nur");
    g.nameVertex(7, "Lazatto"); 		    g.nameVertex(18, "KB Kiddie Cloud");
    g.nameVertex(8, "Pangkas Rambut"); 	    g.nameVertex(19, "Musholla Baiturrasyidin");
    g.nameVertex(9, "Puskesmas"); 			g.nameVertex(20, "Toko Frozen Food SS");
    g.nameVertex(10, "Bimbel CF"); 			g.nameVertex(11, "Warung Mpok");			 	

    g.addEdge(0, 1, 1);			g.addEdge(13, 15, 7);
    g.addEdge(1, 2, 3);			g.addEdge(14, 15, 8);
    g.addEdge(2, 3, 4);			g.addEdge(14, 16, 9);
    g.addEdge(1, 7, 3);			g.addEdge(16, 17, 11);
    g.addEdge(3, 4, 3);			g.addEdge(15, 17, 7);
    g.addEdge(4, 5, 2);			g.addEdge(18, 19, 9);
    g.addEdge(5, 6, 5);		    g.addEdge(19, 20, 11);
    g.addEdge(2, 7, 5);		
    g.addEdge(7, 8, 6);			
    g.addEdge(8, 9, 10);		
    g.addEdge(9, 10, 5);		
    g.addEdge(7, 10, 9);		
    g.addEdge(0, 11, 2);		
    g.addEdge(0, 12, 6);		
    g.addEdge(12, 13, 8);		
    g.addEdge(14, 13, 8);
  
    g.printMatrix();
    int start, end;
    cout << "Start: ";
    cin >> start;
    cout << "End: ";
    cin >> end;
    g.BFS(start, end);
    g.DFS(start, end);
    return 0;
}
