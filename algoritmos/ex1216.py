names = []
total_distance = 0
cont = 0

while (True):
    A = str(input())
    if len(A) == 0: break
    names.append(A)
    total_distance += float(input())
    cont += 1

if cont != 0:
    total_distance = total_distance / cont
    total_distance = round(total_distance, 1)

print(total_distance)