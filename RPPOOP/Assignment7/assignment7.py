from tkinter import * 
from tkinter.ttk import *

m = Tk()

l1 = Label(m, text = "First:")
l2 = Label(m, text = "Second:")
 
l1.configure(background='black')
l2.configure(background='red')
 
l1.grid(row = 0, column = 0, sticky = W, pady = 2)
l2.grid(row = 1, column = 0, sticky = W, pady = 2)

m.mainloop()
