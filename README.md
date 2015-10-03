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
 Three tests have been configured. (1) visually explains the list operations on a small number of nodes. (2) is used in conjunction with (3) and it creates a large (millions of nodes) list. (3) creates a list of the same size and traverses it. For example to run `test1` (ignore the warnings when `./test2` and `./test3` do not have targets):  
 ```
 make test1
 make run
 ```
 You can build alI executables and run them by:  
 ```
 make build
 make run
 ```
 Or you can measure the traversal time by changing the hardcoded `SIZE_TEST2` in `doubly.h` and:  
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
* Traversal time  
<p align="center">
  <img src="https://github.com/0xLeo/data-structs/blob/master/doubly-linked/img/test23.png" title="test 2 and 3" width=75%>  
</p>

### 2. Binary tree  
##### (./bin-tree)  
  **Description**  
  My C implementation of binary (not necessarily balanced), ordered, [ trees](https://en.wikipedia.org/wiki/Binary_tree). The term ordered implies that for each parent node, the data of its left child is smaller than the parent's and the value of its right child is greater.  
  **Instructions**  
  Clone the project and head to the tree directory:  
```
$ git clone https://github.com/0xLeo/data-structs.git
$ cd data-structs/bin-tree/
```
 The test consists of 4 parts. To compile all of them, run them, and delete the outputs, type:
```
$ make
```
 Alternatively, to compile and run a single test, e.g. 3, type:
```
$ make build3
$ make run3
$ make clean
```
* test1 = insertion
* test2 = traversal
* test3 = get min + deletion
* test4 = search + measure time

  **Explanation**  
  Comments on how the tree functions work are found in tree.c. The functions for traversal, deletion, obtaining the minimum data, and search data are defined there. The average time complexity for every one of them is O(log(n)). Test 4 measures the average search time, over 10 executions, for various data set sizes.  
    
  **Results**  
 System Specifications:
```
CPU: Intel(R) Core(TM) i3 CPU M 380 @ 2.53GHz
RAM size: 8 GB
cache size: 6144 KB
Distribution: Ubuntu 12.04.5 LTS
compiler: gcc 4.6.3
```
 <p align="center">
  <img src="https://github.com/0xLeo/data-structs/blob/master/bin-tree/out/test04.jpg" width=75%>  
</p>  

The respective comma-separated data are found [here](https://github.com/0xLeo/data-structs/blob/master/bin-tree/out/test04csv.csv).
 
