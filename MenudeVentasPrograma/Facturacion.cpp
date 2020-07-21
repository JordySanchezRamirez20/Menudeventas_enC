void facturacion(void){
	int b,i,x,cant,z,tcant,m,indice=1,pos;
	float importe,iva,subtotal=0,total;
	char clave[5],clavep[5],opcion;
	enca();
	printf("\n\tFacturacion\n");
	if(indcliente==0 || indinventario==0){
			printf("\n\tNo se encontro clientes o productos, registrelos primero.");
			return;
	}
		printf("\n\tDigite su clave de cliente: ");
		fflush(stdin);
		gets(clave);
		strupr(clave);
		b=0;
		for(i=0;i<indcliente;i++){
			if(!strcmp(clave,cliente[i].clave)){
		      b=1;
			  pos=i;
	          consultacliente(i);
	          break;
			}
		}
		if(b==0){
			error(5);
			return;
		}
		if(cliente[i].status==0){
			error(15);
			return;
		}
	   amd();
	   system("cls");
	   encab();
	   printf("\n\t-----------------------------------------------------------------\n");
       printf("\n\tNumero de factura: %d",indfact);
	   printf("\n\tFactura para: %s\t\tFecha: %.2d/%.2d/%d",cliente[i].nombre,fact[indfact].FECHAS.dia,fact[indfact].FECHAS.mes,fact[indfact].FECHAS.anio,cliente[i].clave);
	   printf("\n\tClave de cliente: %s            \tCiudad: %s\n",cliente[i].clave,cliente[i].ciudad);
	   printf("\tDomicilio: %s                \tCodigo Postal: %d",cliente[i].domicilio,cliente[i].cp);
	   printf("\n\tRFC: %s",cliente[i].RFC);
	   getch();
	   for(m=0;m<indinventario;m++){
          do{
			printf("\n\tClave de producto: ");
			fflush(stdin);
			scanf("%s",clavep);
			strupr(clavep);
			z=0;
			for(x=1;x<indinventario;x++){
				if(!strcmp(clavep,almacen[x].producto)){
					z=1;
					consultacompras(x);
					break;
				}
			}
			if(z==0){
                error(8);
				continue;
			}
			if(almacen[x].status==0){
				error(16);
				x--;
				continue;
			}
			if(almacen[x].cantidad==0){
                printf("\n\tNo se cuenta con existencia en el inventario, intente con otro\n");
                x--;
				getch();
				continue;
			}
			do{
				printf("\n\tCantidad: ");
				scanf("%d",&cant);
				if(cant<=0 || cant>almacen[x].cantidad){
					printf("\n\tDebe ser mayor de 0 y menor o igual a lo que se tiene en almacen\n");
				}
			}while(cant<=0 || cant>almacen[x].cantidad);
			almacen[x].cantidad-=cant;
			fact[indfact].detallesf[indice].cantidad=cant;
			fact[indfact].detallesf[indice].precio=almacen[x].precio;
			fact[indfact].detallesf[indice].importe=cant*almacen[x].precio;
			strcpy(fact[indfact].detallesf[indice].producto,almacen[x].producto);
			strcpy(fact[indfact].detallesf[indice].descripcion,almacen[x].descripcion);
	    	fact[indfact].subtotal+=fact[indfact].detallesf[indice].importe;
	    	indice++;
		  }while(z==0);
		  	fflush(stdin);
		  	do{
				printf("\n\n\n\tDesea capturar otro producto(S/N): ");
				fflush(stdin);
				scanf("%c",&opcion);
				if(opcion!='N' && opcion != 'n' && opcion!= 's' && opcion!= 'S'){
					error(1);
				}
			}while(opcion!='N' && opcion != 'n' && opcion!= 's' && opcion!= 'S');
			if(opcion=='N' || opcion=='n'){
				break;
			}
        }
		if (indice==1){
			return;
		}
        fact[indfact].iva=fact[indfact].subtotal*IVA;
		fact[indfact].total=fact[indfact].subtotal+fact[indfact].iva;
		fact[indfact].status=1;
		fact[indfact].nfactura=indfact;
		strcpy(fact[indfact].clave,cliente[pos].clave);
		fact[indfact].detalle=indice-1;
		fflush(stdin);
		system("cls");
		encab();
	   printf("\n\t-----------------------------------------------------------------\n");
       printf("\n\tNumero de factura: %d",indfact);
	   printf("\n\tFactura para: %s\t\tFecha: %.2d/%.2d/%d",cliente[i].nombre,fact[indfact].FECHAS.dia,fact[indfact].FECHAS.mes,fact[indfact].FECHAS.anio,cliente[i].clave);
	   printf("\n\tClave de cliente: %s            \tCiudad: %s\n",cliente[i].clave,cliente[i].ciudad);
	   printf("\tDomicilio: %s                \tCodigo Postal: %d",cliente[i].domicilio,cliente[i].cp);
	   printf("\n\tRFC: %s",cliente[i].RFC);
		for(m=1;m<indice;m++){
            printf("\n\t-----------------------------------------------------------------\n");
            printf("\n\tNumero de factura: %d\t\t\tDetalle:%d",fact[indfact].nfactura,m);
			printf("\n\tDescripcion: %s  \t\tCantidad: %d",fact[indfact].detallesf[m].descripcion,fact[indfact].detallesf[m].cantidad);
			printf("\n\tClave de producto: %s \t\t\tPrecio:%.2f",fact[indfact].detallesf[m].producto,fact[indfact].detallesf[m].precio);
			printf("\n\t\t\t\t\t\tImporte: %.2f\n\n",fact[indfact].detallesf[m].importe);
		}
			printf("\n\n\t\t\t\t\t\tIVA: %.2f\n\t\t\t\t\t\tSubtotal: %.2f\n\t\t\t\t\t\tTotal: %.2f",fact[indfact].iva,fact[indfact].subtotal,fact[indfact].total);
			indfact++;
			getch();
}

void cancelfact(void){
		int numero,i,b,z,x;
		printf("\n\tCancelacion de factura\n");
		enca();
		b=0;
	do{
		printf("\n\tNumero de factura: ");
		scanf("%d",&numero);
		if(numero<=0){
			printf("\n\t\a--El numero de factura debe ser mayor de 0--\n");
			getch();
		}
	}while(numero<=0);
	for(i=1;i<indfact;i++){
		if(numero,fact[i].nfactura){
			b=1;
			consultasfact(i);
			break;
		}
	}
	if(fact[numero].status==0){
        printf("\n\t\a--No existe la factura--\n");
		getch();
		return;
	}
	fflush(stdin);
	if(b==0){
		printf("\n\t\a--No se puede cancelar la factura porque se dio de cancelo anteriormente--\n");
		getch();
		return;
	}
	else{
		printf("\n\t\a--La factura se dio de baja satisfactoriamente--\n");
		getch();
 }
    almacen[i].cantidad=almacen[i].cantidad+fact[i].detallesf[numero].cantidad;
    fact[numero].status=0;
	fflush(stdin);
}

