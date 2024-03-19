This is the repo to my CPP01 in the docs there are some amazing documentation! https://github.com/552020/CPP01/

In the ex01 you have 3 ways to create the zombie horde: I two versions out of three, using the placement operator (that we will not use in the other exercises).

In ex02 (super easy) the subject is a little bit not precise when they ask you to print the value pointed to by the reference, cause the reference is not pointing to a value the same way a pointer is pointing to something, and eventually it points to something only inside another scope (i.e. when you pass a value in a function by reference and you change that value, that was declared outside the function, inside this function.) In my code you can check the function ’extra changes()’.

In ex03 you’ll discover the initialisation list, or better understand when there is no other way around than use it for the initialisation of memeber attribute. And this case is when you have a constructor that takes as parameter a reference. Since the value of a reference can’t be reassigned, you need to assign this value in the initialisation list, cause otherwise a default value would be assigned to the reference, and you can’t change the value in the body of the constructor. Otherwise for normal values, you can also decide to set the value passed in the constructor for your member attribute in the body of the. constructor. This value would get first a default value and the it will get reassign.

ex04 is just about file manipulation and strings.

ex05 pointer to member function, which we will use also in the future.

ex06 is pretty easy and the switch statement is introduced: I used in a pretty wrong way, cause the when you enter a case also the ‘cases below’ get executed if you don’t put a break keyword.