import math
num = math.factorial(100)
sum = 0
while(num > 0):
    sum += (num % 10) # get lowest digit
    num //= 10 # integer division to truncate lowest digit
print(sum)
