'''
Define a class to represent a bank account include following details like name of the depositor, account_number,
account_type, and balance amount in the account write method to assign initial values to deposit amount withdraw amount after checking the balance or to display name, account_type, account_number.
'''

class BankAccount():
	def __init__(self, name, account_number, account_type, balance):
		self.name = name
		self.account_number = account_number
		self.account_type = account_type
		self.balance = balance

	def deposite(self, amount):
		self.balance += amount

	def withdraw(self, amount):
		if self.balance > 0 and self.balance >= amount:
			self.balance -= amount
		else:
			print("Not Enough Balance To Withdraw")

	def showBalance(self):
		print("\
		Name : {} \n \
		Account Type : {} \n \
		Account Number : {} \n \
		Balance : {} \n \
		".format(
			self.name,
			self.account_type,
			self.account_number,
			self.balance
			)
		)

accounts = {}

flag = 0
while flag != 3:
	print("1. Create Account")
	print("2. Already Have Account")
	print("3. Exit")
	flag = int(input("Enter Your Choice : "))
	if flag == 1:
			account_number = int(input("Enter Account Number : "))
			name = str(input("Enter Name : "))
			account_type = input("Enter Account Type : ")
			initial_balance = int(input("Initial balance : "))
			accounts[account_number] = BankAccount(
								name,
								account_number,
								account_type, 
								initial_balance
							)
	elif flag == 2:
		print("1. Deposite")
		print("2. Withdraw")
		print("3. Show Balance")
		print("4. Back")
		flag = int(input("Enter Your Choice : "))

		if flag == 1:
			accounts[int(input("Enter Account Number : "))].deposite(int(input("Enter the amount to deposite : ")))
		elif flag == 2:
			accounts[int(input("Enter Account Number : "))].withdraw(int(input("Enter the amount to withdraw : ")))
		elif flag == 3:
			accounts[int(input("Enter Account Number : "))].showBalance()
			flag = 4
		elif flag == 4:
			pass
		else:
			print("Invalid Input")

	elif flag != 3:
		print("Invalid Input")
