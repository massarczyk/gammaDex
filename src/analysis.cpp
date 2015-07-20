//---------------------start of analysis.cpp----------------------------------

#include "include/analysis.h"
#include "mainwindow.h"

using namespace std;


//******************************************************************************
Analysis::Analysis(MainWindow *MWindow):mainwindow_object(MWindow){
}

Analysis::~Analysis(){
}
//******************************************************************************

void Analysis::Calculate(){
    mainwindow_object->DoError("Start building up level scheme");

    scheme.clear();
    N = A-Z;


    groundstate.energy = 0;
    groundstate.spin = spin;
    groundstate.parity=parity;
    groundstate.levelnumber = 1;


    if ((Number(binning,spin,parity)==Number(binning,spin,parity))&&(Number(binning,spin,parity)>0)){
       // cout << Number(binning,spin,parity) << endl;
        groundstate.levelnumber=Number(binning,spin,parity);
    }


    groundstate.S =1;
    groundstate.gswidth = 0;
    groundstate.totalwidth = 0;
    for (k=0;k<=(int)(Emax/binning)+1;k++){
        groundstate.spectrum[k]=0;
        groundstate.spectrum_primary[k]=0;
    }
    groundstate.multiplicity = 0;
    scheme.push_back(groundstate);

    E_i = binning;
    Emax = ((int)((Emax+binning/2)/binning))*binning;
    while (E_i <= (Emax)){                                        //build all bins
        // cout << "working bin: "<<E_i << endl;

        for (j=scheme[0].spin-6;j<=scheme[0].spin+6;j++){                //runs over spins
            if (j>=0){
                p=-1;                                                    //negative parity
                state.energy = E_i;
                state.spin = j;
                state.parity = p;
                state.levelnumber = Number(E_i,j,p);
                for (k=0;k<=(int)(Emax/binning)+1;k++){
                    state.spectrum[k]=0;
                    state.spectrum_primary[k]=0;
                }
                if ((fabs(state.spin-scheme[0].spin) <= 1) &&            // spin change
                    ((state.spin!=0)||(scheme[0].spin!=0)) &&                 // no spin 0<->0
                    (state.parity*scheme[0].parity)<0 &&
                    state.levelnumber>1 ){
                    state.S = 3-2.*exp(-0.08671329*(state.levelnumber))/(pow(state.levelnumber,0.25));
                }
                else if ((fabs(state.spin-scheme[0].spin) <= 1) &&            // spin change
                         ((state.spin!=0)||(scheme[0].spin!=0)) &&                 // no spin 0<->0
                         (state.parity*scheme[0].parity)>0 &&
                         state.levelnumber>1 ){
                    state.S = 3-2.*exp(-0.08671329*(state.levelnumber))/(pow(state.levelnumber,0.25));
                }
                else if ((fabs(state.spin-scheme[0].spin) <= 2) &&           // spin change
                         ((state.spin!=0)||(scheme[0].spin!=0)) &&           // no spin 0<->0
                         ((state.spin!=0)||(scheme[0].spin!=1)) &&           // no spin 0->1
                         ((state.spin!=1)||(scheme[0].spin!=0)) &&           // no spin 1->0
                         ((state.spin!=0.5)||(scheme[0].spin!=0.5)) &&       // no spin 0.5<->0.5
                         (state.parity*scheme[0].parity)>0 &&                // no parity change)
                         state.levelnumber>1){
                    state.S = 3-2.*exp(-0.08671329*(state.levelnumber))/(pow(state.levelnumber,0.25));
                }
                else {state.S = 1;}
                state.multiplicity = 0;
                scheme.push_back(state);


                p=+1;                                                    //positive parity
                state.energy = E_i;
                state.spin = j;
                state.parity = p;
                state.levelnumber = Number(E_i,j,p);
                for (k=0;k<=(int)(Emax/binning);k++){
                    state.spectrum[k]=0;
                    state.spectrum_primary[k]=0;
                }
                if ((fabs(state.spin-scheme[0].spin) <= 1) &&            // spin change
                    ((state.spin!=0)||(scheme[0].spin!=0)) &&                 // no spin 0<->0
                    (state.parity*scheme[0].parity)<0 &&
                    state.levelnumber>1 ){
                    state.S = 3-2.*exp(-0.08671329*(state.levelnumber))/(pow(state.levelnumber,0.25));
                }
                else if ((fabs(state.spin-scheme[0].spin) <= 1) &&            // spin change
                         ((state.spin!=0)||(scheme[0].spin!=0)) &&                 // no spin 0<->0
                         (state.parity*scheme[0].parity)>0 &&
                         state.levelnumber>1 ){
                    state.S = 3-2.*exp(-0.08671329*(state.levelnumber))/(pow(state.levelnumber,0.25));
                }
                else if ((fabs(state.spin-scheme[0].spin) <= 2) &&           // spin change
                         ((state.spin!=0)||(scheme[0].spin!=0)) &&           // no spin 0<->0
                         ((state.spin!=0)||(scheme[0].spin!=1)) &&           // no spin 0->1
                         ((state.spin!=1)||(scheme[0].spin!=0)) &&           // no spin 1->0
                         ((state.spin!=0.5)||(scheme[0].spin!=0.5)) &&       // no spin 0.5<->0.5
                         (state.parity*scheme[0].parity)>0 &&                // no parity change)
                         state.levelnumber>1){
                    state.S = 3-2.*exp(-0.08671329*(state.levelnumber))/(pow(state.levelnumber,0.25));
                }
                else {state.S = 1;}
                state.multiplicity = 0;
                scheme.push_back(state);
            }
        }
        //Number(E_i,1,-1);





        E_i += binning;

    }
    mainwindow_object->DoError("Finished building up level scheme");

}
//******************************************************************************

