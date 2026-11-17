DAY 1 — C++ PROGRAM EXECUTION

1. PROGRAM vs PROCESS
- Program = instructions stored in an executable.
- Process = running instance of a program.
- One program → multiple processes.
- Each process has its own virtual address space.
- Physical memory pages can still be shared.
- Process can contain multiple threads.

2. COMPILATION PIPELINE

Source (.cpp)
    ↓
Preprocessor → Expands headers/macros/directives
    ↓
Compiler → Analyses C++ and generates assembly
    ↓
Assembler → Assembly to machine code (.o)
    ↓
Linker → Resolves symbols + combines object files/libraries
    ↓
Executable (ELF on Linux)

Remember: P → C → A → L

3. COMPILER vs LINKER vs LOADER vs OS
- Compiler: Source → machine-level code.
- Linker: Combines object files, resolves symbols.
- Loader: Prepares executable for execution.
- OS: Manages processes, memory, CPU scheduling and resources.

4. SYMBOLS
- Symbol = named entity represented in compiled code/object metadata.
- U = Undefined reference.
- T = Defined code symbol.
- nm -C file.o → Inspect symbols.
- Missing function definition → Usually linker error, not compiler error.

5. HEADERS vs LIBRARIES
- Header → Declarations, definitions, templates; compile-time information.
- Library → Compiled implementations and/or data.
- Including a header ≠ automatically linking a shared library.

6. ELF
Linux executable/object-file format.

Commands:
- file hello → Identify file type.
- readelf -h hello → ELF header.
- readelf -l hello → Program headers/segments.
- ldd hello → Shared-library dependencies.
- nm -C hello → Symbols.
- objdump -d hello → Disassembly.

Remember:
Sections → Linking/object organisation.
Segments → Loading/execution.

7. WHAT HAPPENS AT ./HELLO?

Shell → fork() → execve() → Kernel loads ELF → Dynamic linker → Runtime startup → main()

- fork() creates a child process.
- execve() replaces the calling process's program image.
- _start is typically the executable entry point.
- Runtime initialisation happens before main().
- main() is not necessarily the first executed function.

8. IMPORTANT DISTINCTIONS
- Compile-time error ≠ Link-time error ≠ Runtime error.
- Process ≠ Thread.
- Virtual memory ≠ Physical memory.
- Header ≠ Library.
- Declaration ≠ Definition.
- Executable ≠ Running process.

9. ENGINEERING CONNECTION
Backend server = Running process + memory + threads + libraries + OS resources.

Understanding execution, memory and resource management helps with debugging, performance and infrastructure reliability.

10. COMMANDS TO REMEMBER

g++ -E file.cpp -o file.i    # Preprocess
g++ -S file.cpp -o file.s    # Assembly
g++ -c file.cpp -o file.o    # Object file
g++ file.o -o app            # Link
g++ -v file.cpp -o app       # Verbose build

DAY 1 STATUS:
- Build pipeline: Studied
- ELF: Practised
- Process execution: Studied
- Symbols/linking experiment: Pending
- Memory management: Not started
- DSA: 2 problems
- Video: Recorded

NEXT: Complete symbol experiment → Variables → Objects → Addresses → Scope → Lifetime.
