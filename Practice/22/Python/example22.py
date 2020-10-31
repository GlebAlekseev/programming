


def Completion( x:list,  y:list,  array:list):
	lgth = len(x)
	i = 0
	while i < lgth:
		if (array[y[i]][x[i] + 1] != '#' and array[y[i]][x[i] + 1] != '1' and array[y[i]][x[i] + 1] != 'A' and array[y[i]][x[i] + 1] != 'B' and array[y[i]][x[i] + 1] != 'C' and array[y[i]][x[i] + 1] != 'D' and array[y[i]][x[i] + 1] != 'E' and array[y[i]][x[i] + 1] != 'F'):
			x.append(x[i] + 1)
			y.append(y[i])
			array[y[i]][x[i] + 1] = '1'

		

		if (array[y[i]][x[i] - 1] != '#' and array[y[i]][x[i] - 1] != '1' and array[y[i]][x[i] - 1] != 'A' and array[y[i]][x[i] - 1] != 'B' and array[y[i]][x[i] - 1] != 'C' and array[y[i]][x[i] - 1] != 'D' and array[y[i]][x[i] - 1] != 'E' and array[y[i]][x[i] - 1] != 'F'):
			x.append(x[i] - 1)
			y.append(y[i])
			array[y[i]][x[i] - 1] = '1'

		
		if (array[y[i] + 1][x[i]] != '#' and array[y[i] + 1][x[i]] != '1' and array[y[i] + 1][x[i]] != 'A' and array[y[i] + 1][x[i]] != 'B' and array[y[i] + 1][x[i]] != 'C' and array[y[i] + 1][x[i]] != 'D' and array[y[i] + 1][x[i]] != 'E' and array[y[i] + 1][x[i]] != 'F'):
			x.append(x[i])
			y.append(y[i] + 1)
			array[y[i] + 1][x[i]] = '1'

		if (array[y[i] - 1][x[i]] != '#' and array[y[i] - 1][x[i]] != '1' and array[y[i] - 1][x[i]] != 'A' and array[y[i] - 1][x[i]] != 'B' and array[y[i] - 1][x[i]] != 'C' and array[y[i] - 1][x[i]] != 'D' and array[y[i] - 1][x[i]] != 'E' and array[y[i] - 1][x[i]] != 'F'):
			x.append(x[i])
			y.append(y[i] - 1)
			array[y[i] - 1][x[i]] = '1'


		i +=1


	x.reverse()
	k = 0
	while k < lgth:
		x.pop()
		k +=1
	x.reverse()

	y.reverse()
	k = 0
	while k < lgth:
		y.pop()
		k += 1
	y.reverse()


	print()
	print()
	if len(x) != 0:
		Completion(x, y, array)
	
maze = [
    "####B######################",
    "# #       #   #      #    #",
    "# # # ###### #### ####### #",
    "# # # #       #   #       #",
    "#   # # ######### # ##### #",
    "# # # #   #       #     # #",
    "### ### ### ############# #",
    "# #   #     # #           #",
    "# # #   ####### ###########",
    "# # # #       # #         C",
    "# # ##### ### # # ####### #",
    "# # #     ### # #       # #",
    "#   ##### ### # ######### #",
    "######### ### #           #",
    "# ####### ### #############",
    "A           #   ###   #   #",
    "# ############# ### # # # #",
    "# ###       # # ### # # # #",
    "# ######### # # ### # # # F",
    "#       ### # #     # # # #",
    "# ######### # ##### # # # #",
    "# #######   #       #   # #",
    "# ####### ######### #######",
    "#         #########       #",
    "#######E############D######"
]

x,y =map(str, input().split())
x = int(x)
y = int(y)
i = 0
while i < len(maze):
	Temp = maze[i]
	Temp = list(Temp)
	maze[i] = Temp
	i +=1

if x < 27 and y < 25:
	if maze[y][x] != "#":
		maze[y][x] = '#'
		coordX = []
		coordX.append(x)
		coordY = []
		coordY.append(y)
		Completion(coordX, coordY, maze)

		status = 0
		r = 0
		while  r < 25:
			g = 0
			while g < 27:
				if (maze[r][g] == 'A' and maze[r][g + 1] == '1') :
					print("A ")
					status = 1

				if (maze[r][g] == 'B' and maze[r + 1][g] == '1') :
					print("B ")
					status = 1
					
				if (maze[r][g] == 'C' and maze[r][g - 1] == '1') :
					print("C ")
					status = 1

				if (maze[r][g] == 'D' and maze[r - 1][g] == '1') :
					print("D ")
					status = 1
					
				if (maze[r][g] == 'E' and maze[r - 1][g] == '1') :
					print("E ")
					status = 1

				if (maze[r][g] == 'F' and maze[r][g - 1] == '1') :
					print("F ")
					status = 1
					

				g +=1
			r +=1
		if status == 0 :
			print("Выхода нет")
			

		
	else :
		print("Не верные координаты")

	
else :
	print("Не верные координаты")
