QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bishop.cpp \
    Board.cpp \
    Capture.cpp \
    King.cpp \
    Knight.cpp \
    LogicalBoard.cpp \
    Pawn.cpp \
    Piece.cpp \
    Queen.cpp \
    Rook.cpp \
    Tile.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Bishop.h \
    Board.h \
    Capture.h \
    King.h \
    Knight.h \
    LogicalBoard.h \
    Pawn.h \
    Piece.h \
    Queen.h \
    Rook.h \
    Tile.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS +=

DISTFILES += \
    Black/Chess_bdt60.png \
    Black/Chess_kdt60.png \
    Black/Chess_ndt60.png \
    Black/Chess_pdt60.png \
    Black/Chess_qdt60.png \
    Black/Chess_rdt60.png \
    White/Chess_blt60.png \
    White/Chess_klt60.png \
    White/Chess_nlt60.png \
    White/Chess_plt60.png \
    White/Chess_qlt60.png \
    White/Chess_rlt60.png
