void regiscompras(void){
	int b,i,cant;
	char nombre[5];
	enca();
	b=0;
	printf("\n\tRegistro de Producto\n");
	printf("\n\tClave de producto: ");
    gets(nombre);
	fflush(stdin);
	strupr(nombre);
	for(i=0;i<indinventario;i++){
	   if(!strcmp(nombre,almacen[i].producto)){
         b=1;
         consultacompras(i);
		 break;
		}
	}
	if(b==1){
		if(almacen[i].status==1){
	         do{
				printf("\n\tCantidad de producto: ");
				scanf("%d",&cant);
				if(cant<=0){
					error(7);
				}
			 }while(cant<=0);
			 almacen[i].cantidad=almacen[i].cantidad+cant;
		   	 do{
			   printf("\n\tCosto de producto: ");
			   scanf("%f",&almacen[i].costo);
			   if(almacen[i].costo <=0){
			      printf("\n\tEl costo debe ser mayor de 0\n");
			   }
			 }while(almacen[i].costo<=0);
			 do{
				printf("\n\tPrecio de producto: ");
				scanf("%f",&almacen[i].precio);
				if(almacen[i].precio <= almacen[i].costo){
					error(7);
				}
			 }while(almacen[i].precio <= almacen[i].costo);
		}
		else{
			error(11);
		}
	}
	else{
	    strcpy(almacen[indinventario].producto,nombre);
		printf("\n\tDescripcion del producto: ");
		gets(almacen[indinventario].descripcion);
		fflush(stdin);
		do{
			printf("\n\tCantidad de producto: ");
			scanf("%d",&almacen[indinventario].cantidad);
			if(almacen[indinventario].cantidad<0){ //Prueba para poder dar de baja un producto
				error(7);
			}
		}while(almacen[indinventario].cantidad<0); //Prueba para poder dar de baja un producto
		do{
		   printf("\n\tCosto de producto: ");
		   scanf("%f",&almacen[indinventario].costo);
		   if(almacen[indinventario].costo <=0){
		      printf("\n\tEl costo debe ser mayor de 0\n");
		   }
		}while(almacen[indinventario].costo<=0);
		do{
			printf("\n\tPrecio de producto: ");
			scanf("%f",&almacen[indinventario].precio);
			if(almacen[indinventario].precio <= almacen[indinventario].costo){
				error(7);
			}
		}while(almacen[indinventario].precio <= almacen[indinventario].costo);
		fflush(stdin);
		almacen[indinventario].status=1;
		indinventario=indinventario+1;
	}
	fflush(stdin);
	return;
}

void modicompras(void){
	int b,i;
	char nombre[5];
	float costop;
	enca();
	printf("\n\tModificacion de compra \n");
	printf("\n\tClave del producto: ");
	scanf("%s",nombre);
	fflush(stdin);
	strupr(nombre);
	b=0;
	for(i=0;i<indinventario;i++){
		if(!strcmp(nombre,almacen[i].producto)){
	      b=1;
          consultacompras(i);
		  break;
		}
	}
    if(b==0){
	  error(8);
	}
	else{
	   if(almacen[i].status==0){
	      error(14);
		}
		else{
			do{
			   printf("\n\tPrecio de producto: ");
			   scanf("%f",&almacen[i].precio);
			   if(almacen[i].precio <= almacen[i].costo){
				   error(7);
				}
			}while(almacen[i].precio <= almacen[i].costo);
			error(13);
			fflush(stdin);
		}
	}
    return;
}

void bajacompras(void){
	int b,i;
	char nombre[5];
	enca();
	printf("\n\t Baja de producto\n");
    printf("\n\tDigite su clave de producto: ");
	scanf("%s",nombre);
    strupr(nombre);
	fflush(stdin);
	b=0;
	for(i=0;i<indinventario;i++){
		if(!strcmp(nombre,almacen[i].producto)){
           b=1;
           consultacompras(i);
			break;
		}
    }
	if(b==0){
    	error(8);
	}
	else{
        if(almacen[i].status==0){
				error(10);
		}
		else{
			if(almacen[i].cantidad>0){
				error(12);
			}
			else{
				almacen[i].status=0;
                error(9);

			}
		}
	}
			
	return;
}
