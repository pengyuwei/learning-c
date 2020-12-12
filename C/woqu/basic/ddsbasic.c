/* DDS-BASIC interpreter in "C" annotated by Michael Somos 1997 */
/* INPUT bug fix 07Sep2005 Somos */
/* original by Diomidis Spinellis for 1990 IOCCC
<URL:http://reality.sgi.com/csp/ioccc/1990/dds.c>

#define O(b,f,u,s,c,a)b(){int o=f();switch(*p++){X u:_ o s b();X c:_ o a b();default:p--;_ o;}}
#define t(e,d,_,C)X e:f=fopen(B+d,_);C;fclose(f)
#define U(y,z)while(p=Q(s,y))*p++=z,*p=' '
#define N for(i=0;i<11*R;i++)m[i]&&
#define I "%d %s\n",i,m[i]
#define X ;break;case
#define _ return
#define R 999
typedef char*A;int*C,E[R],L[R],M[R],P[R],l,i,j;char B[R],F[2];A m[12*R],malloc
(),p,q,x,y,z,s,d,f,fopen();A Q(s,o)A s,o;{for(x=s;*x;x++){for(y=x,z=o;*z&&*y==
*z;y++)z++;if(z>o&&!*z)_ x;}_   0;}main(){m[11*R]="E";while(puts("Ok"),gets(B)
)switch(*B){X'R':C=E;l=1;for(i=0;i<R;P[i++]=0);while(l){while(!(s=m[l]))l++;if
(!Q(s,"\"")){U("<>",'#');U("<=",'$');U(">=",'!');}d=B;while(*F=*s){*s=='"'&&j
++;if(j&1||!Q(" \t",F))*d++=*s;s++;}*d--=j=0;if(B[1]!='=')switch(*B){X'E':l=-1
X'R':B[2]!='M'&&(l=*--C)X'I':B[1]=='N'?gets(p=B),P[*d]=S():(*(q=Q(B,"TH"))=0,p
=B+2,S()&&(p=q+4,l=S()-1))X'P':B[5]=='"'?*d=0,puts(B+6):(p=B+5,printf("%d\n",S
()))X'G':p=B+4,B[2]=='S'&&(*C++=l,p++),l=S()-1 X'F':*(q=Q(B,"TO"))=0;p=B+5;P[i
=B[3]]=S();p=q+2;M[i]=S();L[i]=l X'N':++P[*d]<=M[*d]&&(l=L[*d]);}else p=B+2,P[
*B]=S();l++;}X'L':N printf(I)X'N':N free(m[i]),m[i]=0   X'B':_ 0 t('S',5,"w",N
fprintf(f,I))t('O',4,"r",while(fgets(B,R,f))(*Q(B,"\n")=0,G()))X 0:default:G()
;}_ 0;}G(){l=atoi(B);m[l]&&free(m[l]);(p=Q(B," "))?strcpy(m[l]=malloc(strlen(p
)),p+1):(m[l]=0,0);}O(S,J,'=',==,'#',!=)O(J,K,'<',<,'>',>)O(K,V,'$',<=,'!',>=)
O(V,W,'+',+,'-',-)O(W,Y,'*',*,'/',/)Y(){int o;_*p=='-'?p++,-Y():*p>='0'&&*p<=
'9'?strtol(p,&p,0):*p=='('?p++,o=S(),p++,o:P[*p++];}

<URL:http://reality.sgi.com/csp/ioccc/1990/dds.hint>
Best Language Tool: <dds@cc.ic.ac.uk> Diomidis Spinellis

        Diomidis Spinellis
        Imperial College, University of London
        Myrsinis 1
        GR-145 62 Kifissia
        Greece


Judges' comments:

    Compile and run.  Give the following lines as input:

        OLD LANDER.BAS
        RUN

    Be sure not to run out of fuel!


Selected notes from the author:

    This is the DDS-BASIC Interpreter (Version 1.00).

    Immediate commands:

        RUN     LIST    NEW     OLD filename
        BYE     SAVE filename

    Program commands:

        variable names a to z           variables initialized to 0 on RUN
        FOR var = exp TO exp            NEXT variable
        GOSUB exp                       RETURN
        GOTO exp                        IF exp THEN exp
        INPUT variable                  PRINT string
        PRINT exp                       var = exp
        REM any text                    END

    Expressions (ranked by precedence):

        Bracketed expressions
        number (leading 0 for octal, 0x for hex, else decimal), variable
        Unary -
        * /
        + -
        = <>
        > <
        <= >=
        (* and + are also used for boolean AND and boolean OR)
        Boolean expressions evaluate to 0 for false and 1 for true

    Editing:

        - Line editor using line re-entry.
        - A line number with nothing following it, deletes the line.

    Input format:

        - Free format positioning of tokens on the line.
        - No space is allowed before the line number.
        - Exactly one space is needed between the OLD or SAVE command and
          the filename.
        - ALL INPUT MUST BE UPPERCASE.

    Limits:

        Line numbers            1-10000
        Line length             999 characters
        FOR nesting             26
        GOSUB                   999 levels
        Program                 Dynamically allocated
        Expressions             -32768 - 32767 for 16 bit machines,
                                -2147483648 - 2147483647 for 32 bit machines

    Error checking / error reports:

        No error checking is performed.
        The message `core dumped' signifies a syntax or semantic error.

    Hosting Environment:

        ANSI C, traditional K&R C or OSF ANDF
        ASCII or EBCIDIC character set
        48K bytes memory

    The Speed of DDS-BASIC Interpreter (Version 1.00). relative to
    Microsoft Advanced BASIC 3.31 is Approximately 60%.

    The code size could be further reduced by doing ugly things like
    not declaring the return type of functions, not freeing memory,
    #defining define, and joining lines.  In its present 1536 character
    form the program is reasonably portable (it may fail to run in a
    tagged object architecture) and nicely formatted (it fits in an
    80*25 screen).

Copyright (c) 1990, Landon Curt Noll & Larry Bassel.
All Rights Reserved.  Permission for personal, educational or non-profit use is
granted provided this this copyright and notice are included in its entirety
and remains unaltered.  All other uses must receive prior permission in writing
from both Landon Curt Noll and Larry Bassel.
*/

