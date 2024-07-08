#include "checkdataform.h"

CheckDataForm::CheckDataForm(QWidget *parent) : QMainWindow(parent),
    instructLabel{new QLabel(this)},
    selectCustomerLabel{new QLabel(this)},
    selectItemLabel{new QLabel(this)},
    itemTypeLabel{new QLabel(this)},
    itemQuantityLabel{new QLabel(this)},
    selectCusomerComboBox{new QComboBox(this)},
    selectItemComboBox{new QComboBox(this)},
    itemTypeDisplayLabel{new QLabel(this)},
    quantitySpinBox{new QSpinBox(this)},
    displayEdit{new QTextEdit(this)},
    doneButton{new QPushButton(this)},
    showItemButton{new QPushButton(this)}
{
    setUpUI();
}

QComboBox *CheckDataForm::getSelectCustomerComboBox() const
{
    return selectCusomerComboBox;
}

QComboBox *CheckDataForm::getSelectItemComboBox() const
{
    return selectItemComboBox;
}

QLabel *CheckDataForm::getItemTypeDisplay() const
{
    return itemTypeDisplayLabel;
}

QSpinBox *CheckDataForm::getQuantitySpinBox() const
{
    return quantitySpinBox;
}

void CheckDataForm::setUpUI()
{
    setWindowTitle("Shop");
    setFixedSize(380, 600);

    instructLabel->setGeometry(100, 25, 300, 20);
    instructLabel->setText("Complete the required data");

    selectCustomerLabel->setGeometry(30, 60, 300, 20);
    selectCustomerLabel->setText("Select the Customer:");

    selectItemLabel->setGeometry(30, 90, 300, 20);
    selectItemLabel->setText("Select the item:");

    itemTypeLabel->setGeometry(30, 120, 300, 20);
    itemTypeLabel->setText("Item Type:");

    itemQuantityLabel->setGeometry(30, 150, 300, 20);
    itemQuantityLabel->setText("Item Quantity:");

    selectCusomerComboBox->setGeometry(170, 60, 150, 20);

    selectItemComboBox->setGeometry(170, 90, 150, 20);

    itemTypeDisplayLabel->setGeometry(170, 120, 300, 20);

    quantitySpinBox->setGeometry(170, 150, 75, 30);

    displayEdit->setGeometry(30, 190, 300, 300);

    doneButton->setGeometry(160, 520, 80, 40);
    doneButton->setText("Done");

    showItemButton->setGeometry(250, 145, 90, 35);
    showItemButton->setText("Show Item");

    //Adding widgets to the layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(instructLabel);
    layout->addWidget(selectCustomerLabel);
    layout->addWidget(selectItemLabel);
    layout->addWidget(itemTypeLabel);
    layout->addWidget(itemQuantityLabel);

    layout->addWidget(selectCusomerComboBox);
    layout->addWidget(selectItemComboBox);

    layout->addWidget(itemTypeDisplayLabel);
    layout->addWidget(quantitySpinBox);
    layout->addWidget(displayEdit);

    layout->addWidget(doneButton);
    layout->addWidget(showItemButton);

    //Connecting signals & Slots
    connect(showItemButton, SIGNAL(clicked()), this, SLOT(onShowItemClicked()));
    connect(doneButton, SIGNAL(clicked()), this, SLOT(onDoneButtonClicked()));
}

void CheckDataForm::onShowItemClicked()
{
    displayItemsText =  "Purchased Item (part of Transaction):\nCustomer: " + selectCusomerComboBox->currentText() +
            "\nItem name: " + selectItemComboBox->currentText() + ", Item Type: " + itemTypeDisplayLabel->text() +
            ", Quantity: " + QString::number(quantitySpinBox->value());

    displayEdit->setText(displayItemsText);
}

void CheckDataForm::onDoneButtonClicked()
{
   this->close();
}
