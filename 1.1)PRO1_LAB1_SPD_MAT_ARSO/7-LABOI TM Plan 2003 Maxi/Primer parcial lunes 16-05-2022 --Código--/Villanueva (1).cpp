    // Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
using namespace std;

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

int main() {
	float contfacu;
	float contfacutipoinvn1;
	float contfacutipoinvn2;
	float contfacutipoinvn3;
	float contgrupos;
	float facu;
	float grupos;
	float inv1;
	float inv2;
	float inv3;
	float invmasdeesaplata1;
	float invmasdeesaplata2;
	float invmasdeesaplata3;
	contfacu = 0;
	contgrupos = 0;
	invmasdeesaplata1 = 0;
	invmasdeesaplata2 = 0;
	invmasdeesaplata3 = 0;
	facu = 1;
	grupos = 0;
	// COntFacuTipoInvN1,2,3=ContadorFacutadTipodeInvestigacionN1,2,3
	contfacutipoinvn1 = 0;
	contfacutipoinvn2 = 0;
	contfacutipoinvn3 = 0;
	while (facu!=0) {
		contfacu = contfacu+1;
		cout << "ingrese cantidad de Facultades" << endl;
		cin >> facu;
		grupos = 1;
		if (facu==0) {
			facu = 0;
		} else {
			while (grupos!=0) {
				contgrupos = contgrupos+1;
				cout << "Elija opcion de grupo que usted pertesece" << endl;
				cout << "grupo N°1" << endl;
				cout << "grupo N°2" << endl;
				cout << "grupo N°3" << endl;
				cin >> grupos;
				if (grupos==1) {
					cout << "Ingrese su inversion del grupo N°1" << endl;
					// Inv1=Investigacion1
					cin >> inv1;
					contfacutipoinvn1 = contfacutipoinvn1+1;
					if (inv1>=1000000) {
						invmasdeesaplata1 = invmasdeesaplata1+1;
					}
					// :D
				} else {
					if (grupos==2) {
						cout << "Ingrese su inversion del grupo N°2" << endl;
						// Inv2=Investigacion2
						cin >> inv2;
						contfacutipoinvn2 = contfacutipoinvn2+1;
						if (inv2>=1000000) {
							invmasdeesaplata2 = invmasdeesaplata2+1;
						}
					} else {
						if (grupos==3) {
							cout << "Ingrese su inversion del grupo N°3" << endl;
							// Inv3=Investigacion3
							cin >> inv3;
							contfacutipoinvn3 = contfacutipoinvn3+1;
							if (inv3>=1000000) {
								invmasdeesaplata3 = invmasdeesaplata3+1;
							}
						}
					}
				}
				grupos = 0;
			}
		}
	}
	// A-Inicio
	cout << "=================" << endl;
	cout << "Grupo N°1 que investigo invirtiendo mas de $ 1.000.000= " << invmasdeesaplata1 << endl;
	cout << "Grupo N°2 que investigo invirtiendo mas de $ 1.000.000= " << invmasdeesaplata2 << endl;
	cout << "Grupo N°3 que investigo invirtiendo mas de $ 1.000.000= " << invmasdeesaplata3 << endl;
	// A-FIN
	// B-Inicio
	cout << "=================" << endl;
	cout << "la cantidad de Facultades de grupo de Investigacion Tipo 1 es= " << contfacutipoinvn1 << endl;
	cout << "=================" << endl;
	// B-FIN
	// C-Inicio
	if (contfacutipoinvn1<contfacutipoinvn2) {
		if (contfacutipoinvn1<contfacutipoinvn3) {
			cout << "El grupo Menor es Grupo N°1 y su cantidad es= " << contfacutipoinvn1 << endl;
		} else {
			if (contfacutipoinvn3<contfacutipoinvn2) {
				cout << "El grupo Menor es Grupo N°3 y su cantidad es= " << contfacutipoinvn3 << endl;
			} else {
				cout << "El grupo Menor es Grupo N°2 y su Cantidad es= " << contfacutipoinvn2 << endl;
			}
		}
	} else {
		if (contfacutipoinvn2<contfacutipoinvn3) {
			cout << "El grupo Menor es Grupo N°2 y su Cantidad es= " << contfacutipoinvn2 << endl;
		} else {
			if (contfacutipoinvn3<contfacutipoinvn1) {
				cout << "El grupo Menor es Grupo N°3 y Su Cantida es= " << contfacutipoinvn3 << endl;
			} else {
				cout << "El grupo Menor es Grupo N°1 Y su cantidad es = " << contfacutipoinvn1 << endl;
			}
		}
	}
	// C-Fin
	cout << "=================" << endl;
	return 0;
}

