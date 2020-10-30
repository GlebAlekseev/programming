
stop = 1
while stop == 1:
	stop = 0
	n = int(input())
	resultat = 1
	i = 2
	while i <= n:
		resultat = resultat * i
		i +=1

	if resultat >= 1 and resultat <= 10**9:
		print(resultat)
	else:
		print("Факториал не входит в диапазон")
		stop = 1