double Analysis::Number(double ee, double jj, double pp){
    double lf, sf, pf,sigma,p1,p2,x;

    //spindistribution with quadratic expansion to ee> 0.5 Epair
    double a,b,c,m,ee_0;
    a = 0.391*pow(A,0.675);
    b = 0.5*Pair;
    c = 0.312;
    ee_0 = b/(1-c/2);
    m = a*c/(2*ee_0)*pow(ee_0-b,c-1);

    if ((ee/1000)>ee_0){
        sigma = sqrt(a*pow(ee/1000-b,c));
    }
    else {
        sigma = sqrt(m)*ee/1000;
    }
    sf = exp(-jj*jj/(2*sigma*sigma))-exp(-(jj+1)*(jj+1)/(2*sigma*sigma));
    //cout << sigma*sigma <<" "<< ee_0<<" "<<jj<< " " <<sf<<" "<<ee<<endl;

    //staggering for nothalf spins egidy prc79 + disappear in alhassid prl99
    if (((int)(2*jj+1)%2)!=0){
        if ((((int)jj%2)==0)&&(jj!=0)){x=0.227;}
        else if (jj==0){x=1.02;}
        else{x=-0.227;}
    }
    else{ x = 0;}
    x = x * exp(-0.5*ee/1000.);
    sf = sf * (1+x);


    //parity AlQuraishi PRC67
    double a0,a1,a2,deltap;
    if ((((int)Z%2)==0)&&(((int)N%2)==0)){       a0 = 1.34;}
    else if ((((int)Z%2)==0)&&(((int)N%2)!=0)){  a0 = 0.08;}
    else if ((((int)Z%2)!=0)&&(((int)N%2)==0)){  a0 = -0.42;}
    else if ((((int)Z%2)!=0)&&(((int)N%2)!=0)){  a0 = -0.90;}
    a1 = 75.22;
    a2 = 0.89;
    deltap = a0+a1/pow(A,a2);
    pf = Parity_average*(1+1/(1+exp(3*(ee/1000-deltap))));
    if (pf>1){pf=1;}
    if (pp==-1) {
        pf = 1 -pf;
    }
    //cout << ee<< " for " << pp <<" "         <<pf << " " << Parity_average<< endl ;

    //CT Model or BSGF Model
    if (CTorBSFG==0){
        p1 = param1;
        p2 = param2;
        lf = 1./p1*exp((ee/1000-p2)/p1)*binning/1000; //per keV
    }
    if (CTorBSFG==1){
        p1 = param1;
        p2 = param2;
        lf =exp(2*sqrt(p1*(ee/1000-p2)))/(12*sigma*sqrt(2)*pow(p1,0.25)*pow(ee/1000-p2,1.25))*binning/1000;
        if ((p1*(ee-p2))<0){lf = 0;}
    }
    //cout << ee << " " << lf  << " " << pf  << " " << sf <<endl;
    return (lf*pf*sf*binning);
}
//******************************************************************************
void Analysis::SetStrength(int E1nr,int M1nr)
{
    for (i=0;i<2000;i++){
        E1Strength[i]=0;
        M1Strength[i]=0;
        E2Strength[i]=0;
    }
    //TLO
    if (E1nr==0){
        TLO_beta = mainwindow_object->ui_E1doubleSpinBox_1->value();
        TLO_gamma = (mainwindow_object->ui_E1doubleSpinBox_2->value())/180.*M_PI;  //in Bogenmaß
        TLO_norm = 1.02*11.9*Z*N/3/A/M_PI;
        TLO_R0 = 1.16*pow(A,1./3);
        TLO_u = (1-0.0768)*pow(A,-1./3)*3*32.7/29.2;
        TLO_E0 = 197.3669631/TLO_R0*pow(8*32.7*A*A/874/4/Z/N,0.5)*
                 pow(1+TLO_u-0.0768*(1+TLO_u*3+0.0768)/(1+TLO_u+0.0768),-0.5);
        TLO_E1 = TLO_E0/exp(5./4/M_PI*TLO_beta*cos(TLO_gamma-2./3*1*M_PI));
        TLO_E2 = TLO_E0/exp(5./4/M_PI*TLO_beta*cos(TLO_gamma-2./3*2*M_PI));
        TLO_E3 = TLO_E0/exp(5./4/M_PI*TLO_beta*cos(TLO_gamma-2./3*3*M_PI));
        TLO_G1 = 1.99*pow(TLO_E1/10,1.6);
        TLO_G2 = 1.99*pow(TLO_E2/10,1.6);
        TLO_G3 = 1.99*pow(TLO_E3/10,1.6);
        TLO_CS1 = 12*Z*N/A/3/M_PI/TLO_G1*10;
        TLO_CS2 = 12*Z*N/A/3/M_PI/TLO_G2*10;
        TLO_CS3 = 12*Z*N/A/3/M_PI/TLO_G3*10;
        for (k=0;k<=(int)(Emax/binning);k++){
            TLO_Eg = (binning*k+binning/2)/1000;    //in MeV nur für berechnen!!
            //f dann in /keV^3
            E1Strength[k] = TLO_norm*TLO_Eg/10*0.000026023/3/pow(1000,3)*
                            ( TLO_G1/(pow(TLO_E1*TLO_E1-TLO_Eg*TLO_Eg,2)+TLO_Eg*TLO_Eg*TLO_G1*TLO_G1)
                              +TLO_G2/(pow(TLO_E2*TLO_E2-TLO_Eg*TLO_Eg,2)+TLO_Eg*TLO_Eg*TLO_G2*TLO_G2)
                              +TLO_G3/(pow(TLO_E3*TLO_E3-TLO_Eg*TLO_Eg,2)+TLO_Eg*TLO_Eg*TLO_G3*TLO_G3));
            // cout << TLO_Eg << " "<<E1Strength[k]<< endl;
        }
    }
    else if (E1nr == 1)
    {
        RIPL_G1     = mainwindow_object->ui_E1doubleSpinBox_1 -> value();
        RIPL_E1     = mainwindow_object->ui_E1doubleSpinBox_2 -> value();
        RIPL_CS1    = mainwindow_object->ui_E1doubleSpinBox_3 -> value();
        RIPL_G2     = mainwindow_object->ui_E1doubleSpinBox_4 -> value();
        RIPL_E2     = mainwindow_object->ui_E1doubleSpinBox_5 -> value();
        RIPL_CS2    = mainwindow_object->ui_E1doubleSpinBox_6 -> value();

        for (k=0;k<=(int)(Emax/binning);k++){
            RIPL_Eg = (binning*k+binning/2)/1000;
            E1Strength[k] = ( RIPL_G1*RIPL_CS1/(pow(RIPL_E1*RIPL_E1-RIPL_Eg*RIPL_Eg,2)+RIPL_Eg*RIPL_Eg*RIPL_G1*RIPL_G1)
                              +RIPL_G2*RIPL_CS2/(pow(RIPL_E2*RIPL_E2-RIPL_Eg*RIPL_Eg,2)+RIPL_Eg*RIPL_Eg*RIPL_G2*RIPL_G2))
                            *RIPL_Eg*0.00000026023/pow(1000,3);
            // cout << RIPL_E1 << " "<<RIPL_G1 << " "<<RIPL_CS1 << " .."<<RIPL_E2 << " "<<RIPL_G2 << " "<<RIPL_CS2 <<endl;
            //  cout << RIPL_Eg << " "<<E1Strength[k]<< endl;
        }
    }
    else if (E1nr == 2){
        ownE1_path = mainwindow_object->ui_E1label_6->text();
        if (ownE1_path == ""){
            mainwindow_object->DoError("Error -> no E1 file given ");
            return;
        }
        double aa,bb,aa_o,bb_o;
        QFile ownE1_input(ownE1_path);
        if (!ownE1_input.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        k = 1;
        aa = 0;
        aa_o = 0;
        bb = 0;
        bb_o = 0;
        E1Strength[0]=0;
        QTextStream in(&ownE1_input);
        while (!in.atEnd()) {
            in >> aa >> bb;
            if(in.status() != QTextStream::Ok) break;
            while (k*binning<=aa){
                if (k*binning == aa)
                    E1Strength[k]=bb;
                else if (k*binning < aa)
                    E1Strength[k] = (bb-bb_o)/(aa-aa_o)*(k*binning-aa_o)+bb_o;
                k++;
            }
            aa_o=aa;
            bb_o=bb;
        }
        ownE1_input.close();
        for (i = k;k<=(int)(Emax/binning);k++){
            E1Strength[k] = 2*E1Strength[k-1]-E1Strength[k-2];
        }
        //cout << ownE1_path.toStdString() << endl;
    }

    if (M1nr == 0){
        if (E1nr == 0){
            Grosse_beta = mainwindow_object->ui_E1doubleSpinBox_1->value();
        }
        else{
            Grosse_beta = mainwindow_object->ui_M1doubleSpinBox_1->value();
        }
        Grosse_R0 = 1.16*pow(A,1./3);
        Grosse_u = (1-0.0768)*pow(A,-1./3)*3*32.7/29.2;
        Grosse_E0 = 197.3669631/Grosse_R0*pow(8*32.7*A*A/874/4/Z/N,0.5)*
                    pow(1+Grosse_u-0.0768*(1+Grosse_u*3+0.0768)/(1+Grosse_u+0.0768),-0.5);
        for (k=0;k<=(int)(Emax/binning);k++){
            M1Strength[k] = 1./1000/1000/1000/1000/1000/1000*(      //GeV^-3 -> keV^-3
                    (Z*Z*Grosse_beta*Grosse_beta)/62.*exp(-(k*binning/1000-0.21*Grosse_E0)*(k*binning/1000-0.21*Grosse_E0)/2/0.85/0.85)
                    +(A/9.3*exp(-(k*binning/1000-34*pow(A,-1./3))*(k*binning/1000-34*pow(A,-1./3))/2/0.85/0.85))
                    +(A/9.3*exp(-(k*binning/1000-44*pow(A,-1./3))*(k*binning/1000-44*pow(A,-1./3))/2/1.27/1.27)));
            // cout << k*binning <<" " <<M1Strength[k]<<endl;
        }
    }
    else if (M1nr == 1){
        if (Emax<7000){
            RIPL_M1fE1=(E1Strength[(int)(Emax/binning)]-E1Strength[(int)(Emax/binning-1)])/binning*(7000-Emax)+E1Strength[(int)(Emax/binning)];
        }
        else {
            if((7000%(int)binning)==0){
                k = 7000/binning;
                RIPL_M1fE1 = E1Strength[k];
            }
            else{
                k = 7000/(int)binning;
                RIPL_M1fE1 = (E1Strength[k+1]-E1Strength[k])/(binning)*(7000%(int)binning)+E1Strength[k];
            }
        }
        RIPL_M1E0 = 41*pow(A,-1./3);
        RIPL_M1A = RIPL_M1fE1/(0.0588*pow(A,0.878))/
                   (1*7.*4*4/((7*7-RIPL_M1E0*RIPL_M1E0)*(7*7-RIPL_M1E0*RIPL_M1E0)+7*7*4*4));
        //cout << RIPL_M1fE1 <<" "<<RIPL_M1E0<<" " <<RIPL_M1A<<" "<< (0.0588*pow(A,0.878))<<endl;
        for (k=0;k<=(int)(Emax/binning);k++){
            M1Strength[k] =RIPL_M1A*k*binning/1000.
                           *4*4/(pow(k*binning/1000.*k*binning/1000.-RIPL_M1E0*RIPL_M1E0,2.)+k*binning/1000.*k*binning/1000.*4*4);
        }
    }
    else if (M1nr == 2){
        ownM1_path = mainwindow_object->ui_M1label_2->text();
        if (ownM1_path == ""){
            mainwindow_object->DoError("Error -> no M1 file given ");
            return;
        }
        double aa,bb,aa_o,bb_o;
        QFile ownM1_input(ownM1_path);
        if (!ownM1_input.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        k = 1;
        aa = 0;
        aa_o = 0;
        bb = 0;
        bb_o = 0;
        M1Strength[0]=0;
        QTextStream in(&ownM1_input);
        while (!in.atEnd()) {
            in >> aa >> bb;
            if(in.status() != QTextStream::Ok) break;
            while (k*binning<=aa){
                if (k*binning == aa)
                    M1Strength[k]=bb;
                else if (k*binning < aa)
                    M1Strength[k] = (bb-bb_o)/(aa-aa_o)*(k*binning-aa_o)+bb_o;
                k++;
            }
            aa_o=aa;
            bb_o=bb;
        }
        ownM1_input.close();
        for (i = k;k<=(int)(Emax/binning);k++){
            M1Strength[k] = 2*M1Strength[k-1]-M1Strength[k-2];
        }
    }


    //E2 following RIPL
    E2_E0 = 63*pow(A,-1./3)*1000;
    E2_gamma = (6.11-0.021*A)*1000;
    E2_sigma = 0.00014*Z*Z*E2_E0/pow(A,1./3)/E2_gamma;
    E2Strength[0]=0;
    for (k=1;k<=(int)(Emax/binning);k++){
        E2Strength[k]= E2_sigma*E2_gamma*E2_gamma/(k*binning)*
                       1/(pow(k*binning*k*binning-E2_E0*E2_E0,2.)+k*binning*k*binning*E2_gamma*E2_gamma)*
                       1/3846153/1000/1000; //umrechung mb->MeV²->keV²
    }

    for (k = 0;k<=(int)(Emax/binning);k++){
        E1Strength_ex[k] = E1Strength[k];
        M1Strength_ex[k] = M1Strength[k];
        E2Strength_ex[k] = E2Strength[k];
        // cout << k*binning << " "<< E1Strength[k]<<" "<<M1Strength[k]<< " "<<E2Strength[k]<<endl;
    }

}

//******************************************************************************
//soinfaktor bei f noch mit enbauen da f = g*f_ausSetstrength (vlt???)
void Analysis::Decay(){
    
    
    if ((int(2*spin)%2 != 0)&&(int(2*spin_ex)%2 == 0)){
        mainwindow_object->DoError("Error -> check spins");
        return;
    }
    else if ((int(2*spin)%2 == 0)&&(int(2*spin_ex)%2 != 0)){
        mainwindow_object->DoError("Error -> check spins");
        return;
    }
    else{
        for (i=0;i<scheme.size();i++){
            mainwindow_object->ui_progressbar->setValue((int)(i*100./scheme.size()+1));

            Gammatot = 0;
            //cout << scheme[i].energy<< " "<<i<<endl;
            if (scheme[i].levelnumber>0){
                ArraySum = 0;       //needed for replacement of decay scheme of discrete levels
                for (k=0;k<=(int)(Emax/binning);k++){
                    ArraySum+=scheme[i].spectrum[k];
                }
                for (l=0;l<=i;l++){
                    Etrans = scheme[i].energy-scheme[l].energy;
                    if (Etrans == 0){break;}
                    //E1
                    if ((scheme[i].energy>=scheme[l].energy) &&                  //energy smaller
                        (fabs(scheme[i].spin-scheme[l].spin) <= 1) &&            // spin change
                        ((scheme[i].spin!=0)||(scheme[l].spin!=0)) &&           // no spin 0<->0
                        (scheme[i].parity*scheme[l].parity)<0){                 //parity change
                        // cout << " ! E1 ! " <<" "<< scheme[i].energy-scheme[l].energy<<" ...."<< scheme[i].spin*scheme[i].parity << " to " << scheme[l].spin*scheme[l].parity <<endl;
                        if ((scheme[i].energy == (int)Emax)&&(scheme[i].spin == spin_ex)&&(scheme[i].parity == parity_ex)){
                            Gammatot += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,3)*E1Strength_ex[(int)(Etrans/binning)];
                        }
                        else{
                            Gammatot += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,3)*E1Strength[(int)(Etrans/binning)];
                        }
                    }
                    //M1
                    if ((scheme[i].energy>=scheme[l].energy) &&                  //energy smaller
                        (fabs(scheme[i].spin-scheme[l].spin) <= 1) &&            // spin change
                        ((scheme[i].spin!=0)||(scheme[l].spin!=0)) &&           // no spin 0<->0
                        (scheme[i].parity*scheme[l].parity)>0){                 //no parity change
                        //  cout << " ! M1 ! " <<" "<< scheme[i].energy-scheme[l].energy<<" ...."<< scheme[i].spin*scheme[i].parity << " to " << scheme[l].spin*scheme[l].parity <<endl;
                        if ((scheme[i].energy == (int)Emax)&&(scheme[i].spin == spin_ex)&&(scheme[i].parity == parity_ex)){
                            Gammatot += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,3)*M1Strength_ex[(int)(Etrans/binning)];
                        }
                        else{
                            Gammatot += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,3)*M1Strength[(int)(Etrans/binning)];
                        }
                    }
                    //E2
                    if ((scheme[i].energy>=scheme[l].energy) &&                  //energy smaller
                        (fabs(scheme[i].spin-scheme[l].spin) <= 2) &&           // spin change
                        ((scheme[i].spin!=0)||(scheme[l].spin!=0)) &&           // no spin 0<->0
                        ((scheme[i].spin!=0)||(scheme[l].spin!=1)) &&           // no spin 0->1
                        ((scheme[i].spin!=1)||(scheme[l].spin!=0)) &&           // no spin 1->0
                        ((scheme[i].spin!=0.5)||(scheme[l].spin!=0.5)) &&       // no spin 0.5<->0.5
                        (scheme[i].parity*scheme[l].parity)>0){                 // no parity change
                        // cout << " ! E2 ! " <<" "<< scheme[i].energy-scheme[l].energy<<" ...."<< scheme[i].spin*scheme[i].parity << " to " << scheme[l].spin*scheme[l].parity <<endl;
                        if ((scheme[i].energy == (int)Emax)&&(scheme[i].spin == spin_ex)&&(scheme[i].parity == parity_ex)){
                            Gammatot += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,5)*E2Strength_ex[(int)(Etrans/binning)];
                        }
                        else{
                            Gammatot += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,5)*E2Strength[(int)(Etrans/binning)];
                        }
                    }
                    //cout << scheme[i].energy << " "<< scheme[i].parity *scheme[i].spin << " to "<< scheme[l].energy << " "<< scheme[l].parity *scheme[l].spin << " "<< Gammatot<< endl;
                }
            }
            scheme[i].totalwidth = Gammatot;
            //cout << scheme[i].energy << " "<< scheme[i].parity *scheme[i].spin << " "<< Gammatot<< endl;

            for (l=0;l<=i;l++){
                Gamma = 0;
                Etrans = scheme[i].energy-scheme[l].energy;
                if (Etrans == 0){break;}
                //E1
                if ((scheme[i].energy>=scheme[l].energy) &&                  //energy smaller
                    (fabs(scheme[i].spin-scheme[l].spin) <= 1) &&            // spin change
                    ((scheme[i].spin!=0)||(scheme[l].spin!=0)) &&           // no spin 0<->0
                    (scheme[i].parity*scheme[l].parity)<0){                 //parity change
                    if ((scheme[i].energy == (int)Emax)&&(scheme[i].spin == spin_ex)&&(scheme[i].parity == parity_ex)){
                        Gamma += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,3)*E1Strength_ex[(int)(Etrans/binning)];
                        //cout << " ! E1 ! " <<" "<< scheme[i].energy-scheme[l].energy<<" ...."<< scheme[i].spin*scheme[i].parity << " to " << scheme[l].spin*scheme[l].parity <<" with " <<Gamma<<endl;
                    }
                    else{
                        Gamma += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,3)*E1Strength[(int)(Etrans/binning)];
                    }
                    /*
                    cout << " ! E1 ! " <<" "<< scheme[i].energy-scheme[l].energy<<" ...."
                         << scheme[i].spin*scheme[i].parity << " to " << scheme[l].spin*scheme[l].parity
                         << " "<< Gamma
                         <<" lvl "<<scheme[l].levelnumber<< " strength "<<E1Strength_ex[(int)(Etrans/binning)]
                        <<endl;
                        */
                }
                //M1
                if ((scheme[i].energy>=scheme[l].energy) &&                  //energy smaller
                    (fabs(scheme[i].spin-scheme[l].spin) <= 1) &&            // spin change
                    ((scheme[i].spin!=0)||(scheme[l].spin!=0)) &&           // no spin 0<->0
                    (scheme[i].parity*scheme[l].parity)>0){                 //no parity change
                    //  cout << " ! M1 ! " <<" "<< scheme[i].energy-scheme[l].energy<<" ...."<< scheme[i].spin*scheme[i].parity << " to " << scheme[l].spin*scheme[l].parity <<endl;
                    if ((scheme[i].energy == (int)Emax)&&(scheme[i].spin == spin_ex)&&(scheme[i].parity == parity_ex)){
                        Gamma += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,3)*M1Strength_ex[(int)(Etrans/binning)];
                    }
                    else{
                        Gamma += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,3)*M1Strength[(int)(Etrans/binning)];
                    }
                }
                //E2
                if ((scheme[i].energy>=scheme[l].energy) &&                  //energy smaller
                    (fabs(scheme[i].spin-scheme[l].spin) <= 2) &&            // spin change
                    ((scheme[i].spin!=0)||(scheme[l].spin!=0)) &&           // no spin 0<->0
                    ((scheme[i].spin!=0)||(scheme[l].spin!=1)) &&           // no spin 0->1
                    ((scheme[i].spin!=1)||(scheme[l].spin!=0)) &&           // no spin 1->0
                    ((scheme[i].spin!=0.5)||(scheme[l].spin!=0.5)) &&       // no spin 0.5<->0.5
                    (scheme[i].parity*scheme[l].parity)>0){                 // no parity change
                    // cout << " ! E2 ! " <<" "<< scheme[i].energy-scheme[l].energy<<" ...."<< scheme[i].spin*scheme[i].parity << " to " << scheme[l].spin*scheme[l].parity <<endl;
                    if ((scheme[i].energy == (int)Emax)&&(scheme[i].spin == spin_ex)&&(scheme[i].parity == parity_ex)){
                        Gamma += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,5)*E2Strength_ex[(int)(Etrans/binning)];
                    }
                    else{
                        Gamma += scheme[l].levelnumber/scheme[i].levelnumber*pow(Etrans,5)*E2Strength[(int)(Etrans/binning)];
                    }
                }
                if ((l==0)&&(scheme[i].levelnumber>0)){
                    //cout << scheme[i].energy-scheme[l].energy<<" ...."<< scheme[i].spin*scheme[i].parity << " to " << scheme[l].spin*scheme[l].parity <<" gammas " << Gamma<<" " <<Gammatot<<endl;
                    //cout << "levels: "<< scheme[i].levelnumber << " to "<<scheme[l].levelnumber<<endl;
                    scheme[i].gswidth = Gamma;
                }


                if ((Gammatot != 0)&&(Gammatot==Gammatot)&&(Gamma!=0)){
                    //cout <<scheme[i].energy<<" "<< Etrans << " " <<scheme[i].spin*scheme[i].parity <<" to "<< scheme[l].spin*scheme[l].parity << " g: "<< Gamma<<" gtot: "<< Gammatot<<endl;
                    if (ArraySum==0){
                        scheme[i].spectrum_primary[(int)(Etrans/binning)]+=Gamma/Gammatot;
                        scheme[i].spectrum[(int)(Etrans/binning)]+=Gamma/Gammatot;
                        for (k=0;k<=(int)((scheme[l].energy)/binning);k++){
                            scheme[i].spectrum[k]+=Gamma/Gammatot*scheme[l].spectrum[k];
                        }
                    }
                    else{
                        scheme[i].spectrum_primary[(int)(Etrans/binning)]+=scheme[i].spectrum[(int)(Etrans/binning)];
                        for (k=0;k<=(int)((scheme[l].energy)/binning);k++){
                            /*
                            if (scheme[l].spectrum[k] > 0){
                              cout << (int)((scheme[i].energy)/binning)-k <<" "<<scheme[i].energy << " ato " <<scheme[l].energy << " " << scheme[i].spectrum[(int)((scheme[i].energy)/binning)-k]<<endl;
                              cout << (int)((scheme[i].energy)/binning)-k-1 <<" "<<scheme[i].energy << " bto " <<scheme[l].energy << " " << scheme[i].spectrum[(int)((scheme[i].energy)/binning)-k-1]<<endl;
                              cout << (int)((scheme[i].energy)/binning)-k+1 <<" "<<scheme[i].energy << " cto " <<scheme[l].energy << " " << scheme[i].spectrum[(int)((scheme[i].energy)/binning)-k+1]<<endl;
                            }
                            */
                            scheme[i].spectrum[k]+=scheme[l].spectrum[k]*scheme[i].spectrum[(int)((scheme[i].energy)/binning)-k];
                        }
                    }
                }
            //if (Gammatot<0) cout <<scheme[i].energy<<" "<< Etrans << " " <<scheme[i].spin*scheme[i].parity <<" to "<< scheme[l].spin*scheme[l].parity << " g:"<< Gamma<<" gtot:"<< Gammatot<<endl;
            }
            if (ArraySum != 0){       //norm each deacy of known states
                ArraySum=0;
                for (k=0;k<=(int)(Emax/binning);k++){
                    ArraySum+=scheme[i].spectrum[k];
                }
                for (k=0;k<=(int)(Emax/binning);k++){
                    scheme[i].spectrum[k]=scheme[i].spectrum[k]/ArraySum;
                }
            }
        }


        for (i=0;i<scheme.size();i++){
            for (k=0;k<=(int)((scheme[i].energy)/binning);k++){
                scheme[i].multiplicity+=scheme[i].spectrum[k];
            }
            //cout << scheme[i].energy << " "<<scheme[i].multiplicity<<endl;
        }

    }

}
//******************************************************************************
double Analysis::GetIndex(double ee, double jj, double pp){
    int index = -1;
    //cout <<"index_A"<<ee<<endl;
//    ee = ((int)((ee+binning/2.)/binning))*binning;
    ee = (int)(ee/binning)*binning;
    //cout <<"index_B"<<ee<<endl;
    for (int blub=0;blub<scheme.size();blub++){
        //cout << ee << " " << scheme[blub].energy << " spin " << jj << " " << scheme[blub].spin << " parity " <<pp << " " << scheme[blub].parity << endl;
        if ((ee == scheme[blub].energy) && (jj == scheme[blub].spin) && (pp == scheme[blub].parity)) {index = blub;break;}
    }
    if(index==-1){
        cout << " did not found index for: "<<ee<<","<<jj<<","<<pp<<" !!!"<<endl;

    }
    return index;
}

