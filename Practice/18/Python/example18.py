

dicti = ["hallo, klempner, das, ist, fantastisch, fluggegecheimen"]
word = input()
dicti[0] = dicti[0].replace(" ","")
dicti[0] = dicti[0].replace(",","")
lgth = len(dicti[0])
itog = 1

for a in word:
    itog = itog * dicti[0].count(a)/lgth

print(itog)
