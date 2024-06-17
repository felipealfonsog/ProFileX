#include <QApplication>
#include <QFileDialog>
#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

// Implementation of MainWindow constructor and methods

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    openFileButton = new QPushButton("Open File", this);
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(openFileButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(openFileButton, &QPushButton::clicked, this, &MainWindow::onOpenFileClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenFileClicked()
{
    QString homeDirectory = QDir::homePath();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), homeDirectory);

    if (!fileName.isEmpty()) {
        // Aquí puedes agregar la lógica para manejar el archivo seleccionado
    }
}
