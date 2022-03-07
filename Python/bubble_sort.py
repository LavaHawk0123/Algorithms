import math
import time

def print_array(array):
	n = len(array)
	for i in range(0,n):
		print(array[i],end=" ")
	#print("\n")

def bubble_sort_func(array):
	n = len(array)
	print("Elements of array are : ")
	print_array(array)
	print("\n\n ------------ Performing Bubble Sort ------------- ")
	    # Traverse through all array elements
	for i in range(0,n):
        # Last i elements are already in place
		print("\nIteration {} :".format(i))
		for j in range(0, n-i-1):
			swap = False
            # traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
			print("\nComparing elements {} and {}".format(array[j],array[j+1]))
			if array[j] > array[j+1] :
				print_array(array)
				print("->",end=" ")
				array[j], array[j+1] = array[j+1], array[j]
				print_array(array)
				swap = True
		print("\nArray after iteration {} :".format(i))
		print_array(array)
		print("\n")
		if(not swap):
			break


print("------- Bubble Sort ------")
print("Enter the nummber of elements :")
n = int(input())
arr =[]
for i in range(0,n):
	print("Enter the {} th element of the array:".format(i), end = " ")
	arr.append(input())
	print("Read Element : "+arr[i])
bubble_sort_func(arr)
