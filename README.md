# POV
Pointer of void

Signatures:
```cpp
template<typename T>
T square(void*);

template<>
void square(void* num);

// Works: Variant 1
template<typename T = int>
T square(void* num);

// Works: Variant 2
// template<>
// int square(void* num);

template<>
float square(void* num);

template<typename T = void>
T square(void);
```
