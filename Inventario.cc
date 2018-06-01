#include "Inventario.hh"

Inventario::Inventario(){
}

void Inventario::poner_prod(const string& s){
  map<string,int>::iterator it = inventario.find(s);
  if(it != inventario.end()) throw PRO2Excepcio("el producte ya está");
  inventario[s] = 0;
}

void Inventario::quitar_prod(const string& s){
  map<string,int>::iterator it = inventario.find(s);
  if(it == inventario.end()) throw PRO2Excepcio("el producto no existe");
  else if((*it).second != 0) throw PRO2Excepcio("hay unidades restantes");
  inventario.erase(it);
}

void Inventario::aumentar_unidad(const string& s, int n){
  map<string,int>::iterator it = inventario.find(s);
  if(it == inventario.end()) throw PRO2Excepcio("el producto no existe");
  (*it).second += n;
}

void Inventario::disminuir_unidad(const string& s, int n){
  map<string,int>::iterator it = inventario.find(s);
  if(it == inventario.end()) throw PRO2Excepcio("el producto no existe");
  else if((*it).second < n) throw PRO2Excepcio("no se ha podido quitar");
  (*it).second -= n;
}

bool Inventario::existir_prod(const string& s) const{
  map<string,int>::const_iterator it = inventario.find(s);
  return it != inventario.end();
}

int Inventario::consultar_prod(const string& s) const {
  map<string,int>::const_iterator it = inventario.find(s);
  if(it == inventario.end()) throw PRO2Excepcio("el producto no existe");
  return it -> second;
}

void Inventario::escribir() const{
  map<string,int>::const_iterator it = inventario.begin();
  cout << "inventario" << endl;
  while(it != inventario.end()){
    cout << "  " << (*it).first << ' ' << (*it).second << endl;
    ++it;
  }
}
