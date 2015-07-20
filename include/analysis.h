//---------------------start of analysis.h------------------------------------

#ifndef ANALYSIS_H
#define ANALYSIS_H

//std. c includes
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <math.h>

//QT includes
#include <QWidget>
#include <QString>
#include <QTextStream>



#include "mainwindow.h"


class MainWindow;

class Analysis : public QWidget
{
    MainWindow  *mainwindow_object;

public:
    struct bin{
       double energy;  //in keV
       double spin;
       double parity;
       double levelnumber;
       double spectrum[2000];
       double spectrum_primary[2000];
       double totalwidth;
       double gswidth;
       double S;
       double multiplicity;
    };

    Analysis(MainWindow*);
    virtual     ~Analysis();

    void        Calculate();
    void        Decay();
    void        GammaGamma();
    void        SetStrength(int,int);
    void        ReplaceLevels(QString);
    double      GetIndex(double, double, double);
    void        LoadSpectrum(QString);



    double Emax;
    double binning;
    double spin, parity;
    int CTorBSFG;
    double param1, param2;
    double A,N,Z;
    double Pair, Parity_average;
    int Reaction;



    double spin_ex, parity_ex;
    vector<bin> scheme, scheme2;
    double E1Strength[2000];
    double M1Strength[2000];
    double E2Strength[2000];

    double E1Strength_ex[2000];
    double M1Strength_ex[2000];
    double E2Strength_ex[2000];

    double GammaSpectrum[2000];
    double GammaSpectrum_new[2000];

    double branching[2000];

private:

    int i,k,l;
    double E_i,j,p;

    bin groundstate;
    bin state;


    double Number(double,double,double);

    double TLO_beta,TLO_gamma,
           TLO_norm,TLO_E0,
           TLO_E1,TLO_G1,TLO_CS1,
           TLO_E2,TLO_G2,TLO_CS2,
           TLO_E3,TLO_G3,TLO_CS3,
           TLO_Eg,TLO_R0,TLO_u;

    double  RIPL_E1,RIPL_G1,RIPL_CS1,
            RIPL_E2,RIPL_G2,RIPL_CS2,
            RIPL_Eg;

    QString  ownE1_path,ownM1_path;

    double Grosse_beta,
           Grosse_E0,Grosse_R0,Grosse_u;

    double RIPL_M1fE1, RIPL_M1A, RIPL_M1E0;

    double E2_E0, E2_gamma, E2_sigma;


    double Gammatot,Gamma, Etrans, ArraySum;

    double inputmaxenergy;

};

#endif // ANALYSIS_H

