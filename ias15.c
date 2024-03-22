#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

const int dim = 3;
const int order = 7;

const double h[9] = {
    0.0,
    0.05626256053692215,
    0.18024069173689236,
    0.35262471711316964,
    0.54715362633055538,
    0.73421017721541053,
    0.88532094683909577,
    0.97752061356128750,
    1
};

//const double h[8] = {0.0, 0.0562625605369221464656521910318, 0.180240691736892364987579942780, 0.352624717113169637373907769648, 0.547153626330555383001448554766, 0.734210177215410531523210605558, 0.885320946839095768090359771030, 0.977520613561287501891174488626};

const double c_0_0 = 1;
const double c_1_0 = -0.05626256053692215;
const double c_1_1 = 1;
const double c_2_0 = 0.01014080283006363;
const double c_2_1 = -0.23650325227381452;
const double c_2_2 = 1;
const double c_3_0 = -0.003575897729251617;
const double c_3_1 = 0.09353769525946207;
const double c_3_2 = -0.5891279693869842;
const double c_3_3 = 1;
const double c_4_0 = 0.001956565409947221;
const double c_4_1 = -0.05475538688906869;
const double c_4_2 = 0.4158812000823069;
const double c_4_3 = -1.1362815957175396;
const double c_4_4 = 1;
const double c_5_0 = -0.0014365302363708915;
const double c_5_1 = 0.042158527721268706;
const double c_5_2 = -0.3600995965020568;
const double c_5_3 = 1.250150711840691;
const double c_5_4 = -1.87049177293295;
const double c_5_5 = 1;
const double c_6_0 = 0.0012717903090268678;
const double c_6_1 = -0.03876035791590677;
const double c_6_2 = 0.360962243452846;
const double c_6_3 = -1.466884208400427;
const double c_6_4 = 2.906136259308429;
const double c_6_5 = -2.7558127197720457;
const double c_6_6 = 1;
const double c_7_0 = -0.0012432012432012432;
const double c_7_1 = 0.03916083916083916;
const double c_7_2 = -0.3916083916083916;
const double c_7_3 = 1.7948717948717947;
const double c_7_4 = -4.3076923076923075;
const double c_7_5 = 5.6;
const double c_7_6 = -3.7333333333333334;
const double c_7_7 = 1;
const double c_8_0 = 0.0012432012432012432;
const double c_8_1 = -0.0404040404040404;
const double c_8_2 = 0.4307692307692308;
const double c_8_3 = -2.1864801864801864;
const double c_8_4 = 6.102564102564102;
const double c_8_5 = -9.907692307692308;
const double c_8_6 = 9.333333333333332;
const double c_8_7 = -4.733333333333333;
const double c_8_8 = 1;

const double d_0_0 = 1;
const double d_1_0 = 0.05626256053692215;
const double d_1_1 = 1;
const double d_2_0 = 0.0031654757181708297;
const double d_2_1 = 0.23650325227381452;
const double d_2_2 = 1;
const double d_3_0 = 0.00017809776922174343;
const double d_3_1 = 0.04579298550602792;
const double d_3_2 = 0.5891279693869842;
const double d_3_3 = 1;
const double d_4_0 = 1.002023652232913e-05;
const double d_4_1 = 0.008431857153525702;
const double d_4_2 = 0.25353406905456927;
const double d_4_3 = 1.1362815957175396;
const double d_4_4 = 1;
const double d_5_0 = 5.637641639318209e-07;
const double d_5_1 = 0.001529784002500466;
const double d_5_2 = 0.09783423653244401;
const double d_5_3 = 0.8752546646840911;
const double d_5_4 = 1.87049177293295;
const double d_5_5 = 1;
const double d_6_0 = 3.171881540176138e-08;
const double d_6_1 = 0.0002762930909826477;
const double d_6_2 = 0.03602855398373646;
const double d_6_3 = 0.5767330002770787;
const double d_6_4 = 2.2485887607691595;
const double d_6_5 = 2.7558127197720457;
const double d_6_6 = 1;
const double d_7_0 = 1.7845817717010581e-09;
const double d_7_1 = 4.9830976656238314e-05;
const double d_7_2 = 0.012980851747494276;
const double d_7_3 = 0.3515901065098413;
const double d_7_4 = 2.2276697528059834;
const double d_7_5 = 4.688367487148971;
const double d_7_6 = 3.7333333333333334;
const double d_7_7 = 1;
const double d_8_0 = 1.0040513996341856e-10;
const double d_8_1 = 8.98335428421703e-06;
const double d_8_2 = 0.004627200152004401;
const double d_8_3 = 0.20535465350630017;
const double d_8_4 = 1.987167910494932;
const double d_8_5 = 6.378379695658343;
const double d_8_6 = 8.337777777777777;
const double d_8_7 = 4.733333333333333;
const double d_8_8 = 1;


