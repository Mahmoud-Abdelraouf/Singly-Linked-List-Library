# Singly-Linked-List-Library
It's a library in simplest type of linked list
## This library is one of the libraries belonging to Data Structure in particularly Singly linked list in which every node contains some data and a pointer to 
the next node of the same data type.
- This library contains a lot of useful and easily used functions such as:
1. <pre>CreateList(&List)                  :</pre> This function take the address of the list of type of struct List_t to create your list which point to the 1st
node in your list
2. <pre>AddToFront(&list,Value)            :</pre> This function enables you to add items at the beginning of the list, note when you add from front the first value you add becomes 
the last value in the list
3. <pre>RemoveFromFront(&List,&Retern Data):</pre> This function make you able to remove the last data you add from the front of the list.
4. <pre>AddToBack(&List,Value)        :</pre> This function enables you to add items at the end of the list, note when you add from back, the first value becomes the first item in the list 
and the last value is the last item in the list.
5. <pre>RemoveFromBack(&List,&Retern Data) :</pre>  this function make you able to remove the last data you add from the back of the list.
- There is fundamental user defined data type you should know them:
1. struct list/List_t which contain the address that point to the first node in the list at all.
2. struct node/Node_t which contain the value will be added in and pointer that is point to the next node in the list.
- These functions can also be easily modified to achieve your own goal.
