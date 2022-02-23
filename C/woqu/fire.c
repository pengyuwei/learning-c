  main                                                         
                   ()        {                                                
                    int n                                                     
            =        1280                                                     
             ,       i=n,  j=                                                 
                    23,v[i]    ;                                              
                 unsigned s                                                   
          =     j;while(i>                                                    
      0    )v      [i--]=0      ;                                             
          while(1) { for(i     =                                              
     0    ;i<n;i++){s*= j;    int                                             
      r=s%j;v[i]= i>>6==19?   63                                              
    - r&63: v[i+64+r% 3-1]-r%8  ;                                             
     v[i]=v[i ]<0?0 :v[i]; putchar (                                          
      " .'`~*%@X"[v[i]/8]); if(i%64                                           
    ==  63)putchar('\n');}usleep(                                             
      n*j);printf("\x1b[20A");}}                                              
          /* Burning code */   