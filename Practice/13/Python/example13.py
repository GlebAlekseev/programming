n = int(input())
if (n >= 2 and n <= 10**9):
    resultat = 0
    i = 2
    while i<10:
        if n%i == 0:
            resultat = 1
        i +=1
    if (resultat and n != 2 and n != 3 and n != 5 and n != 7):
        print("Составное")
    else:
        print("Простое")
else:
    print("Число n не соответствует условию")