#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextDocument>
#include <QTextBlock>
#include <QTextTable>
#include <QDebug>
#include <QTextDocumentWriter>
#include <Editor/PagesTextEdit.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    QTextDocument* doc;
    QTextDocumentWriter * docw;
    PagesTextEdit *w;
    QTextCursor *cursor;

private slots:
    void setTextBold();
    void setTextItalic();
    void setTextUnderlined();
    void setTextSize(int p_size);
    void setTextFontStyle(QString p_familyFont);
    void setTextLeftAlign();
    void setTextCenterAlign();
    void setTextRightAlign();
    void setSheetAlbum();
    void setSheetPortate();
    void createDocument();
    void saveDocument();
    void cursorStateUpdate();
    void appendTable();
    void appendColumnTable();
    void appendRowTable();
};
#endif // MAINWINDOW_H
