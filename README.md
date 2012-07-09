gkcrack
=======

GNOME Keyring cracker

1. Put your .keyring files in ~/.gnome2/keyrings

2. Compile gkcrack ```gcc `pkg-config --cflags --libs gnome-keyring-1` gkcrack.c -o gkcrack```

3. ```cat ~/magnum-jumbo/run/password.lst  | ./gkcrack <keyring name>```

Speed: 290 to 350 passwords / second on i3-2120 CPU @ 3.30GHz (using single core).