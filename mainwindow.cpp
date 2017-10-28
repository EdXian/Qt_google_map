#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QUrl url1("https://github.com/");       // strMapPath为QString类，是你html文件的路径
    QUrl url("qrc:/map.html");

    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled,true);
    QWebEnginePage *page = new QWebEnginePage(this);  // 定义一个page作为页面管理
    QWebChannel *channel = new QWebChannel(this);     // 定义一个channel作为和JS或HTML交互
    page->load(url);                         // page上加载html路径
    page->setWebChannel(channel);                   // 把channel配置到page上，让channel作为其信使
    ui->widget->setPage(page);                   // 建立page和UI上的webEngine的联系


    //QString cmd("document.documentElement.contentEditable = true");
        QString js=QString("var marker = new google.maps.Marker({ ")+
        QString("position: new google.maps.LatLng(24.705311, -74.2581939),")+
        QString(" map: map,")+
        QString("title: \"Marker A\",")+
        QString("   }); ");

    //qDebug()<<js;
    //ui->widget->page()->runJavaScript(cmd,[](const QVariant &result){ qDebug() << result.toBool(); });
    ui->widget->page()->runJavaScript(js,[](const QVariant &result){ qDebug() << result.toBool(); });


}

MainWindow::~MainWindow()
{
    delete ui;
}
