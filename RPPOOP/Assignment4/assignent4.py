from abc import ABC, abstractmethod

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

    select = int(input("\n1.Area Of Triangle \n 2. Area Of Rectangle \n 3. Exit \n Enter Your Choice : "))
    if select == 1:
        dim1 = float(input("Enter the Base : "))
        dim2 = float(input("Enter the Height : "))
        tri.set_dimension(dim1, dim2)
        tri.get_area()
        pass
    elif select == 2:
        dim1 = float(input("Enter the Length : "))
        dim2 = float(input("Enter the Breath : "))
        rect.set_dimension(dim1, dim2)
        rect.get_area()
        pass
    elif select == 3:
        break

