#include "book.h"

Book::Book(QObject *parent) : QObject(parent)
{

}

Book::Book(QString n): bookName(n)
{

}

void Book::setName(QString n)
{
    bookName = n;
}

QString Book::getName() const
{
    return bookName;
}