//******************************************************************************
void Analysis::ReplaceLevels(QString levelfile){
    QString line,subline;
    double levelenergy, levelspin, levelparity, levelstrength,levelspectrum[2000], levelTolevel, levelgamma, leveltotgamma,bla;
    std::vector<int> inputLevels; // included by ChL
    double g; //only for transition to discrete levels

    int a,b,c,d, qq;

    QFile Input(levelfile);
    if (Input.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&Input);
        while (!in.atEnd()) {
            line = in.readLine();
            //cout << "here "<< line.size()<<endl;
            if (line.size()==0){break;}
            subline = line.right(line.length()-3);
            while ((subline.left(1)==" ")||(subline.left(1)=="\t")){subline = subline.right(subline.length()-1);} //skip spaces
            qq = 1;
            while ((subline[qq]!=' ')&&(subline[qq]!='\t')){qq++;}
            inputmaxenergy = (subline.left(qq)).toDouble();

        }

        scheme2.push_back(scheme.at(0));
        a=1;
        while (scheme[a].energy < inputmaxenergy+binning){
            scheme2.push_back(scheme.at(a));
            scheme[a].levelnumber=0;
            for (k=0;k<=(int)(Emax/binning);k++){scheme[a].spectrum[k]=0;}
            //cout << scheme2[a].energy << endl;
            a++;
        }
        a=1;


        in.seek(0);

        while (!in.atEnd()) {
            line = in.readLine();
            if (line.size()==0){break;}
            subline = line.right(line.length()-3);
            while ((subline.left(1)==" ")||(subline.left(1)=="\t")){subline = subline.right(subline.length()-1);} //skip spaces
            qq = 1;
            while ((subline[qq]!=' ')&&(subline[qq]!='\t')){
                qq++;
                if (qq>10000){
                    mainwindow_object->DoError("ERROR Check Input file");
                    return;
                }
            }
            levelenergy = (subline.left(qq)).toDouble();
            subline = subline.right(subline.length()-qq);
            while ((subline.left(1)==" ")||(subline.left(1)=="\t")){subline = subline.right(subline.length()-1);}
            qq = 1;
            while ((subline[qq]!=' ')&&(subline[qq]!='\t')){
                qq++;
                if (qq>10000){
                    mainwindow_object->DoError("ERROR Check Input file");
                    return;
                }
            }
            levelspin = fabs((subline.left(qq)).toDouble());
            if (fabs(levelspin-scheme[0].spin)>5){
                break;
            }
            if (subline.left(1) == "-"){levelparity = -1.;}
            else levelparity = 1.;

            subline = subline.right(subline.length()-qq);

            a = 1;
            b = 0;
            if (levelenergy > 0){
                //cout << levelenergy << " spin " << levelspin<<" par "<<levelparity<<endl;
                while (b !=1){
                    //cout <<" "<< scheme[a].energy<<" number "<< scheme[a].levelnumber<<" spin "<< scheme[a].spin<< " pari " <<scheme[a].parity<<endl;
                    //cout <<"vergleich"<<scheme[a].energy<<">"<<levelenergy<<" "<<fabs(scheme[a].energy-levelenergy)<<endl;
                    //if (((binning/2.0)>=fabs(scheme[a].energy-levelenergy))&&
                    if ((levelenergy<scheme[a].energy+binning)&&                          
                        (0.1>fabs(scheme[a].spin-levelspin))&&
                        (0.1>fabs(scheme[a].parity-levelparity))){
                        //scheme[a].levelnumber=scheme2[a].levelnumber;
                        scheme[a].levelnumber++;
                         b = 1;
                        //cout <<" "<< scheme[a].energy<<" number "<< scheme[a].levelnumber<<" spin "<< scheme[a].spin<< " pari " <<scheme[a].parity<<endl;
                        }
                    else a++;
                    if (a>=scheme.size()){break;}
                }
            }
            else a=0;
            inputLevels.push_back((int)levelenergy);
            //for (a=0;a<scheme.size();a++){ cout <<" "<< scheme[a].energy<<" number "<< scheme[a].levelnumber<<" spin "<< scheme[a].spin<< " pari " <<scheme[a].parity<<endl;}
            while ((subline.left(1)==" ")||(subline.left(1)=="\t")){subline = subline.right(subline.length()-1);}
            qq = 1;
            while ((subline[qq]!=' ')&&(subline[qq]!='\t')&&(qq<subline.length())){qq++;}
            levelstrength = (subline.left(qq)).toDouble();
            subline = subline.right(subline.length()-qq);

            b = 0;

            g = (2*levelspin+1)/(2*spin_ex+1);
            //g=1;

            //cout <<  levelstrength <<" "<< g <<endl;
            if ((fabs(levelspin-spin_ex)<=1)&&
                (levelstrength>0)&&
                ((levelspin!=0)||(spin_ex!=0))&&
                (levelparity*parity_ex<0)){
                //cout << "E1"<<endl;
                //cout << Emax<< " to "<<levelenergy<< "  "<< (int)((Emax-levelenergy)/binning)<<endl;
                E1Strength_ex[(int)((Emax-scheme[a].energy)/binning)]=levelstrength/pow((Emax-scheme[a].energy)/1000,1)/3846153.8/g/(1000^3)/binning/binning*(binning/100.);
            }
            if ((fabs(levelspin-spin_ex)<=1)&&
                (levelstrength>0)&&
                ((levelspin!=0)||(spin_ex!=0))&&
                (levelparity*parity_ex>0)){
                //cout << "M1"<<endl;
                M1Strength_ex[(int)((Emax-scheme[a].energy)/binning)]=levelstrength/pow((Emax-scheme[a].energy)/1000,1)/3846153.8/g/(1000^3)/binning/binning*(binning/100.);
                E2Strength_ex[(int)((Emax-scheme[a].energy)/binning)]=0;
                b = 1;
            }
            if ((fabs(levelspin-spin_ex)<=2)&&
                (levelstrength>0)&&
                ((levelspin!=0)||(spin_ex!=0))&&
                ((levelspin!=1)||(spin_ex!=0))&&
                ((levelspin!=0)||(spin_ex!=1))&&
                ((levelspin!=0.5)||(spin_ex!=0.5))&&
                (levelparity*parity_ex>0)&&
                (b!=1)){                                //prefer M1 transition from excited state
                //cout << "E2"<<endl;
                E2Strength_ex[(int)((Emax-scheme[a].energy)/binning)]=levelstrength/pow((Emax-scheme[a].energy)/1000,3)/3846153.8/g/(1000^5)/binning/binning*(binning/100.);
                M1Strength_ex[(int)((Emax-scheme[a].energy)/binning)]=0;
            }

            for (k=0;k<=(int)(Emax/binning);k++){
                levelspectrum[k] = 0;
            }

            while (((subline.left(1)==" ")||(subline.left(1)=="\t"))&&(subline.length()>0)){subline = subline.right(subline.length()-1);}

            leveltotgamma = 0;
            while (subline.length()!=0){
                subline = subline.right(subline.length()-2);
                qq = 1;
                while ((subline[qq]!=' ')&&(subline[qq]!='\t')&&(qq<subline.length())){qq++;}
                levelTolevel = (subline.left(qq)).toDouble();
                subline = subline.right(subline.length()-qq);
                k = 0;
                a = levelTolevel+1;
//                while(((scheme[k].energy-binning)<levelenergy)&&(a>0)){
                while((scheme[k].energy<levelenergy)&&(a>0)){
                    //cout << scheme[k].energy<< " "<<scheme[k].parity*scheme[k].spin<<" "<< scheme[k].levelnumber<<" "<<a<<endl;
                    a -= scheme[k].levelnumber;

                    k++;
                }
                k--;

                while (((subline.left(1)==" ")||(subline.left(1)=="\t"))&&(subline.length()>0)){subline = subline.right(subline.length()-1);}
                while ((subline[qq]!=' ')&&(subline[qq]!='\t')&&(qq<subline.length())){qq++;}
                levelgamma = (subline.left(qq)).toDouble();

//                b = ((int)((levelenergy+binning/2)/binning))*binning - (scheme[k].energy);
                b = (int)levelenergy - inputLevels[levelTolevel];
                //cout << " to "<<scheme[k].energy << "("<<inputLevels[levelTolevel]<< ") from "<<((int)(levelenergy/binning))*binning<<"("<<levelenergy<< ") gamma energy "<< (int)(b/binning)<<" mit "<< levelgamma<< endl;
                //cout << ((int)((levelenergy+binning/2)/binning))*binning - (scheme[k].energy) << " massar --- chl " <<b<<endl;
                if (b<0){
                    mainwindow_object->DoError("ERROR Check Input file - transitions");
                    return;
                }

                levelspectrum[(int)(b/binning)]+=levelgamma;
                leveltotgamma+=levelgamma;
                //cout << leveltotgamma<< " " << levelgamma << " "<< levelenergy<< endl;
                subline = subline.right(subline.length()-qq);
                if (subline.left(1)=="\n"){break;}
                while (((subline.left(1)==" ")||(subline.left(1)=="\t"))&&(subline.length()!=0)){subline = subline.right(subline.length()-1);}
            }
            if (leveltotgamma == 0){leveltotgamma = 1;}
            for (k=0;k<=(int)(Emax/binning);k++){
                levelspectrum[k] = levelspectrum[k]/leveltotgamma;
            }

            /*
            bla =0;
            for (k=0;k<=(int)(Emax/binning);k++){
                bla+=levelspectrum[k];
                cout << leveltotgamma << " " << bla << " " << levelspectrum[k]<< " " <<endl;
            }
            */
            for (k=0;k<=(int)(Emax/binning);k++){
//                scheme[GetIndex(binning*(int)(levelenergy/binning),levelspin,levelparity)].spectrum[k]+=levelspectrum[k];
                //cout << "k = " << k <<" --- GetIndex("<<levelenergy<<","<<levelspin<<","<<levelparity<<") = " << GetIndex(levelenergy,levelspin,levelparity)<<endl;
                //cout << "scheme["<< GetIndex(levelenergy,levelspin,levelparity) << "].spectrum = "<< scheme[GetIndex(levelenergy,levelspin,levelparity)].spectrum <<endl;
                scheme[GetIndex(levelenergy,levelspin,levelparity)].spectrum[k]+=levelspectrum[k];
                // cout << k <<" "<< scheme[GetIndex(binning*(int)(levelenergy/binning),levelspin,levelparity)].spectrum[k]<<endl;
                //cout << k <<" "<< scheme[GetIndex(levelenergy,levelspin,levelparity)].spectrum[k]<<endl;
            }
            if (subline.left(1)=="\n"){break;}




            //cout <<"sub___"<<subline.toStdString()<<endl;
            //cout <<"total_"<<line.toStdString()<<endl<<endl;
        }
    }
    Input.close();

    //for (a=0;a<scheme.size();a++){cout <<" "<< scheme[a].energy<<" "<< scheme[a].levelnumber<<" "<< scheme[a].spin*scheme[a].parity<<endl;}
}
//******************************************************************************


