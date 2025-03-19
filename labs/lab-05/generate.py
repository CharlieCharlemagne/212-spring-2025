import sys
import random

n = int(sys.argv[1])
seq = [random.randint(-2**30, 2**30) for _ in range(n)]
print(' '.join(map(str,seq)))
