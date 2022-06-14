'''

python3 visular.py filename pointX pointY radius

'''

import sys
import matplotlib.pyplot as plt

plt.axis("equal")

x = []
y = []

f = open(sys.argv[1], 'r')
n = int(f.readline())
for row in f:
	row = row.split(',')
	
	x.append(int(row[0]))
	y.append(int(row[1]))
		
plt.scatter(x, y)
plt.title('Points')
plt.xlabel('X')
plt.ylabel('Y')

for i in range(len(x)):
	plt.annotate(" {} : {}".format(x[i], y[i]), (x[i], y[i]))

circle1 = plt.Circle((int(sys.argv[2]), int(sys.argv[3])), int(sys.argv[4]), color = 'r', fill = False)
plt.gcf().gca().add_patch(circle1)

circle2 = plt.Circle((int(sys.argv[2]), int(sys.argv[3])), 2, color = 'b', fill = True)
plt.gcf().gca().add_patch(circle2)

plt.show()