#include <stdio.h>
#include <stdlib.h>

#define SMAX 999
#define CMAX 256
#define BMAX 999
#define LMAX 9999
typedef char * STRPTR ;

int E [ SMAX ] ; /* subroutine line number stack */
int L [ CMAX ] ; /* FOR loop beginning line number */
int M [ CMAX ] ; /* FOR loop maximum index value */
int P [ CMAX ] ; /* program variable value */
int l , i , j ;
int * C ; /* subroutine stack pointer */
char B [ BMAX ] ; /* command input buffer */
char F [ 2 ] ; /* temporary search string */
STRPTR m [ 1 + LMAX ] ; /* pointers to lines of program */
STRPTR p , q , x , y , z , s , d ;
FILE * f ; /* file pointer for input and output */

STRPTR strstr ( STRPTR s , STRPTR o )
{
STRPTR x , y , z ;
 for ( x = s ; * x ; x ++ ) {
  for ( y = x , z = o ; * z && * y == * z ; y ++ ) z ++ ;
  if ( z > o && ! * z ) return x ;
 } return 0 ;
} /* end strstr */

void G ( void ) ;
int S ( void ) ;
int J ( void ) ;
int K ( void ) ;
int V ( void ) ;
int W ( void ) ;
int Y ( void ) ;

