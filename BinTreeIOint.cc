#include "BinTreeIOint.hh"

void read_bintree_int(BinTree<int>& a,int marca)
{
  int x;
  cin >> x;
  if (x!=marca){
	   BinTree<int> l;
	   read_bintree_int(l,marca);
	   BinTree<int> r;
	   read_bintree_int(r,marca);
	   a=BinTree<int>(x,l,r);
  }
}
