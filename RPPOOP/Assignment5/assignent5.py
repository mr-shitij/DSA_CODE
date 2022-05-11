import datetime

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
		for i in range(len(self.questions)):
			print(self.questions[i])
			ip = input()
			if self.ans_type[i] == "float":
				ip = float(ip)
			if type(ip).__name__ != self.ans_type[i]:
				raise INVALID_TYPE("Invalid Input ..!!")
			else:
				if self.ans[i] == ip:
					print("correct ..!!")
				else:
					print("wrong ..!!")

		self.end = datetime.datetime.now()
		print("You passed exam in : {}  sec", format((self.end - self.start).total_seconds()))

TIME().start_exam()

