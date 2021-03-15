#include "../test/test.h"

#define define_maybe(name, T) \
  typedef tagged_union { Nothing, Some(T) } maybe_##name;

define_maybe(int, int);

maybe_int get_some(int x) {
  return (maybe_int) Some(x);
}

void print_maybe_int(maybe_int m) {
  match (m) {
    Nothing => { printf("Nothing\n"); },
    Some(x) => { printf("Some %d\n", x); },
  }
}

int main() {
  maybe_int m = get_some(5);
  print_maybe_int(m);
  print_maybe_int((maybe_int) Nothing);
  print_maybe_int(get_some(2));
}
