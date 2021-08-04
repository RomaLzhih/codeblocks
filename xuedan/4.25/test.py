import matplotlib.pyplot as plt

# read lines
f = open("./input3.txt")
linenum = 469
lines = f.readlines()
width = 5
x = list(range(linenum))
y = list(range(width))
for i in range(width):
    y[i] = list(range(linenum))

idx = 0
minX = 1e5
maxX = -1e5

for line in lines:
    LineWithoutSpace = line.split()
    x[idx] = float(LineWithoutSpace[0])
    for j in range(width):
        y[j][idx] = float(LineWithoutSpace[j+1])
    idx += 1

nx = list(range(4000, 400, -500))
M = 2198.69
print(nx)

plt.plot(x, y[0], label="ALA/PEO")
plt.plot(x, y[1], label="SDS")
plt.plot(x, y[2], label="ALA/PEO/2%SDS")
plt.plot(x, y[3], label="ALA/PEO/4%SDS")
plt.xticks(nx)
plt.xlabel("Wavenumber ($cm^{-1}$)")
plt.ylabel("Absorbance")
plt.gca().invert_xaxis()
plt.legend()
plt.show()
