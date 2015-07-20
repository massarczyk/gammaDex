#include "mainwindow.h"
#include "ui_mainwindow.h"


//******************************************************************************
MainWindow::MainWindow(QMainWindow *parent)
    :  QMainWindow(parent),
    ui(new Ui::MainWindow)
{   //recall Objects from gui
    AnalysisWidget = 0;
    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{;
    delete ui;
}
//******************************************************************************

//______________________________________________________________________________
void MainWindow::init()
{   //initialisation of the gui
    //recall objects from .ui file and connect them with user functions


    ui_ConvertButton    = this->findChild<QCommandLinkButton*>("ConvertButton");
    ui_ExitButton       = this->findChild<QCommandLinkButton*>("ExitButton");
    ui_OutputButton     = this->findChild<QCommandLinkButton*>("OutputButton");

    connect(ui_ConvertButton,   SIGNAL(clicked()), this, SLOT(DoConvert()));
    connect(ui_ExitButton,      SIGNAL(clicked()), this, SLOT(DoExit()));
    connect(ui_OutputButton,      SIGNAL(clicked()), this, SLOT(DoOutput()));

    ui_actionExit = this->findChild<QAction*>("actionExit");
    ui_actionLoad = this->findChild<QAction*>("actionLoad");
    ui_actionSave = this->findChild<QAction*>("actionSave");
    connect(ui_actionExit, SIGNAL(triggered()), this, SLOT(DoExit()));
    connect(ui_actionSave, SIGNAL(triggered()), this, SLOT(DoSave()));
    connect(ui_actionLoad, SIGNAL(triggered()), this, SLOT(DoLoad()));


    ui_EmaxSpinBox         = this->findChild<QSpinBox*>("EmaxSpinBox");
    ui_BinSizeSpinBox      = this->findChild<QSpinBox*>("BinSizeSpinBox");
    ui_ASpinBox            = this->findChild<QSpinBox*>("ASpinBox");
    ui_ZSpinBox            = this->findChild<QSpinBox*>("ZSpinBox");

    ui_SpinParitySpinBox   = this->findChild<QDoubleSpinBox*>("SpinParitySpinBox");
    ui_SpinParitySpinBox_2   = this->findChild<QDoubleSpinBox*>("SpinParitySpinBox_2");
    ui_SpinParitySpinBox_n1  = this->findChild<QDoubleSpinBox*>("SpinParitySpinBox_n1");
    ui_SpinParitySpinBox_n2  = this->findChild<QDoubleSpinBox*>("SpinParitySpinBox_n2");
    ui_TorASpinBox_1       = this->findChild<QDoubleSpinBox*>("TorASpinBox_1");
    ui_TorASpinBox_2       = this->findChild<QDoubleSpinBox*>("TorASpinBox_2");
    ui_PairSpinBox         = this->findChild<QDoubleSpinBox*>("PairSpinBox");
    ui_ParityBox         = this->findChild<QDoubleSpinBox*>("ParityBox");

    ui_E1doubleSpinBox_1   = this->findChild<QDoubleSpinBox*>("E1doubleSpinBox_1");
    ui_E1doubleSpinBox_2   = this->findChild<QDoubleSpinBox*>("E1doubleSpinBox_2");
    ui_E1doubleSpinBox_3   = this->findChild<QDoubleSpinBox*>("E1doubleSpinBox_3");
    ui_E1doubleSpinBox_4   = this->findChild<QDoubleSpinBox*>("E1doubleSpinBox_4");
    ui_E1doubleSpinBox_5   = this->findChild<QDoubleSpinBox*>("E1doubleSpinBox_5");
    ui_E1doubleSpinBox_6   = this->findChild<QDoubleSpinBox*>("E1doubleSpinBox_6");
    ui_M1doubleSpinBox_1   = this->findChild<QDoubleSpinBox*>("M1doubleSpinBox_1");


    ui_OutputLabel    = this->findChild<QLabel*>("OutputLabel");
    ui_TorALabel_1    = this->findChild<QLabel*>("TorALabel_1");
    ui_TorALabel_2    = this->findChild<QLabel*>("TorALabel_2");
    ui_EmaxLabel      = this->findChild<QLabel*>("EmaxLabel");
    ui_E1label_1      = this->findChild<QLabel*>("E1Label_1");
    ui_E1label_2      = this->findChild<QLabel*>("E1Label_2");
    ui_E1label_3      = this->findChild<QLabel*>("E1Label_3");
    ui_E1label_4      = this->findChild<QLabel*>("E1Label_4");
    ui_E1label_5      = this->findChild<QLabel*>("E1Label_5");
    ui_E1label_6      = this->findChild<QLabel*>("E1Label_6");
    ui_M1label_1      = this->findChild<QLabel*>("M1Label_1");
    ui_M1label_2      = this->findChild<QLabel*>("M1Label_2");
    ui_Levellabel     = this->findChild<QLabel*>("Levellabel");
    ui_Spectrumlabel  = this->findChild<QLabel*>("SpectrumLabel");

    ui_progressbar      = this->findChild<QProgressBar*>("progressBar");

    ui_E1pushButton      = this->findChild<QPushButton*>("E1pushButton");
    connect(ui_E1pushButton, SIGNAL(clicked()),this,SLOT(DoSelectfile1()));

    ui_M1pushButton      = this->findChild<QPushButton*>("M1pushButton");
    connect(ui_M1pushButton, SIGNAL(clicked()),this,SLOT(DoSelectfile2()));

    ui_LevelpushButton      = this->findChild<QPushButton*>("LevelpushButton");
    connect(ui_LevelpushButton, SIGNAL(clicked()),this,SLOT(DoSelectfile3()));

    ui_LevelpushButton_2      = this->findChild<QPushButton*>("LevelpushButton_2");
    connect(ui_LevelpushButton_2, SIGNAL(clicked()),this,SLOT(Clear()));

    ui_SpectrumButton      = this->findChild<QPushButton*>("SpectrumButton");
    connect(ui_SpectrumButton, SIGNAL(clicked()),this,SLOT(DoSelectfile4()));

    ui_DensityEnergyComboBox = this->findChild<QComboBox*>("DensityEnergyComboBox");
    connect(ui_DensityEnergyComboBox,SIGNAL(currentIndexChanged(int)) ,this,SLOT(DoModel()));

    ui_ReactionComboBox = this->findChild<QComboBox*>("ReactionComboBox");
    connect(ui_ReactionComboBox,SIGNAL(currentIndexChanged(int)) ,this,SLOT(DoEmax()));

    ui_E1StrengthComboBox = this->findChild<QComboBox*>("E1StrengthComboBox");
    connect(ui_E1StrengthComboBox,SIGNAL(currentIndexChanged(int)) ,this,SLOT(DoE1()));

    ui_M1StrengthComboBox = this->findChild<QComboBox*>("M1StrengthComboBox");
    connect(ui_M1StrengthComboBox,SIGNAL(currentIndexChanged(int)) ,this,SLOT(DoM1()));

    ui_E1pushButton->hide();  
    ui_E1label_6->hide();
    ui_E1doubleSpinBox_3->hide();
    ui_E1doubleSpinBox_4->hide();
    ui_E1doubleSpinBox_5->hide();
    ui_E1doubleSpinBox_6->hide();

    ui_M1label_1->hide();
    ui_M1label_2->hide();
    ui_M1doubleSpinBox_1->hide();
    ui_M1pushButton->hide();

    ui_Spectrumlabel->hide();
    ui_SpectrumButton->hide();


}

//______________________________________________________________________________
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
//        ui->retranslateUi(this);
        retranslateUi(this);
        break;
    default:
        break;
    }
}



