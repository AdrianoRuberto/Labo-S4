/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelNbThreads;
    QLabel *labelNbIterations;
    QLineEdit *editNbThreads;
    QLineEdit *editNbIterations;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_2;
    QLabel *labelResObtenu;
    QLCDNumber *lcdNumberResObtenu;
    QLabel *labelResEspere;
    QLCDNumber *lcdNumberResEspere;
    QLabel *labelResRatio;
    QLCDNumber *lcdNumberResRatio;
    QProgressBar *progressBar;
    QPushButton *startButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(403, 324);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(9);
        Dialog->setFont(font);
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        labelNbThreads = new QLabel(groupBox);
        labelNbThreads->setObjectName(QStringLiteral("labelNbThreads"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNbThreads);

        labelNbIterations = new QLabel(groupBox);
        labelNbIterations->setObjectName(QStringLiteral("labelNbIterations"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelNbIterations);

        editNbThreads = new QLineEdit(groupBox);
        editNbThreads->setObjectName(QStringLiteral("editNbThreads"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editNbThreads->sizePolicy().hasHeightForWidth());
        editNbThreads->setSizePolicy(sizePolicy1);
        editNbThreads->setMaxLength(22);
        editNbThreads->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, editNbThreads);

        editNbIterations = new QLineEdit(groupBox);
        editNbIterations->setObjectName(QStringLiteral("editNbIterations"));
        sizePolicy1.setHeightForWidth(editNbIterations->sizePolicy().hasHeightForWidth());
        editNbIterations->setSizePolicy(sizePolicy1);
        editNbIterations->setMaxLength(22);
        editNbIterations->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, editNbIterations);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setHorizontalSpacing(10);
        formLayout_2->setVerticalSpacing(10);
        labelResObtenu = new QLabel(groupBox_2);
        labelResObtenu->setObjectName(QStringLiteral("labelResObtenu"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelResObtenu);

        lcdNumberResObtenu = new QLCDNumber(groupBox_2);
        lcdNumberResObtenu->setObjectName(QStringLiteral("lcdNumberResObtenu"));
        lcdNumberResObtenu->setFrameShape(QFrame::NoFrame);
        lcdNumberResObtenu->setFrameShadow(QFrame::Plain);
        lcdNumberResObtenu->setDigitCount(22);
        lcdNumberResObtenu->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lcdNumberResObtenu);

        labelResEspere = new QLabel(groupBox_2);
        labelResEspere->setObjectName(QStringLiteral("labelResEspere"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelResEspere);

        lcdNumberResEspere = new QLCDNumber(groupBox_2);
        lcdNumberResEspere->setObjectName(QStringLiteral("lcdNumberResEspere"));
        lcdNumberResEspere->setFrameShape(QFrame::NoFrame);
        lcdNumberResEspere->setFrameShadow(QFrame::Plain);
        lcdNumberResEspere->setDigitCount(22);
        lcdNumberResEspere->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lcdNumberResEspere);

        labelResRatio = new QLabel(groupBox_2);
        labelResRatio->setObjectName(QStringLiteral("labelResRatio"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelResRatio);

        lcdNumberResRatio = new QLCDNumber(groupBox_2);
        lcdNumberResRatio->setObjectName(QStringLiteral("lcdNumberResRatio"));
        lcdNumberResRatio->setFrameShape(QFrame::NoFrame);
        lcdNumberResRatio->setFrameShadow(QFrame::Plain);
        lcdNumberResRatio->setSmallDecimalPoint(false);
        lcdNumberResRatio->setDigitCount(22);
        lcdNumberResRatio->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lcdNumberResRatio);


        verticalLayout_3->addLayout(formLayout_2);


        verticalLayout_2->addWidget(groupBox_2);

        progressBar = new QProgressBar(Dialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(false);
        progressBar->setMinimum(0);
        progressBar->setMaximum(1);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);

        verticalLayout_2->addWidget(progressBar);

        startButton = new QPushButton(Dialog);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout_2->addWidget(startButton);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "PCO | Labo 1", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "Param\303\250tres", 0));
        labelNbThreads->setText(QApplication::translate("Dialog", "Nombre de threads", 0));
        labelNbIterations->setText(QApplication::translate("Dialog", "It\303\251rations", 0));
        groupBox_2->setTitle(QApplication::translate("Dialog", "R\303\251sultats", 0));
        labelResObtenu->setText(QApplication::translate("Dialog", "R\303\251sultat obtenu", 0));
        labelResEspere->setText(QApplication::translate("Dialog", "R\303\251sultat esp\303\251r\303\251", 0));
        labelResRatio->setText(QApplication::translate("Dialog", "Ratio (%)", 0));
        startButton->setText(QApplication::translate("Dialog", "Start !", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H