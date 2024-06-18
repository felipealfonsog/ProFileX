QT += widgets

# Optional: Add other required modules if not already present
# QT += core gui

# Include necessary headers
HEADERS += \
    include/file_operations.h \
    include/main.h \
    include/utils.h

# Source files
SOURCES += \
    src/file_operations.cpp \
    src/main.cpp \
    src/utils.cpp

# UI files
FORMS += \
    ui/mainwindow.ui

# Resources (if any)
RESOURCES +=

# Precompiled headers (if used)
PRECOMPILED_HEADER =

# Additional compiler flags (if needed)
QMAKE_CXXFLAGS +=

# Additional linker flags (if needed)
QMAKE_LFLAGS +=
