#pragma once

struct Vec2
{
    int x = 0;
    int y = 0;

    Vec2() = default;
    Vec2(int x, int y) : x(x), y(y) {}
};

template <typename T>
struct Matrix
{
    Vec2 size = {0, 0};
    Vec2 capacity = {2, 2};
    T* data = nullptr;

    Matrix()
    {
        data = new T[capacity.x * capacity.y]{};

        for (int y = 0; y < capacity.y; ++y)
        {
            for (int x = 0; x < capacity.x; ++x)
            {
                data[y * capacity.x + x] = T();
            }
        }
    }

    ~Matrix()
    {
        delete[] data;
    }

    Vec2 growCapacity(Vec2 required) const
    {
        Vec2 newCapacity = capacity;

        while (required.x >= newCapacity.x)
        {
            newCapacity.x *= 2;
        }

        while (required.y >= newCapacity.y)
        {
            newCapacity.y *= 2;
        }

        return newCapacity;
    }

    void setSize(Vec2 newSize)
    {
        const Vec2 newCapacity = growCapacity(newSize);

        if (newCapacity.x != capacity.x || newCapacity.y != capacity.y)
        {
            T* newData = new T[newCapacity.x * newCapacity.y];

            for (int y = 0; y < size.y; ++y)
            {
                for (int x = 0; x < size.x; ++x)
                {
                    newData[y * newCapacity.x + x] = data[y * capacity.x + x];
                }
            }

            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        size = newSize;
    }

    void checkSize(Vec2 pos)
    {
        Vec2 newSize = size;

        if (pos.x >= size.x)
        {
            newSize.x = pos.x + 1;
        }

        if (pos.y >= size.y)
        {
            newSize.y = pos.y + 1;
        }

        if (newSize.x != size.x || newSize.y != size.y)
        {
            setSize(newSize);
        }
    }

    void set(Vec2 pos, T value)
    {
        checkSize(pos);
        data[pos.y * capacity.x + pos.x] = value;
    }

    T& get(Vec2 pos)
    {
        checkSize(pos);
        return data[pos.y * capacity.x + pos.x];
    }
};
