#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       QUrl url("qrc:/map.html");

       QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);
       QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled,true);
       QWebEnginePage *page = new QWebEnginePage(this);
       QWebChannel *channel = new QWebChannel(this);
       page->load(url);
       page->setWebChannel(channel);
       ui->widget->setPage(page);

        QString js=QString("var marker = new google.maps.Marker({ ")+
        QString("position: new google.maps.LatLng(24.705311, -74.2581939),")+
        QString(" map: map,")+
        QString("title: \"Marker A\",")+
        QString("   }); ");

       ui->widget->page()->runJavaScript(js,[](const QVariant &result){ qDebug() << result.toBool(); });


}

MainWindow::~MainWindow()
{
    delete ui;
}
