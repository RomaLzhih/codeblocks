import matplotlib.pyplot as plt

# read lines
f = open("./res4-5-2.txt")
lines = f.readlines()
x = list(range(len(lines)))
y = list(range(len(lines)))
idx = 0
for line in lines:
    LineWithoutSpace = line.split()
    x[idx] = int(LineWithoutSpace[0])
    y[idx] = int(LineWithoutSpace[1])
    idx += 1

step = x[1]-x[0]
nx = list(map(lambda X: X+step/2, x))
# begin to plot
plt.bar(nx, y, 45, label="ALA/PEO/4%SDS")
plt.xlabel("fiber diameter $d$ (nm)")
plt.ylabel("relative derivation $\lambda$ (%)")
plt.xticks(list(range(min(x), max(x)+step, 50)))
plt.legend()
plt.text(1235, 22.5, '$\langle d\\rangle = 672.351\pm 126.373$',
         bbox=dict(facecolor='yellow', alpha=0.5), fontsize=10)
plt.show()
