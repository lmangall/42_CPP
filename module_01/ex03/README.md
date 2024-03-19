
## HumanA:

### Composition with References
- HumanA incorporates a reference to a `Weapon` as part of its composition. This implies a tight coupling between each `HumanA` object and a specific `Weapon` instance from its inception. The `Weapon` must exist at the time of `HumanA`'s creation and cannot be altered subsequently. This relationship is established through the constructor's member initializer list, showcasing the initialization of reference members.

  ```cpp
  HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) { this->_name = name; }
```

In HumanA's attack method, the weapon is directly utilized:

``` 
```cpp
void HumanA::attack() {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
```

## HumanB:

### Composition with pointers
- Conversely, HumanB utilizes a pointer to a Weapon, offering greater flexibility. A HumanB object can be instantiated without a Weapon and can have its Weapon changed or set to nullptr at any point post-creation. This demonstrates dynamic relationships and illustrates how pointers can facilitate optional or mutable associations.

``` 
  ```cpp
void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}
```

HumanB's attack method verifies the existence of the weapon before employing it:


  ```cpp
  void HumanB::attack() {
    if (_weapon == nullptr)
        std::cout << _name << " attacks without any weapon..." << std::endl;
    else
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
}
```

## Educational Goals:
- Object Composition: Demonstrates how classes can be composed of other classes using references or pointers, illustrating "has-a" relationships.
- Member Initializer Lists: Highlights their application in initializing reference members that necessitate initialization at the object's creation time.
- Dynamic Association vs. Static Association: Contrasts the use of a reference (static, necessitating initialization upon object creation and immutable thereafter) against a pointer (dynamic, amendable post object creation) for object associations.
- Pointer Usage: Advises on the safe utilization of pointers, including nullptr checks before dereferencing, to preempt runtime errors.
- Flexibility in Object Relationships: Reflects on how design choices between employing references or pointers influence the flexibility and functionality of your objects.

This exercise underscores important facets of C++ object-oriented programming, particularly how objects interrelate and the implications of those design decisions on software flexibility and behavior.