//______________________________________________________________________________
void MainWindow::DoConvert(){

 // gettimeofday(&start, 0);
  t1.restart();

  ui_progressbar->setValue(0);


  AnalysisWidget = new Analysis(this);
  AnalysisWidget->Emax = ui_EmaxSpinBox->value();
  AnalysisWidget->binning = ui_BinSizeSpinBox->value();
  AnalysisWidget->spin = ui_SpinParitySpinBox->value();
  AnalysisWidget->parity = ui_SpinParitySpinBox_2->value();
  AnalysisWidget->CTorBSFG = ui_DensityEnergyComboBox->currentIndex();
  AnalysisWidget->param1 = ui_TorASpinBox_1->value();
  AnalysisWidget->param2 = ui_TorASpinBox_2->value();
  AnalysisWidget->A = ui_ASpinBox->value();
  AnalysisWidget->Z = ui_ZSpinBox->value();
  AnalysisWidget->Pair = ui_PairSpinBox->value();
  AnalysisWidget->Parity_average = ui_ParityBox->value();
  AnalysisWidget->spin_ex = ui_SpinParitySpinBox_n1->value();
  AnalysisWidget->parity_ex = ui_SpinParitySpinBox_n2->value();

  AnalysisWidget->Calculate();
  AnalysisWidget->SetStrength(ui_E1StrengthComboBox->currentIndex(),ui_M1StrengthComboBox->currentIndex());
  if (ui_Levellabel->text().isEmpty()==false)  {AnalysisWidget->ReplaceLevels(ui_Levellabel->text());}

  if(ui_ReactionComboBox->currentIndex()==0){
      AnalysisWidget->Decay();
  }
  if((ui_ReactionComboBox->currentIndex()==1)&&(ui_Spectrumlabel->text().isEmpty()==false)){
      ui_SpinParitySpinBox_n1->setValue(ui_SpinParitySpinBox->value());
      AnalysisWidget->LoadSpectrum(ui_Spectrumlabel->text());

      AnalysisWidget->GammaGamma();
  }
  if((ui_ReactionComboBox->currentIndex()==1)&&(ui_Spectrumlabel->text().isEmpty()==true)){
    DoError("No Gamma Spectrum given");
  }

  gettimeofday(&end, 0);

  int a = t1.elapsed()/1000;
  QString s ;
  s = "time needed : ";
  s += QString::number(a);
  s += " s";
  if (a>5){
    ui_OutputLabel->setText(s);
  }


//cout <<" Time needed:  "<< end.tv_sec-start.tv_sec<<"s  "<< t2< endl;

}
//______________________________________________________________________________
void MainWindow::DoError(string out){
    ui_OutputLabel->setText(QString::fromStdString(out));
}
//______________________________________________________________________________
void MainWindow::DoModel(){
string text1;
string text2;
string text3;

    if ((ui_DensityEnergyComboBox->currentIndex()==0)){
      text1 = "T";
      text2 = "E0";
      text3 = " MeV";
    }
    if ((ui_DensityEnergyComboBox->currentIndex()==1)){
      text1 = "a";
      text2 = "E1";
      text3 = " 1/MeV";
    }
   ui_TorALabel_1->setText(QString::fromStdString(text1));
   ui_TorALabel_2->setText(QString::fromStdString(text2));
   ui_OutputLabel->setText(QString::fromStdString("Level density model changed"));
   ui_TorASpinBox_1 ->setSuffix(QString::fromStdString(text3));
}
//______________________________________________________________________________
void MainWindow::DoEmax(){
string text;
if (ui_ReactionComboBox->currentIndex()==0)
{
    text = "En+Sn";
    ui->SpinParitySpinBox_n1->show();
    ui->SpinParitySpinBox_n2->show();
    ui->label_ngamma->show();
    ui_Spectrumlabel->hide();
    ui_SpectrumButton->hide();
}

if (ui_ReactionComboBox->currentIndex()==1)
{
    text = "Emax";
    ui->SpinParitySpinBox_n1->hide();
    ui->SpinParitySpinBox_n2->hide();
    ui->label_ngamma->hide();
    ui_Spectrumlabel->show();
    ui_SpectrumButton->show();
}
ui_EmaxLabel->setText(QString::fromStdString(text));
ui_OutputLabel->setText(QString::fromStdString("Reaction changed"));
}
//______________________________________________________________________________
void MainWindow::DoE1(){
ui_OutputLabel->setText(QString::fromStdString("E1 Strength model changed"));
string text1;
string text2;
string text3;
string text4;
string text5;
if (ui_E1StrengthComboBox->currentIndex()==0)
{
    text1 = "beta";
    text2 = "gamma";
    text3 = "";
    text4 = "";
    text5 = "";
    ui_E1label_6->clear();
    ui_E1label_6->hide();
    ui_E1pushButton->hide();
    ui_E1doubleSpinBox_1->setSuffix(QString::fromStdString(""));
    ui_E1doubleSpinBox_2->setSuffix(QString::fromStdString(" deg"));
    ui_E1doubleSpinBox_1->setMinimum(0);
    ui_E1doubleSpinBox_1->setMaximum(1);
    ui_E1doubleSpinBox_1->setSingleStep(0.02);
    ui_E1doubleSpinBox_2->setMinimum(0);
    ui_E1doubleSpinBox_2->setMaximum(60);
    ui_E1doubleSpinBox_2->setSingleStep(2);
    ui_E1doubleSpinBox_1->show();
    ui_E1doubleSpinBox_2->show();
    ui_E1doubleSpinBox_3->hide();
    ui_E1doubleSpinBox_4->hide();
    ui_E1doubleSpinBox_5->hide();
    ui_E1doubleSpinBox_6->hide();

    ui_M1label_1->hide();
    ui_M1doubleSpinBox_1->hide();




}
if (ui_E1StrengthComboBox->currentIndex()==1)
{
    text1 = "width";
    text2 = "E_max";
    text3 = "cs_max";
    text4 = "Lorentz 1";
    text5 = "Lorentz 2";
    ui_E1label_6->clear();
    ui_E1label_6->hide();
    ui_E1pushButton->hide();
    ui_E1doubleSpinBox_1->show();
    ui_E1doubleSpinBox_2->show();
    ui_E1doubleSpinBox_3->show();
    ui_E1doubleSpinBox_4->show();
    ui_E1doubleSpinBox_5->show();
    ui_E1doubleSpinBox_6->show();
    ui_E1doubleSpinBox_1->setMinimum(0);
    ui_E1doubleSpinBox_1->setMaximum(99.999);
    ui_E1doubleSpinBox_1->setSingleStep(1);
    ui_E1doubleSpinBox_2->setMinimum(0);
    ui_E1doubleSpinBox_2->setMaximum(99.999);
    ui_E1doubleSpinBox_2->setSingleStep(1);
    ui_E1doubleSpinBox_1->setSuffix(QString::fromStdString(" MeV"));
    ui_E1doubleSpinBox_2->setSuffix(QString::fromStdString(" MeV"));
    ui_E1doubleSpinBox_3->setSuffix(QString::fromStdString(" mb"));
    ui_E1doubleSpinBox_4->setSuffix(QString::fromStdString(" MeV"));
    ui_E1doubleSpinBox_5->setSuffix(QString::fromStdString(" MeV"));
    ui_E1doubleSpinBox_6->setSuffix(QString::fromStdString(" mb"));
    if (ui_M1StrengthComboBox->currentIndex()==0){
        ui_M1label_1->show();
        ui_M1doubleSpinBox_1->show();
    }
}
if (ui_E1StrengthComboBox->currentIndex()==2)
{
    text1 = "load own data - 1st column energy(keV), 2nd f in /keV^-3 ";
    text2 = "";
    text3 = "";
    text4 = "";
    text5 = "";
    ui_E1label_6->show();
    ui_E1pushButton->show();
    ui_E1doubleSpinBox_1->hide();
    ui_E1doubleSpinBox_2->hide();
    ui_E1doubleSpinBox_3->hide();
    ui_E1doubleSpinBox_4->hide();
    ui_E1doubleSpinBox_5->hide();
    ui_E1doubleSpinBox_6->hide();
    if (ui_M1StrengthComboBox->currentIndex()==0){
        ui_M1label_1->show();
        ui_M1doubleSpinBox_1->show();
    }

}

ui_E1label_1->setText(QString::fromStdString(text1));
ui_E1label_2->setText(QString::fromStdString(text2));
ui_E1label_3->setText(QString::fromStdString(text3));
ui_E1label_4->setText(QString::fromStdString(text4));
ui_E1label_5->setText(QString::fromStdString(text5));

}
//______________________________________________________________________________
void MainWindow::DoM1(){
    string text;
    ui_OutputLabel->setText(QString::fromStdString("M1 Strength model changed"));
    if (ui_M1StrengthComboBox->currentIndex()==0){
        text = "beta";
        ui_M1label_2->clear();
        ui_M1label_2->hide();
        ui_M1pushButton->hide();
        if (ui_E1StrengthComboBox->currentIndex()==0){
            ui_M1label_1->hide();
            ui_M1doubleSpinBox_1->hide();
        }
        else{
            ui_M1label_1->show();
            ui_M1label_1->setText(QString::fromStdString(text));
            ui_M1doubleSpinBox_1->show();
        }
    }
    else if (ui_M1StrengthComboBox->currentIndex()==1){
        ui_M1label_1->hide();
        ui_M1label_2->clear();
        ui_M1label_2->hide();
        ui_M1doubleSpinBox_1->hide();
        ui_M1pushButton->hide();
    }
    else {
        text = "load own data - 1st column energy(keV), 2nd f in /keV^-3 ";
        ui_M1label_1->show();
        ui_M1label_1->setText(QString::fromStdString(text));
        ui_M1label_2->show();
        ui_M1doubleSpinBox_1->hide();
        ui_M1pushButton->show();
    }
}

