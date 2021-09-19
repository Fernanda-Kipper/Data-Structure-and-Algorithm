# Data Structure Queue

## Type: Restricted Access
We can add nodes only on the end of the queue or at its priority position and remove from the front, just like a queue at the bank for example (with or without priority).

## Basic Operations
- POP - Remove the first node and return the data that was removed - **DEQUEUE**
- APPEND - Add a node on the end of the queue or at an specific position given the priority - **ENQUEUE**
- RESET - Reset the queue, often used in start
- CLEAR - Remove all the nodes from the queue
- EMPTY - Check if the list is empty

### Obs: These queues were implemented using simple linked lists. Each node has its data and a pointer to the next element. 
## Non priority Queue - FIFO
The **FIRST NODE IN IS THE FIRST NODE OUT**. Nodes are add at the back and removed from the front.

<p align="center"><img src="https://miro.medium.com/max/1000/1*wN83zdV3arHyUl5GQXxRfw.jpeg" width="400px"/></p>

## Simple priority Queue
**Nodes are added to the queue at their priority position**. Elements are removed from the front of the queue.
(in this example I have implemented descending order queues)

<p align="center"><img src="https://lh4.googleusercontent.com/IjCJUHMzsB2mXAMfStjjip6zk06K8wQZSvXTn3kO4hiBVLJbCN2mrkS0d6DQc_fY88Zv_zodEuXMg4ZxMkhKy9hHrMNl0qR3dBGqC9FHIz2u1xbKska9-SPdSDjvdzpGM7ZaJrg" width="400px"/></p>