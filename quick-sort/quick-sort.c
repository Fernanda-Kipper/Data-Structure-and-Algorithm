#include <stdio.h>

void quickSort(int data[], int left, int right){
  int mid, tmp, i, j;
  i = left;
  j = right;
  mid = data[(left + right) / 2];

  do {
    while(data[i] < mid){
      i++;
    }
    while(data[j] > mid){
      j--;
    }
    if(i <= j){
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
      i++;
      j--;
    }
  } while( i <= j );

  if(left < j){
    quickSort(data, left, j);
  }
  if(i < right){
    quickSort(data, i, right);
  }
}

void printAll(int data[], int length)
{
    int i;
    for (i = 0; i < length; i++)
      printf("Data[%d] = %d \n", i + 1, data[i]);
}
 
int main()
{
  int data[] = { 1, 13, 5, 3, 7, 2, 15 , 23, 1, 34, 3, 32, 45, 9};
  int length = sizeof(data) / sizeof(data[0]);

  quickSort(data, 0, length - 1);
  printAll(data, length);

  return 0;
}