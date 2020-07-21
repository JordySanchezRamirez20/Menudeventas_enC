void menualta(void){
    int i;
    int b;
	char clave[5];
	enca();
	printf("\n\tRegistro de clientes\n");
    printf("\n\tDigite su clave de cliente: ");
	scanf("%s",clave);
    strupr(clave);
	fflush(stdin);
    b=0;
	for(i=0;i<indcliente;i++){
	   if(!strcmp(clave,cliente[i].clave)){
         b=1;
         consultacliente(i);
	     break;
	   }
	}
	if(b==0){
   	    strcpy(cliente[indcliente].clave,clave);
   	    printf("\n\tEscriba su nombre: ");
	    gets(cliente[indcliente].nombre);
	    fflush(stdin);
	    printf("\n\tEscriba su domicilio: ");
		gets(cliente[indcliente].domicilio);
		fflush(stdin);
		printf("\n\tEscriba su ciudad: ");
		gets(cliente[indcliente].ciudad);
		fflush(stdin);
		do{
	        printf("\n\tEscriba su codigo postal: ");
		    scanf("%d",&cliente[indcliente].cp);
		    if(cliente[indcliente].cp<10000 || cliente[indcliente].cp>99999){
				printf("\n\tCodigo postal invalido\n");
			}
	   	}while(cliente[indcliente].cp<10000 || cliente[indcliente].cp>99999);
		printf("\n\tEscriba su RFC: ");
		scanf("%s",cliente[indcliente].RFC);
		fflush(stdin);
		cliente[indcliente].status=1;
		indcliente=indcliente+1;
	}
	else{
		error(2);
	}
}

void menubaja(void){
	char clave[5];
	int i;
	int b;
	enca();
	printf("\n\t Baja de cliente\n");
    printf("\n\tDigite su clave de cliente: ");
	scanf("%s",clave);
    strupr(clave);
	fflush(stdin);
	b=0;
	for(i=0;i<indcliente;i++){
		if(!strcmp(clave,cliente[i].clave)){
           b=1;
           consultacliente(i);
	       if(cliente[i].status==0){
				error(3);
			}
			else{
				cliente[i].status=0;
				error(4);
			}
			break;
		}
    }
	if(b==0){
    	error(5);
	}
	return;
}
void modicliente(void){
    int i;
	enca();
	int b;
	char clave[5];
	enca();
	printf("\n\tModificacion de clientes\n\n");
    printf("\n\tDigite su clave de cliente: ");
	scanf("%s",clave);
    strupr(clave);
	fflush(stdin);
    b=0;
	for(i=0;i<indcliente;i++){
		if(!strcmp(clave,cliente[i].clave)){
	      b=1;
          consultacliente(i);
          break;
		}
	}
    if(cliente[i].status==0){
		error(5);
	}
	else{
        printf("\n\n\tEscriba su domicilio: ");
	    gets(cliente[i].domicilio);
	    fflush(stdin);
		printf("\n\tEscriba su ciudad: ");
		gets(cliente[i].ciudad);
		fflush(stdin);
		do{
	        printf("\n\tEscriba su codigo postal: ");
		    scanf("%d",&cliente[i].cp);
		    if(cliente[i].cp<10000 || cliente[i].cp>99999){
				printf("\n\tCodigo postal invalido\n");
			}
	    }while(cliente[i].cp<10000 || cliente[i].cp>99999);
	    fflush(stdin);
    }
	return;
}
