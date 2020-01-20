/************************************************************************
 *
 * libSSQ @2020 Scuola Sisini
 * Licenza GPL3 
 * 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <complex.h>
#include <stdio.h>
#include "libSSQ.h"

/*___________________________________________________
 *
 * Base STANDARD qubit singolo
 */
const base1 base_std1 =
  {
    {{1,0}},//0
    {{0,1}} //1
  };

/*___________________________________________________
 *
 * Base STANDARD 2qubits
 */
const base2 base_std2=
  {
    {{1,0,0,0}},//00
    {{0,1,0,0}},//01
    {{0,0,1,0}},//10
    {{0,0,0,1}} //11
  };

/*___________________________________________________
 *
 * Base STANDARD opertori 1_1
 */
const base1_1 base_std1_1 =
  {
    {
      {1,0,
      0,0}
    }
    ,
    {
      {0,1,
      0,0}
    }
    ,
    {
      {0,0,
      1,0}
    }
    ,
    {
      {0,0,
      0,1}
    }
  };

/*___________________________________________________
 *
 * Base STANDARD opertori 2_2
 */
const base2_2 base_std2_2 =
  {
    {
      {1,0,0,0,
       0,0,0,0,
       0,0,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,1,0,0,
       0,0,0,0,
       0,0,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,1,0,
       0,0,0,0,
       0,0,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,1,
       0,0,0,0,
       0,0,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       1,0,0,0,
       0,0,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,1,0,0,
       0,0,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,1,0,
       0,0,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,0,1,
       0,0,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,0,0,
       1,0,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,0,0,
       0,1,0,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,0,0,
       0,0,1,0,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,0,0,
       0,0,0,1,
       0,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,0,0,
       0,0,0,0,
       1,0,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,0,0,
       0,0,0,0,
       0,1,0,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,0,0,
       0,0,0,0,
       0,0,1,0}
    }
    ,
    {
      {0,0,0,0,
       0,0,0,0,
       0,0,0,0,
       0,0,0,1}
    }
  };

//--Servizio
void matrice_x_vettore2
(double complex v_out[2],elemento1_1 m,elemento1 v_in)
{
  for(int i=0;i<2;i++) v_out[i] = 0;
  
  for(int i=0;i<2;i++)
    {
      for(int j=0;j<2;j++)
        {
          v_out[i]+=m.c[i][j]*v_in.c[j];
        }
    }
}
void matrice_x_vettore4
(double complex v_out[4],elemento2_2 m,elemento2 v_in)
{
  for(int i=0;i<4;i++) v_out[i] = 0;
  
  for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
        {
          v_out[i]+=m.c[i][j]*v_in.c[j];
        }
    }
}


/*____________________________________________________
 *
 * crea un ket di stato di ampiezze complesse
 * x e y sulla base b
 */
ket1
crea_ket1(double complex x, double complex y, base1 b)
{
  ket1 ket = {x,y,b};
  return ket;
}

/*____________________________________________________
 *
 * crea un ket di stato di due qubits ampiezze complesse
 * x1, y1, x2 e y2 sulla base b
 * come prodotto dei due key
 * non è possibile creare direttamente ket entangled
 */
ket2
crea_ket2(double complex x1, double complex y1,
          double complex x2, double complex y2,base2 b)
{
  ket2 ket ={x1*x2,x1*y2,y1*x2,y1*y2,b};
  return ket;
  
}

/*____________________________________________________
 *
 * crea un operatore (tensore 1_1) di coefficienti
 * complessi a11, a12, a21 e a22 sulla base b
 */
op1_1 crea_tensore1_1
(double complex a11,double complex a12,double complex a21,double complex a22, base1_1 b)
{
  op1_1 o = {a11,a12,a21,a22,b};
  return o;
}

/*____________________________________________________
 *
 * crea un operatore (tensore 2_2) di coefficienti
 * complessi a11, a12,...,a44 sulla base b
 */
op2_2 crea_tensore2_2
(double complex a11,double complex a12,double complex a13,double complex a14,
 double complex a21,double complex a22,double complex a23,double complex a24,
 double complex a31,double complex a32,double complex a33,double complex a34,
 double complex a41,double complex a42,double complex a43,double complex a44,
 base2_2 b
 )
{
  op2_2 o={a11,a12,a13,a14,a21,a22,a23,a24,a31,a32,a33,a34,a41,a42,a43,a44,b};
  return o;
}

