#include "../include/file_operations.h"
#include <QFile>
#include <QTextStream>

QString FileOperations::readFromFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QString(); // Error handling, in this case, return an empty string

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    return content;
}

bool FileOperations::writeToFile(const QString &fileName, const QString &data)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false; // Error handling, in this case, return false

    QTextStream out(&file);
    out << data;
    file.close();

    return true;
}
