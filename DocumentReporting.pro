QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Editor/PageMetrics.cpp \
    Editor/PagesTextEdit.cpp \
    main.cpp \
    mainwindow.cpp \
    structfilereport.cpp

HEADERS += \
    Editor/PageMetrics.h \
    Editor/PagesTextEdit.h \
    mainwindow.h \
    structfilereport.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    DocumentReporting_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/Left.png \
    images/ListPortate.png \
    images/Listalbom.png \
    images/Right.png \
    images/Settings.png \
    images/justify.png \
    images/print.png \
    images/save.png

RESOURCES += \
    Resources.qrc
