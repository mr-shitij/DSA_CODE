class INVALID_TIME(Exception):
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return repr(self.value)

class TIME:
    def __init__(self):
        self.starting_hr = 0
        self.starting_mi = 0
        self.starting_se = 0
        self.ending_hr = 0
        self.ending_mi = 0
        self.ending_se = 0

    def set_starting_time(self, hr, mi, se):
        self.starting_hr = hr
        self.starting_mi = mi
        self.starting_se = se
        
        


    def set_ending_time(self, hr, mi, se):
        if self.starting_hr > hr:
            raise INVALID_TIME("Invalid Ending Time (HR) .. !!")
        elif self.starting_mi > mi:
            raise INVALID_TIME("Invalid Ending Time (MI) .. !!")
        elif self.starting_se > se:
            raise INVALID_TIME("Invalid Ending Time (SE) .. !!")
        else:
            self.ending_hr = hr
            self.ending_mi = mi
            self.ending_se = se
    
    def display_difference(self):
        print("Difference is -> {} : {} : {}".format(self.starting_hr - self.ending_hr, self.starting_mi - self.ending_mi, self.starting_se - self.ending_se ))

    def starting_time(self):
        print("Starting Time is ->  {} : {} : {}".format(self.starting_hr, self.starting_mi, self.starting_se))
    
    def ending_time(self):
        print("Ending Time is ->  {} : {} : {}".format(self.ending_hr, self.ending_mi, self.ending_se))


while True:
    ti = TIME()

    choice = int(input("\n12 Hour Clock Format .. !! \n1. Enter Starting Time Of Exam \n2.Enter The Ending Time Of The Exam \n3.Display Difference \n4.Display Timing \n5.Exit"))
    if choice == 1:
        ti.set_starting_time(int(input("Hour : ")), int(input("Minutes : ")), int(input("Seconds : ")))
    elif choice == 2:
        try:
            ti.set_ending_time(int(input("Hour : ")), int(input("Minutes : ")), int(input("Seconds : ")))
        except INVALID_TIME as m:
            print("Error : " + repr(m.value))
    elif choice == 3:
        ti.display_difference()
    elif choice == 4:
        ti.starting_time()
        ti.ending_time()
    elif choice == 5:
        break


