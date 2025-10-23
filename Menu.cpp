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
		case 1: {
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
		case 2: {
			while (opcion2 != 7) {
				cout << "----Planteles, Parqueos y Vehiculos----" << endl;
				cout << "1-Creacion de Plantel" << endl;
				cout << "2-Vehiculos por Sucursal" << endl;
				cout << "3-Reubicacion de Vehiculo (dentro de su sucursal)" << endl;
				cout << "4-Visualizacion de los estacionamientos" << endl;
				cout << "5-Cambio de Estado de un Vehiculo" << endl;
				cout << "6-Traslado de un Vehiculo (de una sucursal a otra)" << endl; //opcional
				cout << "7-Volver" << endl;
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
						cout << "4-Volver" << endl;
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
							cin.ignore();
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
							negocio->getSucurales()->getSucursal(num)->getPlantel(plantel)->insertarVehiculo(nuevo, plantel, ubi1, ubi2);
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
							string placa;
							cout << "Digite la placa del Vehiculo: " << endl;
							cin >> placa;
							if (negocio->getSucurales()->getSucursal(num)->getVehiculo(placa)) {
								negocio->getSucurales()->getSucursal(num)->eliminarVehiculo(placa);
								cout << "Vehiculo eliminado con exito! " << endl;
								system("pause");
								system("cls");
								break;
							}
							else {
								cout << "ERROR-Vehiculo no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
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
							string placa;
							cout << "Digite la placa del Vehiculo: " << endl;
							cin >> placa;
							if (negocio->getSucurales()->getSucursal(num)->getVehiculo(placa)) {
								cout << negocio->getSucurales()->getSucursal(num)->getVehiculo(placa)->toString() << endl;
								system("pause");
								system("cls");
								break;
							}
							else {
								cout << "ERROR-Vehiculo no existente" << endl;
								system("pause");
								system("cls");
								break;
							}
						}
						}
					}
				}
				case 3: {
					cout << "----Reubicacion de Vehiculo (dentro de su sucursal)----" << endl;
					string num;
					cout << "Digite el codigo de la Sucursal en la que se encuentra el vehiculo: " << endl;
					cin >> num;
					if (negocio->getSucurales()->buscarSucursal(num) == false) {
						cout << "ERROR-Sucursal no existente" << endl;
						system("pause");
						system("cls");
						break;
					}
					else {
						string placa;
						cout << "Digite la placa del Vehiculo a reubicar: " << endl;
						cin >> placa;
						if (negocio->getSucurales()->getSucursal(num)->getVehiculo(placa)) {
							if (negocio->getSucurales()->getSucursal(num)->getVehiculo(placa)->getEstado() != "Alquilado") {
								Vehiculo* cambio = negocio->getSucurales()->getSucursal(num)->getVehiculo(placa);
								string ide;
								cout << "Digite el codigo del Plantel al que se le desea reubicar: " << endl;
								cin >> ide;
								if (negocio->getSucurales()->getSucursal(num)->getPlantel(ide)) {
									negocio->getSucurales()->getSucursal(num)->getPlantel(ide)->insertarDisponible(cambio);
									negocio->getSucurales()->getSucursal(num)->getPlantel(ide)->eliminarVehiculo(cambio->getPlaca());
									system("pause");
									system("cls");
									break;
								}
								else {
									cout << "ERROR-Plantel no existente" << endl;
									system("pause");
									system("cls");
									break;
								}
							}
							else {
								cout << "ERROR-Vehiculo Alquilado" << endl;
								system("pause");
								system("cls");
								break;
							}
						}
						else {
							cout << "ERROR-Vehiculo no existente" << endl;
							system("pause");
							system("cls");
							break;
						}
					}
				}
				case 4: {
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
					cout << "Digite la identificacion del Plantel: " << endl;
					cin >> cod;
					if (!negocio->getSucurales()->getSucursal(num)->getPlantel(cod)) {
						cout << "ERROR-Plantel no existente" << endl;
						system("pause");
						system("cls");
						break;
					}
					else {
						cout << "---Visualizacion del Plantel---" << endl;
						cout << negocio->getSucurales()->getSucursal(num)->getPlantel(cod)->toString() << endl;
						string ide;
						cout << "Digite el codigo del estacionamiento con el vehiculo a visualizar:" << endl;
						cin >> ide;
						if (negocio->getSucurales()->getSucursal(num)->getPlantel(cod)->buscarVehiculoPorCodigo(ide)) {
							cout << negocio->getSucurales()->getSucursal(num)->getPlantel(cod)->buscarVehiculoPorCodigo(ide)->toString() << endl;
							system("pause");
							system("cls");
							break;
						}
						else {
							cout << "ERROR-Estacionamiento Disponible" << endl;
							system("pause");
							system("cls");
							break;
						}
					}
				}
				case 5: {
					string num;
					cout << "Digite el codigo de la Sucursal: " << endl;
					cin >> num;
					if (negocio->getSucurales()->buscarSucursal(num) == false) {
						cout << "ERROR-Sucursal no existente" << endl;
						system("pause");
						system("cls");
						break;
					}
					string placa;
					cout << "Digite la placa del Vehiculo: " << endl;
					cin >> placa;
					if (negocio->getSucurales()->getSucursal(num)->getVehiculo(placa)) {
						char estado;
						do {
							cout << "Digite la letra del estado seleccionado del vehiculo:" << endl;
							cout << "A-Ingreso de Vehiculo" << endl;
							cout << "B-Eliminar Vehiculo" << endl;
							cout << "C-Visualizacion de Vehiculo" << endl;
							cout << "D-Volver" << endl;
							cout << "E-Volver" << endl;
							cin >> estado;
						} while (estado != 'A' || estado != 'B' || estado != 'C' || estado != 'D' || estado != 'E');
						string id;
						cout << "Digite el id del colaborador encargado del cambio:" << endl;
						cin >> id;
						if (negocio->getSucurales()->getSucursal(num)->getColaborador(id)) {
							int dia, mes, annio;
							cout << "Digite el numero del dia del cambio:" << endl;
							cin >> dia;
							cout << "Digite el numero del mes del cambio:" << endl;
							cin >> mes;
							cout << "Digite el annio del cambio:" << endl;
							cin >> annio;
							Fecha* nueva = new Fecha(dia, mes, annio);
							negocio->getSucurales()->getSucursal(num)->getVehiculo(placa)->actualizaEstado(estado, negocio->getSucurales()->getSucursal(num)->getColaborador(id), nueva);
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
					else {
						cout << "ERROR-Vehiculo no existente" << endl;
						system("pause");
						system("cls");
						break;
					}
				}
				}
			}
		}
		case 3: {
			while (opcion2 != 5) {
				cout << "3-Solicitudes y Contratos\n" << endl;

				cout << "1-Creacion de solicitud" << endl;
				cout << "2-Visualizacion de solicitud" << endl;
				cout << "3-Aprobacion o rechazo de solicitud de alquiler" << endl;
				cout << "4-Recepcion del vehiculo en alquiler y finalizacion del contrato" << endl;
				cout << "5-Volver" << endl;
				cout << "Digite el numero de la opcion seleccionada:" << endl;
				cin >> opcion2;
				switch (opcion2) {
				case 1: {
					cout << "       CREACIÓN DE NUEVA SOLICITUD DE ALQUILER    " << endl;
					int dia, mes, annio;
					cout << "Ingrese Fecha de Inicio" << endl;
					cout << "Dia: ";
					cin >> dia;
					cout << "Mes: ";
					cin >> mes;
					cout << "Anio: ";
					cin >> annio;
					Fecha* inicio = new Fecha(dia, mes, annio);
					cout << "Ingrese Fecha de Entrga" << endl;
					cout << "Dia: ";
					cin >> dia;
					cout << "Mes: ";
					cin >> mes;
					cout << "Anio: ";
					cin >> annio;
					Fecha* entrega = new Fecha(dia, mes, annio);

					string codigo, idCliente, idColaborador, idSucursal, placa;
					int canDias;
					float precioDia;
					cout << "Codigo (ID Unico): ";
					cin >> codigo;
					cout << "ID Cliente: ";
					cin >> idCliente;
					cout << "ID Colaborador Responsable: ";
					cin >> idColaborador;
					cout << "ID Sucursal: ";
					cin >> idSucursal;
					cout << "Placa del Vehiculo: ";
					cin >> placa;
					if (negocio->getSucurales()->getSucursal(idSucursal) == nullptr) {
						cout << "ERROR: No existe la sucursal" << endl;
						delete inicio;
						delete entrega;
						break;
					}
					if (negocio->getSucurales()->getSucursal(idSucursal)->getCliente(idCliente) == nullptr) {
						cout << "ERROR: No existe el cliente" << endl;
						delete inicio;
						delete entrega;
						break;

					}
					if (negocio->getSucurales()->getSucursal(idSucursal)->getColaborador(idColaborador) == nullptr) {
						cout << "ERROR: No existe el colaborador" << endl;
						delete inicio;
						delete entrega;
						break;

					}
					if (negocio->getSucurales()->getSucursal(idSucursal)->getVehiculo(placa) == nullptr) {
						cout << "ERROR: No existe el vehiculo" << endl;
						delete inicio;
						delete entrega;
						break;

					}

					cout << "Cantidad de Dias de Alquiler: ";
					cin >> canDias;
					cout << "Precio por Dia de Alquiler: ";
					cin >> precioDia;
					SolicitudAlquiler* nuevaSolicitud = new SolicitudAlquiler(
						codigo,
						idCliente,
						idColaborador,
						idSucursal,
						placa,
						canDias,
						inicio,
						entrega,
						precioDia
					);
					negocio->getSucurales()->getSucursal(idSucursal)->insertarSolicitud(nuevaSolicitud);
					negocio->getSucurales()->getSucursal(idSucursal)->getCliente(idCliente)->insertarSolicitud(nuevaSolicitud);
					negocio->getSucurales()->getSucursal(idSucursal)->getColaborador(idColaborador)->insertarTrabajo(nuevaSolicitud);
					negocio->getSucurales()->getSucursal(idSucursal)->getVehiculo(placa)->insertarSolicitud(nuevaSolicitud);
					cout << "-> Solicitud:  " << codigo << " creada exitosamente (Estado: pendiente)." << endl;
					break;

				}
				case 2: {
					cout << "       VISUALIZACION DE SOLCITUD DE ALQUILER       " << endl;
					string cod, idSucursal;
					cout << "ID Sucursal: ";
					cin >> idSucursal;
					if (negocio->getSucurales()->getSucursal(idSucursal) == nullptr) {
						cout << "ERROR: No existe la sucursal" << endl;
						break;

					}
					cout << "Digte el codigo de la solicitud de alquiler o contrato: " << endl;
					cin >> cod;
					if (negocio->getSucurales()->getSucursal(idSucursal)->getSolicitud(cod) == nullptr) {
						cout << "ERROR: No existe la solicitud" << endl;
						break;

					}
					cout << negocio->getSucurales()->getSucursal(idSucursal)->getSolicitud(cod)->toString();
				}
				case 3: {
					cout << "       APROBACION O RECHAZO DE SOLICITUD DE ALQUILER       " << endl;
					string cod, idSucursal;
					cout << "ID Sucursal: ";
					cin >> idSucursal;
					if (negocio->getSucurales()->getSucursal(idSucursal) == nullptr) {
						cout << "ERROR: No existe la sucursal" << endl;
						break;

					}
					cout << "Digte el codigo de la solicitud de alquiler: " << endl;
					cin >> cod;
					if (negocio->getSucurales()->getSucursal(idSucursal)->getSolicitud(cod) == nullptr) {
						cout << "ERROR: No existe la solicitud" << endl;
						break;

					}

					if (negocio->getSucurales()->getSucursal(idSucursal)->getSolicitudes()->esSolicitud(cod)) {
						SolicitudAlquiler* solicitud = negocio->getSucurales()->getSucursal(idSucursal)->getSolicitud(cod);
						int estado = -1;
						cout << "  CAMBIO DE ESTADO (Solicitud: " << cod << ")" << endl;
						cout << "  Estado actual: " << solicitud->getEstado() << endl;
						cout << "--------------------------------------------------" << endl;

						cout << "Seleccione el nuevo estado:" << endl;
						cout << "1. APROBADA" << endl;
						cout << "2. PENDIENTE" << endl;
						cout << "3. RECHAZADA" << endl;
						cout << "4. ANULADA" << endl;
						cout << "Opcion: ";
						cin >> estado;
						if (estado >= 1 && estado <= 4) {
							solicitud->setEstado(estado);
							cout << "-> Estado actualizado a: " << solicitud->getEstado() << endl;
							system("pause");
							system("cls");
							if (solicitud->getEstado() == "aprobada") {
								negocio->getSucurales()->getSucursal(idSucursal)->getSolicitudes()->cambiarAContrato(cod);
								bool cambioRealizado = false;
								while (!cambioRealizado) {
									cout << "La Solicitud ha pasado a ser un Contrato" << endl;
									cout << "Actualice el estado del contrato\n" << endl;
									cout << "\tSeleccione el nuevo estado:" << endl;
									cout << "1. Aprobado en alquiler" << endl;
									cout << "2. Aprobado pendiente de ejecucion" << endl;
									cout << "Opcion: ";
									cin >> estado;
									if (estado == 1 || estado == 2) {
										solicitud->setEstado(estado);
										cambioRealizado = true;
										system("pause");
										system("cls");
									}
									else {
										cout << "ERROR: Numero fuera del rango, vuelva a intentar" << endl;
									}
								}
							}


						}
						else {
							cout << "ERROR: Opcion fuera de rango." << endl;
						}
					}
					else {
						cout << "ERROR: Es un Contrato, no una Solicitud." << endl;

					}

				}
				case 4: {
					string cod, idSucursal;
					cout << "ID Sucursal: ";
					cin >> idSucursal;
					if (negocio->getSucurales()->getSucursal(idSucursal) == nullptr) {
						cout << "ERROR: No existe la sucursal" << endl;
						break;

					}
					cout << "Digte el codigo del contrato: " << endl;
					cin >> cod;
					if (negocio->getSucurales()->getSucursal(idSucursal)->getSolicitud(cod) == nullptr) {
						cout << "ERROR: No existe el contrato" << endl;
						break;

					}

					if (!negocio->getSucurales()->getSucursal(idSucursal)->getSolicitudes()->esSolicitud(cod)) {
						ContratoAlquiler* contrato = negocio->getSucurales()->getSucursal(idSucursal)->getSolicitud(cod);
						int estado = -1;
						cout << "  CAMBIO DE ESTADO (Contrato: " << cod << ")" << endl;
						cout << "  Estado actual: " << contrato->getEstado() << endl;
						cout << "--------------------------------------------------" << endl;

						cout << "Seleccione el nuevo estado:" << endl;
						cout << "1. Aprobado en alquiler" << endl;
						cout << "2. Aprobado pendiente de ejecucion" << endl;
						cout << "3. Finalizado con multa" << endl;
						cout << "4. Finalizado con reintegro" << endl;
						cout << "5. Finalizado sin vargos adicionales" << endl;
						cout << "Opcion: ";
						cin >> estado;
						if (estado >= 1 && estado <= 5) {
							contrato->setEstado(estado);
							cout << "-> Estado actualizado a: " << contrato->getEstado() << endl;
							if (estado == 3) {
								int diasDeMas = -1;
								while (diasDeMas < 1) {
									float precioDia, precioActual, precioMas;
									cout << "Digite cuantos dias de mas uso el vehiculo: "; cin >> diasDeMas;
									precioDia = contrato->getPrecioDia();
									precioActual = contrato->getPrecioTotal();
									precioMas = diasDeMas * (precioDia * 1.3);
									contrato->setPrecioTotal(precioActual + precioMas);
								}
							}
							if (estado == 4) {
								int diasDeMenos = -1;
								while (diasDeMenos < 1) {
									float precioDia, precioActual, precioMenos;
									cout << "Digite cuantos dias de menos uso el vehiculo: "; cin >> diasDeMenos;
									precioDia = contrato->getPrecioDia();
									precioActual = contrato->getPrecioTotal();
									precioMenos = diasDeMenos * (precioDia * 0.7);
									contrato->setPrecioTotal(precioActual - precioMenos);
								}
							}


						}
						else {
							cout << "ERROR: Opcion fuera de rango." << endl;
						}
					}
					else {
						cout << "ERROR: Es una Solicitud de alquiler no un Contrato." << endl;
					}
				}
				}

			}

		case 4: {
			while (opcion2 != 3) {
				cout << "4-Reportes de Cliente\n" << endl;
				cout << "1-Historial de un cliente" << endl;
				cout << "2-Reporte de clientes por cantidad de contratos" << endl;
				cout << "3-Devolverse" << endl;
				cout << "Digite el numero de la opcion seleccionada:" << endl;
				cin >> opcion2;
				switch (opcion2) {
				case 1: {
					cout << "1-Historial de un cliente" << endl;

					string idClie, idSucursal;
					cout << "ID Sucursal: ";
					cin >> idSucursal;
					if (negocio->getSucurales()->getSucursal(idSucursal) == nullptr) {
						cout << "ERROR: No existe la sucursal" << endl;
						break;
					}
					cout << "Digte el codigo de la solicitud de alquiler: " << endl;
					cin >> idClie;
					if (negocio->getSucurales()->getSucursal(idSucursal)->getSolicitud(idClie) == nullptr) {
						cout << "ERROR: No existe el Cliente" << endl;
						break;
					}
					cout << negocio->getSucurales()->getSucursal(idSucursal)->getCliente(idClie)->getHistorialAlquiler()->toString();
					system("pause");
					system("cls");
				}
				case 2: {
					cout << "2-Reporte de clientes por cantidad de contratos" << endl;
					string idSucursal;
					cout << "ID Sucursal: ";
					cin >> idSucursal;
					if (negocio->getSucurales()->getSucursal(idSucursal) == nullptr) {
						cout << "ERROR: No existe la sucursal" << endl;
						break;
					}
					negocio->getSucurales()->getSucursal(idSucursal)->getClientes()->OrdenarClientes();
					cout << negocio->getSucurales()->getSucursal(idSucursal)->getClientes()->toString();
					system("pause");
					system("cls");
				}
				}
			}
		}
		case 5: {
			opcion2 = -1;
			while (opcion2 != 9) {
				cout << "5-Reportes de Planteles y Vehiculos" << endl;
				cout << "1-Creacion de solicitud" << endl;
				cout << "1-Creacion de solicitud" << endl;
				cout << "1-Creacion de solicitud" << endl;
				cout << "5-Volver" << endl;
				cout << "Digite el numero de la opcion seleccionada:" << endl;

			}
		}
		}


		}






	}
}
