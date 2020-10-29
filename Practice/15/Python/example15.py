import random
i = 1
print("Угадай число от 0-100 у тебя 5 попыток!!!\n")
while (i > 0):
    y = random.randint(1,100)
    z = 0
    while z<5:
        x = int(input())
        if x == y:
            print("Поздравляю! Вы угадали\n")
            break
        elif x < y and z != 4:
            print("Загаданное число больше\n")
        elif x > y and z != 4:
            print("Загаданное число меньше\n")
        elif z == 4:
            print("Вы проиграли. Было загадано: " + str(y) + "\n")
        z +=1
    print("Хотите начать сначала? (1 - ДА )\n")
    status = int(input())
    if status != 1:
        break