#include "playlist.h"

int main(void)
{
	song_t *current = NULL;
	song_t **playlist = NULL;

	add_song(playlist, "Smells Like Teen Spirit", "Nevermind", 1991);
	add_song(playlist, "Careless Whisper", "Make It Big", 1984);
	add_song(playlist, "Don't Stop Believin'", "Escape", 1981);

	current = *playlist;
	play(&current);
	skip(&current);
	previous(&current);

	return (0);
}

song_t *add_song(song_t **playlist, char *songName,
		char *albumName, int releaseDate)
{
	song_t *new = NULL;

	new = malloc(sizeof(song_t));

	if (!new)
		return (NULL);

	new->songName = songName;
	new->albumName = albumName;
	new->releaseDate = releaseDate;

	new->next = NULL;
	new->prev = NULL;

	if (*playlist == NULL)
	{
		*playlist = new;
		return (new);
	}

	new->next = *playlist;
	(*playlist)->prev = new;

	*playlist = new;

	return (new);
}

void play(song_t **current)
{
	printf("%s\n", (*current)->songName);
	printf("%s\n", (*current)->albumName);
	printf("%d\n", (*current)->releaseDate);
}

void skip(song_t **current)
{
	if (!(*current)->next)
	{
		printf("End of playlist\n");
		return;
	}
	*current = (*current)->next;
	play(current);
}

void previous(song_t **current)
{
	*current = (*current)->next;
	play(current);
}
