#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest;
   int l = 2*root + 1;
   int r = 2*root + 2;
   if (l < n && arr[l] > arr[root]){
      largest = l;
   }
   else{
      largest = root;
   }
   if (r < n && arr[r] > arr[largest]){
      largest = r;
   }
   if (largest != root){
      int temp = arr[root];
      arr[root] = arr[largest];
      arr[largest] = temp;
      heapify(arr, n, largest);
   }
}


// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = (int)n/2 -1; i >= 0; i--){
      heapify(arr,n,i);
   }
   // extracting elements from heap one by one 
   for (int j = n-1; j >= 1; j--){
      int temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;
      n--;
      heapify(arr,n,0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   vector <int> vct;
   cout << "Enter numbers one by one ...." << endl;
   cout << "Enter -1 to stop" << endl;
   string s = "";
   while (true){
      cin >> s;
      if (s == "-1"){
         break;
      }
      vct.push_back(stoi(s));
   }
   int n = vct.size();
   int heap_arr[n];
   for (int x = 0; x < n; x++){
      heap_arr[x] = vct[x];
   }
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}