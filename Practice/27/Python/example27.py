def sortdsc(array):
	n = len(array)
	i = 1
	while i < n:
		r = 0
		while r < n-i:
			if int(array[r])<int(array[r+1]):
				temp = array[r]
				array[r] = array[r+1]
				array[r+1] = temp
			r +=1
		i +=1
last_nums = []
n = int(input())
arr = []
if n > 1 and n <= 100000:
	go = 1
	arr = list(input().split())
	for x in arr:
		if abs(int(x)) > 10**6 :
			go = 0
	if go == 1:
		j = 0
		while j<n:
			start = 1
			if len(last_nums) < 5:
				last_nums.append(arr[j])
				start = 0
			if len(last_nums) == 5 and start == 1:
				p = 0
				while p<5:
					if int(arr[j])<=int(last_nums[p]):
						last_nums[p] = arr[j]
						break
					p +=1
			sortdsc(last_nums)
			for x in last_nums:
				print(x,end= " ")
			print()
			j +=1
	else:
		print("Не соответствует условию")
else:
	print("Не соответствует условию")