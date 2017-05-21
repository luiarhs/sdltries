#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define WIDTH 1024	  // Definimos el ancho, alto de pantalla y el número de bits por píxel
#define HEIGHT 640

typedef struct nodo{
	int palabras;
	int prefijos;
	struct nodo *nodos[3];
}TRIE;
typedef TRIE *PNODO;

//Funciones...
SDL_Surface *inicializa( );//Inicializa modo grafico
void SDL_Loadimg();//Carga imagenes
void SDL_Loadfnt();//Carga fuentes
void SDL_Loadaudio();//Carga y reproduce audio
void SDL_Mario();//Movimientos mario
void SDL_Nodos(char pal[]);//
void SDL_Imprime(char *c, int x, int y, SDL_Color color, TTF_Font *fuente[0]);
void SDL_insertar(TRIE *r, char *pal);
void SDL_inicializar(TRIE *r);
int SDL_numpalabras(TRIE r, char *pal);
int SDL_numprefijos(TRIE r, char *pal);
int SDL_totalpalabras(TRIE r);
int SDL_Read(int n);

//Variables globales
int done= 0;
TRIE r;
Uint8 *keys;
TTF_Font *fuente[2];
SDL_Event event;
SDL_Surface *screen=NULL;
SDL_Surface *ttext;
SDL_Surface *mario[4];
SDL_Surface *fondo[5];
SDL_Surface *nodos[3];
SDL_Surface *flechas[6];
SDL_Rect destino, destmario, destnodo;

