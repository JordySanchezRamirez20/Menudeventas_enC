void error(int e){
	printf("\n");
	switch(e){
		case 1:
			printf("\n\t\a--Opcion invalida--\n");
			break;
		case 2:
			printf("\n\t\a--El cliente ya existe--\n");
			break;
		case 3:
			printf("\n\t\a--El cliente no se puede dar de baja, porque fue dado de baja anteriormente--\n");
			break;
		case 4:
			printf("\n\t\a--El cliente se dio de baja satisfactoriamente--\n");
			break;
		case 5:
			printf("\n\t\a--El cliente no existe--\n");
			break;
		case 6:
			printf("\n\t\a--El producto ya existe--\n");
			break;
		case 7:
            printf("\n\t\a--El precio debe ser mayor que el costo--\n");
            break;
        case 8:
			printf("\n\t\a--El producto no existe--\n");
			break;
		case 9:
			printf("\n\t\a--El producto se dio de baja satisfactoriamente--\n");
			break;
		case 10:
			printf("\n\t\a--El producto no se puede dar de baja, porque fue dado de baja anteriormente--\n");
			break;
		case 11:
			printf("\n\t\a--No se puede comprar el producto porque ya fue dado de baja anteriormente--\n");
			break;
		case 12:
			printf("\n\t\a--El producto no puede darse de baja porque tiene productos en el inventario--\n");
			break;
		case 13:
			printf("\n\t\a--Se modifico el precio satisfactoriamente--\n");
			break;
		case 14:
			printf("\n\t\a--El producto no se puede modificar porque se dio de baja anteriormente--\n");
			break;
		case 15:
			printf("\n\t\a--No se puede facturar porque el cliente esta dado de baja--\n");
			break;
		case 16:
			printf("\n\t\a--No se puede facturar porque el producto esta dado de baja--\n");
			break;
	}
	printf("\n");
	getch();
}
