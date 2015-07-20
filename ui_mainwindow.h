/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionExit;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QComboBox *ReactionComboBox;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout;
    QLabel *EmaxLabel;
    QSpinBox *EmaxSpinBox;
    QSpinBox *BinSizeSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLabel *label_4;
    QSpinBox *ASpinBox;
    QSpinBox *ZSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QLabel *label_ngamma;
    QDoubleSpinBox *SpinParitySpinBox;
    QDoubleSpinBox *SpinParitySpinBox_n1;
    QDoubleSpinBox *SpinParitySpinBox_2;
    QDoubleSpinBox *SpinParitySpinBox_n2;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_9;
    QGridLayout *gridLayout_4;
    QLabel *E1Label_1;
    QLabel *E1Label_2;
    QLabel *E1Label_3;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *E1doubleSpinBox_1;
    QLabel *E1Label_6;
    QDoubleSpinBox *E1doubleSpinBox_2;
    QDoubleSpinBox *E1doubleSpinBox_3;
    QDoubleSpinBox *E1doubleSpinBox_4;
    QDoubleSpinBox *E1doubleSpinBox_5;
    QDoubleSpinBox *E1doubleSpinBox_6;
    QComboBox *E1StrengthComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *E1Label_5;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *E1pushButton;
    QLabel *E1Label_4;
    QLabel *label_10;
    QGridLayout *gridLayout_5;
    QPushButton *M1pushButton;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *M1doubleSpinBox_1;
    QLabel *M1Label_2;
    QComboBox *M1StrengthComboBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *M1Label_1;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *E2StrengthComboBox;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_10;
    QCommandLinkButton *ConvertButton;
    QCommandLinkButton *OutputButton;
    QCommandLinkButton *ExitButton;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *SpectrumButton;
    QLabel *SpectrumLabel;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_7;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *ParityBox;
    QComboBox *DensityEnergyComboBox;
    QLabel *TorALabel_1;
    QLabel *TorALabel_2;
    QDoubleSpinBox *TorASpinBox_1;
    QDoubleSpinBox *TorASpinBox_2;
    QLabel *label_12;
    QLabel *label_7;
    QDoubleSpinBox *PairSpinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *Levellabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *LevelpushButton;
    QPushButton *LevelpushButton_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *OutputLabel;
    QMenuBar *menuBar;
    QMenu *MainMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(835, 671);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Buttons/HZDR.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(6, 0, 821, 641));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ReactionComboBox = new QComboBox(gridLayoutWidget_2);
        ReactionComboBox->setObjectName(QStringLiteral("ReactionComboBox"));
        ReactionComboBox->setMaximumSize(QSize(150, 16777215));
        ReactionComboBox->setInsertPolicy(QComboBox::InsertAtBottom);
        ReactionComboBox->setModelColumn(0);

        verticalLayout->addWidget(ReactionComboBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        EmaxLabel = new QLabel(gridLayoutWidget_2);
        EmaxLabel->setObjectName(QStringLiteral("EmaxLabel"));
        EmaxLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(EmaxLabel, 1, 0, 1, 1);

        EmaxSpinBox = new QSpinBox(gridLayoutWidget_2);
        EmaxSpinBox->setObjectName(QStringLiteral("EmaxSpinBox"));
        EmaxSpinBox->setMaximum(20000);
        EmaxSpinBox->setValue(5500);

        gridLayout->addWidget(EmaxSpinBox, 1, 1, 1, 1);

        BinSizeSpinBox = new QSpinBox(gridLayoutWidget_2);
        BinSizeSpinBox->setObjectName(QStringLiteral("BinSizeSpinBox"));
        BinSizeSpinBox->setMinimum(10);
        BinSizeSpinBox->setMaximum(1000);
        BinSizeSpinBox->setSingleStep(10);
        BinSizeSpinBox->setValue(100);

        gridLayout->addWidget(BinSizeSpinBox, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 3, 1, 1);

        ASpinBox = new QSpinBox(gridLayoutWidget_2);
        ASpinBox->setObjectName(QStringLiteral("ASpinBox"));
        ASpinBox->setMaximum(250);
        ASpinBox->setValue(196);

        gridLayout->addWidget(ASpinBox, 1, 4, 1, 1);

        ZSpinBox = new QSpinBox(gridLayoutWidget_2);
        ZSpinBox->setObjectName(QStringLiteral("ZSpinBox"));
        ZSpinBox->setMaximum(250);
        ZSpinBox->setValue(78);

        gridLayout->addWidget(ZSpinBox, 2, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 5, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 6, 1, 1);

        label_ngamma = new QLabel(gridLayoutWidget_2);
        label_ngamma->setObjectName(QStringLiteral("label_ngamma"));

        gridLayout->addWidget(label_ngamma, 2, 6, 1, 1);

        SpinParitySpinBox = new QDoubleSpinBox(gridLayoutWidget_2);
        SpinParitySpinBox->setObjectName(QStringLiteral("SpinParitySpinBox"));
        SpinParitySpinBox->setEnabled(true);
        SpinParitySpinBox->setDecimals(1);
        SpinParitySpinBox->setMinimum(0);
        SpinParitySpinBox->setMaximum(10);
        SpinParitySpinBox->setSingleStep(0.5);

        gridLayout->addWidget(SpinParitySpinBox, 1, 7, 1, 1);

        SpinParitySpinBox_n1 = new QDoubleSpinBox(gridLayoutWidget_2);
        SpinParitySpinBox_n1->setObjectName(QStringLiteral("SpinParitySpinBox_n1"));
        SpinParitySpinBox_n1->setDecimals(1);
        SpinParitySpinBox_n1->setMaximum(10);
        SpinParitySpinBox_n1->setSingleStep(0.5);
        SpinParitySpinBox_n1->setValue(1);

        gridLayout->addWidget(SpinParitySpinBox_n1, 2, 7, 1, 1);

        SpinParitySpinBox_2 = new QDoubleSpinBox(gridLayoutWidget_2);
        SpinParitySpinBox_2->setObjectName(QStringLiteral("SpinParitySpinBox_2"));
        SpinParitySpinBox_2->setEnabled(true);
        SpinParitySpinBox_2->setDecimals(0);
        SpinParitySpinBox_2->setMinimum(-1);
        SpinParitySpinBox_2->setMaximum(1);
        SpinParitySpinBox_2->setSingleStep(2);
        SpinParitySpinBox_2->setValue(1);

        gridLayout->addWidget(SpinParitySpinBox_2, 1, 8, 1, 1);

        SpinParitySpinBox_n2 = new QDoubleSpinBox(gridLayoutWidget_2);
        SpinParitySpinBox_n2->setObjectName(QStringLiteral("SpinParitySpinBox_n2"));
        SpinParitySpinBox_n2->setDecimals(0);
        SpinParitySpinBox_n2->setMinimum(-1);
        SpinParitySpinBox_n2->setMaximum(1);
        SpinParitySpinBox_n2->setSingleStep(2);
        SpinParitySpinBox_n2->setValue(-1);

        gridLayout->addWidget(SpinParitySpinBox_n2, 2, 8, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 8, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 7, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 5, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_5, 2, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(150, 16777215));
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_9, 5, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        E1Label_1 = new QLabel(gridLayoutWidget_2);
        E1Label_1->setObjectName(QStringLiteral("E1Label_1"));

        gridLayout_4->addWidget(E1Label_1, 0, 2, 1, 1);

        E1Label_2 = new QLabel(gridLayoutWidget_2);
        E1Label_2->setObjectName(QStringLiteral("E1Label_2"));

        gridLayout_4->addWidget(E1Label_2, 0, 3, 1, 1);

        E1Label_3 = new QLabel(gridLayoutWidget_2);
        E1Label_3->setObjectName(QStringLiteral("E1Label_3"));

        gridLayout_4->addWidget(E1Label_3, 0, 4, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        E1doubleSpinBox_1 = new QDoubleSpinBox(gridLayoutWidget_2);
        E1doubleSpinBox_1->setObjectName(QStringLiteral("E1doubleSpinBox_1"));
        E1doubleSpinBox_1->setMaximum(1);
        E1doubleSpinBox_1->setSingleStep(0.02);

        horizontalLayout_2->addWidget(E1doubleSpinBox_1);

        E1Label_6 = new QLabel(gridLayoutWidget_2);
        E1Label_6->setObjectName(QStringLiteral("E1Label_6"));
        E1Label_6->setMinimumSize(QSize(0, 20));
        E1Label_6->setMaximumSize(QSize(16777215, 20));
        E1Label_6->setAutoFillBackground(false);
        E1Label_6->setFrameShape(QFrame::WinPanel);
        E1Label_6->setFrameShadow(QFrame::Sunken);
        E1Label_6->setLineWidth(1);
        E1Label_6->setMidLineWidth(1);

        horizontalLayout_2->addWidget(E1Label_6);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        E1doubleSpinBox_2 = new QDoubleSpinBox(gridLayoutWidget_2);
        E1doubleSpinBox_2->setObjectName(QStringLiteral("E1doubleSpinBox_2"));
        E1doubleSpinBox_2->setMaximumSize(QSize(150, 16777215));
        E1doubleSpinBox_2->setMaximum(60);
        E1doubleSpinBox_2->setSingleStep(2);

        gridLayout_4->addWidget(E1doubleSpinBox_2, 1, 3, 1, 1);

        E1doubleSpinBox_3 = new QDoubleSpinBox(gridLayoutWidget_2);
        E1doubleSpinBox_3->setObjectName(QStringLiteral("E1doubleSpinBox_3"));
        E1doubleSpinBox_3->setMaximum(999.99);

        gridLayout_4->addWidget(E1doubleSpinBox_3, 1, 4, 1, 1);

        E1doubleSpinBox_4 = new QDoubleSpinBox(gridLayoutWidget_2);
        E1doubleSpinBox_4->setObjectName(QStringLiteral("E1doubleSpinBox_4"));
        E1doubleSpinBox_4->setMaximumSize(QSize(150, 16777215));

        gridLayout_4->addWidget(E1doubleSpinBox_4, 2, 2, 1, 1);

        E1doubleSpinBox_5 = new QDoubleSpinBox(gridLayoutWidget_2);
        E1doubleSpinBox_5->setObjectName(QStringLiteral("E1doubleSpinBox_5"));
        E1doubleSpinBox_5->setMaximumSize(QSize(150, 16777215));

        gridLayout_4->addWidget(E1doubleSpinBox_5, 2, 3, 1, 1);

        E1doubleSpinBox_6 = new QDoubleSpinBox(gridLayoutWidget_2);
        E1doubleSpinBox_6->setObjectName(QStringLiteral("E1doubleSpinBox_6"));
        E1doubleSpinBox_6->setMaximum(999.99);

        gridLayout_4->addWidget(E1doubleSpinBox_6, 2, 4, 1, 1);

        E1StrengthComboBox = new QComboBox(gridLayoutWidget_2);
        E1StrengthComboBox->setObjectName(QStringLiteral("E1StrengthComboBox"));
        E1StrengthComboBox->setMaximumSize(QSize(150, 16777215));

        gridLayout_4->addWidget(E1StrengthComboBox, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        E1Label_5 = new QLabel(gridLayoutWidget_2);
        E1Label_5->setObjectName(QStringLiteral("E1Label_5"));

        horizontalLayout_5->addWidget(E1Label_5);


        gridLayout_4->addLayout(horizontalLayout_5, 2, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        E1pushButton = new QPushButton(gridLayoutWidget_2);
        E1pushButton->setObjectName(QStringLiteral("E1pushButton"));
        E1pushButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(E1pushButton);

        E1Label_4 = new QLabel(gridLayoutWidget_2);
        E1Label_4->setObjectName(QStringLiteral("E1Label_4"));
        E1Label_4->setAutoFillBackground(false);

        horizontalLayout_6->addWidget(E1Label_4);


        gridLayout_4->addLayout(horizontalLayout_6, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 5, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(150, 16777215));
        label_10->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_10, 6, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        M1pushButton = new QPushButton(gridLayoutWidget_2);
        M1pushButton->setObjectName(QStringLiteral("M1pushButton"));
        M1pushButton->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(M1pushButton, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        M1doubleSpinBox_1 = new QDoubleSpinBox(gridLayoutWidget_2);
        M1doubleSpinBox_1->setObjectName(QStringLiteral("M1doubleSpinBox_1"));
        M1doubleSpinBox_1->setMaximumSize(QSize(150, 16777215));
        M1doubleSpinBox_1->setMaximum(1);
        M1doubleSpinBox_1->setSingleStep(0.02);

        horizontalLayout_3->addWidget(M1doubleSpinBox_1);

        M1Label_2 = new QLabel(gridLayoutWidget_2);
        M1Label_2->setObjectName(QStringLiteral("M1Label_2"));
        M1Label_2->setMinimumSize(QSize(0, 20));
        M1Label_2->setMaximumSize(QSize(16777215, 20));
        M1Label_2->setAutoFillBackground(false);
        M1Label_2->setFrameShape(QFrame::WinPanel);
        M1Label_2->setFrameShadow(QFrame::Sunken);
        M1Label_2->setLineWidth(1);
        M1Label_2->setMidLineWidth(1);

        horizontalLayout_3->addWidget(M1Label_2);


        gridLayout_5->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        M1StrengthComboBox = new QComboBox(gridLayoutWidget_2);
        M1StrengthComboBox->setObjectName(QStringLiteral("M1StrengthComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(M1StrengthComboBox->sizePolicy().hasHeightForWidth());
        M1StrengthComboBox->setSizePolicy(sizePolicy);
        M1StrengthComboBox->setMaximumSize(QSize(150, 16777215));
        M1StrengthComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout_5->addWidget(M1StrengthComboBox, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(150, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 0, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        M1Label_1 = new QLabel(gridLayoutWidget_2);
        M1Label_1->setObjectName(QStringLiteral("M1Label_1"));

        horizontalLayout_7->addWidget(M1Label_1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);


        gridLayout_5->addLayout(horizontalLayout_7, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_5, 6, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(150, 25));
        label_11->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_11, 7, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        E2StrengthComboBox = new QComboBox(gridLayoutWidget_2);
        E2StrengthComboBox->setObjectName(QStringLiteral("E2StrengthComboBox"));
        E2StrengthComboBox->setMinimumSize(QSize(150, 0));
        E2StrengthComboBox->setMaximumSize(QSize(150, 25));

        horizontalLayout_8->addWidget(E2StrengthComboBox);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        gridLayout_2->addLayout(horizontalLayout_8, 7, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_4, 8, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_5, 9, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer_6, 11, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        ConvertButton = new QCommandLinkButton(gridLayoutWidget_2);
        ConvertButton->setObjectName(QStringLiteral("ConvertButton"));
        ConvertButton->setMaximumSize(QSize(100, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ToolBarIcons/ToolBar/AddfromCDButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConvertButton->setIcon(icon1);
        ConvertButton->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(ConvertButton);

        OutputButton = new QCommandLinkButton(gridLayoutWidget_2);
        OutputButton->setObjectName(QStringLiteral("OutputButton"));
        OutputButton->setMaximumSize(QSize(100, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/AnalysisIcons/ToolBar/PHA.png"), QSize(), QIcon::Normal, QIcon::Off);
        OutputButton->setIcon(icon2);
        OutputButton->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(OutputButton);

        ExitButton = new QCommandLinkButton(gridLayoutWidget_2);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setMaximumSize(QSize(100, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ToolBarIcons/ToolBar/CloseButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExitButton->setIcon(icon3);
        ExitButton->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(ExitButton);


        gridLayout_2->addLayout(horizontalLayout_10, 11, 1, 1, 1);

        progressBar = new QProgressBar(gridLayoutWidget_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 10, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        SpectrumButton = new QPushButton(gridLayoutWidget_2);
        SpectrumButton->setObjectName(QStringLiteral("SpectrumButton"));
        SpectrumButton->setMaximumSize(QSize(100, 25));

        horizontalLayout_4->addWidget(SpectrumButton);

        SpectrumLabel = new QLabel(gridLayoutWidget_2);
        SpectrumLabel->setObjectName(QStringLiteral("SpectrumLabel"));
        SpectrumLabel->setMinimumSize(QSize(300, 20));
        SpectrumLabel->setMaximumSize(QSize(300, 20));
        SpectrumLabel->setAutoFillBackground(false);
        SpectrumLabel->setFrameShape(QFrame::WinPanel);
        SpectrumLabel->setFrameShadow(QFrame::Sunken);
        SpectrumLabel->setLineWidth(1);
        SpectrumLabel->setMidLineWidth(1);

        horizontalLayout_4->addWidget(SpectrumLabel);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        verticalSpacer_8 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_4->addItem(verticalSpacer_8);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_7, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        ParityBox = new QDoubleSpinBox(gridLayoutWidget_2);
        ParityBox->setObjectName(QStringLiteral("ParityBox"));
        ParityBox->setMaximum(1);
        ParityBox->setSingleStep(0.05);
        ParityBox->setValue(0.5);

        gridLayout_3->addWidget(ParityBox, 3, 2, 1, 1);

        DensityEnergyComboBox = new QComboBox(gridLayoutWidget_2);
        DensityEnergyComboBox->setObjectName(QStringLiteral("DensityEnergyComboBox"));
        DensityEnergyComboBox->setMaximumSize(QSize(150, 16777215));
        DensityEnergyComboBox->setEditable(false);
        DensityEnergyComboBox->setMaxVisibleItems(1);

        gridLayout_3->addWidget(DensityEnergyComboBox, 0, 0, 1, 1);

        TorALabel_1 = new QLabel(gridLayoutWidget_2);
        TorALabel_1->setObjectName(QStringLiteral("TorALabel_1"));

        gridLayout_3->addWidget(TorALabel_1, 0, 1, 1, 1);

        TorALabel_2 = new QLabel(gridLayoutWidget_2);
        TorALabel_2->setObjectName(QStringLiteral("TorALabel_2"));

        gridLayout_3->addWidget(TorALabel_2, 1, 1, 1, 1);

        TorASpinBox_1 = new QDoubleSpinBox(gridLayoutWidget_2);
        TorASpinBox_1->setObjectName(QStringLiteral("TorASpinBox_1"));
        TorASpinBox_1->setMaximum(100);
        TorASpinBox_1->setSingleStep(0.01);
        TorASpinBox_1->setValue(0.66);

        gridLayout_3->addWidget(TorASpinBox_1, 0, 2, 1, 1);

        TorASpinBox_2 = new QDoubleSpinBox(gridLayoutWidget_2);
        TorASpinBox_2->setObjectName(QStringLiteral("TorASpinBox_2"));
        TorASpinBox_2->setMinimum(-100);
        TorASpinBox_2->setMaximum(100);
        TorASpinBox_2->setSingleStep(0.01);
        TorASpinBox_2->setValue(-1.75);

        gridLayout_3->addWidget(TorASpinBox_2, 1, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 3, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 2, 1, 1, 1);

        PairSpinBox = new QDoubleSpinBox(gridLayoutWidget_2);
        PairSpinBox->setObjectName(QStringLiteral("PairSpinBox"));
        PairSpinBox->setDecimals(3);
        PairSpinBox->setMinimum(-10);
        PairSpinBox->setMaximum(10);
        PairSpinBox->setSingleStep(0.001);
        PairSpinBox->setValue(1.59);

        gridLayout_3->addWidget(PairSpinBox, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 3, 1, 1);

        Levellabel = new QLabel(gridLayoutWidget_2);
        Levellabel->setObjectName(QStringLiteral("Levellabel"));
        Levellabel->setEnabled(true);
        Levellabel->setMinimumSize(QSize(250, 20));
        Levellabel->setMaximumSize(QSize(250, 20));
        Levellabel->setAutoFillBackground(false);
        Levellabel->setFrameShape(QFrame::WinPanel);
        Levellabel->setFrameShadow(QFrame::Sunken);
        Levellabel->setLineWidth(1);
        Levellabel->setMidLineWidth(1);

        gridLayout_3->addWidget(Levellabel, 1, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LevelpushButton = new QPushButton(gridLayoutWidget_2);
        LevelpushButton->setObjectName(QStringLiteral("LevelpushButton"));

        horizontalLayout->addWidget(LevelpushButton);

        LevelpushButton_2 = new QPushButton(gridLayoutWidget_2);
        LevelpushButton_2->setObjectName(QStringLiteral("LevelpushButton_2"));

        horizontalLayout->addWidget(LevelpushButton_2);


        gridLayout_3->addLayout(horizontalLayout, 0, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 4, 1, 1, 1);

        OutputLabel = new QLabel(gridLayoutWidget_2);
        OutputLabel->setObjectName(QStringLiteral("OutputLabel"));
        OutputLabel->setAutoFillBackground(false);
        OutputLabel->setFrameShape(QFrame::Box);
        OutputLabel->setFrameShadow(QFrame::Plain);

        gridLayout_2->addWidget(OutputLabel, 9, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 835, 25));
        MainMenu = new QMenu(menuBar);
        MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(MainMenu->menuAction());
        MainMenu->addAction(actionSave);
        MainMenu->addAction(actionLoad);
        MainMenu->addAction(actionExit);

        retranslateUi(MainWindow);

        ReactionComboBox->setCurrentIndex(0);
        DensityEnergyComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "gDEX", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save Parameter", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load Parameter", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        ReactionComboBox->clear();
        ReactionComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "neutron capture", 0)
         << QApplication::translate("MainWindow", "photon scattering", 0)
        );
        EmaxLabel->setText(QApplication::translate("MainWindow", "En+Sn", 0));
        EmaxSpinBox->setSuffix(QApplication::translate("MainWindow", " keV", 0));
        BinSizeSpinBox->setSuffix(QApplication::translate("MainWindow", " keV", 0));
        label->setText(QApplication::translate("MainWindow", "A", 0));
        label_4->setText(QApplication::translate("MainWindow", "Z", 0));
        label_2->setText(QApplication::translate("MainWindow", "Ground State:", 0));
        label_ngamma->setText(QApplication::translate("MainWindow", "Excited state:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Parity", 0));
        label_6->setText(QApplication::translate("MainWindow", "Spin", 0));
        label_3->setText(QApplication::translate("MainWindow", "Binssize", 0));
        label_9->setText(QApplication::translate("MainWindow", "E1", 0));
        E1Label_1->setText(QApplication::translate("MainWindow", "beta", 0));
        E1Label_2->setText(QApplication::translate("MainWindow", "gamma", 0));
        E1Label_3->setText(QString());
        E1Label_6->setText(QString());
        E1doubleSpinBox_2->setSuffix(QApplication::translate("MainWindow", "\302\260", 0));
        E1StrengthComboBox->clear();
        E1StrengthComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Triple Lorentzian", 0)
         << QApplication::translate("MainWindow", "RIPL (1 or 2 Lorentzian)", 0)
         << QApplication::translate("MainWindow", "own", 0)
        );
        E1Label_5->setText(QString());
        E1pushButton->setText(QApplication::translate("MainWindow", "Browse...", 0));
        E1Label_4->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "M1", 0));
        M1pushButton->setText(QApplication::translate("MainWindow", "Browse...", 0));
        M1Label_2->setText(QString());
        M1StrengthComboBox->clear();
        M1StrengthComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Triple Gauss", 0)
         << QApplication::translate("MainWindow", "RIPL", 0)
         << QApplication::translate("MainWindow", "own", 0)
        );
        M1Label_1->setText(QApplication::translate("MainWindow", "beta", 0));
        label_11->setText(QApplication::translate("MainWindow", "E2", 0));
        E2StrengthComboBox->clear();
        E2StrengthComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "RIPL", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "Comments", 0));
        ConvertButton->setText(QApplication::translate("MainWindow", "Run", 0));
        OutputButton->setText(QApplication::translate("MainWindow", "Output", 0));
        ExitButton->setText(QApplication::translate("MainWindow", "Exit", 0));
        SpectrumButton->setText(QApplication::translate("MainWindow", "Load Spectrum", 0));
        SpectrumLabel->setText(QString());
        DensityEnergyComboBox->clear();
        DensityEnergyComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Constant-Temperature", 0)
         << QApplication::translate("MainWindow", "Back-Shifted-Fermi-Gas", 0)
        );
        TorALabel_1->setText(QApplication::translate("MainWindow", "T", 0));
        TorALabel_2->setText(QApplication::translate("MainWindow", "E0", 0));
        TorASpinBox_1->setSuffix(QApplication::translate("MainWindow", " MeV", 0));
        TorASpinBox_2->setSuffix(QApplication::translate("MainWindow", " MeV", 0));
        label_12->setText(QApplication::translate("MainWindow", "Parity ratio (pos par)", 0));
        label_7->setText(QApplication::translate("MainWindow", "Pairing Energy", 0));
        PairSpinBox->setSuffix(QApplication::translate("MainWindow", " MeV", 0));
        Levellabel->setText(QString());
        LevelpushButton->setText(QApplication::translate("MainWindow", "Use own levels...", 0));
        LevelpushButton_2->setText(QApplication::translate("MainWindow", "clear", 0));
        OutputLabel->setText(QApplication::translate("MainWindow", "0", 0));
        MainMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
