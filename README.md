# Insertion Sort

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. Insertion sort will be performed on two differenct data structures: a) Array b) Linked Lists.

For arrays, the array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

Below is simple insertion sort algorithm for arrays (To sort an array of size n in ascending order):

1) Iterate from arr[1] to arr[n] over the array. 
2) Compare the current element to its predecessor. 
3) If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.


![image](https://user-images.githubusercontent.com/70550648/111022048-28016080-8385-11eb-9b78-b4e202ef4f87.png)

Source: Geekforgeeks : https://www.geeksforgeeks.org/insertion-sort/

For linked lists, you start with an empty list, then add all the elements one by one in this new list, in their appropriate spot.

Below is simple insertion sort algorithm for linked list:

1) Create an empty sorted (or result) list
2) Traverse the given list, do following for every node. ------>
2a) Insert current node in sorted way in sorted or result list.
4) Change head of given linked list to head of sorted (or result) list.

Creating a sorted linked list is much more complicated than an array. So (step 2a in the above algo) in achieving this the following is performed: given a sorted linked list and a value to insert, write a function to insert the value in a sorted way. 

This is summarized in the picture below:

![image](https://user-images.githubusercontent.com/70550648/111022297-bd512480-8386-11eb-91ce-afc43152302f.png)

Source: Geekforgeeks : https://www.geeksforgeeks.org/given-a-linked-list-which-is-sorted-how-will-you-insert-in-sorted-way/

Once that is done, it is easy to create a copy of the linked list which is sorted in place. 

Since the size of the result list keeps increasing, this is not a good algorithm for fixed-sized data structures like arrays.

There are 3 files in this repository:

1) Insertion sort for an array
2) Insertion sort for the simplified case shown above
3) Insertion sort for a non-sorted linked list
