#include "Menu.h"
#include<sstream>
Menu::Menu(): negocio(nullptr){}
Menu::Menu(RentACar* aux) :negocio(aux) {}
Menu::~Menu() { delete negocio; }
void Menu::ejecutar() {
	int opcion1 = -1;
	while (opcion1 != 7) {
		cout << "----Menu Rent A Car----" << endl;
		cout << "1-Datos Generales" << endl;
		cout << "2-Planteles, Parqueos y Vehiculos" << endl;
		cout << "3-Solicitudes y Contratos" << endl;
		cout << "4-Reportes de Cliente" << endl;
		cout << "5-Reportes de Planteles y Vehiculos" << endl;
		cout << "6-Reportes de Alquileres" << endl;
		cout << "7-Salir del Sistema" << endl;
		cout << "Digite el numero de la opcion seleccionada:" << endl;
		cin >> opcion1;
		system("pause");
		system("cls");
		int opcion2 = 0;
		switch (opcion1) {
		case 1:{
			while (opcion2 != 4) {
				cout << "----Datos Generales----" << endl;
				cout << "1-Sucursales" << endl;
				cout << "2-Clientes por Sucursal" << endl;
				cout << "3-Colaboradores por Sucursal" << endl;
				cout << "4-Volver" << endl;
				cout << "Digite el numero de la opcion seleccionada:" << endl;
				cin >> opcion2;
				system("pause");
				system("cls");
				int opcion3;
				switch (opcion2) {
				case 1: {
					while (opcion3 != 4) {
						cout << "----Sucursales----" << endl;
						cout << "1-Ingreso de Sucursal" << endl;
						cout << "2-Eliminar Sucursal" << endl;
						cout << "3-Visualizacion de Sucursal" << endl;
						cout << "4-Volver" << endl;
						cout << "Digite el numero de la opcion seleccionada:" << endl;
						cin >> opcion3;
						system("pause");
						system("cls");
						switch (opcion3) {
						case 1: {
							string num;
							string ubi;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							if (negocio->getSucurales()->buscarSucursal(num) == true) {
								cout << "ERROR-Sucursal existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							cout << "Digite la ubicacion de la Sucursal: " << endl;
							getline(cin, ubi);
							Sucursal* nueva = new Sucursal(ubi, num);
							negocio->insertarSucursal(nueva);
							cin.ignore();
							system("pause");
							system("cls");
							break;
						}
						case 2: {
							string num;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							if (negocio->getSucurales()->buscarSucursal(num) == false) {
								cout << "ERROR-Sucursal no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							negocio->eliminarSucursal(num);
							system("pause");
							system("cls");
							break;
						}
						case 3: {
							string num;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							if (negocio->getSucurales()->buscarSucursal(num) == false) {
								cout << "ERROR-Sucursal no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							cout << negocio->getSucurales()->getSucursal(num)->toString() << endl;
							system("pause");
							system("cls");
							break;
						}
						}
					}
				}
				case 2: {
					while (opcion3 != 4) {
						cout << "----Clientes por Sucursal----" << endl;
						cout << "1-Ingreso de Cliente" << endl;
						cout << "2-Eliminar Cliente" << endl;
						cout << "3-Visualizacion de Cliente" << endl;
						cout << "4-Volver" << endl;
						cout << "Digite el numero de la opcion seleccionada:" << endl;
						cin >> opcion3;
						system("pause");
						system("cls");
						switch (opcion3) {
						case 1: {
							string num;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							if (negocio->getSucurales()->buscarSucursal(num) == false) {
								cout << "ERROR-Sucursal no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							string nom, ced, resi;
							cout << "Digite el nombre del cliente: " << endl;
							getline(cin, nom);
							cout << "Digite la identificacion del cliente: " << endl;
							cin.ignore();
							cin >> ced;
							cout << "Digite el lugar de residencia del cliente: " << endl;
							getline(cin, resi);
							Cliente* nuevo = new Cliente(ced, nom, resi);
							if (negocio->getSucurales()->getSucursal(num)->getCliente(ced)) {
								cout << "ERROR-Cliente existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							negocio->getSucurales()->getSucursal(num)->insertarCliente(nuevo);
							cin.ignore();
							system("pause");
							system("cls");
							break;
						}
						case 2: {
							string num;
							string ced;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							cout << "Digite la identificacion del Cliente: " << endl;
							cin >> ced;
							if (negocio->getSucurales()->buscarSucursal(num) == false) {
								cout << "ERROR-Sucursal no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							else if (negocio->getSucurales()->getSucursal(num)->getCliente(ced)) {
								negocio->getSucurales()->getSucursal(num)->eliminarCliente(ced);
								cout << "Cliente eliminado exitosamente!" << endl;
								system("pause");
								system("cls");
								break;
							}
							else {
								cout << "ERROR-Cliente no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
						}
						case 3: {
							string num;
							string ced;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							if (negocio->getSucurales()->buscarSucursal(num) == false) {
								cout << "ERROR-Sucursal no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							cout << "Digite la identificacion del Cliente: " << endl;
							cin >> ced;
							cout << negocio->getSucurales()->getSucursal(num) << endl;
							if (!negocio->getSucurales()->getSucursal(num)->getCliente(ced)) {
								cout << "ERROR-Cliente no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							cout << negocio->getSucurales()->getSucursal(num)->getCliente(ced)->toString() << endl;
							system("pause");
							system("cls");
							break;
						}
						}
					}
				}
				case 3: {
					while (opcion3 != 4) {
						cout << "----Colaboradores por Sucursal----" << endl;
						cout << "1-Ingreso de Colaborador" << endl;
						cout << "2-Eliminar Colaborador" << endl;
						cout << "3-Visualizacion de Colaborador" << endl;
						cout << "4-Volver" << endl;
						cout << "Digite el numero de la opcion seleccionada:" << endl;
						cin >> opcion3;
						system("pause");
						system("cls");
						switch (opcion3) {
						case 1: {
							string num;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							if (negocio->getSucurales()->buscarSucursal(num) == false) {
								cout << "ERROR-Sucursal no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							string nom, ced;
							int dia, mes, annio;
							cout << "Digite el nombre del cliente: " << endl;
							getline(cin, nom);
							cout << "Digite la identificacion del cliente: " << endl;
							cin.ignore();
							cin >> ced;
							cout << "Digite el dia de la fecha de ingreso del colaborador: " << endl;
							cin >> dia;
							cout << "Digite el mes de la fecha de ingreso del colaborador: " << endl;
							cin >> mes;
							cout << "Digite el annio de la fecha de ingreso del colaborador: " << endl;
							cin >> annio;
							Fecha* fechaI = new Fecha(dia, mes, annio);
							Colaborador* nuevo = new Colaborador(ced, nom, fechaI);
							if (negocio->getSucurales()->getSucursal(num)->getColaborador(ced)) {
								cout << "ERROR-Cliente existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							negocio->getSucurales()->getSucursal(num)->insertarColaborador(nuevo);
							cin.ignore();
							system("pause");
							system("cls");
							break;
						}
						case 2: {
							string num;
							string ced;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							cout << "Digite la identificacion del Colaborador: " << endl;
							cin >> ced;
							if (negocio->getSucurales()->buscarSucursal(num) == false) {
								cout << "ERROR-Sucursal no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							else if (negocio->getSucurales()->getSucursal(num)->getColaborador(ced)) {
								negocio->getSucurales()->getSucursal(num)->eliminarColaborador(ced);
								cout << "Colaborador eliminado exitosamente!" << endl;
								system("pause");
								system("cls");
								break;
							}
							else {
								cout << "ERROR-Colaborador no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
						}
						case 3: {
							string num;
							string ced;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							if (negocio->getSucurales()->buscarSucursal(num) == false) {
								cout << "ERROR-Sucursal no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							cout << "Digite la identificacion del Colaborador: " << endl;
							cin >> ced;
							cout << negocio->getSucurales()->getSucursal(num) << endl;
							if (!negocio->getSucurales()->getSucursal(num)->getColaborador(ced)) {
								cout << "ERROR-Colaborador no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							cout << negocio->getSucurales()->getSucursal(num)->getColaborador(ced)->toString() << endl;
							system("pause");
							system("cls");
							break;
						}
						}
					}
				}
				}
			}
		}
		case 2: {
			while (opcion2 !=9) {
				cout << "----Planteles, Parqueos y Vehiculos----" << endl;
				cout << "1-Creacion de Plantel" << endl;
				cout << "2-Vehiculos por Sucursal" << endl;
				cout << "3-Reubicacion de Vehiculo (dentro de su sucursal)" << endl;
				cout << "4-Reportes de Cliente" << endl;
				cout << "5-Reportes de Planteles y Vehiculos" << endl;
				cout << "6-Visualizacion de Plantel" << endl;
				cout << "7-Cambio del Estado del Vehiculo" << endl;
				cout << "8-Traslado de Vehiculo a otra Sucursal" << endl;
				cout << "9-Volver" << endl;
				cout << "Digite el numero de la opcion seleccionada:" << endl;
				cin >> opcion2;
				switch (opcion2) {
				case 1: {
					string num;
					cout << "Digite el codigo de la Sucursal: " << endl;
					cin >> num;
					if (negocio->getSucurales()->buscarSucursal(num) == false) {
						cout << "ERROR-Sucursal no existente" << endl;
						system("pause");
						system("cls");
						break;
					}
					string cod;
					char tipo;
					int f, c;
					cout << "Digite la identificacion del Plantel: " << endl;
					cin >> cod;
					if (negocio->getSucurales()->getSucursal(num)->getPlantel(cod)) {
						cout << "ERROR-Plantel existente" << endl;
						system("pause");
						system("cls");
						break;
					}
					cout << "Digite el tipo del Plantel: " << endl;
					cout << "1-Techado y asfaltado" << endl;
					cout << "2-Techado y lastreado" << endl;
					cout << "3-Asfaltado" << endl;
					cout << "4-Lastreado" << endl;
					cin >> tipo;
					cout << "Digite la cantidad de filas del Plantel: " << endl;
					cin >> f;
					cout << "Digite la cantidad de columnas del Plantel: " << endl;
					cin >> c;
					Plantel* nuevo = new Plantel(cod, tipo, f, c);
					negocio->getSucurales()->getSucursal(num)->insertarPlantel(nuevo);
					cout << "Plantel ingresada con exito!" << endl;
					cout << "Plantel ingresado:" << endl;
					cout << nuevo->toString() << endl;
					system("pause");
					system("cls");
					break;
				}
				case 2: {
					int opcion3;
					while (opcion3 != 4) {
						cout << "----Vehiculos Por Sucursal----" << endl;
						cout << "1-Ingreso de Vehiculo" << endl;
						cout << "2-Eliminar Vehiculo" << endl;
						cout << "3-Visualizacion de Vehiculo" << endl;
						cout << "4-Reportes de Cliente" << endl;
						cin >> opcion3;
						switch (opcion3) {
						case 1: {
							string num;
							cout << "Digite el codigo de la Sucursal: " << endl;
							cin >> num;
							if (negocio->getSucurales()->buscarSucursal(num) == false) {
								cout << "ERROR-Sucursal no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							string ced;
							cout << "Digite la cedula del cliente propietario del vehiculo:" << endl;
							cin >> ced;
							if (!negocio->getSucurales()->getSucursal(num)->getCliente(ced)) {
								cout << "ERROR-Cliente no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							string placa;
							cout << "Digite la placa del Vehiculo: " << endl;
							cin >> placa;
							if (negocio->getSucurales()->getSucursal(num)->getVehiculo(placa)) {
								cout << "ERROR-Vehiculo existente" << endl;
								system("pause");
								system("cls");
								break;
							}
							string modelo, marca, plantel, licencia;
							int ubi1, ubi2;
							char categoria;
							cout << "Digite la marca del Vehiculo: " << endl;
							getline(cin, marca);
							cout << "Digite el modelo del Vehiculo: " << endl;
							cin.ignore();
							getline(cin, modelo);
							while (categoria != 'A' || categoria != 'B' || categoria != 'C' || categoria != 'D') {
								cout << "A-Economico" << endl;
								cout << "B-Estandar" << endl;
								cout << "C-Lujo" << endl;
								cout << "D-4x4" << endl;
								cout << "Digite la letra de la categoria del Vehiculo: " << endl;
								cin >> categoria;
							}
							cin >> placa;
							cout << "Digite la licencia requerida para manejar el Vehiculo: " << endl;
							cin >> licencia;
							cout << "Plantel recomendado: " << endl;
							cout << negocio->getSucurales()->getSucursal(num)->getPlanteles()->plantelRecomendado() << endl;
							do {
								cout << "Digite el codigo del plantel: " << endl;
								cin >> plantel;
							} while (!negocio->getSucurales()->getSucursal(num)->getPlantel(plantel));
							cout << "Estacionamientos recomendados: " << endl;
							cout << negocio->getSucurales()->getSucursal(num)->getPlantel(plantel)->toString() << endl;
							cout << negocio->getSucurales()->getSucursal(num)->getPlantel(plantel)->recomendacionDeEstacionamiento() << endl;
							cout << "Digite el indice de la fila del estacionamiento: " << endl;
							cin >> ubi1;
							cout << "Digite el indice de la columna del estacionamiento: " << endl;
							cin >> ubi2;
							Vehiculo* nuevo = new Vehiculo(placa, modelo, marca, categoria, licencia, negocio->getSucurales()->getSucursal(num)->getCliente(ced));
							negocio->getSucurales()->getSucursal(num)->getPlantel(plantel)->insertarVehiculo(nuevo,plantel,ubi1,ubi2);

						}
						}
					}
				}
				}
			}
		}


	}






}
