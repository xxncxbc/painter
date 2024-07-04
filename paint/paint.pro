QT       += core gui svg
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    figure.cpp \
    main.cpp \
    oval.cpp \
    paint.cpp \
    paintscene.cpp \
    romb.cpp \
    square.cpp \
    svgreader.cpp

HEADERS += \
    figure.h \
    oval.h \
    paint.h \
    paintscene.h \
    romb.h \
    square.h \
    svgreader.h

FORMS += \
    paint.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    ress.qrc

DISTFILES += \
    res/circle_udtuaqvaduof.svg \
    res/new_file_zd95d3grvcrr.svg \
    res/open_folder_2wnrzrmc83im.svg \
    res/rhomb_outline_abumlcw28ppg.svg \
    res/save_ocwlkbncu1nq.svg \
    res/square_n0n76xad9jge.svg
