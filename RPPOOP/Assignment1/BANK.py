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

	def get_name(self):
		return self.name

	def get_balance(self):
		return self.balance

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
	try:
		print("\n\n1. Create Account")
		print("2. Already Have Account")
		print("3. Exit")
		flag = int(input("Enter Your Choice : "))
		if flag == 1:
				account_number = int(input("\nEnter Account Number : "))
				name = str(input("Enter Name : "))
				print("Choose Account Type : ")
				print("1. Savings")
				print("2. Current")
				_type = int(input(""))
				if _type == 1 : 
					account_type = "Savings"
				elif _type == 2:
					account_type = "Current"
				else:
					continue

				initial_balance = int(input("\nInitial balance : "))
				accounts[account_number] = BankAccount(
									name,
									account_number,
									account_type, 
									initial_balance
								)
		elif flag == 2:
			account_number = int(input("\nEnter Account Number : "))
			print("Welcome {} Your Avaliable Balance is {}"
					.format(accounts[account_number].get_name(), accounts[account_number].get_balance()))

			print("1. Deposite")
			print("2. Withdraw")
			print("3. Show Balance")
			print("4. Back")
			flag = int(input("Enter Your Choice : "))

			if flag == 1:
				accounts[account_number].deposite(int(input("Enter the amount to deposite : ")))
			elif flag == 2:
				accounts[account_number].withdraw(int(input("Enter the amount to withdraw : ")))
			elif flag == 3:
				accounts[account_number].showBalance()
				flag = 4
			elif flag == 4:
				pass
			else:
				print("Invalid Input")

		elif flag != 3:
			print("Invalid Input")
	except ValueError:
		print("Please Input Data At The Inputs")
