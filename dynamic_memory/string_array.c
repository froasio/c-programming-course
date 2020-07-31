#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * string;

string strdup(string s);
void destroy_string_array(string ss[], size_t l);
string * clone_string_array(string ss[], size_t l);

int main(int argc, string argv[]) {

	size_t i;
	string *ss;

	ss = clone_string_array(argv, argc);
	if(ss == NULL)
		return EXIT_FAILURE;
	
	for(i = 0; i < argc; i++) {
		puts(ss[i]);
	}

	destroy_string_array(ss, argc);

	return EXIT_SUCCESS;

}

string strdup(string s) {
	string sc;
	sc = (char*) malloc((strlen(s)+1) * sizeof(char));
	if(sc == NULL)
		return NULL;
	strcpy(sc,s);
	return sc;
}

void destroy_string_array(string ss[], size_t l) {

	size_t i;
	
	for(i = 0; i < l; i++){
		free(ss[i]);
		ss[i] = NULL;
	}
	free(ss);

}

string * clone_string_array(string ss[], size_t l) {

  string * ssc;
  size_t i;
	if(ss == NULL || l == 0)
    return NULL;
  ssc=(string*)malloc(l*sizeof(string));
  if(ssc==NULL)
    return NULL;
  for(i = 0; i<l; i++){
    if((ssc[i] = strdup(ss[i]))==NULL){
      destroy_string_array(ssc,i);
      return NULL;
    }
  }
  return ssc;
	
}
