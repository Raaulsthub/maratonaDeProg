# -*- coding: utf-8 -*-

a = int(input())

q = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]


for i in str(a):
    q[int(i)] += 1


most_f = 0
f = 0
iterator = 0

for i in q:
    if i >= f:
        most_f = iterator
        f = i
    iterator += 1

if (a != 0):
    print(most_f)
