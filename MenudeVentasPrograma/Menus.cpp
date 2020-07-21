
void menup(void){
     char opcion;
     do{
	   enca();
       printf("\n\t----Menu principal----\n");
       printf("\n\t 1. Compras\n");
       printf("\n\t 2. Clientes\n");
       printf("\n\t 3. Facturas\n");
       printf("\n\t 4. Consultas\n");
       printf("\n\t 0.Salir\n");
       printf("\n\n\tSeleccione la opcion: ");
       scanf("%c",&opcion);
	   fflush(stdin);
       if(opcion=='0'){
			break;
	   }
       switch (opcion){
          case '1':
               menucompras();
               break;
          case '2':
			   menucte();
               break;
          case '3':
			   menufact();
               break;
          case '4':
               consultag();
               break;
          case '0':
			   break;
		default:
			error(1);
       }
     }while(opcion!='0');
     return;
}
void menucompras(void){
	char opcion;
	do{
		enca();
		printf("\n\t----Menu Compras----\n");
		printf("\n\t1. Registrar producto\n");
		printf("\n\t2. Modificacion producto\n");
		printf("\n\t3. Baja producto\n");
		printf("\n\t0. Regresar\n");
		printf("\n\n\n\tSeleccione una opcion: ");
		scanf("%c",&opcion);
		fflush(stdin);
		if(opcion=='0'){
			break;
		}
		switch(opcion){
			case '1':
				regiscompras();
				break;
			case '2':
				modicompras();
				break;
			case '3' :
				bajacompras();
				break;
			case'0':
				break;
			default:
				error(1);
		}
	}while(opcion!='0');
	return;
}

void menucte(void){
 char opcion;
 do{
   enca();
   printf("\t----Menu clientes----\n");
   printf("\n\t1. Alta\n");
   printf("\n\t2. Modificacion\n");
   printf("\n\t3. Baja\n");
   printf("\n\t0. Regresar\n");
   printf("\n\n\n\tSeleccione la opcion: ");
   scanf("%c",&opcion);
   fflush(stdin);
   if(opcion=='0'){
			break;
	}
   switch(opcion){
       case '1':
			menualta();
			break;
       case '2':
			modicliente();
			break;
       case '3':
			menubaja();
			break;
	   case'0':
			break;
 	   default:
		   error(1);
   }
 }while(opcion!='0');
 return;
}

void menufact(void){
	char opcion;
	do{
		enca();
		printf("\n\t----Facturacion----\n");
		printf("\n\t1. Factura\n");
		printf("\n\t2. Cancelar factura\n");
		printf("\n\t0. Regresar\n");
		printf("\n\n\n\tSeleccione una opcion: ");
		scanf("%c",&opcion);
		fflush(stdin);
		if(opcion=='0'){
			break;
		}
		switch(opcion){
			case '1':
				facturacion();
				break;
			case '2':
				cancelfact();
				break;
			case '0':
				break;
			default:
				error(1);
		}
	}while(opcion!=0);
}

void menuconsulta(void){
	char opcion;
	do{
		enca();
		printf("\t----Consulta de clientes----\n");
		printf("\n\t1. Todos los clientes\n");
		printf("\n\t2. Clientes activos\n");
		printf("\n\t3. Clientes inactivos\n");
		printf("\n\t4. Consulta por cliente\n");
		printf("\n\t0. Regresar\n");
		printf("\n\n\n\tSeleccione una opcion: ");
		scanf("%c",&opcion);
		fflush(stdin);
		if(opcion=='0'){
			break;
		}
		switch(opcion){
			case '1':
				clientes();
				break;
			case '2':
				clientesact();
				break;
			case '3':
				clientesinact();
				break;
			case '4':
				buscliente();
				break;
			case '0':
				break;
			default:
				error(1);
		}
	}while(opcion!='0');
	return;
}

void consultag(void){
	char opcion;
	do{
		enca();
		printf("\t----Menu de consulta----\n");
		printf("\n\t1. Consulta de Clientes\n");
		printf("\n\t2. Consulta de Inventario\n");
		printf("\n\t3. Consulta de Facturas\n");
		printf("\n\t0. Regresar");
		printf("\n\n\n\tSeleccione una opcion: ");
		scanf("%c",&opcion);
		fflush(stdin);
		if(opcion=='0'){
			break;
		}
		switch(opcion){
			case '1':
                menuconsulta();
                break;
            case '2':
				Mcompras();
				break;
			case '3':
				consultafact();
				break;
			case '0':
				break;
			default:
				error(1);
			}
	}while(opcion!='0');
	return;
}
void Mcompras(void){
	char opcion;
	do{
		enca();
		printf("\n\t----Menu de compras----\n");
		printf("\n\t1. Todos los productos\n");
		printf("\n\t2. Productos activos\n");
		printf("\n\t3. Productos inactivos\n");
		printf("\n\t4. Busqueda por compra\n");
		printf("\n\t0. Regresar");
		printf("\n\n\n\tSeleccione una opcion: ");
		scanf("%c",&opcion);
		fflush(stdin);
		if(opcion=='0'){
			break;
		}
		switch(opcion){
			case '1':
				todascompras();
				break;
			case '2':
				comprasact();
				break;
			case '3':
				comprasinact();
				break;
			case '4':
				buscompras();
				break;
			default:
				error(1);
			}
		}while(opcion!='0');
}

void consultafact(void){
	char opcion;
	do{
		enca();
		printf("\n\t----Consulta de factura----\n");
		printf("\n\t1. Todas las facturas\n");
		printf("\n\t2. Facturas activas\n");
		printf("\n\t3. Facturas inactivas\n");
		printf("\n\t4. Busqueda por factura\n");
		printf("\n\t0. Regresar\n");
		printf("\n\n\n\tSeleccione una opcion: ");
		scanf("%c",&opcion);
		fflush(stdin);
		if(opcion=='0'){
			break;
		}
		switch(opcion){
			case '1':
				todasfactura();
				break;
			case '2':
				facturasact();
				break;
			case '3':
				facturasinact();
				break;
			case '4':
				busfactura();
				break;
			case '0':
				break;
			default:
				error(1);
		}
	}while(opcion!=0);
}
