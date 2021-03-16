#include <stdio.h>

#define define_maybe(name, T) \
  typedef tagged_union { Nothing, Some(T) } maybe_##name;

define_maybe(int, int);

maybe_int get_some(int x) {
  return (maybe_int) Some(x);
}

maybe_int return_maybe_zero(maybe_int m) {
  return m if m is Nothing;
  return (maybe_int) Some(0);
}

void print_maybe_int(maybe_int m) {
  match (m) {
    Nothing => { printf("Nothing\n"); },
    Some(x) => { printf("Some(%d)\n", x); },
  }
}

int main() {
  maybe_int m = get_some(5);
  print_maybe_int(m);
  print_maybe_int((maybe_int) Nothing);
  print_maybe_int(get_some(2));

  maybe_int n = return_maybe_zero(m);

  if (n is Nothing)
    puts("n is Nothing");

  if (n is Some)
    puts("n is Something");

  printf("n = ");
  print_maybe_int(n);

  return 0;
}
