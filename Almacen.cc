#include "Almacen.hh"




Almacen::Almacen(int n){
  almacen = vector <Sala>(n);
}

int Almacen::poner_items_sala(int n, const string& p, int cantidad){
  return almacen[n-1].poner_items(p,cantidad);
}
int Almacen::quitar_items_sala(int n, const string& p, int cantidad){
  return almacen[n-1].quitar_items(p,cantidad);
}

void Almacen::compactar_sala_iden(int n){
  cout << "compactar " << n << endl;
  almacen[n-1].compactar();
}

void Almacen::reorganizar_sala_iden(int n){
  cout << "reorganizar " << n <<endl;
  almacen[n-1].reorganizar();
}

void Almacen::redimensionar_sala_iden(int n, int i, int j){
  almacen[n-1].redimensionar(i,j);
}

int Almacen::consultar_sala_prod(int n) const{
  return almacen[n-1].consultar_total();
}

string Almacen::consultar_sala_pos_prod(int n, int i, int j) const{
  return almacen[n-1].consultar_pos(i, j);
}

void Almacen::leer_sala(int n){
  int fila,columna;
  for(int i = 0; i < n; ++i){
    cin >> fila >> columna;
    almacen[i] = Sala(fila, columna);
  }
}

void Almacen::escribir_sala(int n) const{
  cout << "escribir " << n << endl;
  almacen[n-1].escribir();
}
