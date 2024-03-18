
Now, what is the actual point of the exercise? You have to determine in what case
it’s better to allocate the zombies on the stack or heap


1. **Zombies Created on the Heap**
   - **Creation Process:** Zombies are created on the heap using the `new` keyword. This process is encapsulated within the `newZombie` function. Here, a Zombie object is dynamically allocated on the heap and its pointer is returned.
   - **Example from `main.cpp`:** The main function demonstrates this process by calling `newZombie(name)`, which allocates a new Zombie named "Alfred_the_Zombie" on the heap and returns a pointer to it. This pointer is stored in `pointer_to_alfred`. The dynamically allocated Zombie is later manually deleted using `delete pointer_to_alfred;` to avoid memory leaks.

2. **Zombies Created on the Stack**
   - **Creation Process:** Zombies are also created on the stack, which is done directly within a function's scope without using `new`. The lifetime of these stack-allocated objects is limited to the block of code in which they are defined.
   - **Example from `main.cpp` and `randomChump.cpp`:** The `randomChump` function exemplifies this by creating a Zombie object named "Bernard_the_Zombie" on the stack. Inside `randomChump`, a Zombie object `oneZombie` is instantiated with the provided name, and its `announce` method is called. When `randomChump` is invoked in main, it creates "Bernard_the_Zombie" on the stack. Once `randomChump` completes execution, the stack-allocated Zombie is automatically destroyed.

**Summary**
- **Heap Zombies:** Created dynamically with `new` inside the `newZombie` function, requiring explicit deletion to free memory.
- **Stack Zombies:** Instantiated within the `randomChump` function's scope, automatically destroyed when the function's execution ends, demonstrating automatic memory management characteristic of stack allocation.




Constructors and Destructors: When you allocate memory for an object using new, it not only allocates memory but also calls the constructor of the object's class. This means the object is both allocated and initialized. Similarly, when you deallocate an object using delete, it calls the object's destructor before freeing the memory. This ensures that any cleanup required for the object is performed properly.

Example:

MyClass* obj = new MyClass(); // Allocates memory and calls MyClass constructor
delete obj; // Calls MyClass destructor and then frees memory


malloc
No Constructors or Destructors: In contrast, malloc is a C-style memory allocation function that is also available in C++. It simply allocates a block of memory of the specified size but does not call any constructors. When you free memory allocated with malloc using free, it also does not call any destructors. This means if you use malloc to allocate memory for an object, you must manually call the constructor (e.g., using placement new), and similarly, you must manually call the destructor if necessary before freeing the memory.

https://github.com/achrafelkhnissi/CPP_Modules/blob/master/Module_01/README.md