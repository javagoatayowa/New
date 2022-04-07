#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <fstream>
using namespace std;
//ANEEQ CHOWDHURY 4/6/2022 CODE to do heap with numbers. I have recieved help from Nihal on display, heap function, and removal(I was confused about the instructions). I have also gotten help from : https://www.cplusplus.com/doc/tutorial/files/ for file input C++
void display(int in, int* arr, int depth, int len) {//Display function i used help from nihal on.
  if (in*2 + 2 <= len && arr[in*2 + 2] != 0) {
    display(in*2 + 2, arr, depth + 1, len);
  }
  for (int i = 0; i < depth; i++) {
    cout << "\t";//tabs based on the depth of the node.
  }
  cout << arr[in] << endl;
  if (in*2 + 1 <= len && arr[in*2 + 1] != 0) {
    display(in*2 + 1, arr, depth + 1, len);
  }
}
void heap(int* array, int &curr) {//Heaps the array with the index from a certian point(Important for moving the index to a proper parent
  if (array[curr] > array[(int) floor((curr-1)/2)]) {//Checks the parent and child values. If child is bigger, it switches. 
    int temp = array[curr];
    array[curr] = array[(int) floor((curr-1)/2)];
    array[(int) floor((curr-1)/2)] = temp;
    int newcurr = (int) floor((curr-1)/2);
    
    heap(array, newcurr);//Recursive rearrangement.
  }
}
int main(){
  int arr[100];//full num input
  int count = 0;
  int a = 0;
  while(a == 0) {
    cout<<"Say ADD to add, PRINT to print, REMOVE to remove, FILE to file add";
    cout<<endl;
    if(count == 100) {
      cout<<"100 terms fulled! Bad spelling ik, but L + ratio here is heap"; 
      display(0,arr,0,count);
    }
     char arr2[81];//input c
     cin>>arr2;//add function below
     if(strcmp(arr2,"ADD") == 0) {
       int n;
       cin>>n;
       if(count < 100) {
	 arr[count] = n;
       }
       if(count > 0) {
     	 heap(arr,count);//after adding, have to rearrange that part
       }
       count++;
     }
     else if(strcmp(arr2, "REMOVE") == 0) {//remove function
       while(count != 0) {
	 cout<<arr[0] << endl;//Keep printing out the top, then setting the top to after it. 
	 arr[0] = arr[count-1];
	 arr[count - 1] = 0;
	 heap(arr,count);
	 count--;
       }
     }
     else if(strcmp(arr2, "PRINT") == 0) {//print function
       display(0,arr,0,count);
     }
     else if(strcmp(arr2,"FILE") == 0) {//file function
       cout<<"ENTER NUMS IN THE FILEEEEE";
       fstream myfile("numbers.txt");
       string filename("input.txt");
       int number;
       ifstream input_file(filename);
       if (!input_file.is_open()) {
	 cerr << "Could not open file L bozo + ratio + mad cuz bad" << endl;
       }
       
       while (input_file >> number) {
	 if(count < 100) {
	   arr[count] = number;
	   if(count > 0) {
	     heap(arr,count);
	   }
	   count++;
	 }
       }
       cout << endl;
       input_file.close();
    //cin>>n3
     }

  } 

}
