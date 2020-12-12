def print_factorization(n:int)->None:
    nums = []
    a=n
    go = True
    i = 1
    if a != 1:
        i +=1
    while go:
        if a % i == 0:
            nums.append(i)
            a = a/i
        else:
            i +=1
        if a==1:
            break
    count = 1
    templast = -1000
    zvezd = 0
    j = 0
    while j<len(nums)-1:
        if nums[j]==nums[j+1]:
            if j == 0:
                zvezd = 1
            count +=1
        if count != 1 and nums[j] != nums[j+1] or j == len(nums)-2 and nums[j] == nums[j+1]:
            if zvezd:
                print(nums[j],"^",count,sep='',end='')
                zvezd = 0
            else:
                print("*",nums[j],"^",count,sep='',end='')
            count = 1
        if templast != nums[j] and nums[j] !=nums[j+1] and j != 0:
            print("*",nums[j],sep='',end='')
        if nums[j] != nums[j+1] and j == 0:
            print(nums[j],sep='',end='')
        if nums[j] != nums[j+1] and j == len(nums)-2:
            print("*",nums[j+1],sep='',end='')
        templast = nums[j]
        j +=1
n = int(input())
print_factorization(n)