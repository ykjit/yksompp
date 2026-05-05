# Yk-enabled SOM++

SOM++ with the Yk meta-tracing JIT retrofitted.

## Build

Make sure to set the path to `yk_config` in [justfile](./justfile)

### Plain (no JIT)

```shell
just build          # release build → cmake-build/SOM++
just build-debug    # debug build   → cmake-debug/SOM++
```

### With Yk JIT

```shell
just build-yk         # Yk debug build   → cmake-yk/SOM++
just build-yk-release # Yk release build → cmake-yk/SOM++
```

## Run

```shell
# Plain
cmake-build/SOM++ -cp Smalltalk Examples/Hello.som

# With Yk JIT
cmake-yk/SOM++ -cp Smalltalk Examples/Hello.som
```

## Test

```shell
just test          # unit tests + SOM test suite (plain)
just test-som      # SOM test suite only (plain)
just test-yk       # SOM test suite under Yk JIT
```

## Benchmarks

```shell
just awfy          # Are-We-Fast-Yet benchmarks (plain)
just awfy-compare  # AWFY benchmarks: plain vs Yk side-by-side
```

## Clean

```shell
just clean   # remove cmake-build, cmake-debug, cmake-yk
```
