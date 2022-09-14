# -*- coding: utf-8 -*-

a = int(input())

q = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]


for i in str(a):
    q[int(i)] += 1

print(q)

most_f = 0
f = 0
iterator = 0

for i in q:
    if i >= f:
        most_f = iterator
        f = i
    iterator += 1

print(most_f)