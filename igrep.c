// This is an Academic Project, and was published after finishing the lecture.
// @author Joao Elvas @ FCT/UNL

#include<stdio.h>
#define MAXL 8000

/* Retorna true se o 'padrao' estiver presente na 'linha' */
int linha_inclui(char c1, char c2, char *linha) {
  int strlen = 0;
  int i = 0, n = 0;
  int ctrl1 = 0;
  int ctrl2 = 0;
  int r = 0;

  while (linha[n] != '\0'){
  	n++;
  }
  
  if(c2 != '\0') {
	  for(i;i<n;i++) {
	    if (linha[i] == c1 && ctrl1 != 1) {
        ctrl1 = 1;
      }  
      if (linha[i] == c2 && ctrl2 != 1 && ctrl1 == 1) {
                ctrl2 = 1;
              }
     

    }
  } else {
      for(i=0;i<n;i++) {
        if (linha[i] == c1) {
          ctrl1 = 1;
        }
      }
    }
   if(c2 != '\0') {
      if (ctrl1 && ctrl2){
        r = 1;
      } else r = 0;
   } else {
    if (ctrl1)
    {
      r = 1;
    } else r = 0;
   }
   return r;
}

int main(int argc, char *argv[]) {

  char str[MAXL];
  char *r=str;
  char char1, char2 = '\0';
  if ((argc<2)||(argc>3)) {
    printf("Utilize: %s caracter1 [caracter2]\n",argv[0]);
    return -1;
  }
  char1 = *(argv[1]);
  if (argc==3)
    char2 = *(argv[2]);
  while(r!=NULL) {
    r=fgets(str,MAXL,stdin);
    if (r &&
        linha_inclui(char1, char2, str))
            printf("%s",str);
  }
  return 0;
}
