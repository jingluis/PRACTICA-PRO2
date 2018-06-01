#include "Sala.hh"

Sala::Sala(){
  cantidad = 0;
  row = column = 0;
  compactado = false;
}

Sala::Sala(const int& i, const int& j){
  compactado = false;
  cantidad = 0;
  row = i; column = j;
  estanteria = Matriz (i, vector<string>(j,"NULL"));
}

void Sala::first_pos_no_null(int& i, int& j) const{
  while(i >= 0){
    while(j < column){
      if(estanteria[i][j] != "NULL") return;
      else ++j;
    }
    j = 0;
    --i;
  }
}

void Sala::first_pos_null(int& i, int& j) const{
  while(i >= 0){
    while(j < column){
      if(estanteria[i][j] == "NULL") return;
      else ++j;
    }
    j = 0;
    --i;
    }
}

void Sala::compactar_sala(){
  if(not compactado){
    if(cantidad > 0){
      int row_null,col_null;
      row_null = row-1;
      col_null = 0;
      int row_no_null,col_no_null;
      first_pos_null(row_null,col_null);
      row_no_null = row_null;
      col_no_null = col_null;
      first_pos_no_null(row_no_null,col_no_null);
      while(not(row_no_null == -1 and col_no_null == 0)){
        swap(estanteria[row_null][col_null],estanteria[row_no_null][col_no_null]);
        first_pos_no_null(row_no_null,col_no_null);
        first_pos_null(row_null,col_null); //si no da ninguna vuelta
      }
    }
    compactado = true;
  }
}

void Sala::reorganizar_sala(){
  if(cantidad > 0){
    int i = row-1;
    int j = 0;
    map <string,int>::iterator it = prod_existente.begin();
    for(; it != prod_existente.end(); ++it){
      for(int aux = it -> second; aux > 0; -- aux){
        estanteria[i][j] = it -> first;
        ++j;
        if(j == column){
          --i; j = 0;
        }
      }
    }
    for(; i >= 0; --i){
      for(; j < column; ++j){
        estanteria[i][j] = "NULL";
      }
      j = 0;
    }
    compactado = true;
  }
}

int Sala::poner_items(const string& p, int c){
  map <string,int>::iterator it = prod_existente.lower_bound(p);
  /* no se pone items cuando el parámetro implícito está lleno o la c = 0 */
  if(not (cantidad == row*column) and not c == 0){
    int puesto = 0;
    for(int i = row-1; i >= 0 and c > 0; --i){
      for(int j = 0; j < column and c > 0; ++j){
        if(estanteria[i][j] == "NULL"){
          estanteria[i][j] = p;
          --c; ++puesto;
        }
      }
    }
    cantidad += puesto;
    if(it != prod_existente.end() and it -> first == p){
      (*it).second += puesto;
    }
    else prod_existente.insert(it,make_pair(p,puesto));
  }
  return c;
}

int Sala::quitar_items(const string& p, int c){
  map <string,int>::iterator it = prod_existente.find(p);
  if(it == prod_existente.end()) return c;
  int aux = it -> second;
  int quitados = 0;
  for(int i = row-1; i >= 0 and aux > 0 and c > 0; --i){
    for(int j = 0; j < column and aux > 0 and c > 0; ++j){
      if(estanteria[i][j] == p){
        estanteria[i][j] = "NULL";
        --c; --aux; ++quitados;
      }
    }
  }
  if(aux == 0) prod_existente.erase(it);
  else (*it).second = aux;
  cantidad -= quitados;
  compactado = false;
  return c;
}


void Sala::compactar(){
  compactar_sala();
}

void Sala::reorganizar(){
  reorganizar_sala();
}

void Sala::redimensionar(const int& fil, const int& col){
  if(fil*col < cantidad) throw PRO2Excepcio("error");
  if(cantidad > 0){
    vector <string> producte(cantidad);
    int index = 0;
    bool acabat = false;
    /* guardar todos los productos en un vector auxiliar */
    for(int i = row-1; i >= 0 and not acabat; --i){
      for(int j = 0; j < column and not acabat; ++j){
        if(estanteria[i][j] != "NULL"){
          producte[index++] = estanteria[i][j];
          if(index == cantidad) acabat = true;
        }
      }
    }
    index = 0; acabat = false;
    estanteria = Matriz(fil,vector<string>(col,"NULL"));
    row = fil; column = col;
    /* rellenar la matriz nueva */
    for(int i = row-1; i >= 0 and not acabat; --i){
      for(int j = 0; j < column and not acabat; ++j){
          estanteria[i][j] = producte[index++];
          if(index == cantidad) acabat = true;
      }
    }
  }
  else {
    estanteria = Matriz(fil,vector<string>(col,"NULL"));
    row = fil; column = col;
  }
  compactado = true;
}

string Sala::consultar_pos(const int& fila, const int& columna) const{
  return estanteria[fila-1][columna-1];
}

int Sala::consultar_total() const{
  return cantidad;
}

void Sala::escribir() const{
  for(int i = 0; i < row; ++i){
    cout << "  ";
    for(int j = 0; j < column; ++j){
      if(j == column-1) cout << estanteria[i][j];
      else cout << estanteria[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "  " << cantidad << endl;
  for(map<string,int>::const_iterator it = prod_existente.begin(); it != prod_existente.end(); ++it){
    cout <<"  " << (*it).first << ' ' << (*it).second << endl;
  }
}
