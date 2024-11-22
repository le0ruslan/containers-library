# S21 Containers Library

## Overview

The **S21 Containers Library** is a custom implementation of fundamental C++ Standard Template Library (STL) container classes. It includes classes such as `list`, `map`, `queue`, `set`, `stack`, `vector`, and more, implemented as header files with templates. This project demonstrates an understanding of template programming, memory management, and data structure design in modern C++ (C++17).

## Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation and Setup](#installation-and-setup)
4. [Usage](#usage)
5. [Implemented Containers](#implemented-containers)
6. [Bonus Features](#bonus-features)
7. [Testing](#testing)
8. [Requirements](#requirements)
9. [License](#license)

---

## Introduction

The S21 Containers Library was inspired by the need to create efficient and reusable components for handling data structures. The library is implemented within the `s21` namespace and mirrors the functionality of STL, adhering to its principles of memory safety and behavior.

This project is divided into three parts:
- **Part 1:** Core container classes (`list`, `map`, `queue`, `set`, `stack`, `vector`).
- **Part 2:** Additional container classes (`array`, `multiset`).
- **Part 3:** Enhanced functionality via `insert_many` methods for bulk data manipulation.

---

## Features

- **Standard container operations** such as insertion, deletion, traversal, and access.
- **Iterators** for seamless data access and manipulation.
- **Custom memory handling** and dynamic allocation.
- **Header-only implementation** for easy integration.
- **Templated classes** for type-agnostic behavior.
- **Bonus Features**: Extended container support and bulk insertion methods.

---

## Installation and Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/le0ruslan/containers-library.git
   cd containers-library
    ```

2. Navigate to the source directory:
   ```bash
    cd src
    ```

3. Build the library and run tests using the provided Makefile:
   ```bash
    make test
    ```

4. Generate a coverage report (if desired):
   ```bash
    make gcov_report
    ```
   
---


## Usage

To use the library, include the necessary headers in your project:
   ```cpp
#include "s21_containers.h"

int main() {
    s21::list<int> my_list;
    my_list.push_back(10);
    my_list.push_back(20);

    for (auto it = my_list.begin(); it != my_list.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}

   ```

Compile your project using a C++17 compatible compiler (e.g., GCC):
   ```bash
    g++ -std=c++17 -o my_project main.cpp
   ```

---

## Implemented Containers
### Core Containers

* #### List (`s21::list`)

  * Doubly linked list implementation.
  * Full iterator support.
  * Efficient insertion and deletion.

* #### Vector (`s21::vector`)

  * Dynamic array with random access.
  * Supports resizing and capacity management.

* #### Stack (`s21::stack`)

  * LIFO data structure.
  * Built using s21::list.

* #### Queue (`s21::queue`)
  * FIFO data structure.
  * Built using s21::list.

* #### Map (`s21::map`)

    * Associative container for key-value pairs.
    * Implements balanced binary search trees.

* #### Set (s21::set)

    * Stores unique keys in sorted order.
    * Implements balanced binary search trees.

### Bonus Containers
* #### Array (s21::array)
    * Fixed-size array with STL-like behavior.

* #### Multiset (s21::multiset)
  * Stores sorted, non-unique elements.

---

## Bonus Features
### Bulk Insertion Methods

| Modifiers      | Definition                                      | Applicable Containers |
|----------------|-------------------------------------------------| -------------------------------------------|
| `iterator insert_many(const_iterator pos, Args&&... args)`          | Inserts multiple elements at a specific position.  | List, Vector. |
| `void insert_many_back(Args&&... args)`          | Appends multiple elements to the end.  | List, Vector, Queue. |
| `void insert_many_front(Args&&... args)`          | Appends multiple elements to the front.  | List, Stack. |
| `vector<std::pair<iterator,bool>> insert_many(Args&&... args)`          | Inserts multiple key-value pairs.  | Map, Set, Multiset. |

##### Example:
```cpp
s21::list<int> numbers;
numbers.insert_many(numbers.begin(), 1, 2, 3, 4);
```

---

## Testing
The library includes comprehensive unit tests using the GTest framework to ensure the correctness of each container's implementation.

To run tests:
```bash
  make test
```

To view coverage:
```bash
  make gcov_report
```

Test cases cover:
* Constructor behavior.
* Element insertion and deletion.
* Iterator functionality.
* Edge cases and boundary conditions.