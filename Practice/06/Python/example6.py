import math

a = int(input())
b = int(input())
c = int(input())


D = b*b - 4*a*c


if D > 0 and a != 0 and b != 0 and c != 0:
    x1 = (-b + math.sqrt(D)) /(2*a)
    x2 = (-b - math.sqrt(D)) /(2*a)
    print("x1 = " + str(x1) + "\nx2 = " + str(x2))
elif (D == 0 and a != 0 and b != 0 and c != 0):
    x1 = -b / (2 * a)
    print("x1 = " + str(x1))
elif (D < 0 and a != 0 and b != 0 and c != 0):
    print("Нет корней")
elif (a == 0 and b != 0 and c != 0):
    x1 = -c / b
    print("x1 = " + str(x1))
elif (a != 0 and b == 0 and c != 0):
	if (-c / a >= 0):
		x1 = +math.sqrt(-c / a)
		x2 = -math.sqrt(-c / a)
		print("x1 = " + str(x1) + "\nx2 = " + str(x2))
	else:
		print("Нет корней")
elif (a != 0 and b != 0 and c == 0):

    x1 = 0
    x2 = -b / a
    print("x1 = " + str(x1) + "\nx2 = " + str(x2))
elif (a == 0 and b == 0 and c == 0):
    print("x = R")
elif (a == 0 and b != 0 and c == 0):
    x1 = 0
    print( "x1 = " + str(x1))
elif (a == 0 and b == 0 and c != 0):
    if (c == 0):
        print("x = R")
    else:
        print("Нет корней")# c != 0
elif (a != 0 and b == 0 and c == 0):
    x1 = 0
    print( "x1 = " + str(x1))
    


