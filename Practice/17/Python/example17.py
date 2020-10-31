numerics = []
numerics.append(37)
i = 0
tempN = 0
sk = 1
Numbers = [ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 ]
Lastlist = []
while 1>0:
	num = int(input())
	if num >= -36 and num <=36:
		if num >= 0:
			numerics.append(num)
			numerics.sort()

			j = 0
			while j <= i:

				if numerics.count(numerics[j]) >= tempN:
					tempN = numerics.count(numerics[j])
				j +=1
			v = 0

			while v < i+1:
				# 1 37
				# 1 2 37
				# 1 2 3 37
				# 1 2 3 3 37
				# 1 2 3 3 4 37
				# 1 2 3 3 4 5 37
				# 2
				if numerics[v] == numerics[v+1]:
					sk = sk +1
				else:
					sk = 1
				if sk == tempN:
					print(numerics[v], end = " ")
				v +=1

			# 
			Lastlist.append(num)
			if i >= 12:
				Lastlist.reverse()
				Lastlist.pop()
				Lastlist.reverse()
			print()
			u = 0
			while u < len(Numbers):
				what = 0
				if i>= 12:
					r = 0
					while r< 12:
						if Numbers[u] == Lastlist[r]:
							what = 1
						r +=1
				else:
					r = 0
					while r< len(Lastlist):
						if Numbers[u] == Lastlist[r]:
							what = 1
						r+=1
				if what == 1:
					u +=1
					continue
				print(Numbers[u], end = " ")
				u +=1
			print()
# 		

			red = 0
			black = 0
			dg = 0
			while dg < len(Lastlist):
				if Lastlist[dg] == 0:
					s = 0
				elif Lastlist[dg] % 2 == 0:
					black = black + 1
				else: 
					red = red + 1

				dg +=1
			print(red,black)

		else:
			break
		print()
	else:
		print("Число не входит в диапазон от -36 до 36.")
	i +=1