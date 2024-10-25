import math
num = int(2 ** 1000)
sum = 0
while(num > 0):
    sum += (num % 10) # get lowest digit
    num //= 10 # integer division to truncate lowest digit
print(sum)
