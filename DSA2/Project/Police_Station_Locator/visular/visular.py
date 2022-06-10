import matplotlib.pyplot as plt

x = []
y = []

f = open('../data.txt','r')
n = int(f.readline())
for row in f:
	row = row.split(',')
	
	print(row)	
	
	x.append(int(row[0]))
	y.append(int(row[1]))
		
plt.scatter(x, y)
plt.title('Points')
plt.xlabel('X')
plt.ylabel('Y')

circle1 = plt.Circle((200, 200), 30, color = 'r', fill = False)
plt.gcf().gca().add_patch(circle1)

plt.show()

