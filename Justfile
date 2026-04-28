build: build-release

build-release:
    mkdir -p cmake-build
    cmake -DCMAKE_BUILD_TYPE=Release -S . -B cmake-build
    cmake --build cmake-build --parallel

build-debug:
    mkdir -p cmake-debug
    cmake -DCMAKE_BUILD_TYPE=Debug -S . -B cmake-debug
    cmake --build cmake-debug --parallel

test: test-unit test-som

test-som: build-release
    cmake-build/SOM++ -cp Smalltalk TestSuite/TestHarness.som

test-unit: build-debug
    cmake-debug/unittests -cp Smalltalk:TestSuite/BasicInterpreterTests Examples/Hello.som

hello: build-release
    cmake-build/SOM++ -cp Smalltalk Examples/Hello.som

clean:
    rm -rf cmake-build cmake-debug
