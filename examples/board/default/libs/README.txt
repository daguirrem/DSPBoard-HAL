Struc Lib Folder:
This folder permits compile a custom extern source libraries.

The struct of lib folder must be the next:
E.g.

-| libs                   [this folder]

  -|custom_lib            [lib folder]
    -|src                 [folder]
      -|source.c          [file]
      -|something.cpp     [file]
      -|other.c           [file]
    -|include             [folder]
      -|source.h          [file]
      -|something.hpp     [file]
      -|other.h           [file]

  -|src                   [lib folder]
      -|source            [folder]
        -| ...            [source file/s]
      -|include           [folder]
        -| ...            [include file/s]
  -|...                   [etc]
