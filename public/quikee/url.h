#ifndef __QUIKEE_URL_H__
#define __QUIKEE_URL_H__

// Represents an full URL
typedef struct {
	char *protocol; // The protocol that this URL requests with
	char *host; // The host that this specific URL refers to
	char *uri; // The URI that this request occured on
	short port; // The port number for this URL
	char *hashtag; // The hash tag, which is generally used for client logic

	/**
	 	 TODO: I don't think that we'll ever even see the hash tag, but it
	 	 remains within this structure until I can prove that suggestion
	 	 without a doubt.
	 **/
} qkURL;

qkURL* quikee_create_url (const char *protocol,
                          const char *host,
                          const char *uri);

void quikee_destroy_url(qkURL *url);
void quikee_real_url(const qkURL url, char *buffer);

void quikee_set_url_hashtag(qkURL *url, char *hashtag);
void quikee_unset_url_hashtag(qkURL *url);

void quikee_get_port_for_url(qkURL *url);

#endif
