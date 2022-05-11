# read from user and add, subtract, multiply, divide, transpose
import numpy as np

print("Enter the rows and cols")
rows, cols = map(int, input().split()) # taking number of rows and column


print("Enter the data for first matrix : ")
mat1 = []

for i in range(rows):
	a =[]
	for j in range(cols):
		a.append(int(input()))
	mat1.append(a)



print("Enter the data for second matrix : ")
mat2 = []
for i in range(rows):
	a =[]
	for j in range(cols):
		a.append(int(input()))
	mat2.append(a)

mat1 = np.array(mat1)
mat2 = np.array(mat2)


print("Addition of Matrix is : ")
print(mat1 + mat2)

print("Subtract of Matrix is : ")
print(mat1 - mat2)

print("Multiply of Matrix is : ")
print(mat1 * mat2)

print("Divide of Matrix is : ")
print(mat1 / mat2)

print("Transpose of Matrix1 is : ")
print(mat1.transpose())

print("Transpose of Matrix2 is : ")
print(mat2.transpose())

