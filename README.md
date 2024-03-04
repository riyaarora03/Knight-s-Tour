# Knight-s-Tour
![Image Alt Text](https://github.com/riyaarora03/Knight-s-Tour/blob/main/screenshot.png)

A KNIGHT IN A CHESS GAME CAN MOVE TO ANY SQUARE ON TE STANDARD 8x8 CHESS BOARD FROM ANY OTHER SQUARE ON THE BOARD,GIVEN ENOUGH TURNS ITS BASIC MOVE IS TWO STEPS FORWARD AND ONE STEP SIDEWAYS DEPENDING ON THE DIRECTION IT IS MOVING.
OUR TASK IN THIS PROJECT IS TO BUILD A FUNCTION THAT SHOWS THE SIMPLEST WAY TO HET FROM ONE SQUARE TO ANOTHER BY OUTPUTTING ALL SQUARES THE KNIGHT WILL STOP ON ITS WAY.

## Data Structures Used:
K-Ary Tree
Arrays
OOPSs
Queue

## CONSIDERING CLASSES NODE & TREE.
Class node is for creating a child of a tree. A node has three data members x,y,dist  which stores a square’s information on the chess board.it has a pointer to array of 8 children.
As our k-ary is assumed to have 8 children as maximum 8 directions are possible in which a knight can move.
### CLASS TREE
Class tree contains a function counttree() which creates a tree with all possible moves.
### COUNTREE FUNCTION:
It has two arguments root src and root dest.
The parent node that is being explored is front of our queue.
It is stored in node and then condition is checked if whether it is equal to destination node (return distance if equal).
If front is not equal to the destination then then 8 children of the given node are created (if possible).

We can have 8 possible moves.
dx= [2,2,-2,-2,1,1,-1,-1]
dy=[1,-1,1,-1,2,-2,-2,2]
Based on the children the “dist” variable is incremented by 1 further and further and these children are stored in a queue.
To store the position of squares visited on chess board an array is also maintained.
The counttree function returns distance if the final destination is found else it returns infinity.
Thus we found the shortest distance.
 
### NOW SHORTEST DISTANCE PATH:
Since our tree is already made and we have its parent’s address so we have to just find the path from root to its given child.
Since it is a k-ary tree we have considered first 7 children as left child and the last as 8th as right child.

WE HAVE CONSIDERED TWO FUNTIONS,
Haspath(),printpath().
 
The bool haspath() function short algo is as
If root = NULL, return false.
push the root into arr[].
if root’s data ==(x,y) return true.
if (x,y) is present in root’s left or right subtree, return true.
Else remove root from arr[] and return false.
The print path function is simply printing the path
