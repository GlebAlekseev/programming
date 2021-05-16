# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainwindowyjTjPb.ui'
##
## Created by: Qt User Interface Compiler version 6.0.3
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(278, 370)
        MainWindow.setStyleSheet(u"QMainWindow{background-color:white;}\n"
"QPushButton{border: 1px solid #360099;border-radius:2px;padding-top:5px;padding-bottom:5px;background-color:#F0F9FA;}\n"
"QPushButton:hover{color: red;border-color: 1px solid red;}\n"
"QPushButton:pressed{color: #AB274F;border-color: 2px solid #AB274F;}\n"
"\n"
"\n"
"QPlainTextEdit{\n"
"border: 1px solid gray;\n"
"border-radius:2px;}\n"
"\n"
"QPlainTextEdit:focus{\n"
"border: 1px solid #046167;\n"
"}")
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.centralwidget.setMinimumSize(QSize(278, 370))
        self.centralwidget.setMaximumSize(QSize(278, 670))
        self.verticalLayout = QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout_2 = QVBoxLayout()
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.main_lbl = QLabel(self.centralwidget)
        self.main_lbl.setObjectName(u"main_lbl")

        self.verticalLayout_2.addWidget(self.main_lbl)

        self.status_lbl = QLabel(self.centralwidget)
        self.status_lbl.setObjectName(u"status_lbl")

        self.verticalLayout_2.addWidget(self.status_lbl)

        self.upload_img_btn = QPushButton(self.centralwidget)
        self.upload_img_btn.setObjectName(u"upload_img_btn")

        self.verticalLayout_2.addWidget(self.upload_img_btn)

        self.decode_text_btn = QPushButton(self.centralwidget)
        self.decode_text_btn.setObjectName(u"decode_text_btn")

        self.verticalLayout_2.addWidget(self.decode_text_btn)

        self.text_inp = QPlainTextEdit(self.centralwidget)
        self.text_inp.setObjectName(u"text_inp")
        self.text_inp.setStyleSheet(u"color:#474A51;")

        self.verticalLayout_2.addWidget(self.text_inp)

        self.encode_text_btn = QPushButton(self.centralwidget)
        self.encode_text_btn.setObjectName(u"encode_text_btn")

        self.verticalLayout_2.addWidget(self.encode_text_btn)

        self.save_img_btn = QPushButton(self.centralwidget)
        self.save_img_btn.setObjectName(u"save_img_btn")

        self.verticalLayout_2.addWidget(self.save_img_btn)


        self.verticalLayout.addLayout(self.verticalLayout_2)

        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.main_lbl.setText(QCoreApplication.translate("MainWindow", u"<center style=\"color:#FF3379;font-size:10pt;\">\u0421\u0442\u0435\u0433\u0430\u043d\u043e\u0433\u0440\u0430\u0444\u0438\u044f</center>", None))
        self.status_lbl.setText("")
        self.upload_img_btn.setText(QCoreApplication.translate("MainWindow", u"\u0417\u0430\u0433\u0440\u0443\u0437\u0438\u0442\u044c \u043a\u0430\u0440\u0442\u0438\u043d\u043a\u0443", None))
        self.decode_text_btn.setText(QCoreApplication.translate("MainWindow", u"\u0414\u0435\u043a\u043e\u0434\u0438\u0440\u043e\u0432\u0430\u0442\u044c \u0442\u0435\u043a\u0441\u0442", None))
        self.text_inp.setPlaceholderText(QCoreApplication.translate("MainWindow", u"\u0412\u0432\u0435\u0434\u0438\u0442\u0435 \u0442\u0435\u043a\u0441\u0442", None))
        self.encode_text_btn.setText(QCoreApplication.translate("MainWindow", u"\u0417\u0430\u043a\u043e\u0434\u0438\u0440\u043e\u0432\u0430\u0442\u044c \u0442\u0435\u043a\u0441\u0442", None))
        self.save_img_btn.setText(QCoreApplication.translate("MainWindow", u"\u0421\u043e\u0445\u0440\u0430\u043d\u0438\u0442\u044c \u043a\u0430\u0440\u0442\u0438\u043d\u043a\u0443", None))
    # retranslateUi




