#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    connect(ui->pushButton_bold, SIGNAL(clicked()),SLOT(setTextBold()));
    connect(ui->pushButton_italic, SIGNAL(clicked()),SLOT(setTextItalic()));
    connect(ui->pushButton_underlined, SIGNAL(clicked()),SLOT(setTextUnderlined()));
    connect(ui->spinBox_font_size,SIGNAL(valueChanged(int)),SLOT(setTextSize(int)));

    connect(ui->fontComboBox,SIGNAL(currentIndexChanged(QString)),SLOT(setTextFontStyle(QString)));

    connect(ui->pushButton_leftAlign, SIGNAL(clicked()),SLOT(setTextLeftAlign()));
    connect(ui->pushButton_centerAlign, SIGNAL(clicked()),SLOT(setTextCenterAlign()));
    connect(ui->pushButton_RightAlign, SIGNAL(clicked()),SLOT(setTextRightAlign()));

    connect(ui->pushButton_ListAlbum,SIGNAL(clicked()),SLOT(setSheetAlbum()));
    connect(ui->pushButton_ListPortated,SIGNAL(clicked()),SLOT(setSheetPortate()));

    connect(ui->pushButton_addTable,SIGNAL(clicked(bool)),SLOT(appendTable()));
    connect(ui->pushButton_addTableColumn,SIGNAL(clicked(bool)),SLOT(appendColumnTable()));
    connect(ui->pushButton_addTableRow,SIGNAL(clicked(bool)),SLOT(appendRowTable()));


    w = new PagesTextEdit();
    doc = new QTextDocument;

    doc->setDefaultFont(QFont("Courier", 12));
    w->setDocument(doc);

    cursor = new QTextCursor(doc);

    w->setPageFormat(QPageSize::A4);
    w->setPageMargins(QMarginsF(15, 15, 15, 15));
    w->setUsePageMode(true);

    w->setPageNumbersAlignment(Qt::AlignTop | Qt::AlignHCenter);

    w->resize(600, 400);
    ui->horizontalLayout->addWidget(w);
    connect(w, SIGNAL(cursorPositionChanged()),SLOT(cursorStateUpdate()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTextBold()
{
    w->setFontWeight(ui->pushButton_bold->isChecked() ? 600 : 400);
}
void MainWindow::setTextItalic()
{
     w->setFontItalic(ui->pushButton_italic->isChecked());
}
void MainWindow::setTextUnderlined()
{
     w->setFontUnderline(ui->pushButton_underlined->isChecked());
}
void MainWindow::setTextSize(int p_size)
{
    w->setFontPointSize(p_size);

}
void MainWindow::setTextFontStyle(QString p_familyFont)
{
    w->setFontFamily(p_familyFont);
}
void MainWindow::setTextLeftAlign()
{
    w->setAlignment(Qt::AlignLeft);

}
void MainWindow::setTextCenterAlign()
{
    w->setAlignment(Qt::AlignCenter);
}
void MainWindow::setTextRightAlign()
{
    w->setAlignment(Qt::AlignRight);
}
void MainWindow::setSheetAlbum()
{
    w->setPageOrientation(QPrinter::Landscape);
    w->repaint();
    w->setFocus();
}
void MainWindow::setSheetPortate()
{
    w->setPageOrientation(QPrinter::Portrait);
    w->repaint();
    w->setFocus();
}
void MainWindow::createDocument()
{

}
void MainWindow::saveDocument()
{

}
void MainWindow::cursorStateUpdate()
{


}
void MainWindow::appendTable()
{
    QTextCursor cur = w->textCursor();
    cur.insertTable(1,1);

}
void MainWindow::appendColumnTable()
{
    QTextCursor cur = w->textCursor();
    QTextTable * table = cur.currentTable();

    //table->insertColumns(table->columns(),1);
    qDebug()<<cur.positionInBlock();
    table->appendColumns(1);
}
void MainWindow::appendRowTable()
{
    QTextCursor cur = w->textCursor();
    QTextTable * table = cur.currentTable();
    //table->insertRows(table->rows(),1);
    table->appendRows(1);
}

