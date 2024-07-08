#ifndef SHOPTREEMODELVIEW_H
#define SHOPTREEMODELVIEW_H

#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include "customerform.h"

class ShopTreeModelView
{
public:
    ShopTreeModelView();

    QStandardItemModel* getModel() const;
    CustomerForm* getCustomerForm() const;

     void updateModel();

private:
    QStandardItemModel *model;
    CustomerForm *t_CustomerForm;

};

#endif // SHOPTREEMODELVIEW_H
