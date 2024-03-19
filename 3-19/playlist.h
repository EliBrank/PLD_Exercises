#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct song_s
{
	char *songName;
	char *albumName;
	int releaseDate;
	struct song_s *next;
	struct song_s *prev;
} song_t;

void play(song_t **current);
void skip(song_t **current);
void previous(song_t **current);
song_t *add_song(song_t **playlist, char *songName,
		char *albumName, int releaseDate);

#endif
