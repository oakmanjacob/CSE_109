# CSE 109 Hash Lab
Jacob Oakman   
jco222    
4/09/2019    
SECTION 011

# Build Instructions
## Build
```
$> make
```

## Run
```
$> ./build/bin/hashlab
```

## Clean
```
$> make clean
```

# Writeup
The data structure with the highest performance for the find operation was the size 1000 hash set. This slightly beat out the size 100 with the 10 coming in third and lastly the linked list with by far the worst performance.

I used the insert_tail method for inserting into the linked list so the operation should be O(1) for it and the hash sets. The graph seems to indicate a slight advantage to the linked list at low numbers of insertions with the size 10 hash set winning at higher numbers.

As the number of slots were increased, the average time per number of names inserted became more and more resembling O(1) while the linked list was clearly O(n).