/*____________________________________________________
 *
 * Trasforma un ket tramite un operatore
 * 
 */
ket1 trasforma_ket1(op1_1 o,ket1 ket)
{
  ket1 ketp;

  //Preparazione array di servizio
  double complex v[2];
  elemento1 e[2] = {ket.b.e1,ket.b.e2};
  elemento1_1 ee_[2][2] = {o.b.e1e_1,o.b.e1e_2,o.b.e2e_1,o.b.e2e_2};
  double complex x[2] =  {ket.x,ket.y};
  double complex a[2][2] = {o.a11,o.a12,o.a21,o.a22};

  //Inizializzazione
  ketp.x = 0;
  ketp.y = 0;
  for(int k=0;k<2;k++)
    for(int i=0;i<2;i++)
      {
        //Il tensore o è svliluppato sulla base eie_j come:
        //o = a11*e1e_1+...+a22*e2e_2
        //Il ket ket è sviluppato sulla base ei come:
        //ket = x*e1+y*e2
        //Il prodottotto o*ket si sviluppa linearmente come:
        //o*ket=(a11*e1e_1+...+a22*e2e_2)*(x*e1+y*e2) quindi:
        //o*ket=e1e_1(e1)*a11*x+... dove si ricorda che
        //e1e_1(e1) è un prodotto matrice x colonna
        for(int j=0;j<2;j++)
          {
            matrice_x_vettore2(v,ee_[i][j],e[k]);
            ketp.x += v[0]*a[i][j]*x[k];
            ketp.y += v[1]*a[i][j]*x[k];
          }
      }
  /*
  //Ket è la somma dei due vettori di base e1 ed e2
  // oe1 --------------------------------------------
  matrice_x_vettore2(v,o.b.e1e_1,ket.b.e1);
  ketp.x = v[0]*o.a11*ket.x;
  ketp.y = v[1]*o.a11*ket.x;
  //--
  matrice_x_vettore2(v,o.b.e1e_2,ket.b.e1);
  ketp.x += v[0]*o.a12*ket.x;
  ketp.y += v[1]*o.a12*ket.x;
  //--
  matrice_x_vettore2(v,o.b.e2e_1,ket.b.e1);
  ketp.x += v[0]*o.a21*ket.x;
  ketp.y += v[1]*o.a21*ket.x;
  //--
  matrice_x_vettore2(v,o.b.e2e_2,ket.b.e1);
  ketp.x += v[0]*o.a22*ket.x;
  ketp.y += v[1]*o.a22*ket.x;
  // oe2 ---------------------------------------------
  matrice_x_vettore2(v,o.b.e1e_1,ket.b.e2);
  ketp.x += v[0]*o.a11*ket.y;
  ketp.y += v[1]*o.a11*ket.y;
  //--
  matrice_x_vettore2(v,o.b.e1e_2,ket.b.e2);
  ketp.x += v[0]*o.a12*ket.y;
  ketp.y += v[1]*o.a12*ket.y;
  //--
  matrice_x_vettore2(v,o.b.e2e_1,ket.b.e2);
  ketp.x += v[0]*o.a21*ket.y;
  ketp.y += v[1]*o.a21*ket.y;
  //--
  matrice_x_vettore2(v,o.b.e2e_2,ket.b.e2);
  ketp.x += v[0]*o.a22*ket.y;
  ketp.y += v[1]*o.a22*ket.y;
  */
  return ketp;
}

