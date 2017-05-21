# Simulation of Trie Data Structure in C with SDL library
--------------------------

Simulation of the [Tries](https://en.wikipedia.org/wiki/Trie) Data Structure. The simulation have three nodes [a, b, c] and simulate the insertion of words with a kinky animation of Mario Bros sprites using SDL library.



#### Installation of SDL Library

You can install the library follow the official page. [Simple DirectMedia Layer](https://www.libsdl.org/)

#### Trie data structure example

```c
typedef struct nodo {
	int palabras;
	int prefijos;
	struct nodo *nodos[3];
	
} TRIE;
```

![image of trie](http://wikistack.com/wp-content/uploads/2014/12/tree.jpeg)


#### SDL Functions Examples

```c
    //Load bmp images
    void SDL_Loadimg();
    //Load ogg audios
    void SDL_Loadaudio();
    //Load ttf fonts
    void SDL_Loadfnt();
    //Load Marios Bross Sprites
    void SDL_Mario();
    //SDL_Surface
    SDL_Surface *inicializa() {

    atexit(SDL_Quit);
	Uint32 videoflags;
		if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
			fprintf(stderr, "Couldn't initialize SDL: %s\n",SDL_GetError());
			exit(0);
		}
		videoflags = SDL_SWSURFACE;
        //videoflags |= SDL_FULLSCREEN;
		screen = SDL_SetVideoMode(WIDTH,HEIGHT,24, videoflags);
		if(screen == NULL) {
			printf("Couldn't initialize video mode %s\n", SDL_GetError());
			exit(1);
		}

	return screen;
}
```

## Licence
__________

MIT License