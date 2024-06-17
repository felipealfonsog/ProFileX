#ifndef GUI_H
#define GUI_H

#include <QWidget>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onButtonClicked();

private:
    // Declare widgets and other GUI components here
};

#endif // GUI_H
