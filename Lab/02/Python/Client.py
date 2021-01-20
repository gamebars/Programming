from flask import Flask, request, jsonify #импорт json Документ
from datetime import datetime #Модуль datetime предоставляет классы для обработки времени и даты разными способами. 
import openpyxl #импортируем модуль Pyxl

Buffer = []

def GetEmptyCell(sheet):
    i = 2
    while sheet[i][0].value != None:
        i += 1
    return i


def ListGenerate(sheet):
    num = GetEmptyCell(sheet)
    for i in range(len(Buffer)):
        for j in range(len(Buffer[i]['check'])):
            sheet[num][0].value = num - 1 #Обращение к атрибуту value, для записи, без него ошибка.
            sheet[num][1].value = Buffer[i]['user_id']
            sheet[num][2].value = Buffer[i]['datetime']
            sheet[num][3].value = Buffer[i]['check'][j]['item']
            sheet[num][4].value = Buffer[i]['check'][j]['price']
            num += 1
    del num, i, j
    return sheet


def BufferToExcel():
    global Buffer
    #В блоке try мы выполняем инструкцию, которая может породить исключение, 
    #а в блоке except мы перехватываем их
    try:
        book = openpyxl.open(r'C:\Users\admin\Desktop\Programming\Lab\02\excel\data.xlsx', read_only=False)
        #атрибут рид онли, фалс хочу редактировать	
    except:
        book = openpyxl.Workbook() #обращаемся к классу воркбук, создаем рабочую книгу
    sheet = book.active #обращение к атрибуту актив, по умолчанию открывает превый лист первый лист
    if sheet['A1'].value == None:
        sheet['A1'] = 'N'
        sheet['B1'] = 'User ID'
        sheet['C1'] = 'Datetime'
        sheet['D1'] = 'Item'
        sheet['E1'] = 'Prise'
    sheet = ListGenerate(sheet)
    book.save(r'C:\Users\admin\Desktop\Programming\Lab\02\excel\data.xlsx') #
    book.close()


def BufferGenerate(data):
    global Buffer
    data['datetime'] = datetime.now().strftime("%d.%m.%Y %H:%M:%S") # now() метод класса дейттайм, возвращает 
  # текущее время
  #Метод strftime () возвращает строку, представляющую дату и время, используя объект date, time или datetime.s
  #codes %d %....
    Buffer.append(data)
    if len(Buffer) >= 3: #Когда количество записей в буфере превосходит 1000, 
    					#данные сохраняются в excel-таблицу с именем data.xlsx и буфер очищается.
        BufferToExcel()
        Buffer = []


app = Flask(__name__)

@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        data = request.json #Полученные данные складываются в переменную-буфер. Данные приходят в json формате 
        BufferGenerate(data)
        return 'OK'
      
    elif request.method == 'GET':
        return 'Это GET запрос'
if __name__ == "__main__":
	app.run()