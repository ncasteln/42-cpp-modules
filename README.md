# 42-cpp-modules

42 Heilbronn school projects about learning CPP.

## Subject
The goal of these modules is to learn C++ in a practical way. Like any other project at 42, we learn-by-doing. Each exercise has its own specific topic and requirements. You'll find those requirements inside each module folder.

## Brief explanation
The project covers the following topics about CPP:

### 0. CPP basics
We started from the basics about the [C++98 standard](https://cplusplus.com/doc/oldtutorial/). The first modules are simply a practice about classes definition and implementation, constants qualification, operator overloading and basic input/output operations. 

### 1. Object-Oriented Programming
During the modules we learn the basics about Object-Oriented Programming: encapsulation, inheritance, polymorphism and abstraction. For example in the [module_03](./cpp_03/) we leanred how to "solve" the so cllaed *diamond problem* about multiple inheritance.

### 2. Try Catch & exceptions
Coming from C programming, this is a new and quite useful feature which comes with C++. In the [module_05](./cpp_05/) we learned how to use the *try catch* statement and how to handle exceptions. Error handling has never been easier.

### 3. Type casting
The [module_06](./cpp_06/) is about [type casting](https://cplusplus.com/doc/oldtutorial/typecasting/): static_cast, dynamic_cast and reinterpret_cast in action.

### 4. Template
Another very important feature about C++ are the [template functions and classes](https://cplusplus.com/doc/oldtutorial/templates/). In the [module_07](./cpp_07/) and [_08](./cpp_08/) we learn this new concept by applying it into mini-projects like the creation of a [Mutant stack](./cpp_08/ex02/).

### 5. Containers
In the last modules, in particular in the [module_08](./cpp_08/) and [_09](./cpp_09/) we learned the *Standard Template Library* along with the [algorithm](https://cplusplus.com/reference/algorithm/) header and the C++98 [containers](https://cplusplus.com/reference/stl/). A relevant project is the last one about the implementation of the [merge-insertion sort](https://en.wikipedia.org/wiki/Merge-insertion_sort) algorithm using 2 different containers (since we had to measure the speed) and template classes.

### 4. Leaks free
Like in any other project of 42, the memory allocated by has to be properly freed. No leaks are tolerated during evaluation. In this modules I used [valgrind](https://valgrind.org/) to check eventual memory leaks and memory inconsistences.
