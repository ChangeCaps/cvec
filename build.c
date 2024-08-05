#include <lute/lute.h>

void build(Build *build) {
    Target *lib = target(build, "cvec", HEADER);
    include(lib, "include");

    Target *test = target(build, "test", BINARY);

    source(test, "test");
    include(test, "include");
}
