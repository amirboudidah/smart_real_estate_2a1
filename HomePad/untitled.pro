QT       += core gui sql printsupport svg network
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console app_bundle\

win32:CONFIG(release, debug|release): LIBS += -LC:/OpenSSL-Win32/lib/ -lssl -lcrypto
win32: INCLUDEPATH += C:/Qt/Qt5.9.9/Tools/OpenSSL-Win32/include
win32: LIBS += -LC:/Qt/Qt5.9.9/Tools/OpenSSL-Win32/bin -llibcrypto-1_1 -llibssl-1_1
INCLUDEPATH += C:/Qt/Qt5.9.9/Tools/OpenSSL-Win32/include
DEPENDPATH += C:/Qt/Qt5.9.9/Tools/OpenSSL-Win32/include


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS SMTP_BUILD

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    contenu.cpp \
    gestioncontrats.cpp \
    main.cpp \
    mainwindow.cpp \
    newwindow.cpp \
    qrcode.cpp \
    chatbox.cpp \
    gestionagence.cpp \
    src/emailaddress.cpp \
    src/mimeattachment.cpp \
    src/mimecontentformatter.cpp \
    src/mimefile.cpp \
    src/mimehtml.cpp \
    src/mimeinlinefile.cpp \
    src/mimemessage.cpp \
    src/mimemultipart.cpp \
    src/mimepart.cpp \
    src/mimetext.cpp \
    src/quotedprintable.cpp \
    src/smtpclient.cpp

QMAKE_CXXFLAGS += -std=gnu++11

HEADERS += \
    chatbox.h \
    connection.h \
    gestionagence.h \
    contenu.h \
    gestioncontrats.h \
    mainwindow.h \
    newwindow.h \
    qrcode.h \
    src/SmtpMime \
    src/emailaddress.h \
    src/mimeattachment.h \
    src/mimecontentformatter.h \
    src/mimefile.h \
    src/mimehtml.h \
    src/mimeinlinefile.h \
    src/mimemessage.h \
    src/mimemultipart.h \
    src/mimepart.h \
    src/mimetext.h \
    src/quotedprintable.h \
    src/smtpclient.h \
    src/smtpexports.h

FORMS += \
    contenu.ui \
    chatbox.ui \
    mainwindow.ui \
    newwindow.ui

RC_ICONS = logo.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    GFX.qrc

DISTFILES += \
    SpyBot.qss


