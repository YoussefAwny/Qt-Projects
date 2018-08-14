#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    //Bar Chart
    QBarSet *set0 = new QBarSet("M.Salah");
    QBarSet *set1 = new QBarSet("Shika");
    QBarSet *set2 = new QBarSet("Warda");
    QBarSet *set3 = new QBarSet("Trezegeh");
    QBarSet *set4 = new QBarSet("Hadary");

    *set0 << 283 << 294 << 313 << 325 << 210 << 396 ;
    *set1 << 243 << 232 << 371 << 253 << 345 << 150 ;
    *set2 << 328 << 374 << 331 << 195 << 234 << 240 ;
    *set3 << 423 << 143 << 342 << 360 << 432 << 234 ;
    *set4 << 287 << 243 << 189 << 379 << 321 << 254 ;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Running Statistics");
    chart->setAnimationDuration(QChart::AllAnimations);

    QStringList Categories;
    Categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018" ;
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(Categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window,QRgb(0xffffff) );
    pal.setColor(QPalette::WindowText,QRgb(0x404040));
    qApp->setPalette(pal);


    //Line Charts
    QLineSeries *series1 = new QLineSeries();
    series1->append(0,2);
    series1->append(1,4);
    series1->append(2,3);
    series1->append(3,5);
    series1->append(4,4);
    series1->append(5,5);
    series1->append(6,6);

    QChart *chart1 = new QChart();
    chart1->legend()->hide();
    chart1->addSeries(series1);
    chart1->createDefaultAxes();

    QFont font1;
    font1.setPixelSize(18);
    chart1->setTitleFont(font1);
    chart1->setTitleBrush(QBrush(Qt::black));
    chart1->setTitle("Assists");

    QPen pen1(QRgb(0x00fff0));
    pen1.setWidth(5);
    series1->setPen(pen1);

    chart1->setAnimationOptions(QChart::AllAnimations);

    QCategoryAxis *axisX1 = new QCategoryAxis();
    axisX1->append("2000",0);
    axisX1->append("2001",1);
    axisX1->append("2002",2);
    axisX1->append("2003",3);
    axisX1->append("2004",4);
    axisX1->append("2005",5);
    axisX1->append("2006",6);

    chart1->setAxisX(axisX1,series1);
    QChartView *chartview1 = new QChartView(chart1);
    chartview1->setRenderHint(QPainter::Antialiasing);

//  Pie Chart
    QPieSeries *series2 = new QPieSeries();
    series2->append("Vegetables", 0.20);
    series2->append("meat", 0.30);
    series2->append("fruits", 0.25);
    series2->append("seeds",0.1);
    series2->append("chicken",0.15);

    QPieSlice *slice0 = series2->slices().at(0);
    slice0->setLabelVisible();

    QPieSlice *slice1 = series2->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    QPieSlice *slice2 = series2->slices().at(2);
    slice2->setLabelVisible();
    QPieSlice *slice3 = series2->slices().at(3);
    slice3->setLabelVisible();
    QPieSlice *slice4 = series2->slices().at(4);
    slice4->setLabelVisible();

    QChart *chart2 = new QChart();
    chart2->addSeries(series2);
    chart2->setTitle("My food Diet");
    chart2->legend()->hide();

    QChartView *chartview2 = new QChartView(chart2);
    chartview2->setRenderHint(QPainter::Antialiasing);


    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420,300);
    window.setWindowTitle("Bar Chart");
    window.show();

    QMainWindow window1;
    window1.setCentralWidget(chartview1);
    window1.resize(420,300);
    window1.setWindowTitle("Line Chart");
    window1.show();


    QMainWindow window2;
    window2.setCentralWidget(chartview2);
    window2.resize(420,300);
    window2.setWindowTitle("Pie Chart");
    window2.show();


    return a.exec();
}
