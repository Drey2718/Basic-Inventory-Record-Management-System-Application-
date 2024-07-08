#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QtCore>

class Book : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString bookName READ getName WRITE setName);
public:
    explicit Book(QObject *parent = nullptr);

    //Custom Constructor:
    Book(QString n);

    //SETTERS
    void setName(QString n);

    //GETTERS
    QString getName() const;

private:
    QString bookName;

};

#endif // BOOK_H
