import math
import random
arr = []
n = int(input()) # Ввод n
z = abs(n)
if float(z**0.5) - int(z**0.5) == 0 and n <= 100 and n >= 4: # Проверка условия n
	arr = list(input().split()) # Вводим одномерный массив кол-во элементов n # первый тип
	# получение трех вариаций данных 
	#Преобразовать одномерный список в двумерный список
	matarrx = []
	p = int(n**0.5)
	for i in range(p):
		matarrx.append(arr[i*p:i*p+p]) #Список из списков
	ar0 = arr[0]#Третий тип
	ar1 = arr[1]
	ar2 = arr[2]
	# Нужна функция которая берет три вариации данных
	# и возвращает один список уже отсортированных значений
	# Так же имеется парамтер сортровки
	def BozoSort(mylist,b=None,c= None, asc = True):
		last_arr = []
		# Формирование обработочного списка
		if b != None and c != None:
			last_arr.append(mylist)
			last_arr.append(b)
			last_arr.append(c)
			#Выполняется формирование списка из трех чисел
		elif type(mylist[0]) == list:
			for row in mylist:
				for minirow in row:
					last_arr.append(minirow)
		else:
			last_arr = mylist[:]
			#Выполняется формирование списка из списка из списков
		#Обработка last_arr
		go = True
		while go:
			go = False
			#Получаем 2 рандомных порядковых числа, в диапазоне от 0 до размера last_arr
			randa1 = random.randrange(0,len(last_arr))
			randa2 = random.randrange(0,len(last_arr))
			# Произоводим Change 
			temp = last_arr[randa1]
			last_arr[randa1] = last_arr[randa2]
			last_arr[randa2] = temp
			#Цикл по каждому элементу в целях проверки сортировки
			k = 1
			while k < len(last_arr):
				if asc == True:
					if int(last_arr[k-1]) > int(last_arr[k]):
						go = True
				else:
					if int(last_arr[k-1]) < int(last_arr[k]):
						go = True
				k +=1
		return last_arr
	def printelems(lastlist):
		for x in lastlist:
			print(x,end = " ")
		print()
	printelems(BozoSort(arr,asc = True))
	printelems(BozoSort(arr,asc = False))
	printelems(BozoSort(matarrx,asc = True))
	printelems(BozoSort(matarrx,asc = False))
	printelems(BozoSort(ar0,ar1,ar2,asc = True))
	printelems(BozoSort(ar0,ar1,ar2,asc = False))
else:
	print("n не подходит условию") # не соответствует n условию
