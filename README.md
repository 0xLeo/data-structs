# data-structs
implementation and testing of various data structures

<h3 align="center">Contents</h3>  
<h4 align="center">1. Doubly linked list</h4>  
<h4 align="center">2. Binary tree</h4>


### 1. Doubly linked list  
##### (./doubly-linked)    
######Description
  
My implementation of doubly linked lists in C. It's a simple, sequential and light data structure. It's been tested  
for various numbers of nodes, ranging from 2E+4 to 6E+6.    
######Instructions
  
To download, simply clone the repo:  
`git clone https://github.com/0xLeo/data-structs.git`  
Head in the linked list directory:  
`cd ./data-structs/doubly-linked`  
 Three tests (+) have been configured.
 ```
 + Demonstrates list operations on standard output
 |
 + Create a large list
 |
 +--+ Traverse large list
 ```
 For example to run `test1`:
 ```
 make test1
./test1
 ```
 You can build all executables and run them by:  
 ```
 make build
 make run
 ```
 Or you can measure the traversal [time](#anchor1) by changing the hardcoded `SIZE_TEST2` in `doubly.h` and:  
 ```
 make clean
 make build
 make time
 ```
 *Before you time the executable, make sure the number of iterations (*`N` *in* `timewrapper.sh` *is large enough) and that your computer is occupied with as few processes as possible.*  
 The time results are appended to `test23.txt` (you don't need to create it).  
 Finally to remove all object and executable files:  
 `make clean`

######Explanation
  
 The time complexity for an insertion/ deletion is O(1), and O(n) to traverse the list/ seek an element.  
 Below is a pictorial explanation of the functions developed, declared in ```./doubly-linked/doubly.h```.
 * list_insert  
 <p align="center">
  <img src="https://github.com/0xLeo/data-structs/blob/master/doubly-linked/img/list_insert.png" width=55%>  
</p>
 * list_append  
 Same as list_insert if we replace head with tail and tail->next with NULL instead of prev.  
 * list_insert_at  
 <p align="center">
  <img src="https://github.com/0xLeo/data-structs/blob/master/doubly-linked/img/list_insert_at.png" width=60%>  
</p>  
 * list_delete_at  
  -- In case the head is deleted (similar for tail)  
<p align="center">
  <img src="https://github.com/0xLeo/data-structs/blob/master/doubly-linked/img/list_delete_at_2.png" width=72%>  
</p> 
 -- In case any other node is deleted  
 <p align="center">
  <img src="https://github.com/0xLeo/data-structs/blob/master/doubly-linked/img/list_delete_at_1.png" width=65%>  
</p> 
 
 ######Results
  
 * System Specifications  
```
CPU: Intel(R) Core(TM) i3 CPU M 380 @ 2.53GHz
RAM size: 8 GB
cache size: 6144 KB
Distribution: Ubuntu 12.04.5 LTS
compiler: gcc 4.6.3
```  
Deletion, access, and insertion, and search are reduced to traversal (seek), therefore there is not really point measuring their time.
  
* Traversal time  
<p align="center">
  <img src="https://github.com/0xLeo/data-structs/blob/master/doubly-linked/img/test23.png" title="test 2 and 3" width=75%>  
</p>  
`[*]` Creation takes roughly 6-7 times more than traversal. The latter is extremely fast as it's broken down to N (size of list) pointer updates.

### 2. Binary tree  
##### (./bin-tree)  
  <h6>Description</h6>
  My C implementation of binary (not necessarily balanced), ordered, [ trees](https://en.wikipedia.org/wiki/Binary_tree). The term ordered implies that for each parent node, the data of its left child is smaller than the parent's and the value of its right child is greater.  
  <h6>Instructions</h6> 
  Clone the project and head in the tree directory:  
```
$ git clone https://github.com/0xLeo/data-structs.git
$ cd data-structs/bin-tree/
```
test.c defines 5 tests (+):
```
+ Insert batches of data
|
+ Traverse tree, print nodes, and delete. `test12.sh` verifies whether all nodes were reached.
|
+ Create large tree with random data.
|
+--+ Search last inserted element. Guaranteed to find it so that the search is deep.
|
+--+ Traverse without printing.
```  
To create all executables and run all test for 1000000 nodes type:
```
make build
make run
```
To run tests 4,5 ([measure time](#anchor1)) do:
```
make time
```
Files test4.txt and test5.txt will be generated, containing the search and traversal time. Once you got these data, you can join them in a csv file if you like e.g. by (1000000 is the number of notes):
```
paste test4.txt test5.txt  | sed 's/\s/, /g' | sed 's/^/1000000, /g'
```
You can change the number of nodes (`INPUT_SIZE_2` in tree.h) or the number of repetitions (`N` in test345.sh, however low `N`'s do not eliminate randomness so it is recommended to keep it above 30) and repeat (make sure the CPU usage of other processes is low):
```
make clean
make build
make time
```
Or you can run a single test (e.g. 3) by:
```
make test3
./test3
```

  <h6>Explanation</h6>
  Comments on how the tree functions work are found in tree.c. Time complexity for Depth-First traversal is `O(n)`, for search/ access `O(log(n))` and for deletion `O(log(n))`. When inserting random data, the tree may be badly balanced, so the complexity for each function may converge to its worst time (linear - when all nodes are aligned like in a linked list).  
    
  <h6>Results</h6>
 System Specifications:
```
CPU: Intel(R) Core(TM) i3 CPU M 380 @ 2.53GHz
RAM size: 8 GB
cache size: 6144 KB
Distribution: Ubuntu 12.04.5 LTS
compiler: gcc 4.6.3
```
 <p align="center">
  <img title="traversal time "src="https://github.com/0xLeo/data-structs/blob/master/bin-tree/out/s_time.PNG" width=60%>  
</p> 
 
 <p align="center">
  <img title="traversal time" src="https://github.com/0xLeo/data-structs/blob/master/bin-tree/out/t_time.PNG" width=60%>  
</p> 

The respective comma-separated data are found [here](https://github.com/0xLeo/data-structs/blob/master/bin-tree/out/test45.csv).
 
`[**]` <a id="anchor1"></a>To see why time was measured with shell, view  [issue 2](https://github.com/0xLeo/data-structs/issues/2).
