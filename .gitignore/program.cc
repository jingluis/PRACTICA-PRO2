#include "SalaBinTree.hh"
#include "Inventario.hh"
#include "Almacen.hh"



void ERROR(){
  cout << "  error" <<endl;
}

int main()
{
  int N;
  cin >> N;
  Inventario s;
  Almacen almacen(N);
  SalaBinTree dis_sala;
  dis_sala.leer_distribucion();
  almacen.leer_sala(N);
  string op,iden_producto;
  int iden_sala,cantidad,fila,columna;
  cin >> op;
  while (op != "fin") {
    if(op == "escribir"){
        cin >> iden_sala;
        almacen.escribir_sala(iden_sala);
    } else if(op == "poner_prod"){
        cin >> iden_producto;
        cout << op << " " << iden_producto << endl;
        if(s.existir_prod(iden_producto)) ERROR();
        else s.poner_prod(iden_producto);
    } else if(op == "quitar_prod"){
        cin >> iden_producto;
        cout << op << " " << iden_producto << endl;
        if(not s.existir_prod(iden_producto)) ERROR();
        else if(s.consultar_prod(iden_producto) > 0) ERROR();
        else s.quitar_prod(iden_producto);
    } else if(op == "poner_items"){
        cin >> iden_sala >> iden_producto >> cantidad;
        cout << op << " " << iden_sala << " ";
        cout << iden_producto << " " << cantidad << endl;
        if(not s.existir_prod(iden_producto)) ERROR();
        else{
          cout << "  ";
          int sobrante = almacen.poner_items_sala(iden_sala,iden_producto,cantidad);
          cout << sobrante <<endl;
          s.aumentar_unidad(iden_producto,cantidad-sobrante);
        }
    } else if(op == "quitar_items"){
        cin >> iden_sala >> iden_producto >> cantidad;
        cout << op << " " << iden_sala << " ";
        cout << iden_producto << " " << cantidad << endl;
        if(not s.existir_prod(iden_producto)) ERROR();
        else{
          cout << "  ";
          int sobrante = almacen.quitar_items_sala(iden_sala,iden_producto,cantidad);
          cout << sobrante << endl;
          s.disminuir_unidad(iden_producto,cantidad-sobrante);
        }
    } else if(op == "distribuir"){
        cin >> iden_producto >> cantidad;
        cout << op << " " << iden_producto;
        cout <<" " << cantidad << endl;
        if(not s.existir_prod(iden_producto)) ERROR();
        else {
          cout << "  ";
          int sobrante = dis_sala.distribuir(almacen,iden_producto,cantidad);
          cout << sobrante << endl;
          s.aumentar_unidad(iden_producto,cantidad-sobrante);
        }
    } else if(op == "compactar"){
        cin >> iden_sala;
        almacen.compactar_sala_iden(iden_sala);
    } else if(op == "reorganizar"){
        cin >> iden_sala;
        almacen.reorganizar_sala_iden(iden_sala);
    } else if(op == "redimensionar"){
        cin >> iden_sala >> fila >> columna;
        cout << op << " " << iden_sala << " ";
        cout << fila << " " << columna << endl;
        if(fila*columna < almacen.consultar_sala_prod(iden_sala)) ERROR();
        else almacen.redimensionar_sala_iden(iden_sala, fila, columna);
    } else if(op == "inventario"){
        s.escribir();
    } else if(op == "consultar_pos"){
        cin >> iden_sala >> fila >> columna;
        cout << op << " " << iden_sala << " ";
        cout << fila << " " << columna << endl;
        cout << "  ";
        cout << almacen.consultar_sala_pos_prod(iden_sala, fila, columna) << endl;
    } else if(op == "consultar_prod"){
        cin >> iden_producto;
        cout << op << " " << iden_producto << endl;
        if(not s.existir_prod(iden_producto)) ERROR();
        else cout << "  " << s.consultar_prod(iden_producto) << endl;
    } cin >> op;
  } cout <<"fin"<<endl;
}