const double r_1_0 = 17.773808914078;
const double r_2_0 = 5.548136718537217;
const double r_2_1 = 8.065938648381888;
const double r_2_2 = 1;
const double r_3_0 = 2.835876078644439;
const double r_3_1 = 3.3742499769626355;
const double r_3_2 = 5.801001559264062;
const double r_3_3 = 1;
const double r_3_4 = 0;
const double r_3_5 = 0;
const double r_3_6 = 0;
const double r_3_7 = 0;
const double r_3_8 = 0;
const double r_3_9 = 0;
const double r_4_0 = 1.8276402675175978;
const double r_4_1 = 2.0371118353585844;
const double r_4_2 = 2.725442211808226;
const double r_4_3 = 5.140624105810932;
const double r_4_4 = 1;
const double r_4_5 = 0;
const double r_4_6 = 0;
const double r_4_7 = 0;
const double r_4_8 = 0;
const double r_4_9 = 0;
const double r_5_0 = 1.3620078160624696;
const double r_5_1 = 1.4750402175604116;
const double r_5_2 = 1.8051535801402514;
const double r_5_3 = 2.620644926387035;
const double r_5_4 = 5.3459768998711095;
const double r_5_5 = 1;
const double r_5_6 = 0;
const double r_5_7 = 0;
const double r_5_8 = 0;
const double r_5_9 = 0;
const double r_6_0 = 1.1295338753367898;
const double r_6_1 = 1.2061876660584456;
const double r_6_2 = 1.418278263734739;
const double r_6_3 = 1.8772424961868102;
const double r_6_4 = 2.957116017290456;
const double r_6_5 = 6.617662013702422;
const double r_6_6 = 1;
const double r_6_7 = 0;
const double r_6_8 = 0;
const double r_6_9 = 0;
const double r_7_0 = 1.0229963298234868;
const double r_7_1 = 1.0854721939386425;
const double r_7_2 = 1.2542646222818779;
const double r_7_3 = 1.6002665494908161;
const double r_7_4 = 2.3235983002196945;
const double r_7_5 = 4.109975778344558;
const double r_7_6 = 10.846026190236847;
const double r_7_7 = 1;
const double r_7_8 = 0;
const double r_7_9 = 0;
const double r_8_0 = 1.0;
const double r_8_1 = 1.0596167516347892;
const double r_8_2 = 1.2198702593798945;
const double r_8_3 = 1.5446990739910793;
const double r_8_4 = 2.2082544062281713;
const double r_8_5 = 3.762371295948582;
const double r_8_6 = 8.719988284145643;
const double r_8_7 = 44.48519992867184;
const double r_8_8 = 0;
const double r_8_9 = 0;
const double r_9_0 = 0;
const double r_9_1 = 0;
const double r_9_2 = 0;
const double r_9_3 = 0;
const double r_9_4 = 0;
const double r_9_5 = 0;
const double r_9_6 = 0;
const double r_9_7 = 0;
const double r_9_8 = 0;
const double r_9_9 = 0;

void update_velocity(double *v, int dim, double h_n, double T, double * Fs , double * Bs){
     for (int ii=0; ii < dim; ii++){ 
        *(v+ii) += 
        (h_n * T * 
        (Fs[ii * (order + 1) + 0] + h_n * 
        (Bs[ii * order + 0]/2 + h_n * 
        (Bs[ii * order + 1]/3 + h_n * 
        (Bs[ii * order + 2]/4 + h_n * 
        (Bs[ii * order + 3]/5 + h_n * 
        (Bs[ii * order + 4]/6 + h_n * 
        (Bs[ii * order + 5]/7 + h_n * 
        (Bs[ii * order + 6]/8 //+ h_n * 
        //(Bs[ii * order + 7]/9
        )))))))));
     }
}
    

