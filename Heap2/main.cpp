#include <iostream>//Aneeq Chowdhury Heap code. I used help from Nihal for a print method. Used helps from geeksforgeeks to understand the algorithm, and sm syntax and my binary search tree as well.
//https://www.geeksforgeeks.org/building-heap-from-array/
//https://www.geeksforgeeks.org/heap-sort/
#include <cstring>
#include <fstream>
using namespace std;
void heapify(int arr[], int n, int i) {//Heapify method, a heapify does swapping to turn a thing into a heap.
    int l2 = 2*i+1;//left child
    int r = 2*i+2;//right child;
    int l = i;//the largest
    //right child
    if(r < n && arr[r] > arr[l]) {//if right child is greater than largest
      l = r;
    }
    if(l2 < n && arr[l2] > arr[l]) {//if left child is greater than largest
      l = l2;
    }
    if(l != i) {//if largest is not the root
      swap(arr[i], arr[l]);
      heapify(arr,n,l);
    }
}//heapsort
void hsort(int array[], int bruh) {//going through the array, adn checking if the children are smaller than the parent.
  //This woudl switch when needed. 
   for(int i = bruh/2-1; i>=0; i--) {
     heapify(array,bruh,i);
   }
   for(int i = bruh-1; i > 0; i--) {
     int num = array[i];
     int bruh = array[0];
     array[i] = bruh;
     array[0] = num;
     heapify(array,i,0);
   } 
 }
void buildHeap(int arr[], int n)//Builds array to a heap
  {
    int start = (n/2)-1;
    for (int i = start; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
void printfr(int i, int* array, int space, int length) {//printmethod, I used help from Nihal here.
  if(i*2 +2 <= length && array[i*2+2] != 0) {
    printfr(i*2+2,array,space+1, length);
  }
  for(int k = 0; k < space; k++) {
    cout<< " ";//The tabs
  }
  if(array[i] != -99) {//Make sure its not -99, just in cas
    cout<<array[i] << endl;
  }
  if(i*2 +1 <= length && array[i*2+1] != 0) {
      printfr(i*2+1, array, space+1, length);
    }
}

int main() {
  int *array = new int[100];
  int index = 0;
  char arr[81];
  for(int i = 0; i < 10; i++) {
    array[i] = -99;
  }
  bool bruh = false;
  while(bruh == false) {
    cout<<"What do  you want to do? Add? Print? File? Delete? Remove(This removes all of them)?"<<endl;
    cin>>arr;
    if(strcmp(arr,"Add") == 0) {//add
      cout<<"what are yo adding?"<<endl;
      int n;
      cin>>n;
      array[index] =n;
      index++;
      hsort(array,index);
    }
    else if(strcmp(arr,"Print") == 0) {//print
      buildHeap(array,index);
      printfr(0,array,0,index);
    }
    else if(strcmp(arr,"Delete") == 0) {//delete
      cout<<"What do you want to delete?" << endl;
      int num;
      cin>>num;
      for(int k = 0; k < index+1; k++) {
	if(array[k] == num) {
	  swap(array[k], array[index]);
	  array[index] = -99;
	  index--;
	  buildHeap(array,index);
	}
      }
    }
    else if(strcmp(arr,"Remove") == 0) {//remove
      hsort(array,index);
      for(int k = index-1; k > -1; k--) {
	cout<<array[k] << endl;
      }
    }
    else if(strcmp(arr,"File") ==0) {//File
      cout<<"Enter" <<endl;
       fstream myfile("numbers.txt");
       string filename("input.txt");
       int number;
       ifstream input_file(filename);
       if (!input_file.is_open()) {
	 cerr << "Could not open" << endl;
       }
       
       while (input_file >> number) {
	 array[index] = number;
	 index++;
       }
       cout << endl;
       input_file.close();
    }
  }

}
