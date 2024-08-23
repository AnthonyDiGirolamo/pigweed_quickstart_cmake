## First time setup

```sh
git clone --recursive https://github.com/AnthonyDiGirolamo/pigweed_quickstart_cmake.git
cd pigweed_quickstart_cmake
. ./bootstrap.sh
```

## Building

```sh
cmake -S . -B out -G Ninja --fresh
ninja -C out
```
