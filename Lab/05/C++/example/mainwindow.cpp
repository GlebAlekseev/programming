#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QBitArray>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->upload_img_btn,&QPushButton::clicked,this,&MainWindow::loadImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::msgChanged()
{



qint32 how_much_size = image.width()*image.height()*3 - ui->text_inp->toPlainText().toUtf8().size()*8 - 24 - 32; //24 - mark ,32 - size (fix)
how_much_size = how_much_size/8;
if(how_much_size <0){
    ui->status_lbl->setText(QString("Превышает на %1 байт.").arg(how_much_size*-1));
}else{
    ui->status_lbl->setText(QString("Ещё можно ввести %1 байт.").arg(how_much_size));

}
}

void MainWindow::loadImage()
{
QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Допустимые форматы (*.png)");
if  (fileName !=  ""){
    image.load(fileName);
    image.convertTo(QImage::Format_ARGB32);
    ui->status_lbl->setText("Изображение успешно загружено");

if(get_status_slts()){
    connect(ui->save_img_btn,&QPushButton::clicked,this,&MainWindow::saveImage);
    connect(ui->encode_text_btn,&QPushButton::clicked,this,&MainWindow::encodeMsg);
    connect(ui->decode_text_btn,&QPushButton::clicked,this,&MainWindow::decodeMsg);
    connect(ui->text_inp,&QPlainTextEdit::textChanged,this,&MainWindow::msgChanged);
    set_status_slts(false);}
}
}




void MainWindow::saveImage()
{
QString fileName = QFileDialog::getSaveFileName(this, "Save Image", "", "Допустимые форматы (*.png)");
    if  (fileName !=  ""){
    image.save(fileName);
    ui->status_lbl->setText("Изображение успешно сохранено");
    }else{
      ui->status_lbl->setText("Изображение не сохранено");
    }
}


QBitArray get_bits_array(QByteArray arr){
    qint32 count = arr.size();
    QBitArray bits(count*8);
    for(qint32 i = 0; i < count; ++i) {
      for(qint32 b = 0; b < 8; b++) {
        bits.setBit( i * 8 + b, arr.at(i) & (1 << (7 - b)) );
    }}
return bits;
}



void MainWindow::encodeMsg(){
    QByteArray msgText = ui->text_inp->toPlainText().toUtf8();
    if (image.width()*image.height()*3 >= (msgText.size()+3+4)*8){
            QBitArray bits_text = get_bits_array(msgText);
            QByteArray target;
            QDataStream s(&target, QIODevice::ReadWrite);
            qint32 value = msgText.size();
            s << value;
            QBitArray bits_size = get_bits_array(target);
            QBitArray bits_mark = get_bits_array(QString("❤").toUtf8());
            qint32 full_msg_size = bits_text.size()+bits_size.size()+bits_mark.size();
            QBitArray full_msg(full_msg_size);
           int ir=0;
            for(qint32 i=0;i<bits_mark.size();i++){
                full_msg.setBit(ir, bits_mark[i]);
                ir++;
            }
            for(qint32 i=0;i<bits_size.size();i++){

                full_msg.setBit(ir, bits_size[i]);
                ir++;
            }
            for(qint32 i=0;i<bits_text.size();i++){
                full_msg.setBit(ir, bits_text[i]);
                ir++;
            }
            qint32 count_bit = 0;
            for(qint32 i=0;i<image.height();i++){
                for(qint32 j=0;j<image.width();j++){
                    QColor color = image.pixelColor(j,i);
                    if (full_msg[count_bit]){//1
                        color.setRed(((color.red()>>1)<<1)+1);
                    }else{//0
                        color.setRed(((color.red()>>1)<<1));
                    }
                    count_bit++;
                    if (count_bit>=full_msg_size){
                        image.setPixelColor(j,i,color);break;}

                    if (full_msg[count_bit]){//1
                        color.setGreen(((color.green()>>1)<<1)+1);
                    }else{//0
                        color.setGreen(((color.green()>>1)<<1));
                    }
                    count_bit++;
                    if (count_bit>=full_msg_size){
                        image.setPixelColor(j,i,color);
                        break;}
                    if (full_msg[count_bit]){//1
                        color.setBlue(((color.blue()>>1)<<1)+1);
                    }else{//0
                        color.setBlue(((color.blue()>>1)<<1));
                    }
                    count_bit++;
                    image.setPixelColor(j,i,color);
                    if (count_bit>=full_msg_size)
                        break;
                }
                if (count_bit>=full_msg_size)
                    break;
            }
        ui->status_lbl->setText("Сообщение добавлено в картинку!");
    }else{
        ui->status_lbl->setText("Ошибка. Не достаточно места!");
    }
}


