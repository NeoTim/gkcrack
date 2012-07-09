gkcrack: gkcrack.c
	gcc `pkg-config --cflags --libs gnome-keyring-1` gkcrack.c -o gkcrack
