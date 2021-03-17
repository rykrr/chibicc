#include <stdio.h>

#define define_maybe(name, T) \
  typedef tagged_union { None, Some(T) } maybe_##name;

define_maybe(int, int);

maybe_int unit(int i) {
  return (maybe_int) Some(i);
}

maybe_int bind(maybe_int m, maybe_int (*f)(int)) {
  match (m) {
    Some(x) => { return f(x); },
    None    => { return m; }
  }

  fputs("Fatal error: maybe_int memory corrupted", stderr);
}


void print_maybe_int(maybe_int m) {
  match (m) {
    Some(x) => { printf("Some(%d)\n", x); },
    None    => { printf("None\n"); }
  }
}


maybe_int inc(int x) {
  return (maybe_int) Some(x+1);
}


int main() {
  maybe_int m = unit(5);
  printf("m = ");            print_maybe_int(m);
  printf("bind(m, inc) = "); print_maybe_int(bind(m, inc));

  m = (maybe_int) None;
  printf("m = ");            print_maybe_int(m);
  printf("bind(m, inc) = "); print_maybe_int(bind(m, inc));
  return 0;
}
