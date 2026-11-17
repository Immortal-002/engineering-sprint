# DAY 2 — C FUNDAMENTALS
## Quick Revision Notes

### 1. C PROGRAM STRUCTURE

**Remember: D → D → U → I**

- Declaration: tells compiler what exists.
- Definition: provides implementation or defines an object.
- Header (`.h`): interfaces, declarations, types, macros.
- Source (`.c`): implementations.

Example:
```c
// math.h
int add(int a, int b);  // Declaration

// math.c
int add(int a, int b) { // Definition
    return a + b;
}
```

### 2. COMPILATION PIPELINE

**Remember: P → C → A → L**

1. Preprocessor: expands macros, includes headers, handles directives.
2. Compiler: analysis, optimisation, generates assembly.
3. Assembler: assembly → object file (`.o`).
4. Linker: resolves symbols and relocations, produces executable.

Important:
- Header declarations help compilation.
- Object files contain machine code, symbols and relocation information.
- Linker works with object files and libraries, not C source files.
- `U` = undefined symbol.
- `T` = symbol defined in text section.

Commands:
```bash
gcc -E main.c           # Preprocessed output
gcc -S main.c           # Assembly
gcc -c main.c           # Object file
gcc main.o math.o -o app # Link
nm main.o               # Inspect symbols
```

### 3. TRANSLATION UNITS & MULTI-FILE PROGRAMS

**Translation unit = preprocessed source file + included header contents.**

Typical structure:
```text
project/
├── main.c
├── math.c
└── math.h
```

- Each `.c` file is compiled separately.
- Each produces an object file.
- Linker combines the object files.
- `-c` means compile and assemble, but don't link.
- Separate compilation enables incremental builds.

**Why headers?** So different source files can know each other's interfaces without seeing their implementations.

### 4. SCOPE vs LINKAGE vs STORAGE DURATION

**Remember: S → L → D**

| Concept | Ask yourself |
|---|---|
| Scope | Where can I access the name? |
| Linkage | Can different declarations refer to the same entity? |
| Storage duration | How long does the object exist? |

Four storage durations in C:

1. Automatic: associated with block execution.
2. Static: entire program execution.
3. Thread: entire thread execution.
4. Allocated: from allocation until deallocation.

### 5. STATIC, EXTERN & CONST

**STATIC — context matters**

| Declaration | Scope | Linkage | Duration |
|---|---|---|---|
| `static int x;` at file scope | File | Internal | Static |
| `static int x;` inside function | Block | None | Static |
| `int x;` inside function | Block | None | Automatic |
| `int x;` at file scope | File | External | Static |

Remember:

- File-scope `static` = private to translation unit.
- Block-scope `static` = local name, persistent object.
- Both have static storage duration.

**EXTERN**

```c
extern int counter;
```

Declares an externally linked object in the usual cross-file case. Does not itself define or initialise the object.

```c
int counter = 10;
```

Definition.

**CONST**

```c
const int *p;       // Cannot modify value through p
int * const p = 0;  // Cannot change p itself
const int * const p = 0; // Neither
```

Important: `const` in C does NOT automatically make an integer a compile-time constant expression.

### 6. POINTERS

**Remember: & = address, * = dereference**

```c
int x = 100;
int *ptr = &x;
```

- `x` = value.
- `&x` = address.
- `ptr` = stored address.
- `*ptr` = value at that address.

```c
*ptr = 200;
```

Changes the original `x`.

Pointer type determines how the pointed-to object is interpreted and how pointer arithmetic works.

### 7. ARRAYS vs POINTERS

**Array ≠ Pointer**

```c
int arr[4] = {10, 20, 30, 40};
int *ptr = arr;
```

- Array = collection of contiguous elements.
- Pointer = separate object holding an address.
- Array often decays into pointer to first element.
- Array does not decay in contexts such as `sizeof(arr)` and `&arr`.

```c
sizeof(arr); // Entire array size
sizeof(ptr); // Pointer object size
```

Array indexing:

```c
arr[2]
```

Equivalent to:

```c
*(arr + 2)
```

### 8. POINTER ARITHMETIC

```c
int arr[] = {10, 20, 30};
int *p = arr;

p++;
```

Pointer advances by `sizeof(int)` bytes, not necessarily one byte.

Rules:
- Arithmetic within the same array is permitted.
- One-past-the-end pointer can be formed.
- One-past-the-end pointer cannot be dereferenced.
- Accessing outside valid bounds causes undefined behaviour.

### 9. ARRAYS IN FUNCTIONS

```c
void process(int arr[], int size);
```

Equivalent parameter declaration:

```c
void process(int *arr, int size);
```

Function parameters declared as arrays are adjusted to pointers.

Therefore, pass array length separately.

Common systems API pattern:

```c
void process(const unsigned char *data, size_t length);
```

Pointer = starting address. Length = available bytes.

### 10. STRINGS IN C

C strings = character arrays terminated by `\0`.

```c
char name[] = "HELLO";
```

Actual contents:

`H E L L O \0`

```c
sizeof(name); // 6
strlen(name); // 5
```

- `sizeof` = total array size in bytes.
- `strlen` = characters before null terminator.
- String literals must not be modified.

### 11. POINTER TO POINTER

```c
int x = 100;
int *ptr = &x;
int **pptr = &ptr;
```

- `x` = integer.
- `ptr` = pointer to integer.
- `pptr` = pointer to pointer.

```c
**pptr = 500;
```

Changes `x` to 500.

Used for modifying pointers through functions, dynamic data structures and output parameters.

---

## FINAL MEMORY MAP

| Topic | Remember this |
|---|---|
| Declaration | What exists? |
| Definition | Where is it implemented? |
| Translation unit | Preprocessed source |
| `-c` | Compile without linking |
| Linker | Resolve symbols |
| Scope | Visibility |
| Linkage | Shared identity |
| Storage duration | Lifetime |
| File `static` | Internal linkage |
| Block `static` | Persistent local object |
| `extern` | External declaration |
| `const` | Restricts modification |
| Pointer | Holds an address |
| `&` | Address-of |
| `*` | Dereference |
| Array | Contiguous elements |
| Array decay | Array → pointer to first element |
| Pointer arithmetic | Moves by element size |
| C string | Null-terminated characters |
| `int **` | Pointer to pointer |

## WHAT WE HAVE NOT COVERED YET

- Structures and unions in practical C programs.
- Function pointers.
- `malloc`, `calloc`, `realloc`, `free`.
- Memory ownership and allocation failures.
- Buffer overflows and undefined behaviour.
- ELF inspection and Linux process startup.
- GDB and sanitizer-based debugging.

**Day 2 central takeaway:**

Understand how C code is organised, compiled, linked, and how data is represented and accessed through memory. Don't just memorise syntax; understand the relationship between source files, symbols, objects, addresses and lifetimes.