//______________________________________________________________________________
void MainWindow::DoExit(){
    //close application
    QApplication::quit();
}
//______________________________________________________________________________
void MainWindow::DoSelectfile1()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("QFileDialog::getOpenFileName()"),
                                ui_E1label_6->text(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
        ui_E1label_6->setText(fileName);
}
//______________________________________________________________________________
void MainWindow::DoSelectfile2()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("QFileDialog::getOpenFileName()"),
                                ui_M1label_2->text(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
        ui_M1label_2->setText(fileName);
}
//______________________________________________________________________________
void MainWindow::DoSelectfile3()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("QFileDialog::getOpenFileName()"),
                                ui_Levellabel->text(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
        ui_Levellabel->setText(fileName);
}
//______________________________________________________________________________
void MainWindow::DoSelectfile4()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("QFileDialog::getOpenFileName()"),
                                ui_Levellabel->text(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
        ui_Spectrumlabel->setText(fileName);
}
//______________________________________________________________________________
void MainWindow::DoOutput()
{
    ui_OutputLabel->setText(QString::fromStdString("write files"));

    QFileDialog::Options options;
    QString selectedFilter;
    QString OutputName = QFileDialog::getSaveFileName(this,
                                tr("QFileDialog::getSaveFileName()"),
                                0,
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);

    if (OutputName.isEmpty()){return;}
    QString out = OutputName + "_strengthfunctions.txt";
    QFile Strength_output(out);
    Strength_output.open(QIODevice::WriteOnly);
    QTextStream outStream(&Strength_output);
    for (k = 0;k<=(int)((ui_EmaxSpinBox->value())/(ui_BinSizeSpinBox->value()));k++){
      outStream << k*(ui_BinSizeSpinBox->value()) << " "<< AnalysisWidget->E1Strength[k]<<" "<<AnalysisWidget->M1Strength[k]<< " "<<AnalysisWidget->E2Strength[k]<<endl;
    }
    Strength_output.close();

    QString out3 = OutputName + "_levels.txt";
    QFile widths_output(out3);
    widths_output.open(QIODevice::WriteOnly);
    QTextStream outStream3(&widths_output);
    for ( int i =0;i<(AnalysisWidget->scheme.size());i++){
        outStream3  << AnalysisWidget->scheme[i].energy << "\t "
                    << (AnalysisWidget->scheme[i].spin)*(AnalysisWidget->scheme[i].parity)<< "\t"
                    << AnalysisWidget->scheme[i].levelnumber << "\t"
                    << AnalysisWidget->scheme[i].totalwidth/100./(2*(AnalysisWidget->scheme[i].spin)+1)*AnalysisWidget->scheme[i].levelnumber << "\t" //change average width to total width
                    << AnalysisWidget->scheme[i].gswidth << "\t"
                    << AnalysisWidget->scheme[i].S << endl;
    }
    widths_output.close();


    QFile output(OutputName);
    output.open(QIODevice::WriteOnly);
    QTextStream outa(&output);
    outa << "### GammaDex2.0 by R.Massarczyk and G.Schramm"<<endl;
    outa << "### Status 2012/2013 , see also PHYSICAL REVIEW C 85, 014311"<<endl;
    outa << "### contact r.massarczyk@hzdr.de"<<endl;
    output.close();


    DoSave(OutputName+"_parameter.txt");

    if(ui_ReactionComboBox->currentIndex()==0){

        QString out1 = OutputName + "_strengthfunctions_excitedstate.txt";
        QFile Strength_output1(out1);
        Strength_output1.open(QIODevice::WriteOnly);
        QTextStream outStream1(&Strength_output1);
        for (k = 0;k<=(int)((ui_EmaxSpinBox->value())/(ui_BinSizeSpinBox->value()));k++){
          outStream1 << k*(ui_BinSizeSpinBox->value()) << " "<< AnalysisWidget->E1Strength_ex[k]<<" "<<AnalysisWidget->M1Strength_ex[k]<< " "<<AnalysisWidget->E2Strength_ex[k]<<endl;
        }
        Strength_output1.close();


        QString out2 = OutputName + "_gammaspectra.txt";
        QFile Gamma_output(out2);
        Gamma_output.open(QIODevice::WriteOnly);
        QTextStream outStream2(&Gamma_output);
        int a  = (int)(AnalysisWidget->GetIndex(ui_EmaxSpinBox->value(),ui->SpinParitySpinBox_n1->value(),ui->SpinParitySpinBox_n2->value()));
        //cout <<"here"<< a <<endl;
        for (k = 0;k<=(int)((ui_EmaxSpinBox->value())/(ui_BinSizeSpinBox->value()));k++){
           outStream2 << k*(ui_BinSizeSpinBox->value()) << " "<< AnalysisWidget->scheme[a].spectrum[k] <<" "<<AnalysisWidget->scheme[a].spectrum_primary[k]<<endl;
        }
        Gamma_output.close();
    }

    if(ui_ReactionComboBox->currentIndex()==1){

        QString out1 = OutputName + "_branching.txt";
        QFile branch_output1(out1);
        branch_output1.open(QIODevice::WriteOnly);
        QTextStream outStream1(&branch_output1);
        for (k = 0;k<=(int)((ui_EmaxSpinBox->value())/(ui_BinSizeSpinBox->value()));k++){
          outStream1 << k*(ui_BinSizeSpinBox->value()) << " "<< AnalysisWidget->branching[k] <<endl;
        }
        branch_output1.close();

        QString out2 = OutputName + "_output.txt";
        QFile Gamma_output(out2);
        Gamma_output.open(QIODevice::WriteOnly);
        QTextStream outStream2(&Gamma_output);
        int a  = (int)(AnalysisWidget->GetIndex(ui_EmaxSpinBox->value(),ui->SpinParitySpinBox_n1->value(),ui->SpinParitySpinBox_n2->value()));
        //cout <<"here"<< a <<endl;
        for (k = 0;k<=(int)((ui_EmaxSpinBox->value())/(ui_BinSizeSpinBox->value()));k++){
           outStream2 << k*(ui_BinSizeSpinBox->value()) << " "<< AnalysisWidget->GammaSpectrum[k] <<" "<<AnalysisWidget->GammaSpectrum_new[k] <<endl;
        }
        Gamma_output.close();

    }
}
//______________________________________________________________________________
void MainWindow::DoSave()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QString OutputName = QFileDialog::getSaveFileName(this,
                                tr("QFileDialog::Save File for Parameter()"),
                                0,
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    QFile Output(OutputName);
    Output.open(QIODevice::WriteOnly);
    QTextStream outStream(&Output);
    outStream<<"#1 - ng or gg :"<<ui_ReactionComboBox->currentIndex()<<endl;
    outStream<<"#2 - Emax or Sn+En :"<<ui_EmaxSpinBox->value() <<endl;
    outStream<<"#3 - Binning :"<<ui_BinSizeSpinBox->value() <<endl;
    outStream<<"#4 - A :"<<ui_ASpinBox->value() <<endl;
    outStream<<"#5 - Z :"<<ui_ZSpinBox->value() <<endl;
    outStream<<"#6 - ground state spin :"<<ui_SpinParitySpinBox->value() <<endl;
    outStream<<"#7 - ground state parity :"<<ui_SpinParitySpinBox_2->value() <<endl;
    if (ui_ReactionComboBox->currentIndex() == 0){
        outStream<<"#8 - excited state spin :"<<ui_SpinParitySpinBox_n1->value() <<endl;
        outStream<<"#9 - excited state parity :"<<ui_SpinParitySpinBox_n2->value() <<endl;
    }
    outStream<<"#10 - CT or BSFG :"<<ui_DensityEnergyComboBox->currentIndex() <<endl;
    outStream<<"#11 - T or a (MeV) :"<<ui_TorASpinBox_1->value() <<endl;
    outStream<<"#12 - E0 or E1 (MeV) :"<<ui_TorASpinBox_2->value() <<endl;
    outStream<<"#13 - Pairing energy (MeV) :"<<ui_PairSpinBox->value() <<endl;
    outStream<<"#14 - E1 Strength Model :"<<ui_E1StrengthComboBox->currentIndex() <<endl;
    outStream<<"#15 - M1 Strength Model :"<<ui_M1StrengthComboBox->currentIndex() <<endl;
    if (ui_M1StrengthComboBox->currentIndex() == 0){
        if (ui_E1StrengthComboBox->currentIndex() != 0){
            outStream<<"#16 - gamma :"<<ui_M1doubleSpinBox_1->value() <<endl;
        }
    }
    if (ui_E1StrengthComboBox->currentIndex() == 0){
        outStream<<"#16 - gamma :"<<ui_E1doubleSpinBox_1->value() <<endl;
        outStream<<"#17 - beta :"<<ui_E1doubleSpinBox_2->value() <<endl;
    }
    if (ui_E1StrengthComboBox->currentIndex() == 1){
        outStream<<"#18 - width1 (MeV):"<<ui_E1doubleSpinBox_1->value() <<endl;
        outStream<<"#19 - EMax1 (MeV) :"<<ui_E1doubleSpinBox_2->value() <<endl;
        outStream<<"#20 - csMax1 (mb) :"<<ui_E1doubleSpinBox_3->value() <<endl;
        outStream<<"#21 - width2 (MeV):"<<ui_E1doubleSpinBox_4->value() <<endl;
        outStream<<"#22 - EMax2 (MeV) :"<<ui_E1doubleSpinBox_5->value() <<endl;
        outStream<<"#23 - csMax2 (mb) :"<<ui_E1doubleSpinBox_6->value() <<endl;
    }
    if (ui_E1StrengthComboBox->currentIndex() == 2){
        outStream<<"#comments:  own E1Strength"<<endl;
    }

    if (ui_M1StrengthComboBox->currentIndex() == 2){
        outStream<<"#comments:  own M1Strength"<<endl;
    }
    Output.close();
}
//______________________________________________________________________________
void MainWindow::DoSave(QString OutputName)
{
    QFile Output(OutputName);
    Output.open(QIODevice::WriteOnly);
    QTextStream outStream(&Output);
    outStream<<"#1 - ng or gg :"<<ui_ReactionComboBox->currentIndex()<<endl;
    outStream<<"#2 - Emax or Sn+En :"<<ui_EmaxSpinBox->value() <<endl;
    outStream<<"#3 - Binning :"<<ui_BinSizeSpinBox->value() <<endl;
    outStream<<"#4 - A :"<<ui_ASpinBox->value() <<endl;
    outStream<<"#5 - Z :"<<ui_ZSpinBox->value() <<endl;
    outStream<<"#6 - ground state spin :"<<ui_SpinParitySpinBox->value() <<endl;
    outStream<<"#7 - ground state parity :"<<ui_SpinParitySpinBox_2->value() <<endl;
    if (ui_ReactionComboBox->currentIndex() == 0){
        outStream<<"#8 - excited state spin :"<<ui_SpinParitySpinBox_n1->value() <<endl;
        outStream<<"#9 - excited state parity :"<<ui_SpinParitySpinBox_n2->value() <<endl;
    }
    outStream<<"#10 - CT or BSFG :"<<ui_DensityEnergyComboBox->currentIndex() <<endl;
    outStream<<"#11 - T or a (MeV) :"<<ui_TorASpinBox_1->value() <<endl;
    outStream<<"#12 - E0 or E1 (MeV) :"<<ui_TorASpinBox_2->value() <<endl;
    outStream<<"#13 - Pairing energy (MeV) :"<<ui_PairSpinBox->value() <<endl;
    outStream<<"#14 - E1 Strength Model :"<<ui_E1StrengthComboBox->currentIndex() <<endl;
    outStream<<"#15 - M1 Strength Model :"<<ui_M1StrengthComboBox->currentIndex() <<endl;
    if (ui_M1StrengthComboBox->currentIndex() == 0){
        if (ui_E1StrengthComboBox->currentIndex() != 0){
            outStream<<"#16 - gamma :"<<ui_M1doubleSpinBox_1->value() <<endl;
        }
    }
    if (ui_E1StrengthComboBox->currentIndex() == 0){
        outStream<<"#16 - gamma :"<<ui_E1doubleSpinBox_1->value() <<endl;
        outStream<<"#17 - beta :"<<ui_E1doubleSpinBox_2->value() <<endl;
    }
    if (ui_E1StrengthComboBox->currentIndex() == 1){
        outStream<<"#18 - width1 (MeV):"<<ui_E1doubleSpinBox_1->value() <<endl;
        outStream<<"#19 - EMax1 (MeV) :"<<ui_E1doubleSpinBox_2->value() <<endl;
        outStream<<"#20 - csMax1 (mb) :"<<ui_E1doubleSpinBox_3->value() <<endl;
        outStream<<"#21 - width2 (MeV):"<<ui_E1doubleSpinBox_4->value() <<endl;
        outStream<<"#22 - EMax2 (MeV) :"<<ui_E1doubleSpinBox_5->value() <<endl;
        outStream<<"#23 - csMax2 (mb) :"<<ui_E1doubleSpinBox_6->value() <<endl;
    }
    if (ui_E1StrengthComboBox->currentIndex() == 2){
        outStream<<"#comments:  own E1Strength"<<endl;
    }

    if (ui_M1StrengthComboBox->currentIndex() == 2){
        outStream<<"#comments:  own M1Strength"<<endl;
    }
    Output.close();
}

