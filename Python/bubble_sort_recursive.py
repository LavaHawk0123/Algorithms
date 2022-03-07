import math
import time

class Bubble_Sort_Recursion:

    # Constructor to assign array and its length
    def __init__(self, array):
        self.array = array
        self.length = len(array)

    # Function to display elements of array as a string
    def __str__(self):
        str_arr = "".join([str(x) for x in self.array])
        return str_arr
    
    # Function to print elements of the array
    def print_array(self):
        for i in range(self.length):
            print(self.array[i],end=" ")    

    def bubble_sort_recursive_func(self,n = None):
        # Resolution of function calls without n
        if n==None:
            n = self.length
        # Base Case for Recursion
        if n==1:
            return 
        # Loop to traverse the array
        for i in range(n-1):
            if self.array[i]>self.array[i+1]:
                self.array[i],self.array[i+1] = self.array[i+1],self.array[i]       # Swapping of bigger and smaller elements
        # Recursive Function Call
        self.bubble_sort_recursive_func(n-1)

# Driver Function for Bubble_Sort_Recursion class
def driver():
    print("------- Bubble Sort ------")
    print("Enter the nummber of elements :")
    n = int(input())
    arr =[]
    for i in range(0,n):
        print("Enter the {} th element of the array:".format(i), end = " ")
        arr.append(input())
        print("Read Element : "+arr[i])
    bub = Bubble_Sort_Recursion(arr)
    bub.bubble_sort_recursive_func()
    print("Sorted array is :")
    bub.print_array()

# Ensures driver only executes once
if __name__ == "__main__":
    driver()
