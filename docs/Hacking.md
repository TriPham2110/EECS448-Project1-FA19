
# Table of Contents

1.  [GUI Class Design](#orgdde1f43)



<a id="orgdde1f43"></a>

# GUI Class Design

Each class in the `BattleShip` GUI extends some GTK widget, encapsulating all
of the abilities of the parent widget while giving the developer the option to
add custom functionality or wrap bootstrapping logic in custom functions, two
abilities of which extensive advantage was taken.

Each class declaration =#include=s the parent GTK class and contains forward
declarations of subordinate components of the GUI; this is meant to keep the
`#include` logic as simple as possible, both for the preprocessor (smaller end
code size) and for the developer from an extensibility standpoint. Minimal
=#include=s in the class headers themselves provide greater flexibility to
developers wishing to extend the GUI functionality.

A map of the GUI classes is as follows:

          executive
              \
              \
              \
              v
           window
              \
              \
              \
              v
         gui container
            /  \
           /    \
          /      \
         /        \
    play field  menu bar (contains GTK buttons)
