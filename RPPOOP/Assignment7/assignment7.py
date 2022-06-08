from tkinter import * 
from tkinter.ttk import *

m = Tk()

l1 = Label(m, text = "First:", background='black')
l2 = Label(m, text = "Second:", background='red')

l1.place(m, x=0, y=0)
l1.place(m, x=100, y=0)

m.mainloop()
