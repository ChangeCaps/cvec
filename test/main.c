#include <assert.h>

#include <cvec/cvec.h>

int main() {
    // test vec_new
    Vec(int) v = vec_new();
    assert(v.len == 0);

    // test vec_push
    vec_push(&v, 1);
    assert(v.len == 1);
    assert(v.data[0] == 1);

    // test vec_pop
    int *p = vec_pop(&v);
    assert(*p == 1);
    assert(!vec_pop(&v));
    assert(v.len == 0);

    vec_push(&v, 1);
    vec_push(&v, 2);

    // test vec_for
    int sum = 0;
    vec_for(&v, i) { sum += i; }
    assert(sum == 3);

    // test vec_for_each
    sum = 0;
    vec_for_each(&v, i) { sum += *i; };
    assert(sum == 3);

    // test vec_copy
    Vec(int) v2 = vec_new();
    vec_copy(&v2, &v);

    assert(v2.len == 2);
    assert(v2.data[0] == 1);
    assert(v2.data[1] == 2);
}
