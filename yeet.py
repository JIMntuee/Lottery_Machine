#!/usr/bin/python3
import random

L = [1, 1, 4, 2, 5,
     25, 25, 20, 20, 75,
     140, 77, 105]

pool = list()

for i in range(len(L)):
    pool.extend([i+1]*L[i])

while True:
    input()
    print(random.choice(pool))
