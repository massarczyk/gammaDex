/*******************************************************************************
 *
 *  mainwindow.h : class header for AcqirisDaq GUI
 *------------------------------------------------------------------------------
 ******************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//std. c includes
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sys/time.h>

using namespace std;

//GUI include
#include "ui_mainwindow.h"

//myClass includes
#include "analysis.h"


//Qt includes
#include <QApplication>
#include <QAction>
#include <QMainWindow>
#include <QFileDialog>
#include <QCommandLinkButton>
#include <QString>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QList>
#include <QUrl>
#include <QLabel>
#include <QProgressBar>
#include <QTime>


#ifdef __MAKECINT__
#pragma link C++ class vector<vector<float> >+;
#endif

class Analysis;




class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QMainWindow *parent = 0);
    virtual ~MainWindow();

    void                DoError(string);

    QDoubleSpinBox      *ui_E1doubleSpinBox_1,*ui_E1doubleSpinBox_2,*ui_E1doubleSpinBox_3,
                        *ui_E1doubleSpinBox_4,*ui_E1doubleSpinBox_5,*ui_E1doubleSpinBox_6,
                        *ui_M1doubleSpinBox_1;

    QLabel              *ui_E1label_6,*ui_M1label_2;

    QProgressBar        *ui_progressbar;
    

public slots:
    virtual void init();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow      *ui;
    QCommandLinkButton  *ui_ExitButton, *ui_ConvertButton, *ui_OutputButton;

    //QAction             *ui_actionConvert, *ui_actionExit;

    QSpinBox            *ui_EmaxSpinBox, *ui_BinSizeSpinBox,
                        *ui_ASpinBox, *ui_ZSpinBox;

    QDoubleSpinBox      *ui_SpinParitySpinBox,*ui_SpinParitySpinBox_2, *ui_PairSpinBox, *ui_ParityBox,
                        *ui_TorASpinBox_1, *ui_TorASpinBox_2,
                        *ui_SpinParitySpinBox_n1,*ui_SpinParitySpinBox_n2;


    QLabel              *ui_OutputLabel, *ui_EmaxLabel,
                        *ui_TorALabel_1, *ui_TorALabel_2,
                        *ui_label_ngamma,
                        *ui_E1label_1,*ui_E1label_2,*ui_E1label_3,
                        *ui_E1label_4,*ui_E1label_5,
                        *ui_M1label_1,
                        *ui_Levellabel,
                        *ui_Spectrumlabel;

    QComboBox           *ui_DensityEnergyComboBox,*ui_ReactionComboBox,
                        *ui_E1StrengthComboBox,*ui_M1StrengthComboBox;

    QPushButton         *ui_E1pushButton,*ui_M1pushButton, *ui_LevelpushButton,
                        *ui_LevelpushButton_2, *ui_SpectrumButton;

    Analysis            *AnalysisWidget;

    timeval start, end;
    QTime t1, t2;

    int k;

    QAction             *ui_actionExit, *ui_actionSave, *ui_actionLoad;


private slots:
    void               DoConvert();
    void               DoExit();
    void               DoOutput();
    void               DoModel();
    void               DoEmax();
    void               DoE1();
    void               DoM1();
    void               DoSelectfile1();
    void               DoSelectfile2();
    void               DoSelectfile3();
    void               DoSelectfile4();
    void               DoLoad();
    void               DoSave();
    void               DoSave(QString);
    void               Clear();




};

#endif // MAINWINDOW_H

