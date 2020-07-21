void consultacliente(int n1){
	printf("\n\tClave: %s",cliente[n1].clave);
	printf("\n\tNombre: %s",cliente[n1].nombre);
	printf("\n\tDomicilio: %s",cliente[n1].domicilio);
	printf("\n\tCiudad: %s",cliente[n1].ciudad);
	printf("\n\tCodigo postal: %d",cliente[n1].cp);
	printf("\n\tRFC: %s",cliente[n1].RFC);
	if(cliente[n1].status==0){
		printf("\n\tCliente inactivo\n");
	}
	else{
		printf("\n\tCliente activo\n");
	}
    return;
}

void clientes(void){
	int i;
	enca();
	printf("\n\tTodos los clientes\n");
	for(i=0;i<indcliente;i++){
       consultacliente(i);
	   printf("\n");
	}
	getch();
	return;
}

void clientesact(void){
    int i;
	enca();
	printf("\n\tTodos los clientes activos\n");
	for(i=0;i<indcliente;i++){
		if(cliente[i].status==1){
           consultacliente(i);
	       printf("\n");
		}
	}
	getch();
	return;
}

void clientesinact(void){
    int i;
	enca();
	printf("\n\tTodos los clientes inactivos\n");
	for(i=0;i<indcliente;i++){
		if(cliente[i].status==0){
           consultacliente(i);
	       printf("\n");
		}
	}
	getch();
	return;
}

void buscliente(void){
	int i,b;
	char clave[5];
	enca();
    printf("\n\tConsulta por cliente\n");
    printf("\n\tDigite su clave de cliente: ");
	scanf("%s",clave);
    strupr(clave);
	fflush(stdin);
    b=0;
	for(i=0;i<indcliente;i++){
	   if(!strcmp(clave,cliente[i].clave)){
          b=1;
          consultacliente(i);
		  getch();
		  break;
	    }
	}
	if(b==0){
		error(5);
	}
	return;
}

void consultacompras(int x1){
	printf("\n\tNombre de producto: %s",almacen[x1].producto);
	printf("\n\tDescripcion de producto: %s",almacen[x1].descripcion);
	printf("\n\tCantidad de producto: %d",almacen[x1].cantidad);
	printf("\n\tCosto de producto: %c%.2f",36,almacen[x1].costo);
	printf("\n\tPrecio de producto: %c%.2f",36,almacen[x1].precio);
	if(almacen[x1].status==0){
		printf("\n\tProducto inactivo\n");
	}
	else{
		printf("\n\tProducto activo\n");
	}
    return;
}

//Esto es lo de consulta de inventario

void todascompras(void){
	int i;
	enca();
	printf("\n\tTodos los productos\n");
	for(i=0;i<indinventario;i++){
       consultacompras(i);
	   printf("\n");
	}
	getch();
	return;
}

void comprasact(void){
    int i;
	enca();
	printf("\n\tTodos los productos activos\n");
	for(i=0;i<indinventario;i++){
		if(almacen[i].status==1){
           consultacompras(i);
	       printf("\n");
		}
	}
	getch();
	return;
}

void comprasinact(void){
    int i;
	enca();
	printf("\n\tTodos los productos inactivos\n");
	for(i=0;i<indinventario;i++){
		if(almacen[i].status==0){
           consultacompras(i);
	       printf("\n");
		}
	}
	getch();
	return;
}

void buscompras(void){
	int i,b;
	char nombre[5];
	enca();
    printf("\n\tConsulta por producto\n");
    printf("\n\tDigite su clave de producto: ");
	scanf("%s",nombre);
    strupr(nombre);
	fflush(stdin);
    b=0;
	for(i=0;i<indinventario;i++){
	   if(!strcmp(nombre,almacen[i].producto)){
          b=1;
          consultacompras(i);
		  getch();
		  break;
	    }
	}
	if(b==0){
		error(8);
	}
	return;
}


//Consultas factura

void consultasfact(int f){
	int n1,d,b,x;
//	encab();
		for(x=0;x<=indcliente;x++){
		   if(!strcmp(fact[f].clave,cliente[x].clave)){
			  b=x;
			  break;
			}
 		}
	   printf("\n\t-----------------------------------------------------------------\n");
       printf("\n\tNumero de factura: %d",fact[f].nfactura);
	   printf("\n\tFactura para: %s\t\tFecha: %.2d/%.2d/%d",cliente[b].nombre,fact[f].FECHAS.dia,fact[f].FECHAS.mes,fact[f].FECHAS.anio);
	   printf("\n\tClave de cliente: %s            \tCiudad: %s\n",cliente[b].clave,cliente[b].ciudad);
	   printf("\tDomicilio: %s                \tCodigo Postal: %d",cliente[b].domicilio,cliente[b].cp);
	   printf("\n\tRFC: %s",cliente[b].RFC);
	   for(d=1;d<=fact[f].detalle;d++){
            printf("\n\t-----------------------------------------------------------------\n");
            printf("\n\tNumero de factura: %d\t\t\tDetalle:%d",fact[f].nfactura,d);
			printf("\n\tDescripcion: %s \t\tCantidad: %d",fact[f].detallesf[d].descripcion,fact[f].detallesf[d].cantidad);
			printf("\n\tClave de producto: %s \t\t\tPrecio:%.2f",fact[f].detallesf[d].producto,fact[f].detallesf[d].precio);
			printf("\n\t\t\t\t\t\tImporte: %.2f\n\n",fact[f].detallesf[d].importe);
		}
  printf("\n\n\t\t\t\t\t\tIVA: %.2f\n\t\t\t\t\t\tSubtotal: %.2f\n\t\t\t\t\t\tTotal: %.2f",fact[f].iva,fact[f].subtotal,fact[f].total);
	if(fact[f].status==0){
	   printf("\n\tFactura inactiva\n");
	}
	else{
		printf("\n\tFactura activa\n");
	}
    return;
}

void todasfactura(void){
	int i;
	enca();
	printf("\n\tTodas las facturas\n");
	for(i=1;i<indfact;i++){
       consultasfact(i);
	   printf("\n");
	}
	getch();
	return;
}

void facturasact(void){
    int i;
	enca();
	printf("\n\tTodas las facturas activas\n");
	for(i=1;i<indfact;i++){
		if(fact[i].status==1){
           consultasfact(i);
	       printf("\n");
		}
	}
	getch();
	return;
}

void facturasinact(void){
    int i;
	enca();
	printf("\n\tTodas las facturas inactivas\n");
	for(i=1;i<indfact;i++){
		if(fact[i].status==0){
           consultasfact(i);
	       printf("\n");
		}
	}
	getch();
	return;
}

void busfactura(void){
	int i,b;
	int numero;
	enca();
    printf("\n\tConsulta por factura\n");
    printf("\n\tNumero de factura: ");
    fflush(stdin);
	scanf("%d",&numero);
    b=0;
	for(i=1;i<indfact;i++){
	   if(numero==fact[i].nfactura){
          b=1;
          consultasfact(i);
		  getch();
		  break;
	    }
	}
	if(b==0){
		printf("\n\t\aFactura no existente\n");
		getch();
	}
	fflush(stdin);
	return;
}


