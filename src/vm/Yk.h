#pragma once

// This header is a thin C++-compatibility shim around the upstream <yk.h>
// C API (ykcapi library).  Include this file instead of <yk.h> directly
// anywhere in the C++ codebase.
//
// Two incompatibilities in <yk.h> must be papered over:
//
//   1. `restrict` keyword — valid in C99 but not in the C++ standard.
//      Clang accepts `__restrict` as an extension in both languages, so we
//      redefine `restrict` → `__restrict` for the duration of the include and
//      then undefine it to avoid polluting the rest of the translation unit.
//
//   2. Missing `extern "C"` linkage guards — without them the C++ compiler
//      applies name-mangling to every symbol declared in <yk.h> (e.g.
//      `yk_mt_new` becomes `_Z9yk_mt_newPPc`).  The linker then cannot match
//      those mangled names against the plain C symbols exported by ykcapi,
//      causing "undefined symbol" link errors for every Yk API call.
#ifdef __cplusplus
#define restrict __restrict
extern "C" {
#endif
#include <yk.h>
#ifdef __cplusplus
#undef restrict
}
#endif
