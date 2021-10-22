#include <stdio.h>

void selectionSort(int data[], int length){
  int min, tmp, i, j;
  for(j = 0; j < length - 1; j++){
    min = data[j];
    for(i = j + 1; i < length; i++){
      if(data[i] < min){
        min = data[i];
        tmp = data[j];
        data[j] = min;
        data[i] = tmp;
      }
    }
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

  selectionSort(data, length);
  printAll(data, length);

  return 0;
}