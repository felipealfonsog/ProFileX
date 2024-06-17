#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onOpenFileClicked();

private:
    Ui::MainWindow *ui;
    QPushButton *openFileButton;
    QVBoxLayout *mainLayout;
};

#endif // MAIN_H
