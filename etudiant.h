#include "struct.h"
TNOF* open_file(char *,char );
void read_entete(TNOF *);
void write_entete(Entete, TNOF *);
void insert_etudiant(TNOF *,Etudiant );
int rechercher_etudiant(TNOF *,int,Etudiant * );
int read_bloc(TNOF *, Bloc *,int);
int write_bloc(TNOF*,int, Bloc,int);
void printetudiant(Etudiant);