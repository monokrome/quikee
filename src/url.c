#include <string.h>
#include <stdlib.h>

#include "quikee/quikee.h"
#include "util.h"

qkURL* quikee_create_url(const char *protocol,
                         const char *host,
                         const char *uri)
{
	qkURL *new_url = malloc(sizeof(qkURL));

	new_url->protocol = malloc(sizeof(char) * strlen(protocol));
	strcpy(new_url->protocol, protocol);

	new_url->host = malloc(sizeof(char) * strlen(host));
	strcpy(new_url->protocol, host);

	new_url->uri = malloc(sizeof(char) * strlen(uri));
	strcpy(new_url->protocol, uri);

	new_url->hashtag = NULL;

	return new_url;
}

/**
 * Completely and safely deletes URLs created with quikee_create_url.
 */
void quikee_destroy_url(qkURL *url)
{
	free(url->protocol);
	free(url->host);
	free(url->uri);

	if (url->hashtag != NULL)
		free(url->hashtag);

	free(url);
}

/**
 * Convert a qkURL structure into a char-string referring to the real URL
 */
void quikee_real_url(const qkURL url, char *buffer)
{
	char *str_port = NULL;
	int url_length;

	url_length = strlen(url.protocol) + 3 // 3 for "://"
	             + strlen(url.host)
	             + strlen(url.uri)
	             + 1; // For our null terminator

	if (url.port != 0)
	{
		itoa(url.port, str_port, 10);
		url_length += strlen(str_port) + 1; // +1 for the ':' character
	}

	if (url.hashtag != NULL)
	{
		url_length += (1 + strlen(url.hashtag)); // +1 for the '#' character
	}

	buffer = malloc(sizeof(char) * url_length);

	strcpy(buffer, url.protocol);
	strcat(buffer, "://");
	strcat(buffer, url.host);

	if (url.port != 0)
	{
		strcat(buffer, ":");
		strcat(buffer, str_port);
		free(str_port);
	}

	strcat(buffer, url.uri);

	if (url.hashtag != NULL)
	{
		strcat(buffer, "#");
		strcat(buffer, url.hashtag);
	}
}


/**
 * Automatically determines the best port to use for the given URL.
 */
void quikee_get_port_for_url(qkURL *url)
{
	/**
	 TODO: We should maintain a list of protocols and their related ports
	       and use this method to automatically provide the right port
	       number for the given URL based on it's protocol.
	 */
}

/**
 * Receives a URL and a hashtag. Copies the memory from the given hashtag
 * into a newly allocated piece of memory, pointed to by url->hashtag.
 */
void quikee_set_url_hashtag(qkURL *url, char *hashtag)
{
	if (url->hashtag != NULL)
		free(url->hashtag);

	url->hashtag = malloc(sizeof(char) * strlen(hashtag));
	strcpy(url->hashtag, hashtag);
}

/**
 * Removes the hash tag from a given URL.
 */
void quikee_unset_url_hashtag(qkURL *url)
{
	if (url->hashtag != NULL)
	{
		free(url->hashtag);
		url->hashtag = NULL;
	}
}