void update_position(double *y, double *v, int dim, double h_n, double T, double * Fs, double * Bs){
    for (int ii=0; ii < dim; ii++){ 
      *(y+ii) += 
        ((*(v+ii) * h_n * T) + 
        ((h_n * T)*(h_n * T)) * 
        (Fs[ii * (order + 1) + 0]/2 + h_n * 
        (Bs[ii * order + 0]/6 + h_n * 
        (Bs[ii * order + 1]/12 + h_n * 
        (Bs[ii * order + 2]/20 + h_n * 
        (Bs[ii * order + 3]/30 + h_n * 
        (Bs[ii * order + 4]/42 + h_n * 
        (Bs[ii * order + 5]/56 + h_n * 
        (Bs[ii * order + 6]/72 //+ h_n * 
        //(Bs[ii * order + 7]/90)
        )))))))));
    }
}

void update_Gs_from_Fs(int current_truncation_order, int i, double * Gs, double * Fs){
  //int i;
  int j;
  //for (i = 0; i < dim; i++){
  j = i * order;
  if (current_truncation_order == 0 + 1){ Gs[j + 0] = (Fs[j + 1] - Fs[j + 0]) * r_1_0; }
  if (current_truncation_order == 1 + 1){ Gs[j + 1] = ((Fs[j + 2] - Fs[j + 0]) * r_2_0 - Gs[j + 0]) * r_2_1; }
  if (current_truncation_order == 2 + 1){ Gs[j + 2] = (((Fs[j + 3] - Fs[j + 0]) * r_3_0 - Gs[j + 0]) * r_3_1 - Gs[j + 1]) * r_3_2; }
  if (current_truncation_order == 3 + 1){ Gs[j + 3] = ((((Fs[j + 4] - Fs[j + 0]) * r_4_0 - Gs[j + 0]) * r_4_1 - Gs[j + 1]) * r_4_2 - Gs[j + 2]) * r_4_3; }
  if (current_truncation_order == 4 + 1){ Gs[j + 4] = (((((Fs[j + 5] - Fs[j + 0]) * r_5_0 - Gs[j + 0]) * r_5_1 - Gs[j + 1]) * r_5_2 - Gs[j + 2]) * r_5_3 - Gs[j + 3]) * r_5_4; }
  if (current_truncation_order == 5 + 1){ Gs[j + 5] = ((((((Fs[j + 6] - Fs[j + 0]) * r_6_0 - Gs[j + 0]) * r_6_1 - Gs[j + 1]) * r_6_2 - Gs[j + 2]) * r_6_3 - Gs[j + 3]) * r_6_4 - Gs[j + 4]) * r_6_5; }
  if (current_truncation_order == 6 + 1){ Gs[j + 6] = (((((((Fs[j + 7] - Fs[j + 0]) * r_7_0 - Gs[j + 0]) * r_7_1 - Gs[j + 1]) * r_7_2 - Gs[j + 2]) * r_7_3 - Gs[j + 3]) * r_7_4 - Gs[j + 4]) * r_7_5 - Gs[j + 5]) * r_7_6; }
    //if (current_truncation_order == 7){ Gs[j + 7] = ((((((((Fs[j + 8] - Fs[j + 0]) * r_8_0 - Gs[j + 0]) * r_8_1 - Gs[j + 1]) * r_8_2 - Gs[j + 2]) * r_8_3 - Gs[j + 3]) * r_8_4 - Gs[j + 4]) * r_8_5 - Gs[j + 5]) * r_8_6 - Gs[j + 6]) * r_8_7; }
  //}
}

void update_Gs_from_Bs(int current_truncation_order, int dim, double * Gs, double * Bs){
  int i;
  int j;
  for (i = 0; i < dim; i++){
    j = i * order;
    Gs[j + 0] = d_0_0 * Bs[j + 0] + d_1_0 * Bs[j + 1] + d_2_0 * Bs[j + 2] + d_3_0 * Bs[j + 3] + d_4_0 * Bs[j + 4] + d_5_0 * Bs[j + 5] + d_6_0 * Bs[j + 6];// + d_7_0 * Bs[j + 7];
    Gs[j + 1] =                     d_1_1 * Bs[j + 1] + d_2_1 * Bs[j + 2] + d_3_1 * Bs[j + 3] + d_4_1 * Bs[j + 4] + d_5_1 * Bs[j + 5] + d_6_1 * Bs[j + 6];// + d_7_1 * Bs[j + 7];
    Gs[j + 2] =                                         d_2_2 * Bs[j + 2] + d_3_2 * Bs[j + 3] + d_4_2 * Bs[j + 4] + d_5_2 * Bs[j + 5] + d_6_2 * Bs[j + 6];// + d_7_2 * Bs[j + 7];
    Gs[j + 3] =                                                             d_3_3 * Bs[j + 3] + d_4_3 * Bs[j + 4] + d_5_3 * Bs[j + 5] + d_6_3 * Bs[j + 6];// + d_7_3 * Bs[j + 7];
    Gs[j + 4] =                                                                                 d_4_4 * Bs[j + 4] + d_5_4 * Bs[j + 5] + d_6_4 * Bs[j + 6];// + d_7_4 * Bs[j + 7];
    Gs[j + 5] =                                                                                                     d_5_5 * Bs[j + 5] + d_6_5 * Bs[j + 6];// + d_7_5 * Bs[j + 7];
    Gs[j + 6] =                                                                                                                         d_6_6 * Bs[j + 6];// + d_7_6 * Bs[j + 7];
  }
}

