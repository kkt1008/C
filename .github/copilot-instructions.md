# AI Coding Guidelines for Linked List C Project

## Project Overview
This is a simple C program implementing a singly linked list for storing and summing user-input integers. The project uses head and tail pointers for efficient O(1) append operations.

## Key Architectural Patterns

### Linked List Implementation
- **Head/Tail Pointer Pattern**: Use both head and tail pointers for constant-time appends
- **Double Pointer Parameters**: Functions like `AddNumber` take `NODE**` to modify head/tail pointers
- **Memory Management**: Always allocate with `malloc(sizeof(NODE))` and free all nodes in reverse order

Example from `linkedList.c`:
```c
void AddNumber(NODE** pp_head, NODE** pp_tail, int data) {
    if (NULL != *pp_head) {
        (*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE));
        *pp_tail = (*pp_tail)->p_next;
    } else {
        *pp_head = (NODE*)malloc(sizeof(NODE));
        *pp_tail = *pp_head;
    }
    (*pp_tail)->number = data;
    (*pp_tail)->p_next = NULL;
}
```

## Development Workflow

### Building and Running
- **Build System**: Uses VS Code C/C++ Runner extension with gcc
- **Compiler**: MSYS2 MinGW gcc (`C:/msys64/mingw64/bin/gcc.exe`)
- **Output Path**: `build/Release/outRelease`
- **Warnings**: Extensive warning flags enabled (`-Wall`, `-Wextra`, `-Wpedantic`, etc.)

### Debugging
- **Debugger**: gdb with pretty-printing enabled
- **Launch Config**: External console, stops at entry disabled

## Code Conventions

### Naming and Style
- **Struct Naming**: `NODE` for linked list nodes
- **Pointer Naming**: `p_head`, `p_tail`, `p` for node pointers
- **Function Naming**: PascalCase (`AddNumber`)
- **Comments**: Korean language comments explaining logic

### Memory Safety
- **Allocation**: Use `(NODE*)malloc(sizeof(NODE))` with explicit cast
- **Deallocation**: Free nodes in a loop, updating head pointer each time
- **Null Checks**: Always check `NULL != *pp_head` before operations

### Input/Output
- **Termination**: Use sentinel value (9999) for loop exit
- **Formatting**: Print equations with " + " separators and final "=%d\n"

## Common Patterns
- **Traversal**: `NODE* p = p_head; while (NULL != p) { ... p = p->p_next; }`
- **Cleanup**: `while (NULL != p_head) { p = p_head; p_head = p_head->p_next; free(p); }`

## File Structure
- `linkedList.c`: Main implementation with struct, functions, and main loop
- `build/Release/`: Build output directory
- `.vscode/`: VS Code configuration for C/C++ development</content>
<parameter name="filePath">c:\Users\kkt\Documents\VSCode\C\.github\copilot-instructions.md