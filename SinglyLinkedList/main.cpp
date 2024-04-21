#include "linkedlist.h"

int main() {
  LinkedList<int> *ll = new LinkedList<int>;
  ll->lInsert(23);
  ll->lInsert(12);
  ll->lInsert(4232);
  ll->lInsert(543);
  ll->lInsert(34);
  ll->traversal();
  ll->lDelete(3);
  ll->lInsert(456, 3);
  ll->reverseLL();
  ll->traversal();
  ll->search(456);
  delete ll;
  return 0;
}
