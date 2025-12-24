int estrita_bin(abb *a){

if (a == NULL)
    return 1;

    else{

        int ebe = estrita_bin(a->esq);
        int ebd = estrita_bin(a->dir);
        if (ebe == 0 || ebd == 0)
                return 0;

        else if (a->esq == NULL && a->dir == NULL)
                return 1;
        
        else if (a->esq != NULL && a->dir != NULL)
                return 1;        

    }
}