int main (int argc, char *argv[] ) {

	int i, j;
		destino.x= 0;
		destino.y= 0;
		destnodo.x= (WIDTH/2)-50;
		destnodo.y= 10;
		SDL_Loadimg();//carga todas las imagenes
		SDL_Loadfnt();//carga las fuentes
		screen= inicializa( );//inicializa
		SDL_Mario();
		SDL_Loadaudio();
		SDL_BlitSurface(fondo[3], NULL, screen, &destino);
		SDL_BlitSurface(nodos[1], NULL, screen, &destnodo);
		SDL_Flip(screen);
		done= 0;
		while (done == 0){

			while (SDL_WaitEvent(&event)) {

				if (event.type==SDL_KEYDOWN) {

					switch(event.key.keysym.sym) {

						case SDLK_1:{//insertar
							SDL_Read(1);
							break;
						}
						case SDLK_2:{//busqueda palabra
							SDL_Read(2);
							break;
						}
						case SDLK_3:{//busqueda prefijo
							SDL_Read(3);
							break;
						}
						case SDLK_4:{//salir
							done= 1;
							SDL_BlitSurface(fondo[4], NULL, screen, &destino);
							SDL_Flip(screen);
							SDL_Delay(3000);
							SDL_Quit();
						}
						case SDLK_ESCAPE:
						{
							done= 1;
							SDL_Quit();
						}
					}
				}
			}

			while(SDL_PollEvent(&event)){

		        if(event.type == SDL_QUIT)
					done= 1;
				if(event.type == SDL_KEYDOWN)
					if(event.key.keysym.sym == SDLK_ESCAPE)
						done= 1;
			}
		}


	return 0;
}
void SDL_Nodos(char pal[] ){
	int i;

	SDL_Rect nodo0, nodo1, nodo2, nodo3, nodo4, nodo5, nodo6, nodo7, nodo8, nodo9, nodo10, nodo11, nodo12;

	nodo0.x= 462;	nodo1.x= 120;	nodo2.x= 462;	nodo3.x= 804;	nodo4.x= 14;	nodo5.x= 120;	nodo6.x= 226;
	nodo0.y=  10;	nodo1.y= 160;	nodo2.y=  160;	nodo3.y=  160;	nodo4.y= 300;	nodo5.y= 300;	nodo6.y= 300;

	nodo7.x= 356;	nodo8.x= 462;	nodo9.x= 568;	nodo10.x= 698;	nodo11.x= 804;	nodo12.x= 910;
	nodo7.y= 300;	nodo8.y= 300;	nodo9.y= 300;	nodo10.y= 300;	nodo11.y= 300;	nodo12.y= 300;

	SDL_Rect nodi0,nodi1,nodi2,nodi3,nodi4,nodi5,nodi6,nodi7,nodi8,nodi9,nodi10,nodi11,nodi12,nodi13,nodi14;
    SDL_Rect nodi15,nodi16,nodi17,nodi18,nodi19,nodi20,nodi21,nodi22,nodi23,nodi24,nodi25,nodi26;

    nodi0.x= 14;    nodi1.x= 50;    nodi2.x= 86;    nodi3.x= 122;   nodi4.x= 158;   nodi5.x= 194;    nodi6.x= 230;   nodi7.x= 266;
    nodi0.y= 370;   nodi1.y= 370;   nodi2.y= 370;   nodi3.y= 370;   nodi4.y= 370;   nodi5.y= 370;    nodi6.y= 370;   nodi7.y= 370;

    nodi8.x= 302;   nodi9.x= 356;   nodi10.x= 392;   nodi11.x= 428;   nodi12.x= 464;   nodi13.x= 500;    nodi14.x= 536;   nodi15.x= 572;
    nodi8.y= 370;   nodi9.y= 370;   nodi10.y= 370;   nodi11.y= 370;   nodi12.y= 370;   nodi13.y= 370;    nodi14.y= 370;   nodi15.y= 370;

    nodi16.x= 608;   nodi17.x= 644;   nodi18.x= 698;   nodi19.x= 734;   nodi20.x= 770;   nodi21.x= 806;    nodi22.x= 842;   nodi23.x= 878;
    nodi16.y= 370;   nodi17.y= 370;   nodi18.y= 370;   nodi19.y= 370;   nodi20.y= 370;   nodi21.y= 370;    nodi22.y= 370;   nodi23.y= 370;

    nodi24.x= 914;   nodi25.x= 950;   nodi26.x= 986;
    nodi24.y= 370; 	 nodi25.y= 370;   nodi26.y= 370;

    SDL_Rect flecha0,flecha1,flecha2,flecha3,flecha4,flecha5,flecha6,flecha7,flecha8,flecha9,flecha10,flecha11;

    flecha0.x= 170;   flecha1.x= 507;  flecha2.x= 582;  flecha3.x= 45;  flecha4.x= 165;  flecha5.x=220;  flecha6.x=382; flecha7.x= 507;
    flecha0.y= 60;    flecha1.y= 86;   flecha2.y= 60;   flecha3.y= 200; flecha4.y= 225;  flecha5.y=200;  flecha6.y=200;	flecha7.y= 226;

    flecha8.x= 570;	flecha9.x= 728;	flecha10.x= 846;	flecha11.x= 908;
    flecha8.y= 200;	flecha9.y= 200;	flecha10.y= 226;	flecha11.y= 200;

		if(pal[0] != '\0'){
			//Codigo rama a
			if(pal[0] == 'a'){
				SDL_BlitSurface(nodos[0], NULL, screen, &nodo0);
				SDL_BlitSurface(flechas[0], NULL, screen, &flecha0);
				if(pal[1] == 'a'){
					SDL_BlitSurface(nodos[0], NULL, screen, &nodo1);
					SDL_BlitSurface(flechas[2], NULL, screen, &flecha3);
					if(pal[2] == 'a'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo4);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi0);
					}
					else if(pal[2] == 'b'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo4);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi1);
					}
					else if(pal[2] == 'c'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo4);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi2);
					}
					else
						SDL_BlitSurface(nodos[1], NULL, screen, &nodo4);
				}
				else if(pal[1] == 'b'){
					SDL_BlitSurface(nodos[0], NULL, screen, &nodo1);
					SDL_BlitSurface(flechas[3], NULL, screen, &flecha4);
					if(pal[2] == 'a'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo5);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi3);
					}
					else if(pal[2] == 'b'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo5);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi4);
					}
					else if(pal[2] == 'c'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo5);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi5);
					}
					else
						SDL_BlitSurface(nodos[1], NULL, screen, &nodo5);
				}
				else if(pal[1] == 'c'){
					SDL_BlitSurface(nodos[0], NULL, screen, &nodo1);
					SDL_BlitSurface(flechas[4], NULL, screen, &flecha5);
					if(pal[2] == 'a'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo6);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi6);
					}
					else if(pal[2] == 'b'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo6);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi7);
					}
					else if(pal[2] == 'c'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo6);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi8);
					}
					else
						SDL_BlitSurface(nodos[1], NULL, screen, &nodo6);
				}
				else
					SDL_BlitSurface(nodos[1], NULL, screen, &nodo1);
			}
			//Codigo rama b
			else if(pal[0] == 'b'){
				SDL_BlitSurface(nodos[0], NULL, screen, &nodo0);
				SDL_BlitSurface(flechas[5], NULL, screen, &flecha1);
				if(pal[1] == 'a'){
					SDL_BlitSurface(nodos[0], NULL, screen, &nodo2);
					SDL_BlitSurface(flechas[2], NULL, screen, &flecha6);
					if(pal[2] == 'a'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo7);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi9);
					}
					else if(pal[2] == 'b'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo7);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi10);
					}
					else if(pal[2] == 'c'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo7);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi11);
					}
					else
						SDL_BlitSurface(nodos[1], NULL, screen, &nodo7);
				}
				else if(pal[1] == 'b'){
					SDL_BlitSurface(nodos[0], NULL, screen, &nodo2);
					SDL_BlitSurface(flechas[3], NULL, screen, &flecha7);
					if(pal[2] == 'a'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo8);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi12);
					}
					else if(pal[2] == 'b'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo8);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi13);
					}
					else if(pal[2] == 'c'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo8);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi14);
					}
					else
						SDL_BlitSurface(nodos[1], NULL, screen, &nodo8);
				}
				else if(pal[1] == 'c'){
					SDL_BlitSurface(nodos[0], NULL, screen, &nodo2);
					SDL_BlitSurface(flechas[4], NULL, screen, &flecha8);
					if(pal[2] == 'a'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo9);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi15);
					}
					else if(pal[2] == 'b'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo9);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi16);
					}
					else if(pal[2] == 'c'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo9);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi17);
					}
					else
						SDL_BlitSurface(nodos[1], NULL, screen, &nodo9);
				}
				else
					SDL_BlitSurface(nodos[1], NULL, screen, &nodo1);
			}
			//Codigo rama c
			else if(pal[0] == 'c'){
				SDL_BlitSurface(nodos[0], NULL, screen, &nodo3);
				SDL_BlitSurface(flechas[1], NULL, screen, &flecha2);
				if(pal[1] == 'a'){
					SDL_BlitSurface(nodos[0], NULL, screen, &nodo3);
					SDL_BlitSurface(flechas[2], NULL, screen, &flecha9);
					if(pal[2] == 'a'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo10);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi18);
					}
					else if(pal[2] == 'b'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo10);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi19);
					}
					else if(pal[2] == 'c'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo10);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi20);
					}
					else
						SDL_BlitSurface(nodos[1], NULL, screen, &nodo10);
				}
				else if(pal[1] == 'b'){
					SDL_BlitSurface(nodos[0], NULL, screen, &nodo3);
					SDL_BlitSurface(flechas[3], NULL, screen, &flecha10);
					if(pal[2] == 'a'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo11);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi21);
					}
					else if(pal[2] == 'b'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo11);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi22);
					}
					else if(pal[2] == 'c'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo11);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi23);
					}
					else
						SDL_BlitSurface(nodos[1], NULL, screen, &nodo11);
				}
				else if(pal[1] == 'c'){
					SDL_BlitSurface(nodos[0], NULL, screen, &nodo3);
					SDL_BlitSurface(flechas[4], NULL, screen, &flecha11);
					if(pal[2] == 'a'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo12);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi24);
					}
					else if(pal[2] == 'b'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo12);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi25);
					}
					else if(pal[2] == 'c'){
						SDL_BlitSurface(nodos[0], NULL, screen, &nodo12);
						SDL_BlitSurface(nodos[2], NULL, screen, &nodi26);
					}
					else
						SDL_BlitSurface(nodos[1], NULL, screen, &nodo12);
				}
				else
					SDL_BlitSurface(nodos[1], NULL, screen, &nodo3);
			}
		}
		SDL_Flip(screen);

}
void SDL_insertar(TRIE *r, char *pal){
	static int nivel= 1;
		if(*pal == '\0'){
			r-> palabras++;
			return;
		}
	int i= *pal - 'a';
		r-> prefijos++;
		if(r-> nodos[i] == NULL){
			r-> nodos[i]= (PNODO) malloc (sizeof(TRIE));
			SDL_inicializar(r-> nodos[i]);
		}
		nivel++;
		SDL_insertar(r-> nodos[i], pal+1);
}
int SDL_Read(int n){
	int i= 0;
	char *cad= (char *) malloc (sizeof(char )*4);
	//char cad[4]={0};
	SDL_Color Negro={ 0, 0, 0};

	//while(done == 0){

		//SDL_PollEvent(&event);
		while(SDL_WaitEvent(&event)){
			if(event.type == SDL_KEYDOWN){
				SDL_Rect rellena={865,582,60,25};
				SDL_FillRect(screen, &rellena, SDL_MapRGBA(screen->format,0,200,100,0));
				SDL_Flip(screen);
				switch(event.key.keysym.sym){
					case SDLK_a:
					{
						cad[i++]= 'a';
						cad[i]= '\0';
						break;
					}
					case SDLK_b:
					{
						cad[i++]= 'b';
						cad[i]= '\0';
						break;
					}
					case SDLK_c:
					{
						cad[i++]= 'c';
						cad[i]= '\0';
						break;
					}
					case SDLK_RETURN:
					{
						cad[++i]= '\0';
						if(n == 1){
							SDL_Nodos(cad);
							SDL_insertar( &r, cad);
						}
						else if(n == 2){
							int num= SDL_numpalabras( r, cad);
							char c[10];
							sprintf(c, "%d", num);
							SDL_Imprime( &c[0], 892, 583, Negro, &fuente[0]);
							SDL_Flip(screen);
						}
						else if(n == 3){
							int num= SDL_numprefijos( r, cad);
							char c[10];
							sprintf(c, "%d", num);
							SDL_Imprime( &c[0], 892, 583, Negro, &fuente[0]);
							SDL_Flip(screen);
						}
						done= 1;
						return atoi(cad);
					}

				}
				if(i <= 3){
					SDL_Imprime(&(*cad), 880, 583, Negro, &fuente[0]);
					SDL_Flip(screen);
				}
			}
		//}
	}
	return atoi(cad);
}
void SDL_Imprime(char *cad, int x, int y, SDL_Color Negro, TTF_Font *fuente[0]){
	int w=20, h=20;
	SDL_Rect pos;
    SDL_Surface *letras;
    pos.x= x; pos.y= y;
    TTF_SizeText(fuente[0], cad, &w, &h);
    letras= TTF_RenderText_Shaded(fuente[0], cad, Negro, Negro);
	SDL_SetColorKey(letras, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(letras-> format, 0, 0, 0));
	SDL_BlitSurface(letras, NULL, screen, &pos);
}
void SDL_Mario(){

	int i, j;
		destmario.x= 120;
		destmario.y= 518;
		for(i= 0; i < 46; i++)
			for(j= 0; j < 4; j++){
				SDL_BlitSurface(fondo[0], NULL, screen, &destino);
				SDL_BlitSurface(mario[j], NULL, screen, &destmario);
				SDL_Delay(30);
				SDL_Flip(screen);
				destmario.x += 5;
				if(i >= 10 && i < 18)
					destmario.y -= 4;
				else if(i >= 18 && i < 26)
					destmario.y += 4;
			}
		destmario.x= 10;
		destmario.y= 528;
		for(i= 0; i < 50; i++)
			for(j= 0; j < 4; j++){
				SDL_BlitSurface(fondo[1], NULL, screen, &destino);
				SDL_BlitSurface(mario[j], NULL, screen, &destmario);
				SDL_Delay(30);
				SDL_Flip(screen);
				destmario.x += 5;
				if(i >= 18 && i < 23)
					destmario.y -= 4;
				else if(i >= 24 && i < 29)
					destmario.y += 4;
				if(i >= 36 && i < 42)
					destmario.y -= 4;
				else if(i >= 47 )
					destmario.y += 4;
			}
		destmario.x= 10;
		destmario.y= 532;
		for(i= 0; i < 37; i++)
			for(j= 0; j < 4; j++){
				SDL_BlitSurface(fondo[2], NULL, screen, &destino);
				SDL_BlitSurface(mario[j], NULL, screen, &destmario);
				SDL_Delay(30);
				SDL_Flip(screen);
				destmario.x += 5;
				if(i >= 4 && i < 7)
					destmario.y -= 4;
				else if(i >= 8 && i < 11)
					destmario.y += 4;

			}
		SDL_Delay(4000);

}

