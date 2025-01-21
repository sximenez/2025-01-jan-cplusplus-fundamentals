# Foundational C++

Source: [HackerRank](https://www.hackerrank.com/domains/cpp)

Resources: [cplusplus.com](https://cplusplus.com/reference/)

## Table of contents

<!--TOC-->
  - [Basics](#basics)
  - [Type safety](#type-safety)
  - [Memory](#memory)
    - [Pointers](#pointers)
  - [Data types](#data-types)
    - [Dynamic arrays (vectors)](#dynamic-arrays-vectors)
    - [Dictionaries (maps)](#dictionaries-maps)
  - [Loops](#loops)
    - [For](#for)
  - [Function overloading](#function-overloading)
<!--/TOC-->

## Basics

`stdin` is the app input source, usually the keyboard.

`stdout` is the app output destination, usually the console.

`cin` is a C++ object, reading `stdin` character by character.

`cout` is another C++ object, outputting to the destination.

## Type safety

`C++` introduces type safety vs `C`:

```csharp
cout<<"Hello, world!"; // C++ uses the << overloaded operator to deduce type.
printf("%s", "Hello, world!"); // C requires explicit specifiers to define type.
```

However, if performance is a priority, using `C` syntax will provide more efficiency (lower-level language).

## Memory

As opposed to `C#`, `C++` doesn't have garbage collectors that automatically manage memory allocation and prevent memory leaks.

As a result, `*` and `&` operators are needed to handle heap memory references.

### Pointers

```csharp
void update(int *a,int *b); // As opposed to C#, C++ uses a single-pass compiler, 
// meaning that any call to a function has to happen after the function has been 
// declared; otherwise the compiler fails.

int main() {
    int a, b; // Variables.
    int *pa = &a, *pb = &b; // Assignment of pointers to the addresses in memory of the variables.
    
    scanf("%d %d", &a, &b); // Input iteration and value storage at the addresses.
    update(pa, pb); // Pointers to stored values passed as arguments.
    printf("%d\n%d", a, b);

    return 0;
}

void update(int *a,int *b) {
    *a = *a + *b; // Using * again allows to dereference the pointer, 
    // access the value and modify it.

    int c = abs(*a - *b); // A temp calculation is needed to avoid changing the value of b.
    *b = c;
}
```

## Data types

### Dynamic arrays (vectors)

```csharp
int main() {
    int a; // Variable.
    cin >> a; // First input stored in a.
    
    vector<int> arr(a); // Non-const array.
    int b; // Placeholder variable.
    
    for(int i = a - 1; cin >> b; i--) {
        arr[i] = b;
    }
    
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
```

```csharp
int main() {
    string input = "2 2\n3 1 5 4\n5 1 2 8 9 3\n0 1\n1 3";
    istringstream cin(input);

    int arrays;
    int queries;

    cin >> arrays >> queries;
    vector<vector<int>> arrayOfArrays; // Nesting arrays.

    for (int i = 0; i < arrays; i++) {
        int arraySize;
        cin >> arraySize;
        vector<int> innerArray;

        for (int j = 0; j < arraySize; j++) {
            int innerValue;
            cin >> innerValue;
            innerArray.push_back(innerValue); // Populating an array.
        }
        arrayOfArrays.push_back(innerArray);
    }

    for (int i = 0; i < queries; i++) {
        int targetArray;
        int targetIndex;
        cin >> targetArray >> targetIndex;

        int result = arrayOfArrays[targetArray][targetIndex];
        cout << result << endl;
    }

    return 0;
}
```

### Dictionaries (maps)

`unordered_map` is the equivalent of a C# key-value pair dictionary:

```csharp
unordered_map<int, string> mappedValues;
    
mappedValues[1] = "one";
mappedValues[2] = "two";
mappedValues[3] = "three";
mappedValues[4] = "four";
mappedValues[5] = "five";
mappedValues[6] = "six";
mappedValues[7] = "seven";
mappedValues[8] = "eight";
mappedValues[9] = "nine";
```

`map` is the equivalent of a `SortedDictionary<TKey, TValue>`.

## Loops

### For

```csharp
int main() {
    unordered_map<int, string> mappedValues;
    
    mappedValues[1] = "one";
    mappedValues[2] = "two";
    mappedValues[3] = "three";
    mappedValues[4] = "four";
    mappedValues[5] = "five";
    mappedValues[6] = "six";
    mappedValues[7] = "seven";
    mappedValues[8] = "eight";
    mappedValues[9] = "nine";

    int a;
    int b;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9) {
            cout << mappedValues[i] << endl;
        } else {
            if (i % 2 == 0) {
                cout << "even" << endl;
            } else {
                cout << "odd" << endl;
            }
        }
    }

    return 0;
}
```

## Function overloading

```csharp
class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
        return first_name_;
    }
    const string& get_last_name() const {
        return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};

// Overloarding the << only for the Person class output.
// & locks to the original object, and doesn't make copies (heap vs stack).
ostream& operator<<(ostream& os, const Person& person) {
    os << person.get_first_name() << " " << person.get_last_name();
    return os;
}

int main() {
    string input = "hello world";
    istringstream cin(input);
    
    string first_name, last_name;
    cin >> first_name >> last_name;
    auto p = Person(first_name, last_name);
    cout << p.get_first_name() << endl; // Output: hello
    cout << p << endl;                  // Output: hello world
    return 0;
}
```
