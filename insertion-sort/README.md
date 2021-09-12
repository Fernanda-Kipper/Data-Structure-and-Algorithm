# Insertion Sort Algorithm

## What it does?
Sorts an array in ascending order, the elements that are in the part that as already checked will always be sorted because the algorithm compare the actual element with all the previous one, positioning where it is greater than the previous but less than the next one, doing this until the end of the array. 

## Time Complexity 

Case | Complexity | Explanation | When happens
--- | --- | --- | --- |
Worst |  **O(n ** 2)** | The algorithm will need to enter inside the *while loop* in every time of the *for loop* | When the array is inverted
Best | **O(n)** | Because it will not enter the *while loop* and the *for loop* runs just *n* times  | When the array is already sorted