void SDL_Loadimg(){
	int i;
	char nombres[15];

	for(i= 0; i < 6; i++){
			sprintf(nombres, "img/flecha%d.bmp", i);
			flechas[i]= IMG_Load(nombres);
			if(flechas[i] == NULL){
				printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
				exit(1);
			}
	}
	for(i= 0; i < 4; i++){
			sprintf(nombres, "img/mario%d.bmp", i);
			mario[i]= IMG_Load(nombres);
			if(mario[i] == NULL){
				printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
				exit(1);
			}
	}
	for(i= 0; i < 4; i++)
		SDL_SetColorKey(mario[i], SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(mario[i] -> format, 255, 255, 255));
	for(i= 0; i < 5; i++){
			sprintf(nombres, "img/fondo%d.bmp", i);
			fondo[i]= IMG_Load(nombres);
			if(fondo[i] == NULL){
				printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
				exit(1);
			}
	}
	for(i= 0; i < 3; i++) {
			sprintf(nombres, "img/nodo%d.bmp", i);
			nodos[i]= IMG_Load(nombres);
			if (nodos[i] == NULL) {
				printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
				exit(1);
			}
	}
}
void SDL_Loadfnt(){

	TTF_Init();
	fuente[0] = TTF_OpenFont("fonts/0.ttf",12);
	fuente[1] = TTF_OpenFont("fonts/1.ttf",18);

	if ( fuente == NULL )
		printf("Error al cargar ttf\n");

}
void SDL_Loadaudio(){
	// Array de todas los archivos de musica que queremos cargar.
	int i, canal;
	char nombres[15];
	Mix_Music *musica[2];
	// Iniciar SDL.
	// Activamos el modo de video.
	// Inicializamos SDL_mixer.
	if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096)) {
		printf("No se puede inicializar SDL_mixer %s\n",Mix_GetError());
		exit(1);
	}
	atexit(Mix_CloseAudio);
	// Cargamos todos los archivos de musica en formato MIDI de la carperta
	// “sounds/”. El nombre de todos los archivos es track1, track2, etc
	for (i= 0; i <= 2; i++) {
		sprintf(nombres, "music/%d.ogg", i);
		musica[i] = Mix_LoadMUS(nombres);
	}
	// Comprobamos si se pudieron cargar los archivos de musica.
	if ( musica == NULL ) {
		printf("No pude cargar musica: %s\n", Mix_GetError());
		exit(1);
	}
	// Reproducción la música.
	// Esta función devuelve el canal por el que se reproduce la música.
	canal = Mix_PlayMusic(*musica, -1);
	// Esperamos la pulsación de una tecla para salir.
	// Paramos la música.
	Mix_HaltMusic();
	// Liberamos recursos de todas los archivos de musica que tenemos en el
	// array de archivos de musica llamado musica.
	for (i=0; i <= 2; i++) {
		Mix_FreeMusic(musica[i]);
	}
}

