import math

status = int(input())
if (status == 1):
    a = int(input())
    b = int(input())
    c = int(input())
    P = (a + b + c) / 2;
    if (P * (P - a) * (P - b) * (P - c) >= 0):
        S = math.sqrt(P * (P - a) * (P - b) * (P - c))
        print("S = " + str(S))
    else:
        print("Неверно указаны стороны треугольника!")
elif(status == 2):
    xA, yA = map(int, input().split())
    xB, yB = map(int, input().split())
    xC, yC = map(int, input().split())
    if ((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB) >= 0 and (xB - xC) * (xB - xC) + (yB - yC) * (yB - yC) >= 0 and (xC - xA) * (xC - xA) + (yC - yA) * (yC - yA) >= 0 ):
        AB = math.sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
        BC = math.sqrt((xB - xC) * (xB - xC) + (yB - yC) * (yB - yC));
        AC = math.sqrt((xC - xA) * (xC - xA) + (yC - yA) * (yC - yA));
        P = (AB + BC + AC) / 2;
        S = math.sqrt(P * (P - AB) * (P - BC) * (P - AC));
        print("S = " + str(S))

    else:
        print("Неверно указаны стороны треугольника!")
elif(status <= 1000 and status > 0):
        print("Ошибочный ввод")
