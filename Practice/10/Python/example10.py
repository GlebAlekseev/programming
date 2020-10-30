stop = 1
while stop == 1:
	stop = 0
	s, l1, r1, l2, r2 = map(str, input().split())

	if int(s) <= pow(10, 15) and int(s) >= -pow(10, 15) and int(l1) <= pow(10, 15) and int(l1) >= -pow(10, 15) and int(l2) <= pow(10, 15) and int(l2) >= -pow(10, 15) and int(r1) <= pow(10, 15) and int(r1) >= -pow(10, 15) and int(r2) <= pow(10, 15) and int(r2) >= -pow(10, 15):
		s = int(s)
		l1 = int(l1)
		l2 = int(l2)
		r1 = int(r1)
		r2 = int(r2)
		if (l1 <= r1 and l2 <= r2):
		    if (l1 + l2 <= s and r1 + r2 >= s):
		        x2 = s - l1
		        if (x2 - r2 > 0):
		            x1 = l1 + x2 - r2
		            x2 = s - x1
		        else:
		            x1 = l1
		        print(str(x1) + " " + str(x2))

		    else:
		        print(-1)
		else:
		    print("Неверный диапазон")
		    stop = 1
	else:
		print("Числа не входят в диапазон")
		stop = 1