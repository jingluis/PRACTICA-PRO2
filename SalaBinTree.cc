#include "SalaBinTree.hh"

SalaBinTree::SalaBinTree(){

}
void SalaBinTree::leer_distribucion(){
  read_bintree_int(distribucion,0);
}

int SalaBinTree::i_distribuir_sala(const BinTree<int>& dis, Almacen& a, const string& p, int c){
  if(not dis.empty()){
    int aux = a.poner_items_sala(dis.value(),p,c);
    if(aux == 0) return 0;
    return i_distribuir_sala(dis.left(),a,p,aux/2+aux%2) + i_distribuir_sala(dis.right(), a, p, aux/2);
  }
  return c;
}

int SalaBinTree::distribuir(Almacen& a, const string& p, int c){
  return i_distribuir_sala(distribucion, a, p, c);
}
