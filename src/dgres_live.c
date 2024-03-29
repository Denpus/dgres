/*
 * dgres_live.c
 *
 * dgres_live
 * ==========
 *
 * Author   :  
 * Created  :  Fri Oct 25 20:31:19 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include "dgres_live.h"
#include <stdio.h>
#include <unistd.h>

int dgres_live(dgres_t *dgres) {
    int       err      = 0;
    int       cnt      = 0;
    const int delay_ms = 1;
    const int nprint   = 4;

    while (1) {
        cnt = (cnt + 1) % nprint;

        fwrite(dgres->txt, (size_t) dgres->ntxt, 1, dgres->stream);

        for (int i = 0; i < nprint; ++i) {
            fputc(i < cnt ? '.' : ' ', dgres->stream);
        }

        fflush(dgres->stream);
        fputc('\r', dgres->stream);

        sleep(delay_ms);
    }

    return err;
}