void update_Bs_from_Gs__(int current_truncation_order, int i, double * Bs, double * Gs, double diff_G){
  int j;
  j = i * order;
  if (current_truncation_order == 0 + 1){
    Bs[j + 0] += diff_G;
  }
  if (current_truncation_order == 1 + 1){
    Bs[j + 0] +=  diff_G * c_1_0;
    Bs[j + 1] +=  diff_G;
  }
  if (current_truncation_order == 2 + 1){
    Bs[j + 0] +=  diff_G * c_2_0;
    Bs[j + 1] +=  diff_G * c_2_1;
    Bs[j + 2] +=  diff_G;
  }
  if (current_truncation_order == 3 + 1){
    Bs[j + 0] +=  diff_G * c_3_0;
    Bs[j + 1] +=  diff_G * c_3_1;
    Bs[j + 2] +=  diff_G * c_3_2;
    Bs[j + 3] +=  diff_G;
  }
  if (current_truncation_order == 4 + 1){
    Bs[j + 0] +=  diff_G * c_4_0;
    Bs[j + 1] +=  diff_G * c_4_1;
    Bs[j + 2] +=  diff_G * c_4_2;
    Bs[j + 3] +=  diff_G * c_4_3;
    Bs[j + 4] +=  diff_G;
  } 
  if (current_truncation_order == 5 + 1){
    Bs[j + 0] +=  diff_G * c_5_0;
    Bs[j + 1] +=  diff_G * c_5_1;
    Bs[j + 2] +=  diff_G * c_5_2;
    Bs[j + 3] +=  diff_G * c_5_3;
    Bs[j + 4] +=  diff_G * c_5_4;
    Bs[j + 5] +=  diff_G ;
  }
  if (current_truncation_order == 6 + 1){
    Bs[j + 0] +=  diff_G * c_6_0;
    Bs[j + 1] +=  diff_G * c_6_1;
    Bs[j + 2] +=  diff_G * c_6_2;
    Bs[j + 3] +=  diff_G * c_6_3;
    Bs[j + 4] +=  diff_G * c_6_4;
    Bs[j + 5] +=  diff_G * c_6_5;
    Bs[j + 6] +=  diff_G;
  }
}

void update_Bs_from_Gs(int current_truncation_order, int dim, double * Bs, double * Gs){
  int i;
  for (i = 0; i < dim; i++){
    Bs[i * order + 0] = c_0_0 * Gs[i * order + 0] + c_1_0 * Gs[i * order + 1] + c_2_0 * Gs[i * order + 2] + c_3_0 * Gs[i * order + 3] + c_4_0 * Gs[i * order + 4] + c_5_0 * Gs[i * order + 5] + c_6_0 * Gs[i * order + 6];// + c_7_0 * Gs[i * order + 7];
    if (current_truncation_order == 0){ continue; }
    Bs[i * order + 1] =                             c_1_1 * Gs[i * order + 1] + c_2_1 * Gs[i * order + 2] + c_3_1 * Gs[i * order + 3] + c_4_1 * Gs[i * order + 4] + c_5_1 * Gs[i * order + 5] + c_6_1 * Gs[i * order + 6];// + c_7_1 * Gs[i * order + 7];
    if (current_truncation_order == 1){ continue; }
    Bs[i * order + 2] =                                                         c_2_2 * Gs[i * order + 2] + c_3_2 * Gs[i * order + 3] + c_4_2 * Gs[i * order + 4] + c_5_2 * Gs[i * order + 5] + c_6_2 * Gs[i * order + 6];// + c_7_2 * Gs[i * order + 7];
    if (current_truncation_order == 2){ continue; }
    Bs[i * order + 3] =                                                                                     c_3_3 * Gs[i * order + 3] + c_4_3 * Gs[i * order + 4] + c_5_3 * Gs[i * order + 5] + c_6_3 * Gs[i * order + 6];// + c_7_3 * Gs[i * order + 7];
    if (current_truncation_order == 3){ continue; }
    Bs[i * order + 4] =                                                                                                                 c_4_4 * Gs[i * order + 4] + c_5_4 * Gs[i * order + 5] + c_6_4 * Gs[i * order + 6];// + c_7_4 * Gs[i * order + 7];
    if (current_truncation_order == 4){ continue; }
    Bs[i * order + 5] =                                                                                                                                             c_5_5 * Gs[i * order + 5] + c_6_5 * Gs[i * order + 6];// + c_7_5 * Gs[i * order + 7];
    if (current_truncation_order == 5){ continue; }
    Bs[i * order + 6] =                                                                                                                                                                         c_6_6 * Gs[i * order + 6];// + c_7_6 * Gs[i * order + 7];
    //if (current_truncation_order == 6){ continue; }
    //Bs[i * order + 7] =                                                                                                                                                                                                     c_7_7 * Gs[i * order + 7];
  }
}

