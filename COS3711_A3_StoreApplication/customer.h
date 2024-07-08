#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>
#include <QtCore>

class Customer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName);
public:
    explicit Customer(QObject *parent = nullptr);

    //SETTERS
    void setName(QString n);

    //GETTERS
    QString getName() const;

private:
    QString name;



};

#endif // CUSTOMER_H
