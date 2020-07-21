#ifndef _GLOBAL_H_
  #define _GLOBAL_H_
  
  #include<stdio.h>
  #include<conio.h>
  #include<math.h>
  #include<windows.h>
  #include<string.h>
  #include<ctype.h>
  #include<stdlib.h>
  #define RANGO 100
  #define IVA 0.16
  struct datosp{
    char clave[5];
    char nombre[50];
    char domicilio[50];
    char ciudad[30];
    int cp;
    char RFC[15];
    bool status;
  }cliente[RANGO]={
		{"A10","Jordy Sanchez","San Jeronimo","Leon",37204,"SARJ2019",1},
		{"A20","Daniela Padilla","Las Huertas","Leon",37502,"PAD3KD0",1},
		{"A30","Lee Xiaolong","Kioto","Japon",20922,"Xi93K0",1},
		{"A40","Connor Mcgregor","Edimburgo","Escocia",50392,"MCC39203",0},
		{"A50","Jose Luis","Nezahualcoyotl","CDMX",35246,"JLS398D",0},
		{"A60","Carmen","Luna","Leon",37210,"CMSA39D",1}
	    };
  int indcliente=6;
  
  struct inventario{
     char producto[5];
     char descripcion[40];
     int cantidad;
     float costo;
     float precio; 
     bool status;
  }almacen[RANGO]={
				  {"B70","Mancuernas de 2 kg",2,50.8,60.8,1},
				  {"B10","Guantes de 15 Oz",5,750.5,800.0,1},
				  {"B30","Toalla de ejercicio",1,30.0,40.0,1},
				  {"B40","Faja para peso",0,300.0,350.0,0},
				  {"B50","Botines para boxeo",10,900.0,1050.0,1},
				  {"B60","Vendas color negro",0,100.0,110.0,0}
				  };
  int indinventario=7;
  struct datosfecha{
		int dia;
		int mes;
		int anio;
  }FECHAS;
  
  struct detalles{
    int nfactura;
    char producto[5];
    char descripcion[40];
    int cantidad;
    float precio;
    float importe;
 };
 int inddetalle=1;
 
  struct factura{
     int nfactura;
     char clave[5];
     bool status;
	 struct datosfecha FECHAS;
     float subtotal;
     float iva;
     float total;
     struct detalles detallesf[RANGO];
     int detalle;
 }fact[RANGO];
 int indfact=1;

#endif