void SDL_inicializar(TRIE *r){
	int i;
		r-> palabras= 0;
		r-> prefijos= 0;
		for(i= 0; i < 3; i++)
			r-> nodos[i]= NULL;
}

int SDL_numpalabras(TRIE r, char *pal){
	if(*pal == '\0')
		return r.palabras;
	int i= *pal - 'a';
		if(r.nodos[i] == NULL)
			return 0;
	return SDL_numpalabras(*r.nodos[i], pal+1);
}

int SDL_numprefijos(TRIE r, char *pal){
	if(*pal == '\0')
		return r.prefijos;
	int i= *pal - 'a';
		if(r.nodos[i] == NULL)
			return 0;
	return SDL_numprefijos(*r.nodos[i], pal+1);
}

int SDL_totalpalabras(TRIE r){
	return r.prefijos;
}

SDL_Surface *inicializa( ){

    atexit(SDL_Quit);
	Uint32 videoflags;
		if ( SDL_Init(SDL_INIT_VIDEO) < 0 ){
			fprintf(stderr, "Couldn't initialize SDL: %s\n",SDL_GetError());
			exit(0);
		}
		videoflags = SDL_SWSURFACE;
//		videoflags |= SDL_FULLSCREEN;
		screen = SDL_SetVideoMode(WIDTH,HEIGHT,24, videoflags);
		if(screen == NULL){
			printf("No se ha podido establecer el modo de vídeo: %s\n", SDL_GetError());
			exit(1);
		}

	return screen;
}
