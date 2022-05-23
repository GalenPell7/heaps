/*
*
* @author Galen Pellitteri
*   The purpose of this assignment is to compare the running times of these two heap construction methods
*   on randomly generated inputs. We will use the number of swaps as a proxy for the running time.
*
*
*/
#include <iostream>
using namespace std;

int make_heap_williams(int list[],int size)
{
  int williamsCounter = 0;
  for(int i = 0 ; i < size ; i++) 
  {
    for(int j = 0 ; j < size ; j++)
    {
      if((2*j+1) >= size) break; // reached an index that does not exist
      int greater_num = list[2*j+1] > list[2*j+2] ? list[2*j+1] : list[2*j+2];
      if(list[j] < greater_num) // compare parent and children
      {
        if(greater_num == list[2*j+1])
        {
          swap(list[j] , list[2*j+1]);
        }
        else if(greater_num == list[2*j+2])
        {
          swap(list[j] , list[2*j+2]);
        }
        williamsCounter++;
      }
    }
  }
  return williamsCounter;
}

int make_heap_floyd(int list[],int size)
{
  int floyd_counter = 0;
  int i = size-1;
  int greater_num = 0;
  for (; i >= 2 ; i--) 
  {
     // compare parent and larger of both children, increase counter
    if ( i % 2 != 0) // odd index, compare right child
      greater_num = list[i] > list[i+1] ? list[i] : list[i+1];
    else if ( i % 2 == 0) // even index, compare left child
      greater_num = list[i] > list[i-1] ? list[i] : list[i-1];
    if (i==2) // Compare the last three indices, increase counter
    {
      greater_num = list[i] > list[i-1] ? list[i] : list[i-1];
      if (list[0] < greater_num)
        {
          if(greater_num == list[i]) 
            {
              swap(list[0],list[i]);
              i = size-1;
            }
          else if (greater_num == list[i-1])  
            {
              swap(list[0],list[i-1]);
              i = size-1;
            }
          floyd_counter++;
            }
    } else { 
      if (list[(i-1)/2] < greater_num) // traverse from bottom up
      {
        if (greater_num == list[i]) 
        {
          swap(list[(i-1)/2] , list[i]);
          i = size-1;
        }
        else if (greater_num == list[i-1])
        {
          swap(list[(i-1)/2] , list[i-1]);
          i = size-1;
        }
        else if (greater_num == list[i+1])
        {
          swap(list[(i-1)/2] , list[i+1]);
          i = size-1;
        }
        floyd_counter++;
      }
  }
    
  }
  return floyd_counter;
}
