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
  - [Operator overloading](#operator-overloading)
    - [<](#)
    - [Constructors](#constructors)
      - [C++](#c)
      - [C#](#c)
    - [Stringstream](#stringstream)
    - [Const](#const)
<!--/TOC-->

## Basics

`stdin` is the app input source, usually the keyboard.

`stdout` is the app output destination, usually the console.

`cin` is a C++ object, reading `stdin` character by character (character input).

`cout` is another C++ object, outputting to the destination (character output).

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

## Operator overloading

In C++, many predefined functions use operators that can be overloaded to achieve custom results.

### <



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

### Constructors

#### C++
```csharp
// Initialization list: preferred (initialization and assignment in one step).
Message(const string& text, int index) : stored_text_(text), index_(index) {}

// Initialization with constructor body: less efficient
// (initialization, assignment of default values, then assignment).
Message(const string& text, int index) {
    stored_text_ = text;
    index_ = index;
}
```

#### C#
```csharp
// In C#, initialization with constructor body is the preferred and more efficient way.
public Message(string text, int index) {
    storedText = text;
    index = index;
}
```

### Stringstream

```csharp
vector<int> parseInts(string str) {
	vector<int> arr;

    // Allows to use operators like >> on str.
    // Doesn't read char by char, but anything between commas.
    stringstream ss(str);
    
    int temp;
    char comma;
    
    while (ss >> temp) {
        arr.push_back(temp);
        ss >> comma;
    }
    
    return arr;
}
```

### Const

When Not to Use const for the Return Type:
Modifiable Return Value: If you want the caller to be able to modify the returned value, you should not use const for the return type. For example, if you have a method that returns a reference to a member variable that the caller should be able to modify:
std::string& get_first_name() {
    return first_name_;
}

Temporary Objects: If the method returns a temporary object (e.g., a local variable or a computed value), you typically don’t use const for the return type:
std::string get_full_name() {
    return first_name_ + " " + last_name_;
}

When Not to Use const for the Method:
Modifying Member Variables: If the method needs to modify any member variables, it cannot be marked as const. For example, a method that updates the last name:
void set_last_name(const std::string& last_name) {
    last_name_ = last_name;
}

Calling Non-const Methods: If the method needs to call other non-const methods or modify the state of the object, it cannot be marked as const:
void update_name(const std::string& first_name, const std::string& last_name) {
    set_first_name(first_name);
    set_last_name(last_name);
}

name_ (member variable) is the equivalent of a property in C#.

---

1. Using const and & for Efficiency
This is your original example, which uses a const reference to avoid copying the string:

class Message {
public:
    Message(const std::string& text) : stored_text_(text) {}
    const std::string& get_text() const {
        return stored_text_;
    }

private:
    std::string stored_text_;
};

2. Without const and &
This version copies the string, which can be less efficient for large strings:

class Message {
public:
    Message(std::string text) : stored_text_(std::move(text)) {}
    const std::string& get_text() const {
        return stored_text_;
    }

private:
    std::string stored_text_;
};

3. Using const but Without &
This version uses const to ensure the parameter is not modified, but still copies the string:

class Message {
public:
    Message(const std::string text) : stored_text_(text) {}
    const std::string& get_text() const {
        return stored_text_;
    }

private:
    std::string stored_text_;
};

4. Using const and & with a Default Constructor
This version includes a default constructor and a setter method:

class Message {
public:
    Message() = default;
    Message(const std::string& text) : stored_text_(text) {}
    void set_text(const std::string& text) {
        stored_text_ = text;
    }
    const std::string& get_text() const {
        return stored_text_;
    }

private:
    std::string stored_text_;
};

5. Using const and & with a Move Constructor
This version uses a move constructor for efficiency when the string can be moved:

class Message {
public:
    Message(std::string text) : stored_text_(std::move(text)) {}
    const std::string& get_text() const {
        return stored_text_;
    }

private:
    std::string stored_text_;
};

Explanation of const and &:
const: Ensures that the parameter or return value is not modified.
& (Reference): Avoids copying the parameter, which can be more efficient for large objects like strings.
Do these examples help clarify the use of const and &? Let me know if you have more questions!




Vous
Envoyé par vous :
in these same examples, is there a difference between these two const keywords?

const std::string& get_text() const {
Copilot
Génération de vos réponses…

Envoyé par Copilot :
Yes, there is a difference between the two const keywords in the method declaration const std::string& get_text() const.

Breakdown of the const Keywords:
Return Type const:
const std::string& get_text() const {

This const applies to the return type, indicating that the method returns a constant reference to a std::string. This means the caller cannot modify the returned string through this reference.
Method const:
const std::string& get_text() const {

This const at the end of the method declaration indicates that the method is a constant member function. It means that the method does not modify any member variables of the class and can be called on const instances of the class.
Example with Both const Keywords:
class Message {
public:
    Message(const std::string& text) : stored_text_(text) {}
    const std::string& get_text() const {
        return stored_text_;
    }

private:
    std::string stored_text_;
};

Explanation:
Return Type const: Ensures that the caller cannot modify the stored_text_ through the returned reference.
Method const: Ensures that the method does not modify the state of the object, allowing it to be called on const instances of Message.
Example Usage:
const Message msg("Hello, World!");
const std::string& text = msg.get_text();
// text cannot be modified, and msg remains unchanged