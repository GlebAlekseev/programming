n = int(input())
if n >= 0:
	resultat = 1
	i = 2
	while i <= n:
		resultat = resultat * i
		i +=1
	print(resultat)
else:
	print("n не соответствует условию")
