from abc import ABC, abstractmethod
import math

class Polygon(ABC):
	@abstractmethod
	def set_dimension(self, dimension1, dimension2):
		pass

	@abstractmethod
	def get_dimension(self):
		pass

	@abstractmethod
	def get_area(self):
		pass

class Rectangle(Polygon):
	def __init__(self, length = 0, breath = 0):
		self.length = length
		self.breath = breath

	def set_dimension(self, dimension1, dimension2):
		self.length = dimension1
		self.breath = dimension2

	def get_dimension(self):
		print("Length {} : breath {}".format(self.length, self.breath))

	def get_area(self):
		print("Area Of Reactangle is  : {}".format(self.length * self.breath))

class Triangle(Polygon):
	def __init__(self, base = 0, height = 0):
		self.base = base
		self.height = height

	def set_dimension(self, dimension1, dimension2):
		self.base = dimension1
		self.height = dimension2

	def get_dimension():
		print("Base {} : Height {}".format(self.base, self.height))

	def get_area(self):
		print("Area Of Triangle is  : {}".format(0.5 * self.base * self.height))

while True:
	tri = Triangle()
	rect = Rectangle()

	print()
	sides = int(input("Enter the sides of polygon : "))
	data_sides = []
	while sides > 0:
		data_sides.append(int(input("Enter the sides : ")))
		sides = sides - 1

	if len(data_sides) == 2:
		if data_sides[0] == data_sides[1]:
			print("Square Detected ..!!")
		elif data_sides[0] != data_sides[1]:
			print("rectangle Detected ..!!")
		rect.set_dimension(data_sides[0], data_sides[1])
		rect.get_area()
	elif len(data_sides) == 3:
		print("Triangle Is Detected ..!!")
		dim1 = data_sides[0]
		dim2 = math.sqrt((data_sides[2] * data_sides[2]) - ((data_sides[1] / 2) * (data_sides[1] / 2)))
		tri.set_dimension(dim1, dim2)
		tri.get_area()
	else:
		print("Not Supported ..!!")
