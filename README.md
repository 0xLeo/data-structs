# data-structs
implementation and testing of various data structures

### 1. doubly-linked

**Description**  

**Instructions**  
To run, simply clone the repo: ```git clone https://github.com/0xLeo/data-structs.git```, head in the ```doubly-linked``` directory and in the terminal type ```make```. This will compile the source, run it, and clean the executable.  
 
 **Explanation**  
 
 **Results**  
 * Time  
 
  A wrapper script is used to make the source, test it on inputs of various sizes, for each sizeand measure the average linked   list creation (e.g. insert/ append) time.  
 ![alt-text](https://github.com/0xLeo/data-structs/blob/master/doubly-linked/img/ins-time-vs-numnodes.jpg)  
 * Memory  
  When a node is deleted individually or the list is deleted as a whole the place it was taking is fred and zeroed out so the  compiler can safely reclaim it.  
  After running the program, let's take a look at the memory the first list (of length 30) is occupying. Fire up gdb and set    breakpoints before and after deletion:  
 ```
 (gdb) gdb -q test
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
