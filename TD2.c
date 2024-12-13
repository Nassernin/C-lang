DEBUT
       List := NIL ;
       R := A ;
       CREERPILE ( P ) ;
       TQ ( R <> NIL ) OU ( NON PILEVIDE ( P ) )
           TQ R <> NIL
               EMPILER ( P , R ) ;
               R := FD ( R ) ;
              
           FTQ ;
           DEPILER ( P , R ) ;
           SI STRUCT ( INFO ( R ) , 2 )
               SI Feille ( R )
                   tq (non pilevide(p)) et (feuille_logique(R))
                   DEPILER ( P , R ) ;
                   ftq;
                   EMPILER ( P , R ) ;
                   R := FG ( R ) ;
                  
               SINON

                           EMPILER ( P , R ) ;
                           R := FG ( R ) ;
               FSI
           SINON
               SI Feille ( R )
                   Stop := FAUX ;
                   EMPILER ( P , R ) ;
                   TQ ( NON PILEVIDE ( P ) ) ET ( NON Stop )
                       DEPILER ( P , R ) ;
                       SI NON STRUCT ( INFO ( R ) , 2 )
                           ALLOUER ( Q ) ;
                           Val := STRUCT ( INFO ( R ) , 1 ) ;
                           AFF_VAL ( Q , Val ) ;
                           SI ( List = NIL )
                               List := Q ;
                              
                           SINON
                               AFF_ADR ( H , Q ) ;
                              
                           FSI ;
                           H := Q ;
                           AFF_STRUCT ( INFO ( R ) , 2 , VRAI ) ;
                          
                       SINON
                           Stop := VRAI ;
                           EMPILER ( P , R ) ;
                           R := FG ( R ) ;
                          
                       FSI
                   FTQ
               SINON
                   EMPILER ( P , R ) ;
                   R := FG ( R ) ;
                  
               FSI
           FSI ;
           SI Num_nodes ( A ) = Llc_length ( List )
               TQ ( NON PILEVIDE ( P ) )
                   DEPILER ( P , R ) ;

               FTQ ;
               R := NIL ;

           FSI
       FTQ ;
       APPEL Reinitializebool ( A ) ;
      
   FIN