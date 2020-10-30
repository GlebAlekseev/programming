moneys = int(input())
dif = int(input())

ydel = []
describe = []
TempUp = []
i = 0
while i < dif:
    describe.append(input())
    describe[i] = describe[i].split()

    i +=1

i = 0
while i < dif:
	TempYdel = int(describe[i][2])/int(intdescribe[i][1])
	ydel[i] = str(TempYdel)
	TempUp[i] = describe[i][2]/describe[i][1]
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
        if TempUp[i] == ydel[j]:
            if SumMoney/describe[j][2] >= 1:
                if SumMoney - describe[j][2] * int(moneys/describe[j][2]) < TempM:
                    
                    TempM = SumMoney - describe[j][2] * int(moneys/describe[j][2])
                    TempJ = j

                if j == dif - 1:
                    print(describe[TempJ][0], end = " ")
                    print(int(moneys/describe[TempJ][2]), end = " ")
                    SumV = SumV + describe[TempJ][1] * int(moneys/describe[TempJ][2])
                    SumMoney = SumMoney - describe[TempJ][2] *int(moneys/describe[TempJ][2])
        if i == dif - 1 and j == dif - 1 and SumV != 0:
            print(Sumv)
            print(SumMoney)

        j += 1


        for l in dif:
            if describe[l][2] < dTemp:
                dTemp = describe[l][2]
        if moneys - dTemp < 0:
            print(-1)



    i += 1

#     for (int i = 0; i < dif; i++) {
#         for (int j = 0; j < dif; j++) {

#             if (TempUP[i] == ydelF[j]) {

#                 if (SumMoney / Price[j] >= 1) {
#                     if (SumMoney - Price[j] * int(moneys / Price[j]) < TempM) {

#                         TempM = SumMoney - Price[j] * int(moneys / Price[j]);
#                         Tempj = j;
#                     }

#                     if (j == dif - 1) {

#                         cout << Name[Tempj];
#                         cout << " " << int(moneys / Price[Tempj]) << endl;
#                         SumV = SumV + V[Tempj] * int(moneys / Price[Tempj]);
#                         SumMoney = SumMoney - Price[Tempj] * int(moneys / Price[Tempj]);
#                     }
#                 }
#             }

#             if (i == dif - 1 && j == dif - 1 && SumV != 0) {

#                 cout << SumV << endl;
#                 cout << SumMoney << endl;
#             }
#         }
#     }
#     //
#     for (int i = 0; i < dif; i++) {
#         if (Price[i] < dTemp) { dTemp = Price[i]; }
#     }
#     if (moneys - dTemp < 0) {
#         cout << "-1";
#     }
