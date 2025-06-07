#include "wave.h"

int main(void)
{
    MONO_PCM pcm0, pcm1;
    int n;
    double a, depth, rate;

    /* WAVEファイルからモノラルの音データを入力する */
    mono_wave_read(&pcm0, "sample05.wav");

    pcm1.fs = pcm0.fs;                            /* 標本化周波数 */
    pcm1.bits = pcm0.bits;                        /* 量子化精度 */
    pcm1.length = pcm0.length;                    /* 音データの長さ */
    pcm1.s = calloc(pcm1.length, sizeof(double)); /* メモリの確保 */

    depth = 1.0;
    rate = 5.0;

    /* トレモロ */
    for (n = 0; n < pcm1.length; n++)
    {
        a = 1 + depth * sin(2 * M_PI * rate * n / pcm1.fs);
        pcm1.s[n] = pcm0.s[n] * a; /* 振幅を変調 */
    }

    /* WAVEファイルにモノラルの音データを出力する */
    mono_wave_write(&pcm1, "tremolo.wav");

    free(pcm0.s); /* メモリの解放 */
    free(pcm1.s); /* メモリの解放 */

    return 0;
}
