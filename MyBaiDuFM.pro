#-------------------------------------------------
#
# Project created by QtCreator 2016-07-03T13:53:46
#
#-------------------------------------------------

QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyBaiDuFM
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    getsongplaylistid.cpp \
    getsongreallink.cpp

HEADERS  += mainwidget.h \
    getsongplaylistid.h \
    getsongreallink.h

FORMS    += mainwidget.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/res/values/strings.xml \
    android/res/values/styles.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

RESOURCES += \
    image.qrc

