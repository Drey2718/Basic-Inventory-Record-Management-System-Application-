#include "itemlistmemento.h"

ItemListMemento::ItemListMemento()
{

}

QStringList ItemListMemento::getState()
{
    return mState;
}

void ItemListMemento::setState(QStringList state)
{
    mState = state;
}
