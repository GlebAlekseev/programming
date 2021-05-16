#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage image;
    bool status_slts = true;

bool get_status_slts(){
    return status_slts;
}
void set_status_slts(bool example){
    status_slts = example;
}
public slots:
    void loadImage();
    void saveImage();
    void encodeMsg();
    void decodeMsg();
    void msgChanged();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
