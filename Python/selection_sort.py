import math
import time

def print_array(array,n):
	for i in range(0,n):
		print(array[i],end=" ")
	print("\n")

def selection_sort_func(array,n):
	print("Elements of array are : ")
	print_array(array,n)
	print("\nPerforming Selection Sort")
	for i in range(0,n):
		min_index = i
		for j in range(i+1,n):
			if array[j]<array[min_index]:
				min_index=j
				#print("Min Index of Iteration {} is {}".format(i,min_index))
		array[i],array[min_index] = array[min_index],array[i]
		print("Array after iteration {} :".format(i))
		print_array(array,n)


print("------- Selection Sort ------")
print("Enter the nummber of elements :")
n = int(input())
arr =[]
for i in range(0,n):
	print("Enter the {} th element of the array:".format(i), end = " ")
	arr.append(input())
	print("Read Element : "+arr[i])
selection_sort_func(arr,n)
