
stop = 1

while stop == 1:
	stop = 0
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
		if int(y) == 0:
			print("Знаменатель не может быть равен 0")
			stop = 1
		else:
		    result = float(x) / float(y)
		    print(result)
	else:
	    print("В неверном формате введены данные.")
