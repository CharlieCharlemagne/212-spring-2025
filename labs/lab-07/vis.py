import sys
import numpy as np
import matplotlib.pyplot as plt

grid = np.loadtxt(sys.argv[1], dtype=int, delimiter=' ')

cmap = plt.cm.colors.ListedColormap(['white', 'red', 'blue', 'green', 'yellow', 'cyan', 'magenta', 'orange'])

fig, ax = plt.subplots(figsize=(8, 8))
ax.imshow(grid, cmap=cmap)# Add grid lines
ax.set_xticks(np.arange(-.5, grid.shape[1], 1), minor=True)
ax.set_yticks(np.arange(-.5, grid.shape[0], 1), minor=True)
ax.grid(which="minor", color="black", linestyle='-', linewidth=1)
ax.set_xticks([])
ax.set_yticks([])
plt.tight_layout()
plt.show(block=True)