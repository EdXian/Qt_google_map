#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets>   // 基本组件
#include <QWebEnginePage>       // HTML页面
#include <QWebChannel>          // C++和JS/HTML双向通信，代替了已淘汰的QtWebFrame的功能
#include "QWebEngineSettings"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
