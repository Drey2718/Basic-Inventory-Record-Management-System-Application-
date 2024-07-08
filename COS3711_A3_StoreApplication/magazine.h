#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QObject>
#include <QtCore>

class Magazine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString magazineName READ getMagazineName WRITE setMagazineName);
public:
    explicit Magazine(QObject *parent = nullptr);

    //Custom Constructor
    Magazine(QString n);

    //SETTERS
    void setMagazineName(QString n);

    //GETTERS
    QString getMagazineName() const;
private:
    QString magazineName;

};

#endif // MAGAZINE_H
