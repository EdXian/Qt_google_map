#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       QUrl url("qrc:/map.html");
      // connect(ui->widget->page(), SIGNAL(loadFinished(bool)), this, SLOT(slotForRunJS(bool)));

       QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);
       QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled,true);
       QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptCanAccessClipboard,true);


       QWebEnginePage *page = new QWebEnginePage(this);
       QWebChannel *channel = new QWebChannel(this);
       page->load(url);
       page->setWebChannel(channel);
       ui->widget->setPage(page);
//       js=QString("var marker = new google.maps.Marker({ ")+
//       QString("position: new google.maps.LatLng(24.705311, -74.2581939),")+
//       QString(" map: map,")+
//       QString("title: \"Marker A\",")+
//       QString("   }); ");
//       slotForRunJS(true);
//       ui->widget->page()->runJavaScript(js,[](const QVariant &result){ qDebug() << result.toBool(); });


}


void MainWindow::slotForRunJS(bool ok)
{

//    js=QString("var marker = new google.maps.Marker({ ")+
//    QString("position: new google.maps.LatLng(24.705311, -74.2581939),")+
//    QString(" setMap: map,")+
//    QString("title: \"Marker A\",")+
//    QString("   }); ");

//    js=QString("var myLatLng = {lat: -25.363, lng: 131.044};")
//    +QString("var marker = new google.maps.Marker({ ")
//    +QString("position: myLatLng,")
//    +QString(" map: map,")
//    +QString("title: 'Hello World!',")+
//     QString("   }); ");   //<title>Hello World!</title>
    double lat=23.3,lon=120.9;
    QString str =
              QString("var newLoc = new google.maps.LatLng(%1, %2); ").arg(lat).arg(lon);

    qDebug()<<str;
    ok=true;
    ui->widget->page()->runJavaScript(str,[](const QVariant &result){ qDebug() << result.toBool();});


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    //this->slotForRunJS(true);     initMap()
    QString data =QString("initMap()");
   ui->widget->page()->runJavaScript(data);
}

void MainWindow::on_pushButton_clicked()
{

    /*
     *  var marker = new google.maps.Marker({
          position: new google.maps.LatLng( 23.3,120.9),
          map: map,
          icon:'http://www.google.com/mapfiles/markerA.png',
        });

         Markers.push(marker);
     *
     */
//    QString data =
//         QString("var marker = new google.maps.Marker({ ")
//        +QString("position: new google.maps.LatLng( 50.3,120.9),")
//        +QString(" map: map,")
//        +QString(" });")
//        +QString("Markers.push(marker);");

    //,[](const QVariant &result){ qDebug() << result.toBool();}

    QString data =QString("func(map)");
    ui->widget->page()->runJavaScript(data);
}
