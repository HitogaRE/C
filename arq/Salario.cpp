//Thaigo Pereira dos Santos
#include <stdlib.h>
#include <stdio.h>

int main(){
         
    FILE * sal;
    FILE * calc;
    bool Trocou;

    sal = fopen ("salario.txt", "r");
    calc = fopen ("calculos.txt", "w");
    
    if (sal == NULL){
           printf("Arquivo Salario inexistente. Impossivel de Prosseguir\n\n");
        return 0;
     }
     
     
     int tam=0;
     
     double *salarioB;
     salarioB = NULL;
     double salarioB_aux;
     
     while(fscanf(sal,"%lf\n", &salarioB_aux) != EOF) {
         tam++;
         
        salarioB=(double *)realloc(salarioB, sizeof(double) * tam);
        salarioB[tam-1]= salarioB_aux;    
     
    }
    
    
    int i=0,x=0;
    
    
    Trocou = true;
      while (Trocou) { 
    Trocou = false;
    for (i = 0; i < tam-1; i++) {
      if (salarioB[i] > salarioB[i+1]) {
        x = salarioB[i]; 
        salarioB[i] = salarioB[i+1];
        salarioB[i+1] = x;
        Trocou = true;
        }
      } 
    }  
    
    i=0;
    double AliqINSS[tam];
    double ValINSS[tam];
    double Base_IR[tam];
    double Aliq_IR[tam];
    double VAL_IR[tam];
    double Deducao[tam];
    double Liquido[tam];

    fprintf(calc, "  Bruto       AliqINSS        Val.INSS       Base I.R.       AliqIR        Val.IR          Liquido\n");
    
    while(i < tam){
        
         if(salarioB[i] < 1751.81){
            AliqINSS[i] = 8.0;
            ValINSS[i] = salarioB[i] * 0.08;
            
         }  else if(salarioB[i] >= 1751.82 && salarioB[i] < 2919.72){
            AliqINSS[i] = 9.0;
            ValINSS[i] = salarioB[i] * 0.09;
            
         }  else if(salarioB[i] >= 2919.72 && salarioB[i] < 5839.45){
              AliqINSS[i] = 11.00;
              ValINSS[i] = salarioB[i] * 0.11;
            
         }  else if(salarioB[i] > 5839.45){
              AliqINSS[i] = 0.0;
              ValINSS[i] = 642.34;
            
         }
        
        
        Base_IR[i] = salarioB[i] - ValINSS[i];
        

        if(Base_IR[i] < 1903.98){
            Aliq_IR[i]=0.00;
            Deducao[i]=0.00;
            VAL_IR[i]=0.00;
            
        } else if(Base_IR[i] >= 1903.99 && Base_IR[i] < 2826.65){
            Aliq_IR[i]=7.5;
            Deducao[i]=0.00;
            VAL_IR[i]=(Base_IR[i]*Aliq_IR[i]/100)-Deducao[i];
            
            
        } else if(Base_IR[i] >= 2826.65 && Base_IR[i] < 3751.05){
            Aliq_IR[i]=15.00;
            Deducao[i]=354.80;
            VAL_IR[i]=(Base_IR[i]*Aliq_IR[i]/100)-Deducao[i];
        
            
        } else if(Base_IR[i] >= 3741.05 && Base_IR[i] < 4664.68  ){
            Aliq_IR[i]=22.5;
            Deducao[i]=636.13;
            VAL_IR[i]=(Base_IR[i]*Aliq_IR[i]/100)-Deducao[i];
            
            
        }else if(Base_IR[i] >= 4664.68 ){
        Aliq_IR[i]=27.5;
        Deducao[i]=869.36;
        VAL_IR[i]=(Base_IR[i]*Aliq_IR[i]/100)-Deducao[i];
        }
            
        
        Liquido[i] = salarioB[i] - ValINSS[i] - VAL_IR[i];
     
   
        fprintf(calc, "%8.2f         %4.1f         %6.2f         %8.2lf        %4.1lf          %7.2lf        %8.2lf\n", salarioB[i], AliqINSS[i], ValINSS[i], Base_IR[i],Aliq_IR[i],VAL_IR[i],Liquido[i]);
        i++;
    }
    

    fclose(sal);
    fclose(calc);
    
    printf("Operacao realizada com sucesso!");
    
    return 0;
}
