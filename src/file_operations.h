#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <QString>

class FileOperations
{
public:
    static QString readFromFile(const QString &fileName);
    static bool writeToFile(const QString &fileName, const QString &data);
};

#endif // FILE_OPERATIONS_H