void my_func(double * x, double * a){
    int i;
    for (i = 0; i < dim; i++){
        a[i] = -1 * x[i];
    }
}

void next_sequence_Bs(double Q, double * Bs, double *Es, double * BDs, int dim){
  int i;
  int j;
  for (i = 0; i < dim; i++){
    j = i * order;

    BDs[j + 0] = Bs[j + 0] - Es[j + 0];
    BDs[j + 1] = Bs[j + 1] - Es[j + 1];
    BDs[j + 2] = Bs[j + 2] - Es[j + 2];
    BDs[j + 3] = Bs[j + 3] - Es[j + 3];
    BDs[j + 4] = Bs[j + 4] - Es[j + 4];
    BDs[j + 5] = Bs[j + 5] - Es[j + 5];
    BDs[j + 6] = Bs[j + 6] - Es[j + 6];

    Es[j + 0] = (Bs[j + 0] + 2 * Bs[j + 1] + 3 * Bs[j + 2] + 4 * Bs[j + 3] + 5 * Bs[j + 4] + 6 * Bs[j + 5] + 7 * Bs[j + 6]);
    Es[j + 1] = (Bs[j + 1] + 3 * Bs[j + 2] + 6 * Bs[j + 3] + 10 * Bs[j + 4] + 15 * Bs[j + 5] + 21 * Bs[j + 6]);
    Es[j + 2] = (Bs[j + 2] + 4 * Bs[j + 3] + 10 * Bs[j + 4] + 20 * Bs[j + 5] + 35 * Bs[j + 6]);
    Es[j + 3] = (Bs[j + 3] + 5 * Bs[j + 4] + 15 * Bs[j + 5] + 35 * Bs[j + 6]);
    Es[j + 4] = (Bs[j + 4] + 6 * Bs[j + 5] + 21 * Bs[j + 6]);
    Es[j + 5] = (Bs[j + 5] + 7 * Bs[j + 6]);
    Es[j + 6] = (Bs[j + 6]);

    Bs[j + 0] = Es[j + 0] + BDs[j + 0];
    Bs[j + 1] = Es[j + 1] + BDs[j + 1];
    Bs[j + 2] = Es[j + 2] + BDs[j + 2];
    Bs[j + 3] = Es[j + 3] + BDs[j + 3];
    Bs[j + 4] = Es[j + 4] + BDs[j + 4];
    Bs[j + 5] = Es[j + 5] + BDs[j + 5];
    Bs[j + 6] = Es[j + 6] + BDs[j + 6];
  }
}

