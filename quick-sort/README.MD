# Quick Sort Algorithm

## What it does?
### Divide to conquer!
This algorithm organize the elements in ascending order by dividing the array in two sub-arrays given a pivot. 
Then, all elements less then the pivot are placed in the left side array and the elements greater then the pivot at the right side.
Then each sub-array is divided in two sub-arrays again and the same process is made. Till we reach the ascending order.

## Time Complexity 

Case | Complexity | Explanation | When happens
--- | --- | --- | --- |
Worst |  **O(n ** 2)** | The algorithm will need to swap element by element | When the pivot is the greater or smallest element of the list, meaning that all elements will be at his other side, resulting in no division at all
Best |  **O(n log n)** | The algorithm needs to swap just the size of the sub-array/2, and each round this size is divided by 2 | When the pivot is or is almost the central element, meaning that each side of him will have almost the same number of elements

### Note that this algorithm is instable
**Because it depends on the chosen of the pivot**, which need to occurs randomly
The algorithm has 2 of N chances of choosing the worst pivot (the biggest and the smallest), more greater is the size of N (total number of elements) less is the chance to get the worst pivot