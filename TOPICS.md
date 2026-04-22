# C++ Topics

## Covered
- Header files and include paths (`#include` with `""` vs `<>`, `target_include_directories`)
- Include guards (`#ifndef` / `#define` / `#endif`)
- Classes and structs (constructors, destructors, public/private)
- Pointers and dynamic memory (`new`, `delete`, dangling pointers)
- Single linked list (append, prepend, delete, traversal, deep copy)
- Binary search tree (interface design, stub implementation)
- Build tooling (CMake, Conan, Google Test, `compile_commands.json`)
- Google Test basics (`TEST`, `EXPECT_EQ`, `DISABLED_` prefix)

## Up Next
- Memory management with RAII and smart pointers (`std::unique_ptr`, `std::shared_ptr`)
- Rule of Three / Rule of Five (copy constructor, copy assignment, move semantics)
- Templates and generics (making data structures work with any type)
- Iterators (range-based for loops over custom containers)
- Standard library containers and algorithms (`std::vector`, `std::map`, `std::sort`)
- Recursion patterns (tree traversals, divide and conquer)
- References vs pointers (`&` vs `*`)
- `const` correctness (const methods, const references, const pointers)

Jared Notes:
- C++ Primer Book for learning
- We can find modern C++ patterns in GFX bc of third party libraries, also look at Firefox source docs to find which versions they're using. Maybe ask Firefox Developers in Matrix.
- xpcom in source docs: https://firefox-source-docs.mozilla.org/xpcom/stringguide.html
- Consider asking Claude to make a mach plugin for gtest pretty. Look for mach docs on firefox source: https://firefox-source-docs.mozilla.org/mach/index.html 

