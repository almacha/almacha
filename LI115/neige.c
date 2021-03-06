// Programme ecrit par Raphael CHAMPEIMONT

#include <cini.h>

#define WIN_W 500
#define WIN_H 300

int main() {
	int x, y, i, nx;
	CINI_open_window(WIN_W, WIN_H, "neige");

	// Quelques obstacles :
	CINI_draw_line(100, 30, 200, 30, "blue");
	CINI_draw_line(300, 40, 320, 20, "red");
	CINI_draw_line(300+1, 40, 320+1, 20, "red");
	CINI_draw_line(320, 20, 340, 40, "red");
	CINI_draw_line(320+1, 20, 340+1, 40, "red");

	while (true) {
		// Creation de la neige
		for (i=0; i<10; i++) {
			CINI_draw_pixel_rgb(CINI_random(0, WIN_W-1), 0, 255, 255, 255);
		}

		// Chute de la neige
		for (y=WIN_H-2; y>=0; y--) {
			for (x=0; x<WIN_W; x++) {
				// La case contient-elle un flocon ?
				if (CINI_check_pixel_color_rgb(x, y, 255, 255, 255)) {
					// Le flocon tombe vers le bas soit a gauche, a droite ou au milieu.
					nx = x + CINI_random(-1, 1);
					if (nx < 0)
						nx = 0;
					if (nx >= WIN_W)
						nx = WIN_W - 1;
					// Est-ce que le flocon est bloque par quelque chose ?
					if (y+1 < WIN_H && CINI_check_pixel_color_rgb(nx, y+1, 0, 0, 0)) {
						// on deplace le flocon
						CINI_draw_pixel_rgb(x, y, 0, 0, 0);
						CINI_draw_pixel_rgb(nx, y+1, 255, 255, 255);
					}
				}
			}
		}

		// Pour quitter des qu'on appuie sur une touche
		// et actualiser l'affichage.
		if (CINI_key_down()) {
			exit(0);
		}
	}
	return 0;
}
