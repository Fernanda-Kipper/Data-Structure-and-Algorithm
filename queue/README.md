# Data Structure Queue

## Type: Restricted Access
We can add nodes only on the end of the queue and remove from the begging, just like a queue at the bank for example (considering non priority queues).

## Basic Operations
- POP - Remove the first node and return the data that was removed **DEQUEUE**
- APPEND - Add a node on the end of the list **ENQUEUE**
- RESET - Reset the queue, often used in start
- CLEAR - Remove all the nodes from the queue
- EMPTY - Check if the list is empty

## Non priority Queue - FIFO
Each node has its data and a pointer to the next element. The **FIRST NODE IN IS THE FIRST NODE OUT**.

<p align="center"><img src="https://miro.medium.com/max/1000/1*wN83zdV3arHyUl5GQXxRfw.jpeg" width="400px"/></p>