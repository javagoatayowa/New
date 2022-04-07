 #include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <fstream>
/* A utility function to print array of size n */
using namespace std;
void display(int index, int* array, int depth, int size) {//Displays the heap using tabs
  if (index*2 + 2 <= size && array[index*2 + 2] != 0) {
    display(index*2 + 2, array, depth + 1, size);//Recurcive call
  }
  for (int i = 0; i < depth; i++) {//Prints out the amount of tabs based on the depth
    cout << "\t";
  }
  cout << array[index] << endl;//Prints out the number
  if (index*2 + 1 <= size && array[index*2 + 1] != 0) {
    display(index*2 + 1, array, depth + 1, size);//Recurcive call
  }
}
void heap(int* array, int &curr) {//Rearanges the heap so its propper
  if (array[curr] > array[(int) floor((curr-1)/2)]) {//If the childs value is bigger than its parents
    //Switches child and parent
    int temp = array[curr];
    array[curr] = array[(int) floor((curr-1)/2)];
    array[(int) floor((curr-1)/2)] = temp;
    int newcurr = (int) floor((curr-1)/2);
    
    heap(array, newcurr);
  }
}
int main(){
  int arr[100];
  int count = 0;
  int a = 0;
  while(a == 0) {
     char arr2[81];
     cin>>arr2;
     if(strcmp(arr2,"ADD") == 0) {
       int n;
       cin>>n;
       if(count < 100) {
	 arr[count] = n;
       }
       if(count > 0) {
	 heap(arr,count);
       }
       count++;
     }
     else if(strcmp(arr2, "PRINT") == 0) {
       display(0,arr,0,count);
     }
     else if(strcmp(arr2,"FILE") == 0) {
       fstream myfile("numbers.txt");
       string filename("input.txt");
       int number;

       ifstream input_file(filename);
       if (!input_file.is_open()) {
	 cerr << "Could not open the file - '"
	      << filename << "'" << endl;
       }
       
       while (input_file >> number) {
	 if(count < 100) {
	   arr[count] = number;
	   count++;
	 }
       }
       cout << endl;
       input_file.close();
    //cin>>n3
     }

  } 

}
