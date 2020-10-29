result = 1;
ex = float(input())
n = int(input())
i=0
if n >= 0: 
	while i < n:
		i += 1
		result = result * ex
else:
	while i < -n:
		i += 1
		result = result * ex
	result = 1/result


print(result)


