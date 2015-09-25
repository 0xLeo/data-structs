# data-structs
implementation and testing of various data structures

<h3 align="center">Contents</h3>  
<h4 align="center">1. Doubly linked list</h4>  
<h4 align="center">2. Binary tree</h4>


### 1. Doubly linked list  
##### (./doubly-linked)    
**Description**  
My implementation of doubly linked lists in C. It's a simple, sequential and light data structure. It's been tested  
for various numbers of nodes, ranging from 5E+5 to 4E+8.    
**Instructions**  
To run, simply clone the repo: ```git clone https://github.com/0xLeo/data-structs.git```, head in the directory - ```cd ./data-structs/doubly-linked```, and in the terminal type ```make```. This will compile the source, run it, and clean the executable.  
 
 **Explanation**  
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
 
 **Results**  
 * System Specifications  
```
CPU: Intel(R) Core(TM) i3 CPU M 380 @ 2.53GHz
RAM size: 8 GB
cache size: 6144 KB
Distribution: Ubuntu 12.04.5 LTS
compiler: gcc 4.6.3
```  
 * Time  
 
  A wrapper script is used to make the source, test it on inputs of various sizes, for each sizeand measure the average linked   list creation (e.g. insert/ append) time.  
<p align="center">
  <img src="https://github.com/0xLeo/data-structs/blob/master/doubly-linked/img/ins-time-vs-numnodes.jpg" width=70%>  
</p>  
 * Memory  
  When a node is deleted individually or the list is deleted as a whole the place it was taking is fred and zeroed out so the  compiler can safely reclaim it.  
  After running the program, let's take a look at the memory the first list (of length 30) is occupying. Fire up gdb and set    breakpoints before and after deletion:  
 ```
 $ gdb -q test
 (gdb) br 33  
 (gdb) br 35  
 ```  
 Print some addresses from the list:  
 ```
 (gdb) print (*head)  
 $1 = {data = 20, next = 0x804b148, prev = 0x0}  
 (gdb) print *head->next  
 $2 = {data = 19, next = 0x804b138, prev = 0x804b278}  
 (gdb) print *head->next->next  
 $3 = {data = 18, next = 0x804b128, prev = 0x804b148}  
 ```  
 Continue until deletion:  
 ```
(gdb) cont  

 ```
   View their contents again, for example:   
 ```
 (gdb) print *head  
 Cannot access memory at address 0x0  
 (gdb) x/wx 0x804b148
 0x804b148:	0x00000000
 (gdb) x/xw 0x804b138  
 0x804b138:	0x00000000
 (gdb) x/xw 0x804b128
 0x804b128:	0x00000000
 ```

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
 
