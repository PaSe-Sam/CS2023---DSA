#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int greatest = root;  
   int left = 2*root + 1;  
   int right = 2*root + 2;  

    
   if (left < n && arr[left] > arr[greatest]){ //if the left is greater than root, assign left as greatest
      greatest = left;
   }

    
   else if (right < n && arr[right] > arr[greatest]){ //if the right is greater than greatest value, assign right as greatest
      greatest = right;
   }
    
   if (greatest != root){
      swap(arr[root], arr[greatest]);
      heapify(arr, n, greatest);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
   for (int i = n / 2 - 1; i >= 0; i--){
      heapify(arr, n, i);
   }


   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--)
   {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
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
int main() {

   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; ++i){
      arr[i] = rand() % 100 + 1;
   }

   cout << "Before sorting: ";
   displayArray(arr, n);

   heapSort(arr, n);

   cout << "After sorting: ";
   displayArray(arr, n);
}