void MainWindow::decodeMsg(){
    QBitArray bits_mark = get_bits_array(QString("❤").toUtf8());
    qint32 count_mark = 0;
    QBitArray bits_mark_new(24);
    for(qint32 i=0;i<image.height();i++){
        if(count_mark>23)
            break;
        for(qint32 j=0;j<image.width();j++){
            QColor color = image.pixelColor(j,i);
            if (color.red()%2 == 0){
                bits_mark_new.setBit(count_mark,0);

            }else{
                bits_mark_new.setBit(count_mark,1);
            }
            count_mark++;
            if (color.green()%2 == 0){
                bits_mark_new.setBit(count_mark,0);

            }else{
                bits_mark_new.setBit(count_mark,1);
            }
            count_mark++;
            if (color.blue()%2 == 0){
                bits_mark_new.setBit(count_mark,0);
            }else{
                bits_mark_new.setBit(count_mark,1);
            }
             count_mark++;
            if(count_mark>23)
                break;
        }
    }
     if(bits_mark_new != bits_mark){
         ui->status_lbl->setText("Сообщение не обнаружено");
         return;
     }
     qint32 count_size = 0;
     QBitArray bits_size_new(32);
    qint32 slp = -1;
     for(qint32 i=0;i<image.height();i++){
         for(qint32 j=0;j<image.width();j++){
            slp++;
             if(slp < 8){
                 continue;}
             QColor color = image.pixelColor(j,i);
             if (color.red()%2 == 0){
                 bits_size_new.setBit(count_size,0);
             }else{
                 bits_size_new.setBit(count_size,1);
             }
             count_size++;
             if(count_size>31)
                 break;
             if (color.green()%2 == 0){
                 bits_size_new.setBit(count_size,0);
             }else{
                 bits_size_new.setBit(count_size,1);
             }
             count_size++;
             if(count_size>31)
                 break;
             if (color.blue()%2 == 0){
                 bits_size_new.setBit(count_size,0);
             }else{
                 bits_size_new.setBit(count_size,1);
             }
             count_size++;
             if(count_size>31)
                 break;
         }
         if(count_size>31)
             break;
     }
    ui->status_lbl->setText(QString("Присутствует сообщение длиной %1 байт").arg(bits_size_new.toUInt32(QSysInfo::BigEndian)));

    qint32 count_textbit = 0;
    QBitArray bits_text_new(bits_size_new.toUInt32(QSysInfo::BigEndian)*8);
   slp = 0;
    qint32 sz_text = bits_size_new.toUInt32(QSysInfo::BigEndian)*8;
    for(qint32 i=0;i<image.height();i++){
        for(qint32 j=0;j<image.width();j++){
            QColor color = image.pixelColor(j,i);
            if (slp <56){slp++;}else{
            if (color.red()%2 == 0){
                bits_text_new.setBit(count_textbit,0);
            }else{
                bits_text_new.setBit(count_textbit,1);
            }
            count_textbit++;}
            if (slp <56){slp++;}else{
            if(count_textbit>sz_text-1)
                break;
            if (color.green()%2 == 0){
                bits_text_new.setBit(count_textbit,0);
            }else{
                bits_text_new.setBit(count_textbit,1);
            }
            count_textbit++;}

            if (slp <56){slp++;}else{
            if(count_textbit>sz_text-1)
                break;
            if (color.blue()%2 == 0){
                bits_text_new.setBit(count_textbit,0);
            }else{
                bits_text_new.setBit(count_textbit,1);
            }
            count_textbit++;}

            if(count_textbit>sz_text-1)
                break;
        }
        if(count_textbit>sz_text-1)
            break;
    }
    QByteArray text_fin;
     unsigned char tmp = 0;
     qint32 counter = 0;
   for(qint32 i=0;i< bits_text_new.size()/8;i++){
       for(qint32 j=0;j<8;j++){
           tmp = (tmp<<1) |  (bits_text_new[counter] &1);
            counter++;
       }
       text_fin.push_back(tmp);
       tmp=0;
    }
    ui->text_inp->setPlainText(QString::fromUtf8(text_fin));
}
