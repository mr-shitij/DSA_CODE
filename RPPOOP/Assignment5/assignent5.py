import datetime
import time

class INVALID_TYPE(Exception):
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return repr(self.value)

class TIME:
	def __init__(self):
		self.questions = ["Name : ?", "Age : ?", "Height : "]
		self.ans = ["Shitij", 10, 20]
		self.ans_type = ["str", "float" , "float"]

	def start_exam(self):
		self.start = datetime.datetime.now()
		uans = []
		i = 0
		while i < len(self.questions):
			try:
				print(self.questions[i])
				ip = input()
				if ip.isnumeric() and self.ans_type[i] == "float":
					ip = float(ip)
				if type(ip).__name__ != self.ans_type[i]:
					raise INVALID_TYPE("Invalid Input ..!!")
				else:
					if self.ans[i] == ip:
						print("correct ..!!")
					else:
						print("wrong ..!!")
				i = i + 1
			except:
				print("Invallid Input ..!!")
		self.end = datetime.datetime.now()
		print("Start Time in : {}  sec", format(self.start.second))
		print("End Time in : {}  sec", format(self.end.second))
		print("You passed exam in : {}  sec", format((self.end - self.start).total_seconds()))

TIME().start_exam()

