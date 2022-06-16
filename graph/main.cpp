#include <iostream>
#include <cstring>//aneeq code to do graph creator with djaksra june 26 3033 source for the djsaksra:https://www.educative.io/answers/how-to-implement-dijkstras-algorithm-in-cpp
#include <vector>
#include <climits>
const int INF = INT_MAX;
using namespace std;
//minimum method
int min2(int distance[], bool TF[], int size) {
  int min = INF,ind;
  for(int k = 0; k < size; k++) {
    if(TF[k] == false && distance[k] <= min) {
      min = distance[k];
      ind = k;
    }
  }
  return ind;
}
void Dshort(vector<vector<int>> graph, int startnode) {
  int dist[graph.size()];
  bool TF[graph.size()];//true or false visited
  int x = graph.size();
  for(int l = 0; l < x; l++) {
    dist[l] = INF;
    TF[l] = false;
  }
  dist[startnode] = 0;
  for(int l = 0; l < x; l++) {
    int min = min2(dist, TF, x);
    TF[min] = true;
    for(int l = 0; l < x; l++) {
      if(!TF[l] && dist[min] != INF && dist[min] + graph[min][l] < dist[l] && graph[min][l]) {
	dist[l] = dist[min] + graph[min][l];
      }
    }
    for(int i = 0; i < x; i++) {
      cout<<dist[i] << endl;
    }
    
  }
}
int main() {
  vector<vector<int>> adj;//adjacnly list
  char arr[81];
  bool bruh = false;
  while(bruh == false) {
    cout<<"What do you want to do? ADDVERTEX? ADDEDGE? REMOVEV? REMOVEE? SHORT?" << endl; 
    cin>>arr;//comands
    if(strcmp(arr,"ADDVERTEX")== 0) {
	vector<int> newvect;
        int n;
	cout<<"Enter ur number"<<endl;
	cin>>n;
	newvect.push_back(n);
	//adj.push_back(newvect);
	for(int l = 0; l < adj.size(); l++) {
	  newvect.push_back(0);
	}
	for(int l = 0; l < adj.size(); l++) {
	  vector<int> newv = adj[l];
	  newv.push_back(0);
	  adj[l] = newv;
	}
	adj.push_back(newvect);
    }//inputs
    else if(strcmp(arr,"ADDEDGE")==0) {
      cout<<"Enter first node" << endl;
      int n;
      cin>>n;
      cout<<"Enter second Node" << endl;
      int b;
      cin>>b;
      cout<<"Enter weighted distance" << endl;
      int c;
      cin>>c;
      int placehold = 0;
      int k2 = 0;
      for(int k = 0; k <adj.size(); k++) {
	vector<int> adj2 = adj[k];
	if(adj2[0] == b) {
	  placehold = k;
	  k2 = k;
	}
      }
      // cout<<k2 << endl;
      for(int g = 0; g < adj.size(); g++) {
	vector<int> bru = adj[g];
	if(bru.size() == 1) {
	  for(int w = 0; w < adj.size(); w++) {
	    bru.push_back(0);
	  }
	}
	if(bru[0] == n) {
	  for(int z= 1; z < bru.size(); z++) {
	    if(z-1 == k2) {
	      cout<<k2 << endl;
	      bru[z] = c;
	      break;
	    }
	  }
	  adj[g] = bru;
	}
      }
    }
    else if(strcmp(arr,"PRINT") == 0) {
      //      cout<<"Print" << endl;
      for(int i = 0; i < adj.size(); i++) {
	vector<int> newtemp = adj[i];
	for(int j = 0; j < newtemp.size(); j++) {
	  cout<< newtemp[j] << " ";
	}
	cout<<endl;
      }
    }//removing vertice
    else if(strcmp(arr,"REMOVEV") == 0) {
      int k2 = 0;
      cout<<"WHAT do you want to remove?" << endl;
      int rem;
      cin>>rem;
      for(int i = 0; i < adj.size(); i++) {
	vector<int> lis = adj[i];
	if(lis[0] == rem) {
	  k2 = i;
	  adj.erase(adj.begin() + k2);
	}
      }
      for(int i = 0; i < adj.size(); i++) {
	vector<int> lis = adj[i];
	lis.erase(lis.begin() + k2 +1);
	adj[i] = lis;
      }
      
    }//remove function
    else if(strcmp(arr,"REMOVEE") == 0) {
      cout<<"ENter first node"<<endl;
      int n;
      cin>>n;
      cout<<"ENTER SECOND NODE"<<endl;
      int n2;
      cin>>n2;
      for(int i = 0; i < adj.size(); i++) {
	vector<int> br = adj[i];
	if(br[0] == n) {
	  for(int j = 0; j < br.size(); j++) {
	    if(j+1 == n2) {
	      br[j] = 0;
	    }
	  }
	}
	adj[i] = br;
      }
    }//djaskra
    else if(strcmp(arr,"SHORT") == 0) {
      int length = adj.size();
      cout<<"Enter first node" << endl;
      int n;
      cin>>n;
      cout<<"Enter second node"<<endl;
      int n2;
      cin>>n2;
      Dshort(adj, n);
      /*//converting to an array
      int arr[20][20];
      for(int i = 0; i < adj.size(); i++) {
	vector<int> br = adj[i];
	for(int k = 1; k < adj.size(); k++) {
	  arr[i][k] = br[k];
	  cout<<arr[i][k] << " " ;
	}
	cout<< endl;
      }
      //      Dshort(adj.size(), adj.size(), arr,0);
      */
    }
    
  }
}