void Analysis::GammaGamma(){

    double sum = 0;
    for (i=0;i<2000;i++){
        sum+=GammaSpectrum[i];
        branching[i]=0;
    }
    if (sum == 0) return;
    //cout << "total: " <<sum<<endl;


    for (i=0;i<2000;i++){
        E1Strength_ex[i]=E1Strength[i];
        M1Strength_ex[i]=M1Strength[i];
        E2Strength_ex[i]=E2Strength[i];
    }
    Decay();

    k = scheme.size()-1;
    for (i=(int)((scheme[k].energy)/binning);i>=0;i--){

        //cout <<" erst "<<k<< " "<< i*binning << " "<<scheme[k].energy<<endl;
        l = k;
        Gammatot = 0;
        while ((i*binning == scheme[k].energy)&&(k>0)){
            //excitation gamma_tot //gs width already includes weighting for number of levels in bin
            Gammatot+= scheme[k].gswidth;
            k--;
        }
        k = l;
        while ((i*binning == scheme[k].energy)&&(k>0)){
            if ((scheme[k].totalwidth!=0)&&(Gammatot!=0)&&(scheme[k].gswidth!=0)){
                branching[i]+= scheme[k].gswidth/Gammatot*scheme[k].gswidth/(scheme[k].totalwidth+(scheme[k].S-1)*scheme[k].gswidth)*scheme[k].S;
                //cout <<k<< " "<< i*binning << " "<<scheme[k].energy<< " " << scheme[k].parity*scheme[k].spin<< " " << scheme[k].gswidth<<" "<< scheme[k].totalwidth<<" "<<scheme[k].S<<" "<< Gammatot<<endl;
                //cout << " ****" <<i*binning<< " "<<branching[i]<< " "<<scheme[k].totalwidth<<endl;
            }
            if ((scheme[k].spectrum[i]>0)&&(scheme[k].multiplicity>0)&&(Gammatot!=0)){
                for (l=i-1;l>=0;l--){
                    GammaSpectrum_new[l] -= scheme[k].spectrum[l]/scheme[k].multiplicity*GammaSpectrum[i]/scheme[k].spectrum[i]/scheme[k].S*scheme[k].gswidth/Gammatot;
                    //cout<< "gamma" <<GammaSpectrum_new[l]<<endl;
                    if (GammaSpectrum_new[l]<0){GammaSpectrum_new[l]=0;}
                }
            }
            k--;

        }

    }

    for (i=0;i<=(int)((scheme[scheme.size()-1].energy)/binning);i++){
        if (branching[i]>0){
            GammaSpectrum_new[i] = GammaSpectrum_new[i]/branching[i];
        }
        //cout << i*binning << " "<<branching[i]<<"\t" <<GammaSpectrum[i]<<"\t" <<GammaSpectrum_new[i]   <<endl;
    }


}
//******************************************************************************
void Analysis::LoadSpectrum(QString spectrumfile){
    double ee, nn;
    double ee_old,nn_old;
    for (i=0;i<2000;i++){
        GammaSpectrum[i]=0;
        GammaSpectrum_new[i]=0;
    }
    QFile Input(spectrumfile);
    if (Input.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&Input);
        ee_old = 0;
        nn_old = 0;
        i = 0;
        while (!in.atEnd()) {
            in >> ee >> nn;
            if (nn<0) nn = 0;
            //cout << " jj "<< ee << " "<<ee_old<<endl;
            if ((ee-ee_old)<0) break;
            if ((ee-ee_old)>binning){
               // cout << " jj "<< ee << " "<<ee_old<<endl;
                mainwindow_object->DoError("ERROR Spectrum binning larger than simulated binning");
                for (i=0;i<2000;i++){
                    GammaSpectrum[i]=0;
                }
                return;
            }
         //cout << ee << " "<< i*binning<<" "<<(ee-i*binning)/(ee-ee_old)<<endl;
            if (ee<=i*binning){
                GammaSpectrum[i]+=nn;
               // cout << "here"<<endl;
            }
            else{
                GammaSpectrum[i]+=nn*(1-(ee-(i)*binning)/(ee-ee_old));
                GammaSpectrum[i+1]+=nn*((ee-(i)*binning)/(ee-ee_old));
                i++;
            }

            nn_old = nn;
            ee_old = ee;
            //            if(in.status() != QTextStream::Ok) break;
        }
        Input.close();
    }
    if (ee_old<Emax){
        mainwindow_object->DoError("ERROR Emax to high");
        for (i=0;i<2000;i++){
            GammaSpectrum[i]=0;
        }
    }
    for (i=0;i<2000;i++){
        GammaSpectrum_new[i]=GammaSpectrum[i];
    }
    //for (i=0;i<200;i++){
      //cout<< i*binning << " "<< GammaSpectrum[i]<<endl;
    //}
}
