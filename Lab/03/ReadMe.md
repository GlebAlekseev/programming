

<p align="center">МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<h3 align="center">Отчёт по лабораторной работе № 3<br> по дисциплине "Программирование"</h3>
<br><br>
<p>студента 1 курса группы ИВТ-б-о-201(1)<br>
Задорожного Глеба Алексеевича<br>
направления подготовки 09.03.01 "Информатика и вычислительная техника"</p>
<br><br>
<table>
<tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br><br>
<p align="center">Симферополь, 2020</p>
<hr>

## <p align="center">Лабораторная работа №3 Игра "Lines"
## Цель: 
1. Закрепить навыки разработки программ с простым графическим интерфейсом пользователя на языке Python при помощи библиотеки Tkinter;
2. Получить представление о разработке простых игровых приложений.

## Постановка задачи

1. Используя стандартный модуль для разработки программ с графическим интерфейсом Tkinter реализуйте игру Lines на зыке Python.
2. В качестве образца графического интерфейса используйте [данную игру](http://game-shariki.ru/linii-2).

## Ход работы
В ходе выполнения лабораторной работы использовал образец [этой](http://game-shariki.ru/linii-2) игры.<br>
Для реализации игры изучил необходимые библиотеки: Tkinter для построения интерфейса, Pillow для работы с картинками.<br>
На рисунке 1 представлен скриншот демонстрирующий интерфейс приложения в процессе игры.
<br><br>
<div align="center"><img src="./image/pic_1.jpg"></div><br>
<p align="center">Рис.1 Скриншот демонстрирующий интерфейс приложения в процессе игры</p>
<br><br>

<br>
Полный исходный код клиентского приложения;<br>

```python

from tkinter import *
from PIL import ImageTk
from PIL import Image
from random import shuffle
from random import randint
import time
import copy
root = Tk()
buffercolors = []# инициализация списков для генерация цветов
buffercolorsex = []
colorpath = ['images/ball-aqua.png','images/ball-blue.png',
            'images/ball-green.png','images/ball-pink.png',
            'images/ball-red.png','images/ball-violet.png','images/ball-yellow.png'] # пути для картинок

rowcol_out = []
status_mode_end = 0#  0 - игра идет, 1 - игра окончена
light_last = [] # список для сохранения последнего подсвеченного шара (координат)
SCORE = 0 # Счет
def initz(event): # Функци Инициализация игры
    global status_mode_end,SCORE
    status_mode_end = 0
    SCORE = 0
    pole.clear()
    for row in range(9):# построения поля из 8, 8 - пустая клетка
        pole.append([])
        for col in range(9):
            pole[row].append(8)
    bg = PhotoImage(file="images/page-bgr.png") # получение картинки фона
    cs = Canvas(width=90, height=30,highlightthickness=0)
    cs.create_image(45, 10, image=bg)
    cs.image = bg#  иначе картинка не будет*
    lab = cs.create_text(45, 10, text="Счет: 0", fill="White",font='MicrosoftSansSerif 17')
    cs.place(x=685,y=100)
    print_pole_back()
    addballs(1)
    cellbgr_image = Image.open("images/page-bgr.png").convert('RGBA')# ячейка
    bg_l = ImageTk.PhotoImage(cellbgr_image.crop((1, 0, 67, 66)).resize((170,40), Image.ANTIALIAS))# вырез темную часть
    clast = Canvas(width=170, height=40,highlightthickness=0)
    clast.create_image(85, 20, image=bg_l)
    lab = clast.create_text(85, 30, text="", fill="#FFFFFF",font='MicrosoftSansSerif 17')
    clast.image = bg_l
    clast.place(x=685,y=400)# размещение по абсолютным координатам 

def dellight(col,row):# функция удаления подсветки фона шара
    if pole[row][col] != 8:
        cellbgr_image = Image.open("images/cell-bgr.png").convert('RGBA')# ячейка
        bgrimgz = cellbgr_image.crop((1, 0, 67, 66)).resize((60, 60), Image.ANTIALIAS)
        pic_size_same_as_bgr1 = Image.new("RGBA", bgrimgz.size)
        pic_size_same_as_bgr1.paste(images_balls[pole[row][col]][6], (3,3))
        ball_over_bgr1 = Image.alpha_composite(bgrimgz, pic_size_same_as_bgr1)
        img_ball_cell1 = ImageTk.PhotoImage(ball_over_bgr1)# получение шара на поле
        lbl_ball_plate1 = Label(root, image=img_ball_cell1,borderwidth=0)
        lbl_ball_plate1.bind("<Button-1>", lambda event: Click(event))
        lbl_ball_plate1.image = img_ball_cell1
        lbl_ball_plate1.pos_r = col
        lbl_ball_plate1.pos_l = row
        lbl_ball_plate1.imgparentball = images_balls[pole[row][col]][6]
        lbl_ball_plate1.place(x=65*col+50,y=65*row+30) 
        rowcol_out[:].clear()


def addballs (event):# функция добавления шаров на поле
    global status_mode_end
    if len(buffercolors) == 0: # проверка на случай инициализации
        buffercolorsex = list(range(0, 7))
        buffercolors[:] =list(range(0, 7))
        buffercolors.extend(buffercolorsex)
        shuffle(buffercolors) # 0 1 2 Это буфер 3 цветов, отобразить
    status_much = 0
    for x in pole:# счетчик свободных ячеек
        for inx in x:
            if inx == 8:
                status_much += 1
    cellbgr_image = Image.open("images/cell-bgr.png").convert('RGBA')# ячейка
    bgrimgz = cellbgr_image.crop((1, 0, 67, 66)).resize((60, 60), Image.ANTIALIAS)
    if status_much == 0:# если конец(нет пустых ячеек) не выполнять код ниже
        return
    if status_much > 0:# если есть место для 1 шара и более
        while True: # получение координат рандомной пустой ячейки (анти-повторение ниже)
            pos1_l = randint(0, 8)
            pos1_r = randint(0, 8)
            if pole[pos1_l][pos1_r] == 8:
                break
        if status_much < 4:# выполняется если это последний ход добавления
            status_mode_end = 1
            cellbgr_image = Image.open("images/page-bgr.png").convert('RGBA')# ячейка
            bg_l = ImageTk.PhotoImage(cellbgr_image.crop((1, 0, 67, 66)).resize((170,40), Image.ANTIALIAS))
            clast = Canvas(width=170, height=40,highlightthickness=0)
            clast.create_image(85, 20, image=bg_l)
            lab = clast.create_text(85, 30, text="Всё, проиграли!", fill="#FFFFFF",font='MicrosoftSansSerif 17')
            SCORE = 0
            clast.image = bg_l
            clast.place(x=685,y=400)
        pole[pos1_l][pos1_r] = buffercolors[0]
        pic_size_same_as_bgr1 = Image.new("RGBA", bgrimgz.size)
        pic_size_same_as_bgr1.paste(images_balls[buffercolors[0]][6], (3,3)) 
        ball_over_bgr1 = Image.alpha_composite(bgrimgz, pic_size_same_as_bgr1)
        img_ball_cell1 = ImageTk.PhotoImage(ball_over_bgr1)
        lbl_ball_plate1 = Label(root, image=img_ball_cell1,borderwidth=0)
        lbl_ball_plate1.bind("<Button-1>", lambda event: Click(event))
        lbl_ball_plate1.image = img_ball_cell1
        lbl_ball_plate1.pos_r = pos1_r
        lbl_ball_plate1.pos_l = pos1_l
        lbl_ball_plate1.cellbgr_image = cellbgr_image
        lbl_ball_plate1.imgparentball = images_balls[buffercolors[0]][6]
        lbl_ball_plate1.place(x=65*pos1_r+50,y=65*pos1_l+30)


    if status_much >1:#  если пустых ячеек более 2-ух
        while True:
            pos2_l = randint(0, 8)
            pos2_r = randint(0, 8)
            if pole[pos2_l][pos2_r] == 8 and (pos1_r != pos2_r or pos1_l != pos2_l):
                break
        pole[pos2_l][pos2_r] = buffercolors[1]
        pic_size_same_as_bgr2 = Image.new("RGBA", bgrimgz.size)
        pic_size_same_as_bgr2.paste(images_balls[buffercolors[1]][6], (3,3))
        ball_over_bgr2 = Image.alpha_composite(bgrimgz, pic_size_same_as_bgr2)
        img_ball_cell2 = ImageTk.PhotoImage(ball_over_bgr2)
        lbl_ball_plate2 = Label(root, image=img_ball_cell2,borderwidth=0)
        lbl_ball_plate2.bind("<Button-1>", lambda event: Click(event))
        lbl_ball_plate2.image = img_ball_cell2
        lbl_ball_plate2.pos_r = pos2_r
        lbl_ball_plate2.pos_l = pos2_l
        lbl_ball_plate2.cellbgr_image = cellbgr_image
        lbl_ball_plate2.imgparentball = images_balls[buffercolors[1]][6]
        lbl_ball_plate2.place(x=65*pos2_r+50,y=65*pos2_l+30) 


    if status_much > 2:# если пустых ячеек более 3-ех
        while True:
            pos3_l = randint(0, 8)
            pos3_r = randint(0, 8)
            if pole[pos3_l][pos3_r] == 8 and ((pos3_r != pos2_r or pos3_l != pos2_l)  and (pos3_r != pos1_r or pos3_l != pos1_l)):
                break
        pole[pos3_l][pos3_r] = buffercolors[2]
        pic_size_same_as_bgr3 = Image.new("RGBA", bgrimgz.size)
        pic_size_same_as_bgr3.paste(images_balls[buffercolors[2]][6], (3,3)) 
        ball_over_bgr3 = Image.alpha_composite(bgrimgz, pic_size_same_as_bgr3)
        img_ball_cell3 = ImageTk.PhotoImage(ball_over_bgr3)
        lbl_ball_plate3 = Label(root, image=img_ball_cell3,borderwidth=0)
        lbl_ball_plate3.bind("<Button-1>", lambda event: Click(event))
        lbl_ball_plate3.image = img_ball_cell3
        lbl_ball_plate3.pos_r = pos3_r
        lbl_ball_plate3.pos_l = pos3_l
        lbl_ball_plate3.cellbgr_image = cellbgr_image
        lbl_ball_plate3.imgparentball = images_balls[buffercolors[2]][6]
        lbl_ball_plate3.place(x=65*pos3_r+50,y=65*pos3_l+30)  #sticky="NSEW",

    if status_mode_end != 1:# если не финал добавления подсказки, иначе ошибка, отсутствие рандомных шаров
        delneedline()# удаление возможных линий
        shuffle(buffercolors)# перемешивания списка уветов в буфере
        pic_size_same_as_bgr1 = Image.new("RGBA", bg_main.size)
        pic_size_same_as_bgr1.paste(images_balls[buffercolors[0]][2], (1,1))
        ball_over_bgr1 = Image.alpha_composite(bg_main, pic_size_same_as_bgr1)
        imgbgFIN1 = ImageTk.PhotoImage(ball_over_bgr1)
        lbl_info1_b = Label(root, image=imgbgFIN1,borderwidth=0)
        lbl_info1_b.image =imgbgFIN1
        lbl_info1_b.place(x=675,y=260)

        pic_size_same_as_bgr2 = Image.new("RGBA", bg_main.size)
        pic_size_same_as_bgr2.paste(images_balls[buffercolors[1]][2], (1,1))
        ball_over_bgr2 = Image.alpha_composite(bg_main, pic_size_same_as_bgr2)
        imgbgFIN2 = ImageTk.PhotoImage(ball_over_bgr2)
        lbl_info2_b = Label(root, image=imgbgFIN2,borderwidth=0)
        lbl_info2_b.image =imgbgFIN2
        lbl_info2_b.place(x=725,y=260)

        pic_size_same_as_bgr3 = Image.new("RGBA", bg_main.size)
        pic_size_same_as_bgr3.paste(images_balls[buffercolors[2]][2], (1,1))
        ball_over_bgr3 = Image.alpha_composite(bg_main, pic_size_same_as_bgr3)
        imgbgFIN3 = ImageTk.PhotoImage(ball_over_bgr3)
        lbl_info3_b = Label(root, image=imgbgFIN3,borderwidth=0)
        lbl_info3_b.image =imgbgFIN3
        lbl_info3_b.place(x=775,y=260)
    # 0 - color: aqua
    # 1 - color: blue
    # 2 - color: green
    # 3 - color: pink
    # 4 - color: red
    # 5 - color: violet
    # 6 - color: yellow

```


## Вывод: 

Закрепил навыки разработки программ с простым графическим интерфейсом пользователя на языке Python при помощи библиотеки Tkinter; Получил представление о разработке простых игровых приложений.



