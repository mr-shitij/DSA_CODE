# read from user and add, subtract, multiply, divide, transpose
import numpy as np

print("Enter the rows and cols for 1st matrix")
rows, cols = map(int, input().split()) # taking number of rows and column

print("Enter the data for first matrix : ")
mat1 = []

for i in range(rows):
	a =[]
	for j in range(cols):
		a.append(int(input()))
	mat1.append(a)

mat1 = np.array(mat1)


print("Enter the rows and cols for random matrix")
rows, cols = map(int, input().split()) # taking number of rows and column

print("Enter the data for second matrix : ")
mat2 = np.random.random((rows, cols))

while(1):
	print("1. Addition")
	print("2. Subtract")
	print("3. Multiply")
	print("4. Divide")
	print("5. Transpose")
	data = int(input("Enter Your Choice : "))
	if data == 1:
		print("Addition of Matrix is : ")
		print(mat1 + mat2)
	elif data == 2:
		print("Subtract of Matrix is : ")
		print(mat1 - mat2)

	elif data == 3:
		print("Multiply of Matrix is : ")
		print(mat1 * mat2)

	elif data == 4:
		print("Divide of Matrix is : ")
		print(mat1 / mat2)

	elif data == 5:
		print("Transpose of Matrix1 is : ")
		print(mat1.transpose())

		print("Transpose of Matrix2 is : ")
		print(mat2.transpose())

