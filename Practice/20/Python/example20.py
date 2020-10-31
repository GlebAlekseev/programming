moneys = int(input())
dif = int(input())

ydel = []
describe = []
TempUp = []
Name = []
Price = []
Va = []
SumV = 0


i = 0
while i < dif:
    describe.append(input())
    describe[i] = describe[i].split()
    Name.append(describe[i][0])
    Price.append(int(describe[i][1]))
    Va.append(int(describe[i][2]))
    i +=1
i = 0
while i < dif:
	TempYdel = Price[i]/Va[i]
	ydel.append(TempYdel)
	TempUp.append(TempYdel)
	i +=1


TempUp = TempUp.sort()
SumMoney = moneys
TempM = int(10**12)
dTemp = int(10**12)
SumV = 0

i = 0
while i < dif:
	j = 0
	while j < dif:


		if ydel[i] == ydel[j]:
			if SumMoney/Price[i] >= 1:
				if SumMoney - Price[i] * int(moneys/Price[i]) < TempM:
					TempM = SumMoney - Price[i] * int(moneys/Price[i])
					TempJ = j

				if j == dif - 1:
					print(Name[TempJ], end = " ")
					print(int(moneys/Price[TempJ]))
					SumV = SumV + int(Va[TempJ]) * int(moneys/Price[TempJ])
					SumMoney = SumMoney - int(Price[TempJ]) *int(moneys/Price[TempJ])

		if i == dif - 1 and j == dif - 1 and SumV != 0:

			print(SumV)
			print(SumMoney)

		l = 0
		while l < dif:
			if Price[l] < dTemp:
				dTemp = Price[l]
			l +=1
		j += 1
	i +=1
if moneys - dTemp < 0:
	print(-1)