class Person():
	def __init__(self, name, age):
		self.name = name
		self.age = age

	def display(self):
		print("Hello, My Name is : " + self.name)

class Student(Person):
	def __init__(self, name, age, mis, college, year, communiy_name = ""):
		Person.__init__(self, name, age)
		self.mis = mis
		self.year = year
		self.college = college

	def display(self):
		Person.display(self)
		print("I am {} student of {} and MIS is : {} ".format(self.year, self.college, self.mis))

class Employe(Person):
	def __init__(self, name, age, company, salary, communiy_name = ""):
		Person.__init__(self, name, age)
		self.company = company
		self.salary = salary
		
	def display(self):
		Person.display(self)
		print("Salary {}, Company {} ".format(self.salary, self.company))

class Community():
	@classmethod
	def as_employe(self, name, age, company, salary, communiy_name):
		return Employe(name, age, company, salary, communiy_name)

	@classmethod
	def as_student(self, name, age, year, mis, collge, communiy_name):
		return Student(name, age, mis, collge, year, communiy_name)


e1 = Community.as_employe("Person1_Employee", 19, "Something", 100000, "COMP_PANY")
e1.display()

e2 = Community.as_student("Person2_Student", 19, "SY", 142103007, "COEP", "COEP")
e2.display()