//______________________________________________________________________________
void MainWindow::DoLoad()
{
    QString line, subline;
    float subnumber;
    QFileDialog::Options options;
    QString selectedFilter;
    QString InputName = QFileDialog::getOpenFileName(this,
                                tr("QFileDialog::Load File for Parameter()"),
                                0,
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    QFile Input(InputName);
    if (Input.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&Input);
            while (!in.atEnd()) {
                line = in.readLine();
                if (line.left(3) == "#1 "){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_ReactionComboBox->setCurrentIndex((int)subnumber);
                   // cout<< subnumber << endl;
                }
                if (line.left(3) == "#2 "){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_EmaxSpinBox->setValue((int)subnumber);
                }
                if (line.left(2) == "#3"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_BinSizeSpinBox->setValue((int)subnumber);
                }
                if (line.left(2) == "#4"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_ASpinBox->setValue((int)subnumber);
                }
                if (line.left(2) == "#5"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_ZSpinBox->setValue((int)subnumber);
                }
                if (line.left(2) == "#6"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_SpinParitySpinBox->setValue(subnumber);
                }
                if (line.left(2) == "#7"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_SpinParitySpinBox_2->setValue(subnumber);
                }
                if (line.left(2) == "#8"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_SpinParitySpinBox_n1->setValue(subnumber);
                }
                if (line.left(2) == "#9"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_SpinParitySpinBox_n2->setValue(subnumber);
                }
                if (line.left(3) == "#10"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_DensityEnergyComboBox->setCurrentIndex((int)subnumber);
                }
                if (line.left(3) == "#11"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_TorASpinBox_1->setValue(subnumber);
                }
                if (line.left(3) == "#12"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_TorASpinBox_2->setValue(subnumber);
                }
                if (line.left(3) == "#13"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_PairSpinBox->setValue(subnumber);
                }
                if (line.left(3) == "#14"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_E1StrengthComboBox->setCurrentIndex((int)subnumber);
                }
                if (line.left(3) == "#15"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    ui_M1StrengthComboBox->setCurrentIndex((int)subnumber);
                }
                if (line.left(3) == "#16"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    if (ui_E1StrengthComboBox->currentIndex() == 0){ui_E1doubleSpinBox_1->setValue(subnumber);}
                    if (ui_M1StrengthComboBox->currentIndex() == 0){ui_M1doubleSpinBox_1->setValue(subnumber);}
                }
                if (line.left(3) == "#17"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    if (ui_E1StrengthComboBox->currentIndex() == 0){ui_E1doubleSpinBox_2->setValue(subnumber);}
                }
                if (line.left(3) == "#18"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    if (ui_E1StrengthComboBox->currentIndex() == 1){ui_E1doubleSpinBox_1->setValue(subnumber);}
                }
                if (line.left(3) == "#19"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    if (ui_E1StrengthComboBox->currentIndex() == 1){ui_E1doubleSpinBox_2->setValue(subnumber);}
                }
                if (line.left(3) == "#20"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    if (ui_E1StrengthComboBox->currentIndex() == 1){ui_E1doubleSpinBox_3->setValue(subnumber);}
                }
                if (line.left(3) == "#21"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    if (ui_E1StrengthComboBox->currentIndex() == 1){ui_E1doubleSpinBox_4->setValue(subnumber);}
                }
                if (line.left(3) == "#22"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    if (ui_E1StrengthComboBox->currentIndex() == 1){ui_E1doubleSpinBox_5->setValue(subnumber);}
                }
                if (line.left(3) == "#23"){
                    subline = line.right(line.size()-line.indexOf(":")-1);
                    subnumber = subline.toDouble();
                    if (ui_E1StrengthComboBox->currentIndex() == 1){ui_E1doubleSpinBox_6->setValue(subnumber);}
                }


            }
        Input.close();
    }
}
//______________________________________________________________________________
void MainWindow::Clear()
{
    ui_Levellabel->clear();
}
