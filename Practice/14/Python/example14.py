n = int(input())
x = 1
if n>= 0 and n<= 10**15 :
	if (n == 0):
	    y = 0
	else:
	    i=1
	    while i <= n:
	        x = x*2
	        if(x>n):
	            y=i
	            break
	        i +=1
	print(y)
else:
	print("Число не входит в диапазон")