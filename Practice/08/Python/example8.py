x, op, y = map(str, input().split())

if (op == '+'):
    result = float(x) + float(y)
    print(result)
elif (op == '-'):
    result = float(x) - float(y)
    print(result)
elif (op == '*'):
    result = float(x) * float(y)
    print(result)
elif (op == '/'):
    result = float(x) / float(y)
    print(result)
else:
    print("В неверном формате введены данные.")
