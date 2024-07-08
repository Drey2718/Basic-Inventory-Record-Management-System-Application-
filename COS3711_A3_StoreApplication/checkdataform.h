#ifndef CHECKDATAFORM_H
#define CHECKDATAFORM_H

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>


class CheckDataForm : public QMainWindow
{
    Q_OBJECT
public:
    explicit CheckDataForm(QWidget *parent = nullptr);

public:
   QComboBox* getSelectCustomerComboBox() const;
   QComboBox* getSelectItemComboBox() const;
   QLabel*  getItemTypeDisplay() const;
   QSpinBox* getQuantitySpinBox() const;

private:
    QLabel *instructLabel;
    QLabel *selectCustomerLabel;
    QLabel *selectItemLabel;
    QLabel *itemTypeLabel;
    QLabel *itemQuantityLabel;
    QLabel *itemTypeDisplayLabel;

    QComboBox *selectCusomerComboBox;
    QComboBox *selectItemComboBox;

    QSpinBox *quantitySpinBox;

    QTextEdit *displayEdit;

    QPushButton *doneButton;
    QPushButton *showItemButton;

    QString displayItemsText;


    void setUpUI();


public slots:
    void onShowItemClicked();
    void onDoneButtonClicked();

};

#endif // CHECKDATAFORM_H
