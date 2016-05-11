TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gvector3.cpp \
    cray.cpp \
    csphere.cpp \
    intersectresult.cpp \
    camera.cpp \
    cobject.cpp \
    plane.cpp \
    color.cpp \
    material.cpp \
    checkermaterial.cpp \
    phongmaterial.cpp \
    lamp.cpp \
    union.cpp \
    cdet.cpp \
    ctriangle.cpp \
    cmodel.cpp \
    lightarea.cpp

QT  += core gui
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/opencv/
INCLUDEPATH +=/usr/local/include/opencv2/
LIBS += -L/usr/local/lib
    -lopencv_core
    -lopencv_imgproc
    -lopencv_calib3d
    -lopencv_highgui

LIBS += -L/usr/local/lib
LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -v

HEADERS += \
    gvector3.h \
    cray.h \
    csphere.h \
    intersectresult.h \
    camera.h \
    cobject.h \
    plane.h \
    color.h \
    material.h \
    checkermaterial.h \
    phongmaterial.h \
    lamp.h \
    union.h \
    cdet.h \
    ctriangle.h \
    cmodel.h \
    lightarea.h

DISTFILES +=

RESOURCES += \
    obj.qrc
