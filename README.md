## coroutine-scheduler

Cooperative multitasking: coroutines + scheduler.

    mkdir build && cd build
    cmake ..
    cmake --build .
    ./main

With [Nix](https://nixos.org/nix/):

    nix-shell --pure --run 'mkdir build && cd build && cmake .. && cmake --build .'
    ./build/main

## Resources

- [Boost.Coroutine](http://www.boost.org/doc/libs/1_60_0/libs/coroutine/doc/html/index.html)
- [Boost.Fiber](https://olk.github.io/libs/fiber/doc/html/)


## License

Copyright © 2016 Daniel J. Hofmann

Distributed under the MIT License (MIT).
