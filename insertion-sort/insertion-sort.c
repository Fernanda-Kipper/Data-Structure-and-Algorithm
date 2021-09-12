#include <stdio.h>

void insertionSort(int data[], int length){
  int tmp,i,j;
  for(j = 1; j < length; j++){
    i = j - 1;
    tmp = data[j];
    while((i>=0) && (tmp < data[i])){
      data[i+1] = data[i];
      i--;
    }
    data[i + 1] = tmp;
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
  int data[] = { 1, 13, 5, 3, 7, 2, 15 };
  int length = sizeof(data) / sizeof(data[0]);

  insertionSort(data, length);
  printAll(data, length);

  return 0;
}