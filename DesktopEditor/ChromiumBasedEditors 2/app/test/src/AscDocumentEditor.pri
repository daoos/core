HEADERS += \
    $$PWD/../../../lib/qcefview/qcefview.h \
    $$PWD/../../../lib/include/qascprinter.h

SOURCES += \
    $$PWD/../../../lib/qcefview/qcefview.cpp

HEADERS += \
    $$PWD/QAscApplicationManager.h \
    $$PWD/QAscTabWidget.h \
    $$PWD/QAscMainPanel.h \
    $$PWD/QAscMain.h

SOURCES += \
    $$PWD/QAscMainPanel.cpp

RESOURCES += \
    $$PWD/Icons.qrc

win32 {
LIBS += -lwininet \
        -ldnsapi \
        -lversion \
        -lmsimg32 \
        -lws2_32 \
        -lusp10 \
        -lpsapi \
        -ldbghelp \
        -lwinmm \
        -lshlwapi \
        -lkernel32 \
        -lgdi32 \
        -lwinspool \
        -lcomdlg32 \
        -ladvapi32 \
        -lshell32 \
        -lole32 \
        -loleaut32 \
        -luser32 \
        -luuid \
        -lodbc32 \
        -lodbccp32 \
        -ldelayimp \
        -lcredui \
        -lnetapi32 \
        -lcomctl32 \
        -lrpcrt4 \
        -ldwmapi \
        -lOpenGL32

QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.02
}
