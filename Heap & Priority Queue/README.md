# Heap
## What is Heap?
Heap is a complete binary tree (a tree without NULL node between the list)
```
For Example
Tree A (Heap): [9,7,5,3,1]
Tree B (Not A Heap): [9,7,5,NULL,1]
```

## Node's position of Heap in List
- If a Node is at index i: <br>
- Leftchild will be 2\*i <br>
- Rightchild will be 2\*i+1 <br>
- Parent will be at i/2 <br>

## Heap Type
### Max Heap
* Max Heap is a heap that every nodes have the value that greater or equals to it's descendants.
### Min Heap
* Min Heap is a heap that every nodes have the value that less or equals to it's descendants.

## Heap Insertion
The new node will be inserted in the last element of the list in order to maintain as a binary tree. Then, swap with the nodes to maintain as Max/Min Heap order.<br>

It is very similar to Heap Deletion but in opposite direction.
### Time Complexity
The swapping operation will depend on the height of the binary tree. <br>
Therefore, **the Time Complexity will be worst case O(logn) / best case O(1)**.<br>

## Heap Deletion
You can only delete the root node of the Heap, but not others. <br>
After the root node is removed. The last element of the list will be assigned to the root position in order to maintain as a binary tree. Then swap with the nodes to main as Max/Min Heap order. <br>

It is very similar to Heap Insertion but in opposite direction.<br><br>

Although we "removed" the root node from the heap, we can store the root value in the left over position in the list.<br>
For Example: [50, 40, 30, 20, 10, 5] -> Remove + Swapping -> [40, 30, 20, 10, 5, 50]<br>
We could adjust the Heap is only represented by the first 5 index of the list instead of the whole list.<br>
In this way, we could sort a list with Heap Deletion over time, which is the idea of [**Heap Sort**](https://github.com/yenloned/Data-Structure-Algorithm-Study/blob/main/Sorting/heap_sort.cpp).


### Time Complexity
The swapping operation will depend on the height of the binary tree. <br>
Therefore, **the Time Complexity will be worst case O(logn) / best case O(1)**.<br>

## Heap Sort
* Step1: Given a list, inserting them one by one to form a heap.
* Step2: Delete the heap root one by one to form a sorted list.

### Time Complexity
Step 1: It will take **O(nlogn)** in total. <br>
**O(n)** time in the insertion of the numbers of element in the given list.<br>
**O(logn)** time in ordering the heap in each insertion, which depends on the height. <br>
<br>
Step2: It will take **O(nlogn)** in total. <br>
**O(n)** time in the deletion of the numbers of element in the heap.<br>
**O(logn)** time in ordering the heap in each deletion, which depends on the height. <br>

Therefore, Heap Sort will take **O(nlogn)** in Time Complexity.

## Heapify
### What is Heapify?
Heapify is a procedure for creating(reordering) a heap from a binary tree. <br>

### Procedure
In a binary tree/list, it will keep comparing the node and it's parent, and swapping them when the child is bigger. <br>
Started from last element, look downward to check if it has a child node that is bigger than itself. (Bottom Up) <br>

### Time Complexity & Why Heapify?
Heapify has the **Time Complexity of O(n)** since we only traversal the binary tree once. <br>
It has a better Time Complexity compare with the Insert & Delete for creating a Heap with O(nlogn) time.<br>

# Priority Queue
## What is Priority Queue
Priority Queues is a special type of queue that obtains priority in each insertion and deletion. <br>
For Example: In every deletion, we want the highest priority element be removed.

## Priority Queue in Max/Min Heap
### Max Heap
The root node(highest value) will have the highest priority in the deletion of Max Heap. Therefore, it follows:
* Larger number, Higher Priority

### Min Heap
The root node(smallest value) will have the highest priority in the deletion of Max Heap. Therefore, it follows:
* Smaller number, Higher Priority

## Why using Heap as Priority Queue?
Heap is the best/most efficient data structure for implementing Priority Queue in case of Time Complexity. <br>
* Under normal case:
  * **O(n)** time will be taken to remove a highest priority element from a list.<br>
* By using Heap:
  * **O(logn)** time will be taken for deletion in Max/Min Heap (highest priority element).