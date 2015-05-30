#include <iostream>
#include <list>
#include <memory>
#include <vector>

using namespace std;

class Element{
public:
	Element(){
		size = 0;
		value = 0;
		ptr = 0;
		ptrPrev = 0;
	}
	Element(int n){
		size = 0;
		value = n;
		ptr = 0;
		ptrPrev = 0;
	}
	Element(const Element& E){
		value = E.value;
		ptr = E.ptr;
		ptrPrev = E.ptrPrev;
	}

	int size;
	int value;
	Element** ptr = 0;
  Element* ptrPrev = 0;
};

Element* initTree(Element* a[], Element* tree){
	tree->value = a[0]->value;
	tree->ptr = new Element*[2];
  tree->ptrPrev = 0;
	tree->ptr[0] = a[1];
  tree->ptr[0]->ptrPrev = tree;
	tree->ptr[1] = a[2];
  tree->ptr[1]->ptrPrev = tree;
	tree->size = 2;

	tree->ptr[0]->ptr = new Element*[3];
	tree->ptr[0]->size = 3;
	tree->ptr[0]->ptr[0] = a[3];
  tree->ptr[0]->ptr[0]->ptrPrev = tree->ptr[0];
	tree->ptr[0]->ptr[1] = a[4];
  tree->ptr[0]->ptr[1]->ptrPrev = tree->ptr[0];
	tree->ptr[0]->ptr[1]->ptr = new Element*[2];
	tree->ptr[0]->ptr[1]->size = 2;
	tree->ptr[0]->ptr[1]->ptr[0] = a[8];
  tree->ptr[0]->ptr[1]->ptr[0]->ptrPrev = tree->ptr[0]->ptr[1];
	tree->ptr[0]->ptr[1]->ptr[1] = a[9];
  tree->ptr[0]->ptr[1]->ptr[1]->ptrPrev = tree->ptr[0]->ptr[1];
	tree->ptr[0]->ptr[2] = a[5];
	
	tree->ptr[1]->ptr = new Element* [2];
	tree->ptr[1]->size = 2;
	tree->ptr[1]->ptr[0] = a[6];
  tree->ptr[1]->ptr[0]->ptrPrev = tree->ptr[1];
	tree->ptr[1]->ptr[1] = a[7];
  tree->ptr[1]->ptr[1]->ptrPrev = tree->ptr[1];

	return tree;
}

void printDirect(Element* p){
	cout << p->value << " ";
	for (int i = 0; i < p->size; i++){
		printDirect(p->ptr[i]);
	}
}

Element* getBack(Element* p){
  while (p->size > 0) {
    p = p->ptr[0];
  }
  return p;
}

void printBack(Element* p){
  for (int i = 0; i < p->size; i++){
    printBack(p->ptr[i]);
  }
  cout << p->value << " ";
}

void setToArray(std::vector<int>& v, int i) {
  bool has = false;
  for (auto iter = v.begin(); iter != v.end(); ++iter) {
    if (*iter == i)
      has = true;
  }
  if (has == false)
    v.push_back(i);
}

void printSymmetry(Element* p, std::vector<int>& v) {
  if (p->size  == 0)
    setToArray(v, p->value);
  for (int i = 0; i < p->size; i++){
    printSymmetry(p->ptr[i], v);
    setToArray(v, p->value);
  }
}

void printArray(std::vector<int>& v) {
  for (auto iter = v.begin(); iter != v.end(); ++iter) {
    cout << *iter << " ";
  }
}

void main(){
	
	Element* pE[10];
	for (int i = 0; i < 10; i++){
		pE[i] = new Element(i + 1);
	}

	Element* in = new Element();
	in = initTree(pE, in);
	printDirect(in);

  cout << endl;
  printBack(in);

  cout << endl;
  std::vector<int> v;
  printSymmetry(in, v);
  printArray(v);

	system("pause");
}