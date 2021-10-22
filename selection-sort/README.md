# Selection Sort Algorithm

## What it does?
Sorts an array in ascending order, starts from the first element and checks if any other element is smaller than itself, if so
the algorithm swaps them, one staying in place of the other, then go to the next element and do the same comparison with all the elements after it, so on, until the end of the array

## Time Complexity 

Case | Complexity | Explanation | When happens
--- | --- | --- | --- |
Worst & Best |  **O(n ** 2)** | The algorithm will always need to go till the end of the array on the second *for loop* to be sure that the element being analysed is smaller then the others next him | Always

### Note that is algorithm is stable, same time complexity for all inputs