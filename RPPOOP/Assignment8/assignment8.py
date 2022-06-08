from tkinter import * 
from tkinter.ttk import *


def sele():
	print("SELECTED")

m = Tk()

menubar = Menu(m)

file = Menu(menubar, tearoff = 0)
file.add_command(label ='New File', command = sele)
file.add_command(label ='Open File', command = None)
file.add_command(label ='Exit', command = exit)
menubar.add_cascade(label ='File', menu = file)


view = Menu(menubar, tearoff = 0)
view.add_command(label ='Small View', command = None)
view.add_command(label ='Big View', command = None)
menubar.add_cascade(label ='View', menu = view)


m.config(menu = menubar)
m.mainloop()

