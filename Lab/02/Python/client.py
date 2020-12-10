from openpyxl import Workbook
from flask import Flask, request
import json


app = Flask(__name__)
 
@app.route('/', methods=['POST'])
def index():
	value = request.json
	print(value)
	# wb = Workbook() # создаю блокнотную область
	# ws = wb.active # позиционируюсь на активной странице, первой по умолчанию в WS координаты ячеек 
	# ws['A1'] =  value
	# print('val')
	# wb.save("sampl.xlsx") # сохранение файла есть аналог точечного вноса .cell(row= column=).value =
	return "Ok"
# print("hello")
# print("Value = ",value)
if __name__ == "__main__":
    app.run()
# with open('hello.json') as file:
# 	data = json.load(file)
# print(data)
# wb = Workbook() # создаю блокнотную область
# ws = wb.active # позиционируюсь на активной странице, первой по умолчанию в WS координаты ячеек 
# ws['A1'] =  value

# # grab the active worksheet
# wb.save("sample.xlsx") # сохранение файла есть аналог точечного вноса .cell(row= column=).value =

# # Data can be assigned directly to cells

# ws[1][0].value = 12 # ws[1][0].value - валуе для того чтобы достать значение из ячейки ряд колонка = 'A1'

# # Rows can also be appended
# ws.append([1, 2, 3])

# # Python types will automatically be converted
# import datetime
# ws['A2'] = datetime.datetime.now()

# # Save the file
# wb.save("sample.xlsx") # сохранение файла есть аналог точечного вноса .cell(row= column=).value =


# wb = Workbook() # создаю блокнотную область

# book = wb.open("sample.xlsx",read_only=True )
# ws = book.active # позиционируюсь на активной странице, первой по умолчанию в WS координаты ячеек 
# print(ws["B2"].value) in range (? max_row+1)