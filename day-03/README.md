DAY 3 — SESSION 2 & 3 REVISION
TOPIC: KERNEL, SYSTEM CALLS & INTERRUPTS

1. KERNEL
- Kernel = core component that manages hardware and system resources.
- OS = Kernel + libraries + services + utilities + applications.
- Linux = Kernel; EndeavourOS = Linux distribution.
- Kernel manages processes, memory, filesystems, devices and networking.

2. USER MODE vs KERNEL MODE
- User mode: Restricted execution mode used by normal applications.
- Kernel mode: Privileged mode that allows access to protected system resources.
- CPU enforces privilege restrictions.
- Applications request privileged operations through system calls.

3. KERNEL ARCHITECTURE
- Monolithic kernel: Most core services and drivers run in kernel space.
- Microkernel: Keeps the kernel small; many services run in user space.
- Linux uses a modular monolithic kernel.
- Kernel modules allow functionality (e.g. drivers) to be loaded dynamically.

4. SYSTEM CALLS
- System call = controlled interface through which an application requests a kernel service.
- Examples: read(), write(), open(), close(), fork(), execve(), mmap().
- open() may internally use openat() on Linux.

5. LIBRARY FUNCTION vs SYSTEM CALL
- Library function generally executes in user space.
- System call enters the kernel.
- printf() = library function; formats and buffers output.
- write() = usually a libc wrapper around a system call.
- printf() may eventually call write() to send output.

6. LIBC
- Provides standard C library functions and syscall wrappers.
- Prepares syscall arguments.
- Invokes the syscall mechanism.
- Handles return values and errors (e.g. errno).

7. HOW A SYSTEM CALL WORKS
1. Application requests a kernel operation.
2. Arguments and syscall number are prepared.
3. CPU executes the syscall instruction.
4. CPU transfers control to the kernel.
5. Kernel validates arguments and performs the operation.
6. Result is returned to the application.
7. Execution resumes in user mode.

Linux x86-64 syscall registers:
- rax = syscall number
- rdi = argument 1
- rsi = argument 2
- rdx = argument 3
- r10 = argument 4
- r8  = argument 5
- r9  = argument 6

8. INTERRUPTS, EXCEPTIONS & SYSTEM CALLS
- Interrupt: Usually an asynchronous hardware event.
  Example: Network card signals incoming data.
- Exception: Synchronous event during instruction execution.
  Example: Page fault.
- System call: Intentional request by an application to enter the kernel.

9. MALLOC AND THE KERNEL
- malloc() is a user-space memory allocator.
- It does NOT request memory from the kernel on every call.
- Allocator can reuse previously obtained memory.
- It may request more memory using mechanisms like brk() or mmap().

10. KERNEL VALIDATION
Kernel does not blindly trust application arguments.
It checks things like:
- File descriptor validity.
- File permissions.
- Whether requested operations are allowed.
- Whether user-space memory can be accessed safely.
- Whether arguments are valid.

11. IMPORTANT: WRITE()
- write(fd, buffer, count) requests writing bytes to a file descriptor.
- Successful write() does NOT guarantee all requested bytes were written.
- It can return fewer bytes than requested.
- Robust programs handle partial writes and errors.

REMEMBER:
- Kernel = resource manager.
- User mode = restricted; kernel mode = privileged.
- System call = controlled entry into kernel.
- printf() = library function.
- write() = syscall wrapper.
- malloc() = userspace allocator.
- Interrupt = usually asynchronous.
- Exception = synchronous.
- Never assume write() writes every requested byte.

PRACTICAL PENDING:
- Install strace.
- Trace a small C program.
- Identify write(), mmap(), brk() and other system calls.
- Compare printf() output with an explicit write() call.