int main ( void ) {
int tmp ; /* temp var to fix bug 07Sep2005 Somos */
m [ LMAX ] = "E" ; /* "END" */
while ( puts ( "Ok" ) , gets ( B ) )
 switch ( * B ) {
 case 'R' : /* "RUN" command */
  C = E ;
  l = 1 ;
  for ( i = 0 ; i < CMAX ; P [ i ++ ] = 0 ) ; /* initialize variables */
  while ( l ) {
   while ( ! ( s = m [ l ] ) ) l ++ ;
   if ( ! strstr ( s , "\"" ) ) {
     while ( ( p = strstr ( s , "<>" ) ) ) * p ++ = '#' , * p = ' ' ;
     while ( ( p = strstr ( s , "<=" ) ) ) * p ++ = '$' , * p = ' ' ;
     while ( ( p = strstr ( s , ">=" ) ) ) * p ++ = '!' , * p = ' ' ;
   }
   d = B ;
   while ( ( * F = * s ) ) {
     if ( * s == '"' ) j ++ ;
     if ( j & 1 || ! strstr ( " \t" , F ) )
       * d ++ = * s ;
     s ++ ;
   }
   * d -- = j = 0 ;
   if ( B [ 1 ] != '=' ) switch ( * B ) {
     case 'E' : /* "END" */
       l = - 1 ;
       break ;
     case 'R' : /* "REM" */
       if ( B [ 2 ] != 'M' ) l = * -- C ; /* "RETURN" */
       break ;
     case 'I' :
       if ( B [ 1 ] == 'N' ) { /* "INPUT" */
         tmp = *d ; /* save for bug fix next line 07Sep2005 Somos */ 
         gets ( p = B ) ; P [ tmp ] = S ( ) ;
       } else { /* "IF" */
       * ( q = strstr ( B , "TH" ) ) = 0 ; /* "THEN" */
       p = B + 2 ;
       if ( S ( ) ) { p = q + 4 ; l = S ( ) - 1 ; }
       }
       break ;
     case 'P' : /* "PRINT" */
       if ( B [ 5 ] == '"' ) {
         * d = 0 ; puts ( B + 6 ) ;
       } else {
         p = B + 5 ;
         printf ( "%d\n" , S ( ) ) ;
       }
       break ;
     case 'G' : /* "GOTO" */
       p = B + 4 ;
       if ( B [ 2 ] == 'S' ) { /* "GOSUB" */
         * C ++ = l ; p ++ ; }
       l = S ( ) - 1 ;
       break ;
     case 'F' : /* "FOR" */
       * ( q = strstr ( B , "TO" ) ) = 0 ; /* "TO" */
       p = B + 5 ;
       P [ i = B [ 3 ] ] = S ( ) ;
       p = q + 2 ;
       M [ i ] = S ( ) ;
       L [ i ] = l ;
       break ;
     case 'N' : /* "NEXT" */
        if ( ++ P [ * d ] <= M [ * d ] ) l = L [ * d ] ;
     } else {
     p = B + 2 ;
     P [ * B ] = S ( ) ; }
   l ++ ;
  } /* end while l */
    break ;
  case 'L' : /* "LIST" command */
    for ( i = 0 ; i < LMAX ; i ++ )
    if ( m [ i ] ) printf ( "%d %s\n", i , m [ i ] ) ;
    break ;
  case 'N' : /* "NEW" command */
    for ( i = 0 ; i < LMAX ; i ++ )
    if ( m [ i ] ) { free ( m [ i ] ) ; m [ i ] = 0 ; }
    break ;
  case 'B' : /* "BYE" command */
    return 0 ;
    break ;
  case 'S' : /* "SAVE" command */
    f = fopen ( B + 5 , "w" ) ;
    for ( i = 0 ; i < LMAX ; i ++ )
      if ( m [ i ] ) fprintf ( f , "%d %s\n" , i , m [ i ] ) ;
    fclose ( f )  ;
    break ;
  case 'O' : /* "OLD" command */
    f = fopen ( B + 4 , "r" ) ;
    while ( fgets ( B , BMAX , f ) ) {
      * strstr ( B , "\n" ) = 0 ;
      G ( ) ;
    }
    fclose ( f )  ;
    break ;
  case 0 :
  default :
    G ( ) ;
} /* end switch *B */
return 0 ;
} /* end main */

void G ( void ) { /* get program line from buffer */
l = atoi ( B ) ;
if ( m [ l ] ) free ( m [ l ] ) ;
if ( ( p = strstr ( B , " " ) ) )
  strcpy ( m [ l ] = malloc ( strlen ( p ) ) , p + 1 ) ;
  else m [ l ] = 0 ;
} /* end G */

/* recursive descent parser for arithmetic/logical expressions */
int S ( void ) {
int o = J ( ) ;
switch ( * p ++ ) {
  case '=' : return o == S ( ) ;
    break ;
  case '#' : return o != S ( ) ;
  default : p -- ; return o ;
  }
} /* end S */

int J ( void ) {
int o = K ( ) ;
switch ( * p ++ ) {
  case '<' : return o < J ( ) ;
    break ;
  case '>' : return o > J ( ) ;
  default : p -- ; return o ;
  }
} /* end J */

int K ( void ) {
int o = V ( ) ;
switch ( * p ++ ) {
  case '$'  : return o <= K ( ) ;
    break ;
  case '!'  : return o >= K ( ) ;
  default : p -- ; return o ;
  }
} /* end K */

int V ( void ) {
int o = W ( ) ;
switch ( * p ++ ) {
  case '+'  : return o + V ( ) ;
    break ;
  case '-'  : return o - V ( ) ;
  default : p -- ; return o ;
  }
} /* end V */

int W ( void ) {
int o = Y ( ) ;
switch ( * p ++ ) {
  case '*'  : return o * W ( ) ;
    break ;
  case '/'  : return o / W ( ) ;
  default : p -- ; return o ;
  }
} /* end W */

int Y ( void ) {
int o ;
return
( * p == '-' ) ? ( p ++ , - Y ( ) ) :
  ( * p >= '0' && * p <= '9' ) ? strtol ( p , & p , 0 ) :
    ( * p == '(' ) ?
      ( p ++ , o = S ( ) , p ++ , o ) :
      P [ * p ++ ] ;
} /* end Y */

/* end of DDS-BASIC program */
