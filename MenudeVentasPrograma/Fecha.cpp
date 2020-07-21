void amd(void){
   int anio;
   bool b;
   int mes;
   int dia;
   do{
      printf("\n\tIntroduce el a%co : ",164);
      scanf("%d",&fact[indfact].FECHAS.anio);
      if(fact[indfact].FECHAS.anio<=1900 || fact[indfact].FECHAS.anio >=2050){
         printf("\n\tA%co incorrecto",164);
      }
   }while(fact[indfact].FECHAS.anio<=1900 || fact[indfact].FECHAS.anio>=2050);
      if(anio%4==0 && anio%100!=0 || anio%400==0){
         b=1;
      }
      else{
         b=0;
      }
      do{
         printf("\n\n\tintroduce el mes: ");
         scanf("%d",&fact[indfact].FECHAS.mes);
         if(fact[indfact].FECHAS.mes<=0 || fact[indfact].FECHAS.mes>=13){
            printf("\n\tError de mes");
         }
      }while(fact[indfact].FECHAS.mes<=0 || fact[indfact].FECHAS.mes>=13);
      switch(fact[indfact].FECHAS.mes){
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12:
         do{
            printf("\n\n\tIngrese el dia: ");
            scanf("%d",&fact[indfact].FECHAS.dia);
            if(fact[indfact].FECHAS.dia<=0 || fact[indfact].FECHAS.dia>=32){
               printf("\n\tError de dia");
            }
         }while(fact[indfact].FECHAS.dia<=0 || fact[indfact].FECHAS.dia>=32);
         break;
         case 4:
         case 6:
         case 9:
         case 11:
         do{
            printf("\n\tIngrese el dia: ");
            scanf("%d",&fact[indfact].FECHAS.dia);
            if(fact[indfact].FECHAS.dia<=0 || fact[indfact].FECHAS.dia>=31){
               printf("\n\tError del dia");
            }
        }while(fact[indfact].FECHAS.dia<=0 || fact[indfact].FECHAS.dia>=31);
        break;
        case 2:
               if(b==0){
                 do{
                    printf("\n\n\tIngrese el dia: ");
                    scanf("%d",&fact[indfact].FECHAS.dia);
                    if(dia<=0 || dia>=29){
                      printf("\n\tError de dia");
                    }
                 }while(fact[indfact].FECHAS.dia<=0 || fact[indfact].FECHAS.dia>=29);
               }else{
                  do{
                     printf("\n\n\tIngrese el dia: ");
                     scanf("%d",&fact[indfact].FECHAS.dia);
                     if(fact[indfact].FECHAS.dia<=0 || fact[indfact].FECHAS.dia>=30){
                        printf("\n\tError de dia");
                     }
                  }while(fact[indfact].FECHAS.dia<=0 || fact[indfact].FECHAS.dia>=30);
               }
        }
        return;
}
