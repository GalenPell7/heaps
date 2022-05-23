#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <iterator>
#include "heaps.cpp"

using namespace std;
int main() {
  int n = 0, k=0;
  cout<<"Please enter integers n and k\n";
  cin >> n >> k;
  int arr[n];
  int arr2[n];
  float resultWilliams = 0.0, resultFloyd = 0.0;
  srand(time(0));
  for(int m; m < k ; m++) 
  { 
    for(int i = 0; i < n; i++) 
    {
      arr[i]= rand() % 99 + 1;
    }
    copy(arr,arr+n,arr2);  
    int a = make_heap_williams(arr, n);
    int b = make_heap_floyd(arr2, n);
    resultWilliams += a;
    resultFloyd += b;
  }
  float avgWilliams = (resultWilliams / k);
  float avgFloyd = (resultFloyd / k);
  cout << "Array size : " << n << endl;
  cout << "Performed " << k << " times." << endl;
  cout << "Average swaps for Williams : " << setprecision(9) << avgWilliams << endl;
  cout << "Average swaps for Floyd : " << setprecision(9) << avgFloyd << endl;
}