#include <QApplication>
#include <QMainWindow>
#include <QTreeWidget>
#include <QPlainTextEdit>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    QWidget *centralWidget = new QWidget(&mainWindow);
    mainWindow.setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create QTreeWidget
    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->setHeaderLabels(QStringList() << "Name" << "Type");
    layout->addWidget(treeWidget);

    // Create QPlainTextEdit
    QPlainTextEdit *plainTextEdit = new QPlainTextEdit();
    layout->addWidget(plainTextEdit);

    // Create actions (for demonstration)
    QAction *listFilesAction = new QAction("List Files", &mainWindow);
    QAction *openFileAction = new QAction("Open File", &mainWindow);
    QAction *deleteFileAction = new QAction("Delete File", &mainWindow);
    QAction *createFileAction = new QAction("Create File", &mainWindow);
    QAction *createDirAction = new QAction("Create Directory", &mainWindow);

    // Connect actions to slots (for demonstration)
    QObject::connect(listFilesAction, &QAction::triggered, [&]() {
        // Clear existing items in QTreeWidget
        treeWidget->clear();

        // List files in home directory
        QDir homeDir = QDir::home();
        QFileInfoList fileList = homeDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

        // Populate QTreeWidget with files and directories
        foreach (QFileInfo fileInfo, fileList) {
            QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
            item->setText(0, fileInfo.fileName());
            item->setText(1, fileInfo.isDir() ? "Directory" : "File");
            item->setToolTip(0, fileInfo.absoluteFilePath());
            // Set icon based on type (ASCII icons)
            item->setIcon(0, QIcon(fileInfo.isDir() ? "📁" : "📄"));
        }
    });

    QObject::connect(openFileAction, &QAction::triggered, [&]() {
        // Get selected item from QTreeWidget
        QTreeWidgetItem *selectedItem = treeWidget->currentItem();
        if (!selectedItem) {
            QMessageBox::warning(&mainWindow, "Error", "No file selected.");
            return;
        }

        // Get file path from the selected item
        QString filePath = selectedItem->toolTip(0);

        // Open file for reading
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            plainTextEdit->setPlainText(in.readAll());
            file.close();
        } else {
            QMessageBox::critical(&mainWindow, "Error", "Failed to open file.");
        }
    });

    // Add actions to main window
    mainWindow.addAction(listFilesAction);
    mainWindow.addAction(openFileAction);
    mainWindow.addAction(deleteFileAction);
    mainWindow.addAction(createFileAction);
    mainWindow.addAction(createDirAction);

    // Set main window size and show
    mainWindow.resize(800, 600);
    mainWindow.show();

    return app.exec();
}
