class Person():
	def __init__(self, name, age):
		self.name = name
		self.age = age

	def get_name(self):
		return self.name

	def get_age(self):
		return self.age

	def display(self):
		print("Hello, My Name is : " + self.name)

class Student(Person):
	def __init__(self, name, age, mis, college, year, communiy_name):
		Person.__init__(self, name, age)
		self.mis = mis
		self.year = year
		self.college = college
		self.communiy_name = communiy_name

	def display(self):
		Person.display(self)
		print("I am {} student of {} and MIS is : {} ".format(self.year, self.college, self.mis))
		print("Community is : " + self.get_community())

	def get_mis(self):
		return self.mis

	def get_college(self):
		return self.college

	def get_year(self):
		return self.year

	def get_community(self):
		return self.communiy_name

class Employe(Person):
	def __init__(self, name, age, company, salary, communiy_name):
		Person.__init__(self, name, age)
		self.company = company
		self.salary = salary
		self.communiy_name = communiy_name
		
	def display(self):
		Person.display(self)
		print("Salary {}, Company {} ".format(self.salary, self.company))
		print("Community is : " + self.get_community())


	def get_company(self):
		return self.company

	def get_salary(self):
		return self.salary

	def get_community(self):
		return self.communiy_name

class Community():
	@classmethod
	def as_employe(self, name, age, company, salary, communiy_name):
		return Employe(name, age, company, salary, communiy_name)

	@classmethod
	def as_student(self, name, age, year, mis, collge, communiy_name):
		return Student(name, age, mis, collge, year, communiy_name)


data_of_students = {}
data_of_employee = {}

while True:
	try:
		print("Enter 100 to exit")
		data = str(input("Who Are You (student / employee) ? "))
		if data == "student":
			print("1.Insert")
			print("2.Show")
			print("3.Update")
			choice =  int(input("Select Your Choice "))
			if choice == 1:
				name = str(input("Enter your name : "))
				data_of_students[name] = Community.as_student(
					name, 
					int(input("Enter Your Age  : ")), 
					str(input("Enter Your Year  : ")), 
					int(input("Enter Your MIS  : ")), 
					str(input("Enter Your College Name  : ")), 
					str(input("Enter Your Community Name  : "))
				)
			elif choice == 2:
				data_of_students[str(input("Enter Your Name : "))].display()

			elif choice == 3:
				name = str(input("Enter your name : "))
				data_of_students.pop(name)
				data_of_students[name] = Community.as_student(
					name, 
					int(input("Enter Your Age  : ")), 
					str(input("Enter Your Year  : ")), 
					int(input("Enter Your MIS  : ")), 
					str(input("Enter Your College Name  : ")), 
					str(input("Enter Your Community Name  : "))
				)

			else:
				print("Please Select Proper Choice ..!!!")

		elif data == "employee":
			print("1.Insert")
			print("2.Show")
			print("3.Update")
			choice =  int(input("Select Your Choice "))
			if choice == 1:
				name = str(input("Enter your name : "))
				data_of_employee[name] = Community.as_employe(
					name, 
					int(input("Enter Your Age  : ")), 
					str(input("Enter Your Company  : ")), 
					int(input("Enter Your Salary  : ")), 
					str(input("Enter Your Community Name  : "))
				)
			elif choice == 2:
				data_of_employee[str(input("Enter Your Name : "))].display()
			
			elif choice == 3:
				name = str(input("Enter your name : "))
				data_of_employee.pop(name)
				data_of_employee[name] = Community.as_employe(
					name, 
					int(input("Enter Your Age  : ")), 
					str(input("Enter Your Company  : ")), 
					int(input("Enter Your Salary  : ")), 
					str(input("Enter Your Community Name  : "))
				)

			else:
				print("Please Select Proper Choice ..!!!")

		elif data == "100":
			break

		else:
			print("Please Enter Proper Details ..!!! ")
	except:
		print("Invalid Data Format")