ket2 trasforma_ket2(op2_2 o,ket2 ket)
{
  ket2 ketp;
  ketp.x11 = ketp.x12 = ketp.x21 = ketp.x22 = 0;
  //Preparazione array di servizio
  double complex v[4];
  elemento2 e[4] = {ket.b.e1f1,ket.b.e1f2,ket.b.e2f1,ket.b.e2f2};
  elemento2_2 ee_[4][4] = {
    o.b.e1f1e_1f_1,o.b.e1f1e_1f_2,o.b.e1f1e_2f_1,o.b.e1f1e_2f_2,
    o.b.e1f2e_1f_1,o.b.e1f2e_1f_2,o.b.e1f2e_2f_1,o.b.e1f2e_2f_2,
    o.b.e2f1e_1f_1,o.b.e2f1e_1f_2,o.b.e2f1e_2f_1,o.b.e2f1e_2f_2,
    o.b.e2f2e_1f_1,o.b.e2f2e_1f_2,o.b.e2f2e_2f_1,o.b.e2f2e_2f_2
  };
  double complex x[4] =  {ket.x11,ket.x12,ket.x21,ket.x22};
  double complex a[4][4] = {
    o.a11,o.a12,o.a13,o.a14,
    o.a21,o.a22,o.a23,o.a24,
    o.a31,o.a32,o.a33,o.a34,
    o.a41,o.a42,o.a43,o.a44
  };

   for(int k=0;k<4;k++)
    for(int i=0;i<4;i++)
      {
        //Per una spiegazione, vedi i commenti di trasforma_ket1
        for(int j=0;j<4;j++)
          {
            matrice_x_vettore4(v,ee_[i][j],e[k]);
            
            ketp.x11 += v[0]*a[i][j]*x[k];
            ketp.x12 += v[1]*a[i][j]*x[k];
            ketp.x21 += v[2]*a[i][j]*x[k];
            ketp.x22 += v[3]*a[i][j]*x[k];
          }
      }
  /*
  //Ket è la somma dei quattro  bas e1f1.. e2f2
  // oe1f1 --------------------------------------------
  matrice_x_vettore4(v,o.b.e1f1_e1f1,ket.b.e1f1);
  ketp.x11 = v[0]*o.a11*ket.x11;
  ketp.x12 = v[1]*o.a11*ket.x11;
  ketp.x21 = v[2]*o.a11*ket.x11;
  ketp.x22 = v[3]*o.a11*ket.x11;
  // 1,2
  matrice_x_vettore4(v,o.b.e1f2_e1f2,ket.b.e1f1);
  ketp.x11 += v[0]*o.a12*ket.x11;
  ketp.x12 += v[1]*o.a12*ket.x11;
  ketp.x21 += v[2]*o.a12*ket.x11;
  ketp.x22 += v[3]*o.a12*ket.x11;
  // 1,3
  matrice_x_vettore4(v,o.b.e1f3_e1f3,ket.b.e1f1);
  ketp.x11 += v[0]*o.a13*ket.x11;
  ketp.x12 += v[1]*o.a13*ket.x11;
  ketp.x21 += v[2]*o.a13*ket.x11;
  ketp.x22 += v[3]*o.a13*ket.x11;
  // 1,4
  matrice_x_vettore4(v,o.b.e1f4_e1f4,ket.b.e1f1);
  ketp.x11 += v[0]*o.a14*ket.x11;
  ketp.x12 += v[1]*o.a14*ket.x11;
  ketp.x21 += v[2]*o.a14*ket.x11;
  ketp.x22 += v[3]*o.a14*ket.x11;
  // 2,1
  matrice_x_vettore4(v,o.b.e2f1_e2f1,ket.b.e1f1);
  ketp.x11 += v[0]*o.a21*ket.x11;
  ketp.x12 += v[1]*o.a21*ket.x11;
  ketp.x21 += v[2]*o.a21*ket.x11;
  ketp.x22 += v[3]*o.a21*ket.x11;
  // 2,2
  matrice_x_vettore4(v,o.b.e2f2_e2f2,ket.b.e1f1);
  ketp.x11 += v[0]*o.a22*ket.x11;
  ketp.x12 += v[1]*o.a22*ket.x11;
  ketp.x21 += v[2]*o.a22*ket.x11;
  ketp.x22 += v[3]*o.a22*ket.x11;
  // 2,3
  matrice_x_vettore4(v,o.b.e2f3_e2f3,ket.b.e1f1);
  ketp.x11 += v[0]*o.a23*ket.x11;
  ketp.x12 += v[1]*o.a23*ket.x11;
  ketp.x21 += v[2]*o.a23*ket.x11;
  ketp.x22 += v[3]*o.a23*ket.x11;
  // 2,4
  matrice_x_vettore4(v,o.b.e2f4_e2f4,ket.b.e1f1);
  ketp.x11 += v[0]*o.a24*ket.x11;
  ketp.x12 += v[1]*o.a24*ket.x11;
  ketp.x21 += v[2]*o.a24*ket.x11;
  ketp.x22 += v[3]*o.a24*ket.x11;
  // 3,1
  matrice_x_vettore4(v,o.b.e3f1_e3f1,ket.b.e1f1);
  ketp.x11 += v[0]*o.a31*ket.x11;
  ketp.x12 += v[1]*o.a31*ket.x11;
  ketp.x21 += v[2]*o.a31*ket.x11;
  ketp.x22 += v[3]*o.a31*ket.x11;
  // 3,2
  matrice_x_vettore4(v,o.b.e3f2_e3f2,ket.b.e1f1);
  ketp.x11 += v[0]*o.a32*ket.x11;
  ketp.x12 += v[1]*o.a32*ket.x11;
  ketp.x21 += v[2]*o.a32*ket.x11;
  ketp.x22 += v[3]*o.a32*ket.x11;
  // 3,3
  matrice_x_vettore4(v,o.b.e3f3_e3f3,ket.b.e1f1);
  ketp.x11 += v[0]*o.a33*ket.x11;
  ketp.x12 += v[1]*o.a33*ket.x11;
  ketp.x21 += v[2]*o.a33*ket.x11;
  ketp.x22 += v[3]*o.a33*ket.x11;
  // 3,4
  matrice_x_vettore4(v,o.b.e3f4_e3f4,ket.b.e1f1);
  ketp.x11 += v[0]*o.a34*ket.x11;
  ketp.x12 += v[1]*o.a34*ket.x11;
  ketp.x21 += v[2]*o.a34*ket.x11;
  ketp.x22 += v[3]*o.a34*ket.x11;
  // 4,1
  matrice_x_vettore4(v,o.b.e4f1_e4f1,ket.b.e1f1);
  ketp.x11 += v[0]*o.a41*ket.x11;
  ketp.x12 += v[1]*o.a41*ket.x11;
  ketp.x21 += v[2]*o.a41*ket.x11;
  ketp.x22 += v[3]*o.a41*ket.x11;
  // 4,2
  matrice_x_vettore4(v,o.b.e4f2_e4f2,ket.b.e1f1);
  ketp.x11 += v[0]*o.a42*ket.x11;
  ketp.x12 += v[1]*o.a42*ket.x11;
  ketp.x21 += v[2]*o.a42*ket.x11;
  ketp.x22 += v[3]*o.a42*ket.x11;
  // 4,3
  matrice_x_vettore4(v,o.b.e4f3_e4f3,ket.b.e1f1);
  ketp.x11 += v[0]*o.a43*ket.x11;
  ketp.x12 += v[1]*o.a43*ket.x11;
  ketp.x21 += v[2]*o.a43*ket.x11;
  ketp.x22 += v[3]*o.a43*ket.x11;
  // 4,4
  matrice_x_vettore4(v,o.b.e4f4_e4f4,ket.b.e1f1);
  ketp.x11 += v[0]*o.a44*ket.x11;
  ketp.x12 += v[1]*o.a44*ket.x11;
  ketp.x21 += v[2]*o.a44*ket.x11;
  ketp.x22 += v[3]*o.a44*ket.x11;
  // oe1f2 --------------------------------------------
  matrice_x_vettore4(v,o.b.e1f1_e1f1,ket.b.e1f2);
  ketp.x11 = v[0]*o.a11*ket.x11;
  ketp.x12 = v[1]*o.a11*ket.x11;
  ketp.x21 = v[2]*o.a11*ket.x11;
  ketp.x22 = v[3]*o.a11*ket.x11;
  // 1,2
  matrice_x_vettore4(v,o.b.e1f2_e1f2,ket.b.e1f2);
  ketp.x11 += v[0]*o.a12*ket.x11;
  ketp.x12 += v[1]*o.a12*ket.x11;
  ketp.x21 += v[2]*o.a12*ket.x11;
  ketp.x22 += v[3]*o.a12*ket.x11;
  // 1,3
  matrice_x_vettore4(v,o.b.e1f3_e1f3,ket.b.e1f2);
  ketp.x11 += v[0]*o.a13*ket.x11;
  ketp.x12 += v[1]*o.a13*ket.x11;
  ketp.x21 += v[2]*o.a13*ket.x11;
  ketp.x22 += v[3]*o.a13*ket.x11;
  // 1,4
  matrice_x_vettore4(v,o.b.e1f4_e1f4,ket.b.e1f2);
  ketp.x11 += v[0]*o.a14*ket.x11;
  ketp.x12 += v[1]*o.a14*ket.x11;
  ketp.x21 += v[2]*o.a14*ket.x11;
  ketp.x22 += v[3]*o.a14*ket.x11;
  // 2,1
  matrice_x_vettore4(v,o.b.e2f1_e2f1,ket.b.e1f2);
  ketp.x11 += v[0]*o.a21*ket.x11;
  ketp.x12 += v[1]*o.a21*ket.x11;
  ketp.x21 += v[2]*o.a21*ket.x11;
  ketp.x22 += v[3]*o.a21*ket.x11;
  // 2,2
  matrice_x_vettore4(v,o.b.e2f2_e2f2,ket.b.e1f2);
  ketp.x11 += v[0]*o.a22*ket.x11;
  ketp.x12 += v[1]*o.a22*ket.x11;
  ketp.x21 += v[2]*o.a22*ket.x11;
  ketp.x22 += v[3]*o.a22*ket.x11;
  // 2,3
  matrice_x_vettore4(v,o.b.e2f3_e2f3,ket.b.e1f2);
  ketp.x11 += v[0]*o.a23*ket.x11;
  ketp.x12 += v[1]*o.a23*ket.x11;
  ketp.x21 += v[2]*o.a23*ket.x11;
  ketp.x22 += v[3]*o.a23*ket.x11;
  // 2,4
  matrice_x_vettore4(v,o.b.e2f4_e2f4,ket.b.e1f2);
  ketp.x11 += v[0]*o.a24*ket.x11;
  ketp.x12 += v[1]*o.a24*ket.x11;
  ketp.x21 += v[2]*o.a24*ket.x11;
  ketp.x22 += v[3]*o.a24*ket.x11;
  // 3,1
  matrice_x_vettore4(v,o.b.e3f1_e3f1,ket.b.e1f2);
  ketp.x11 += v[0]*o.a31*ket.x11;
  ketp.x12 += v[1]*o.a31*ket.x11;
  ketp.x21 += v[2]*o.a31*ket.x11;
  ketp.x22 += v[3]*o.a31*ket.x11;
  // 3,2
  matrice_x_vettore4(v,o.b.e3f2_e3f2,ket.b.e1f2);
  ketp.x11 += v[0]*o.a32*ket.x11;
  ketp.x12 += v[1]*o.a32*ket.x11;
  ketp.x21 += v[2]*o.a32*ket.x11;
  ketp.x22 += v[3]*o.a32*ket.x11;
  // 3,3
  matrice_x_vettore4(v,o.b.e3f3_e3f3,ket.b.e1f2);
  ketp.x11 += v[0]*o.a33*ket.x11;
  ketp.x12 += v[1]*o.a33*ket.x11;
  ketp.x21 += v[2]*o.a33*ket.x11;
  ketp.x22 += v[3]*o.a33*ket.x11;
  // 3,4
  matrice_x_vettore4(v,o.b.e3f4_e3f4,ket.b.e1f2);
  ketp.x11 += v[0]*o.a34*ket.x11;
  ketp.x12 += v[1]*o.a34*ket.x11;
  ketp.x21 += v[2]*o.a34*ket.x11;
  ketp.x22 += v[3]*o.a34*ket.x11;
  // 4,1
  matrice_x_vettore4(v,o.b.e4f1_e4f1,ket.b.e1f2);
  ketp.x11 += v[0]*o.a41*ket.x11;
  ketp.x12 += v[1]*o.a41*ket.x11;
  ketp.x21 += v[2]*o.a41*ket.x11;
  ketp.x22 += v[3]*o.a41*ket.x11;
  // 4,2
  matrice_x_vettore4(v,o.b.e4f2_e4f2,ket.b.e1f2);
  ketp.x11 += v[0]*o.a42*ket.x11;
  ketp.x12 += v[1]*o.a42*ket.x11;
  ketp.x21 += v[2]*o.a42*ket.x11;
  ketp.x22 += v[3]*o.a42*ket.x11;
  // 4,3
  matrice_x_vettore4(v,o.b.e4f3_e4f3,ket.b.e1f2);
  ketp.x11 += v[0]*o.a43*ket.x11;
  ketp.x12 += v[1]*o.a43*ket.x11;
  ketp.x21 += v[2]*o.a43*ket.x11;
  ketp.x22 += v[3]*o.a43*ket.x11;
  // 4,4
  matrice_x_vettore4(v,o.b.e4f4_e4f4,ket.b.e1f2);
  ketp.x11 += v[0]*o.a44*ket.x11;
  ketp.x12 += v[1]*o.a44*ket.x11;
  ketp.x21 += v[2]*o.a44*ket.x11;
  ketp.x22 += v[3]*o.a44*ket.x11;
*/    
  return ketp;
}








