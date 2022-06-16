#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main() {
  vector<vector<int>> adj;
  char arr[81];
  bool bruh = false;
  while(bruh == false) {
    cout<<"What do you want to do? ADDVERTEX? ADDEDGE? REMOVEV? REMOVEE? SHORT?" << endl; 
    cin>>arr;
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
      }
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
	if(bru[0] == n) {
	  for(int z= 0; z < bru.size(); z++) {
	    if(z == k2) {
	      if(bru[z] == 0) {
		bru[z] = c;
	      }
	      else 
		bru.push_back(c);
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
    }
    else if(strcmp(arr,"REMOVEV") == 0) {
      int k2 = 0;
      cout<<"WHAT do you want to remove?" << endl;
      int rem;
      cin>>rem;
      for(int k = 0; k < adj.size(); k++) {
	vector<int> adj2 = adj[k];
	if(adj2[0] == rem) {
	  k2 = k;
	}
      }
      //      cout<< k2<<endl;
      for(int l = 0; l < adj.size(); l++) {
	vector<int> bruh = adj[l];
	bruh.erase(bruh.begin()+k2+1);
	adj[l] = bruh;
      }
      
    }
    
  }
}
