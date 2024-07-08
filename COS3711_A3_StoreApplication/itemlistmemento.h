#ifndef ITEMLISTMEMENTO_H
#define ITEMLISTMEMENTO_H
#include <QtCore>



class ItemListMemento
{
public:

private:
    friend class CustomerForm;
    ItemListMemento();
    //getter
    QStringList getState();
    //setter
    void setState(QStringList state);

    QStringList mState;
};

#endif // ITEMLISTMEMENTO_H