class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ui.upload_img_btn.clicked.connect(self.loadImage)

        self.status_slts = True
    



    @Slot()
    def loadImage(self):
        fileName, _ = QFileDialog.getOpenFileName(self, "Open Image", "", "Допустимые форматы (*.png)")
        if len(fileName) != 0:
            self.image = QImage()
            self.image.load(fileName)
            self.image.convertTo(QImage.Format_ARGB32)
            self.ui.status_lbl.setText("Изображение успешно загружено")
            if self.status_slts:
              self.ui.save_img_btn.clicked.connect(self.saveImage)
              self.ui.encode_text_btn.clicked.connect(self.encodeMsg)
              self.ui.decode_text_btn.clicked.connect(self.decodeMsg)
              self.ui.text_inp.textChanged.connect(self.msgChanged)
              self.status_slts = False
        else:
            self.ui.status_lbl.setText("Изображение не загружено")
    @Slot()
    def msgChanged(self):
      how_much_size = self.image.width()*self.image.height()*3 - len(self.ui.text_inp.toPlainText().encode())*8 - 24 - 32
      how_much_size = int(how_much_size/8)
      if how_much_size<0:
        self.ui.status_lbl.setText(f"Превышает на {how_much_size*-1} байт.")
      else:
        self.ui.status_lbl.setText(f"Ещё можно ввести: {how_much_size} байт")

    @Slot()
    def saveImage(self):
      fileName, _ = QFileDialog.getSaveFileName(self, "Save Image", "", "Допустимые форматы (*.png)")
      if len(fileName) != 0:
          self.image.save(fileName)
          self.ui.status_lbl.setText("Изображение успешно сохранено")
      else:
          self.ui.status_lbl.setText("Изображение не сохранено")
    @Slot()
    def encodeMsg(self):
      msgText = self.ui.text_inp.toPlainText().encode()

      if self.image.width()*self.image.height()*3 >= (len(msgText)+3+4)*8:
        def get_bits(bytes_arr):
          bits_arr = []
          for b in bytes_arr:
              tmp_bits_arr=[]
              for i in range(8):
                  tmp_bits_arr.append((b >> i) & 1)
              tmp_bits_arr.reverse()
              for u in tmp_bits_arr:
                bits_arr.append(u)
          return bits_arr




        full_bits = [*get_bits(str("❤").encode()),*get_bits((len(msgText)).to_bytes(4, byteorder="big")),*get_bits(msgText)]
        counter_bit = 0
        for x in range(self.image.height()):
          for y in range(self.image.width()):
            color = self.image.pixelColor(y, x)
            if full_bits[counter_bit]:
              color.setRed(((color.red()>>1)<<1)+1)
              # print(((color.red()>>1)<<1)+1)
            else:
              color.setRed(((color.red()>>1)<<1))
              # print(((color.red()>>1)<<1))
            counter_bit+=1
            if counter_bit>=len(full_bits):
              self.image.setPixelColor(y,x,color)
              break


            if full_bits[counter_bit]:
              color.setGreen(((color.green()>>1)<<1)+1)
              # print(((color.green()>>1)<<1)+1)
            else:
              color.setGreen(((color.green()>>1)<<1))
              # print(((color.green()>>1)<<1))
            counter_bit+=1
            if counter_bit>=len(full_bits):
              self.image.setPixelColor(y,x,color)
              break

            if full_bits[counter_bit]:
              color.setBlue(((color.blue()>>1)<<1)+1)
              # print(((color.blue()>>1)<<1)+1)
            else:
              color.setBlue(((color.blue()>>1)<<1))
              # print(((color.blue()>>1)<<1))
            counter_bit+=1
            self.image.setPixelColor(y,x,color)
            if counter_bit>=len(full_bits):
              break
          if counter_bit>=len(full_bits):
            break


        counter_key = 0
        keyBits_new  = []
        slp = -1
        for x in range(self.image.height()):
          for y in range(self.image.width()):
            slp+=1
            # if slp <8:
            #   continue
            color = self.image.pixelColor(y,x)

            if color.red()%2 == 0:
              keyBits_new.append(0)
            else:
              keyBits_new.append(1)    
            counter_key+=1
            if counter_key>31+100:
              break

            if color.green()%2 == 0:
              keyBits_new.append(0)
            else:
              keyBits_new.append(1)    
            counter_key+=1
            if counter_key>31+100:
              break

            if color.blue()%2 == 0:
              keyBits_new.append(0)
            else:
              keyBits_new.append(1)    
            counter_key+=1
            if counter_key>31:
              break
          if counter_key>31+100:
            break
        # print(keyBits_new, "key-size", full_bits)




        self.ui.status_lbl.setText("Сообщение добавлено в картинку!")
      else:
        self.ui.status_lbl.setText("Ошибка. Не достаточно места!")


    @Slot()
    def decodeMsg(self):
        def get_bits(bytes_arr):
          bits_arr = []
          for b in bytes_arr:
              tmp_bits_arr=[]
              for i in range(8):
                  tmp_bits_arr.append((b >> i) & 1)
              tmp_bits_arr.reverse()
              for u in tmp_bits_arr:
                bits_arr.append(u)
          return bits_arr

        markBits_default = get_bits(str("❤").encode())
        counter_mark = 0
        markBits_new  = []
        for x in range(self.image.height()):
          if counter_mark>23:
            break
          for y in range(self.image.width()):
            color = self.image.pixelColor(y, x)

            if color.red()%2 == 0:
              markBits_new.append(0)
            else:
              markBits_new.append(1)    
            counter_mark+=1

            if color.green()%2 == 0:
              markBits_new.append(0)
            else:
              markBits_new.append(1)    
            counter_mark+=1

            if color.blue()%2 == 0:
              markBits_new.append(0)
            else:
              markBits_new.append(1)    
            counter_mark+=1
            if counter_mark>23:
              break
        if markBits_new != markBits_default:
            self.ui.status_lbl.setText("Сообщение не обнаружено")
            return
        counter_key = 0
        keyBits_new  = []
        slp = -1
        for x in range(self.image.height()):
          for y in range(self.image.width()):
            slp+=1
            if slp <8:
              continue
            color = self.image.pixelColor(y,x)

            if color.red()%2 == 0:
              keyBits_new.append(0)
            else:
              keyBits_new.append(1)    
            counter_key+=1
            if counter_key>31:
              break

            if color.green()%2 == 0:
              keyBits_new.append(0)
            else:
              keyBits_new.append(1)    
            counter_key+=1
            if counter_key>31:
              break

            if color.blue()%2 == 0:
              keyBits_new.append(0)
            else:
              keyBits_new.append(1)    
            counter_key+=1
            if counter_key>31:
              break
          if counter_key>31:
            break
        # print(keyBits_new, "key-size")

        counter_fbkey = 0
        size_bytes = bytearray()

        for i in range(int(len(keyBits_new)/8)):
          tmp = 0
          for j in range(8):
            tmp = (tmp<<1) | (keyBits_new[counter_fbkey] &1)
            # print((keyBits_new[counter_fbkey] &1))
            counter_fbkey +=1
          size_bytes.append(tmp)


        size =int.from_bytes(size_bytes, 'big')
        # print(size.decode())

        self.ui.status_lbl.setText(f"Присутствует сообщение длиной {size} байт")



        counter_text = 0
        textBits_new  = []
        slp = 0
        size = 8*size
        for x in range(self.image.height()):
          for y in range(self.image.width()):
            color = self.image.pixelColor(y,x)

            if slp <56:
              slp+=1
            else:
              if color.red()%2 == 0:
                textBits_new.append(0)
              else:
                textBits_new.append(1)  
              counter_text+=1

            if slp <56:
              slp+=1
            else:
              if counter_text>size-1:
                break
              if color.green()%2 == 0:
                textBits_new.append(0)
              else:
                textBits_new.append(1)  
              counter_text+=1

            if slp <56:
              slp+=1
            else:
              if counter_text>size-1:
                break
              if color.blue()%2 == 0:
                textBits_new.append(0)
              else:
                textBits_new.append(1)  
              counter_text+=1

            if counter_text>size-1:
              break
          if counter_text>size-1:
            break


        counter_fbtext =0
        text_bytes = bytearray()
        for i in range(int(len(textBits_new)/8)):
          tmp = 0
          for j in range(8):
            tmp = (tmp<<1) | (textBits_new[counter_fbtext] &1)
            counter_fbtext +=1
          text_bytes.append(tmp)
          # print(text_bytes)
        self.ui.text_inp.setPlainText(text_bytes.decode())





if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
  
    window = MainWindow()
    window.show()
  
    sys.exit(app.exec())

