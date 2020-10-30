stop = 1
while stop == 1:
	stop = 0
	h1, m1 = (input().replace(':',' ')).split()
	h1 = int(h1)
	m1 = int(m1)

	if (h1 >= 0 and h1 <= 23 and m1 >= 0 and m1 <= 59):
	    h2, m2 = (input().replace(':',' ')).split()
	    h2 = int(h2)
	    m2 = int(m2)
	    if (h2 >= 0 and h2 <= 23 and m2 >= 0 and m2 <= 59):
	        if (h1 == h2 and abs(m2-m1) <= 15 and abs(m1-m2) <= 15):
	            print("Встреча состоится")
	        elif (h2 - h1 == 1 and ((60 - m1) + m2) <= 15 or h2 - h1 == -1 and ((60 - m2) + m1) <= 15 or h2 - h1 == 23 and ((60 - m2) + m1) <= 15 or h2 - h1 == -23 and ((60 - m1) + m2) <= 15):
	            print("Встреча состоится")
	        else:
	            print("Встреча не состоится")

	    else:
	        print("Неверно указано время 2")
	        stop = 1
	else:
	        print("Неверно указано время 1")
	        stop = 1