int main(){
  //Declare and initialize
  double *yo= (double *) malloc ( (2 * dim) * sizeof(double) );
  
  yo[0] = 5.0;
  yo[1] = 0.0;
  yo[2] = 0.0;
  yo[3] = 0.0;
  yo[4] = 0.0;
  yo[5] = 0.0;
  
  double *x= (double *) malloc ( dim * sizeof(double) );
  double *v= (double *) malloc ( dim * sizeof(double) ); 
  double *a= (double *) malloc ( dim * sizeof(double) );
  double *xs= (double *) malloc ( dim * sizeof(double) ); //x substep

  double *Bs= (double *) malloc ( (order * dim) * sizeof(double) );
  double *Es= (double *) malloc ( (order * dim) * sizeof(double) );
  double *BDs= (double *) malloc ( (order * dim) * sizeof(double) );
  double *Gs= (double *) malloc ( (order * dim) * sizeof(double) );
  double *Fs= (double *) malloc ( ((order + 1) * dim) * sizeof(double) );

  int ii, jj, kk;

  for (ii=0; ii < dim; ii++) {
    *(x+ii) = *(yo+ii);
    *(v+ii) = *(yo+dim+ii);
  }

  for (ii=0; ii < (order * dim); ii++) *(Bs+ii)= 0;
  
  printf("%f\n", x[2]);
  printf("%f\n", a[2]);
  //Integrate the system

  //Estimate necessary stepsize
  double dt = 0.0001;
  double init_dt= 1;

  double diff_G;
  if ( dt == -9999.99 ) {
    dt= 0.0001; //TODO create the estimator
  }
  long ndt= 1; //(long) (init_dt/dt);

  //update force at start of step
  my_func(x, a);
  Fs[0] = a[0];
  Fs[1 * (order + 1)] = a[1];
  Fs[2 * (order + 1)] = a[2];
  //update G from B
  update_Gs_from_Bs(order, dim, Gs, Bs);

  //take the first step, 6 iterations
  for (int j=0; j< 6; j++){
      //at start of each step reset xs
      for (ii=0; ii < dim; ii++) *(xs+ii)= *(x+ii);

      for (int k=1; k < (order + 1); k++){
          //update position, update force, update G, update B
          update_position(xs, v, dim, h[k], dt, Fs, Bs);
          my_func(xs, a);
          for (int i=0; i < dim; i++){
              Fs[i * (order + 1) + k] = a[i];

              diff_G = Gs[i * order + k];
              update_Gs_from_Fs(k, i, Gs, Fs);
              diff_G = Gs[i * order + k] - diff_G;

              update_Bs_from_Gs__(k, i, Bs, Gs, diff_G);
          }
      }
  }
  
  update_position(x, v, dim, 1, dt, Fs, Bs);
  update_velocity(v, dim, 1, dt, Fs , Bs);
  next_sequence_Bs(1, Bs, Es, BDs, dim);
  printf("%f\n", x[2]);
  printf("%f\n", a[2]);

  for (ii=0; ii < (2000); ii++){
    for (jj=0; jj < 100; jj++) {
      //after first step, 2 iterations

      //update force at start of step
      my_func(x, a);
      Fs[0] = a[0];
      Fs[1 * (order + 1)] = a[1];
      Fs[2 * (order + 1)] = a[2];
      //update G from B
      //printf("--BBBB------\n");
      //for (int i=0; i < order; i++){
      //  printf("%f\n", Bs[i]);
      //}
      update_Gs_from_Bs(order, dim, Gs, Bs);
      //printf("--GGGG------\n");
      //for (int i=0; i < order; i++){
      //  printf("%f\n", Gs[i]);
      //}

      for (int j=0; j< 2; j++){
          //at start of each step reset xs
          for (int l=0; l < dim; l++) *(xs+l)= *(x+l);

          for (int k=1; k < (order + 1); k++){
              //update position, update force, update G, update B
              update_position(xs, v, dim, h[k], dt, Fs, Bs);
              my_func(xs, a);
              for (int i=0; i < dim; i++){
                  Fs[i * (order + 1) + k] = a[i];

                  diff_G = Gs[i * order + k];
                  update_Gs_from_Fs(k, i, Gs, Fs);
                  diff_G = Gs[i * order + k] - diff_G;

                  update_Bs_from_Gs__(k, i, Bs, Gs, diff_G);
              }
          }
      }

      update_position(x, v, dim, 1, dt, Fs, Bs);
      update_velocity(v, dim, 1, dt, Fs , Bs);
      next_sequence_Bs(1, Bs, Es, BDs, dim);
    }

    //printf("=======\n");
    //printf("%f\n", a[0]);
    //printf("%f\n", Fs[0]);
    //printf("%f\n", v[0]);
    //save
    printf("====xvz====\n");
    printf("%f\n", x[2]);
    printf("%f\n", v[2]);
    printf("%f\n", a[2]);
  }

  printf("BLAH BLAH BLAH");
  //Free allocated memory
  free(x);
  free(v);
  free(a);
  free(xs);
  free(yo);

  free(Fs);
  free(Gs);
  free(Bs);
  free(Es);
  free(BDs);
  //We're done

  return 0;
}
