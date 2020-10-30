n = int(input());
pAr = input()
pArra = pAr.split()
i = 0
count = 0
status = 0
while i < n:
	count = 0
	if pArra[i][0] == 'a':
		count +=1
	if pArra[i][4] == '5':
		count +=1
	if pArra[i][5] == '5':
		count +=1
	if pArra[i][6] == '6':
		count +=1
	if pArra[i][7] == '6':
		count +=1
	if pArra[i][8] == '1':
		count +=1
	if count == 6:
		print(pArra[i], end = " ")
		status = 1
	i +=1
if status == 0:
	print(-1)


