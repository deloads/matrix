# Matrix

This matrix is a simple C++ implementation that lets you create, fill, and read a 2D grid.

## How to use the matrix

```cpp
#include <iostream>
#include "matrix.hpp"

int main()
{
    Matrix<int> matrix;

    matrix.setSize({10, 10});
    matrix.set({3, 3}, 1);

    std::cout << "Value at (3,3): " << matrix.get({3, 3}) << '\n';

    return 0;
}
```

## Printing the matrix

```cpp
for (int y = 0; y < matrix.size.y; ++y)
{
    for (int x = 0; x < matrix.size.x; ++x)
    {
        std::cout << matrix.get({x, y}) << ' ';
    }
    std::cout << '\n';
}
```

## Notes

- `setSize({w, h})` makes the matrix larger or smaller.
- `set({x, y}, value)` stores a value at a position.
- `get({x, y})` reads the value back.
- The matrix grows automatically when you write outside the current size.


